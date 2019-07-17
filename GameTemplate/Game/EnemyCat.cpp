#include "stdafx.h"
#include "EnemyCat.h"
#include "Player.h"
#include "Pen.h"
#include "GameData.h"
#include "EffectManager.h"

EnemyCat::EnemyCat()
{

}
EnemyCat::~EnemyCat()
{
	DeleteGO(m_skinModelRender);

}

bool EnemyCat::Start()
{
	//アニメーション
	m_animClips[enAnimationClip_idle].Load(L"animData/Catidel.tka"); //待機
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].Load(L"animData/Catwalk.tka"); //歩き&逃げ
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);

	////敵のHPbar
	//m_skin = NewGO<prefab::CSpriteRender>(0);
	//m_skin->Init(L"sprite/AHP/Awaku.dds", 100.0f, 30.0f);//500.0f, 45.0f
	//m_position2 = { 0.0f, 150.0f, 0.0f };
	//m_skin->SetPosition(m_position2);
	////敵の白色のバー
	//m_skin2 = NewGO<prefab::CSpriteRender>(0);
	//m_skin2->Init(L"sprite/AHP/AWhp.dds", 100.0f, 30.0f);//500.0f, 80.0f
	//m_position2 = { 0.0f,150.0f,0.0f };
	//m_skin2->SetPosition(m_position2);
	//m_skin2->SetMulColor({ 0.0f,1.0f,0.0f,1.0f });


	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/neko/neko.cmo", m_animClips, enAnimationClip_Num);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetRotation(m_rotation);

	//キャラコン
	m_charaCon.Init(
		15.0f,  //半径。
		25.0f,  //高さ。
		m_position //初期座標。
	);
	return true;
}
void EnemyCat::CatHorizon()
{
	Player* player = Player::GetInstance();
	//エネミーの前方方向を求める。
	//前方方向は{0, 0, 1}のベクトルをm_rotationで回して求めてみる。
	CVector3 enemyForward = { 1.0f, 0.0f, 0.0f };
	m_rotation.Multiply(enemyForward);

	//エネミーからプレイヤーに伸びるベクトルを求める。
	CVector3 toPlayerDir = player->Getm_Position() - m_position;

	//正規化を行う前に、プレイヤーまでの距離を求めておく。
	float toPlayerLen = toPlayerDir.Length();
	//正規化
	toPlayerDir.Normalize();

	//enemyForwardとtoPlayerDirとの内積を計算する。
	float d = enemyForward.Dot(toPlayerDir);

	//内積の結果をacos関数に渡して、enemyForwardとtoPlayerDirのなす角を求める。
	float angle = acos(d);


	//視野角判定
	//fabsfは絶対値を求める関数！
	//角度はマイナスが存在するから、絶対値にする。
	if (fabsf(angle) < CMath::DegToRad(horiAngle) && toPlayerLen < horilong)
	{
		//近い！！！！！
		m_state = EnState_runaway;

	}

}

void EnemyCat::CatIdle()
{
	//待機状態
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	stoptimer++;
	moveVec = moveVec * 0.0f;	//動きませーーん
	if (stoptimer >= stopendtimer) {
		m_state = EnState_walk;
	}

}
void EnemyCat::CatWalk()
{
	//歩き状態
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	count++;

	if (count == randomCount) {
		//ランダムで方向を決定して動きます
		wrandom = rand() % 360;
		m_rotation.SetRotation(CVector3::AxisY, (float)wrandom);
		walkmove = { 1.0f, 0.0f,0.0f };
		m_rotation.Multiply(walkmove);
		count = 0;
	}
	moveVec = walkmove * randomSpeed;
	m_position = m_charaCon.Execute(moveVec);
}
void EnemyCat::CatRunaway()
{
	//逃げてる状態
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	if (diff.Length() < runaway) {
		//離れまーーーーース
		diff.y = 0.0f;
		diff.Normalize();
		moveVec = diff * followSpeed * -1.0f;
		/*m_sound2 = NewGO<prefab::CSoundSource>(0);
		m_sound2->Init(L"sound/cat-threat1.wav");
		m_sound2->Play(false);*/
		//m_sound2->SetVolume(0.5f);
	}
	else {
		//その場で移動
		m_state = EnState_walk;
	}

	//回転の処理
	if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		//わからん
		return;
	}


	CVector3 enemyForward = { -1.0f, 0.0f, 0.0f };

	//　向かせたい方向のベクトルを計算する。
	CVector3 targetVector = P_Position - m_position;
	//　Y成分は除去して正規化する。Y成分を入れると空を向いたりするよ。
	targetVector.y = 0.0f;
	targetVector.Normalize();
	CQuaternion qRot;
	qRot.SetRotation(enemyForward, targetVector);
	m_rotation = qRot;
	m_position = m_charaCon.Execute(moveVec);
}
void EnemyCat::CatDeath()
{
	//死
	EffectManager* effect = EffectManager::GetInstance();
	effect->EffectPlayer(EffectManager::Bakuhatu, m_position, EfeSize);
	DeleteGO(this);

}
void EnemyCat::Animation() {
	if (m_state == EnState_idle) {
		m_skinModelRender->PlayAnimation(0);
	}
	else if (m_state == EnState_runaway || m_state == EnState_walk) {
		m_skinModelRender->PlayAnimation(1);
	}
}

void EnemyCat::Update()
{
	////↓これで変更する
	////スクリーンPos自分
	////猫とカメラと距離を計算する。
	//CVector3 cameraPos = MainCamera().GetPosition();
	//CVector3 Pos = cameraPos - m_position;
	//float len = Pos.Length();
	//if (len < 300.0f) {
	//	m_skin->SetActiveFlag(true);
	//	m_skin2->SetActiveFlag(true);
	//	//2Dを非表示にするには、m_skin->SetActiveFlag(false);
	//	//2Dを表示にするには、m_skin->SetActiveFlag(true);
	//	CVector3 screenPos;
	//	CVector3 atamaNoPos = m_position;
	//	atamaNoPos.y += 40.0f;
	//	MainCamera().CalcScreenPositionFromWorldPosition2(screenPos, atamaNoPos);

	//	if (screenPos.z > 0.0f) {
	//		screenPos.z = 0.0f;
	//		m_skin->SetPosition(screenPos);
	//		m_skin2->SetPosition(screenPos);
	//	}
	//}
	//else {
	//	m_skin->SetActiveFlag(false);
	//	m_skin2->SetActiveFlag(false);
	//}

	CatHorizon();	//視野角
	Animation();
	switch (m_state)
	{
	case EnemyCat::EnState_idle:
		CatIdle();
		break;
	case EnemyCat::EnState_walk:
		CatWalk();
		break;
	case EnemyCat::EnState_runaway:
		CatRunaway();
		break;
	case EnemyCat::EnState_death:
		CatDeath();
		break;

	}
	CatHorizon();	//視野角
	Animation();

	//ペンとの衝突判定
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		if (diff.Length() < DeadLength) {
			//撃たれた....
			GameData* gamedata = GameData::GetInstance();
			gamedata->DeadHkasan(1);
			gamedata->ResultDeadkasan(GameData::DeadCat);
			//ペンも消滅
			/*m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/MAuke.wav");
			m_sound->Play(false);
			m_sound->SetVolume(0.5f);*/
			pen->SetDeath();
			m_state = EnState_death;//死にます。
		}
		return true;
		});

	//移動と回転
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);


}
