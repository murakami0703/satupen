#include "stdafx.h"
#include "EnemyBird.h"
#include "Player.h"
#include "Pen.h"
#include "GameData.h"
#include "EffectManager.h"

EnemyBird::EnemyBird()
{

}
EnemyBird::~EnemyBird()
{

	DeleteGO(m_skinModelRender);
	/*DeleteGO(m_skin);
	DeleteGO(m_skin2);*/

}

bool EnemyBird::Start()
{
	//アニメーション
	m_animClips[enAnimationClip_walk].Load(L"animData/Crowwalk.tka"); //歩き&逃げ
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);
	m_animClips[enAnimationClip_fly].Load(L"animData/Crowfly.tka"); //飛び
	m_animClips[enAnimationClip_fly].SetLoopFlag(true);


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
	m_skinModelRender->Init(L"modelData/karasu/karasuu.cmo", m_animClips, enAnimationClip_Num);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetRotation(m_rotation);

	//キャラコン
	m_charaCon.Init(
		10.0f,  //半径。
		20.0f,  //高さ。
		m_position //初期座標。
	);
	return true;
}

void EnemyBird::BirdHorizon()
{
	Player* player = Player::GetInstance();
	//エネミーの前方方向を求める。
	//前方方向は{0, 0, 1}のベクトルをm_rotationで回して求めてみる。
	CVector3 enemyForward = { -1.0f, 0.0f, 0.0f };
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
		m_state = EnState_fly;

	}

}

void EnemyBird::BirdIdle()
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
void EnemyBird::BirdWalk()
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
		walkmove = { -1.0f, 0.0f,0.0f };
		m_rotation.Multiply(walkmove);
		count = 0;
	}
	moveVec = walkmove * randomSpeed;
	m_position = m_charaCon.Execute(moveVec);
}
void EnemyBird::BirdFly()
{
	//飛ぶとき
	/*m_sound2 = NewGO<prefab::CSoundSource>(0);
	m_sound2->Init(L"sound/crow2.wav");
	m_sound2->Play(false);
	m_sound2->SetVolume(0.5f);*/
	
	//上に逃げるよ
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	//離れまーーーーース
	diff.Normalize();
	moveVec = diff * fleeSpeed * -1.0f;
	moveVec.y += 20.0f;

	CVector3 enemyForward = { 1.0f, 0.0f, 0.0f };

	//回転の処理
	if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		//わからん
		return;
	}
	//　向かせたい方向のベクトルを計算する。
	CVector3 targetVector = P_Position - m_position;
	//　Y成分は除去して正規化する。Y成分を入れると空を向いたりするよ。
	targetVector.y = 0.0f;
	targetVector.Normalize();
	CQuaternion qRot;
	qRot.SetRotation(enemyForward, targetVector);
	m_rotation = qRot;
	m_position = m_charaCon.Execute(moveVec);

	if (m_position.y > 600.0f) {
		DeleteGO(this);
	}
	/*m_sound3 = NewGO<prefab::CSoundSource>(0);
	m_sound3->Init(L"sound/pigeon-take-off1.wav");
	m_sound3->Play(false);
	m_sound3->SetVolume(0.5f);*/
}
void EnemyBird::Animation() {
	if (m_state == EnState_walk) {
		m_skinModelRender->PlayAnimation(0);
	}
	else if (m_state == EnState_fly) {
		m_skinModelRender->PlayAnimation(1);
	}

}

void EnemyBird::BirdDeath()
{
	//死
	EffectManager* effect = EffectManager::GetInstance();
	effect->EffectPlayer(EffectManager::Bakuhatu, m_position, EfeSize);
	DeleteGO(this);
}

void EnemyBird::Update()
{
	//↓これで変更する
	//スクリーンPos自分

	//鳥とカメラと距離を計算する。
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

	BirdHorizon();	//視野角
	Animation();
	switch (m_state)
	{
	case EnemyBird::EnState_idle:
		BirdIdle();
		break;
	case EnemyBird::EnState_walk:
		BirdWalk();
		break;
	case EnemyBird::EnState_fly:
		BirdFly();
		break;
	case EnemyBird::EnState_death:
		BirdDeath();
		break;

	}
	BirdHorizon();	//視野角
	Animation();

	//ペンとの衝突判定
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		if (diff.Length() < DeadLength) {
			//撃たれた....
			GameData* gamedata = GameData::GetInstance();
			gamedata->DeadHkasan(1);
			gamedata->ResultDeadkasan(GameData::DeadBird);
			//ペンも消滅
			pen->SetDeath();
			/*m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/MAuke.wav");
			m_sound->Play(false);
			m_sound->SetVolume(0.5f);*/
			m_state = EnState_death;//死にます。
		}
		return true;
		});

	//移動と回転
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);


}

