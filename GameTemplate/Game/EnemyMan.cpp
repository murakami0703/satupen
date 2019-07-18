#include "stdafx.h"
#include "EnemyMan.h"
#include "Player.h"
#include "Pen.h"
#include "EffectManager.h"
#include "GameData.h"

EnemyMan::EnemyMan()
{

}
EnemyMan::~EnemyMan()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_skin);
	DeleteGO(m_skin2);
	DeleteGO(m_skin3);

}

bool EnemyMan::Start()
{
	//アニメーション
	m_animClips[enAnimationClip_idle].Load(L"animData/Manidel.tka"); //待機
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].Load(L"animData/Manwalk.tka"); //歩き
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);
	m_animClips[enAnimationClip_yobi].Load(L"animData/ManAttackYobi.tka"); //予備
	m_animClips[enAnimationClip_attack].Load(L"animData/ManAttack.tka"); //攻撃
	m_animClips[enAnimationClip_prostrate].Load(L"animData/ManDogeza.tka"); //土下座

	//敵のHPbar
	m_skin = NewGO<prefab::CSpriteRender>(2);
	m_skin->Init(L"sprite/AHP/Awaku.dds", 100.0f, 30.0f);//500.0f, 45.0f
	m_position2 = { 0.0f, 150.0f, 0.0f };
	m_skin->SetPosition(m_position2);
	//敵の白色のバー
	m_skin2 = NewGO<prefab::CSpriteRender>(1);
	m_skin2->Init(L"sprite/AHP/AWhp.dds", 100.0f, 30.0f);//500.0f, 80.0f
	m_position2 = { -50.0f,135.0f,0.0f };
	m_skin2->SetPosition(m_position2);
	m_skin2->SetMulColor({ 0.0f,1.0f,0.0f,1.0f });
	m_skin2->SetPivot(LifePivot);
	//HPBbar翠
	m_skin3 = NewGO<prefab::CSpriteRender>(0);
	m_skin3->Init(L"sprite/HPBbar.dds", 110.0f, 30.0f);
	m_skin3->SetPosition({ 0.0f, 150.0f, 0.0f });

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Man/otoko.cmo", m_animClips, enAnimationClip_Num);
	m_skinModelRender->SetPosition(m_position);

	wrandom = rand() % 360;
	m_rotation.SetRotation(CVector3::AxisY, (float)wrandom);
	walkmove = { 0.0f, 0.0f,-1.0f };
	m_rotation.Multiply(walkmove);

	//キャラコン
	m_charaCon.Init(
		20.0f,  //半径。
		35.0f,  //高さ。
		m_position //初期座標。
	);
	m_skinModelRender->SetShadowCasterFlag(true);

	return true;
}
void EnemyMan::ManHorizon()
{
	Player* player = Player::GetInstance();
	//エネミーの前方方向を求める。
	//前方方向は{0, 0, 1}のベクトルをm_rotationで回して求めてみる。
	CVector3 enemyForward = { 0.0f, 0.0f, -1.0f };
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
	if (attackflag == false) {
		if (fabsf(angle) < CMath::DegToRad(horiAngle) && toPlayerLen < horilong)
		{
			//近い！！！！！
			m_state = EnState_attack;

		}

	}

}
void EnemyMan::ManIdle()
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
void EnemyMan::ManWalk()
{
	//歩き状態
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;
	if (count > randomCount) {
		count = 0;
	}
	count++;

	if (count == randomCount ) {
		//ランダムで方向を決定して動きます
		wrandom = rand() % 360;
		m_rotation.SetRotation(CVector3::AxisY, (float)wrandom);
		walkmove = { 0.0f, 0.0f,-1.0f };
		m_rotation.Multiply(walkmove);
		count = 0;
		attackflag = false;

	}
	moveVec = walkmove * randomSpeed;
	m_position = m_charaCon.Execute(moveVec);

}

void EnemyMan::ManAttack()
{
	//攻撃状態
	GameData* gamedata = GameData::GetInstance();
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;
	move = diff;
	if (diff.Length() < 600.0f && diff.Length() > 50.0f) {
		//近づきます
		move.y = 0.0f;
		move.Normalize();
		moveVec = move * attackSpeed;
		m_skinModelRender->PlayAnimation(1);
	}
	else if (diff.Length() < 50.0f && attackflag == false) {
		m_skinModelRender->PlayAnimation(3);
		gamedata->tiryokugennsyou(-10);
		attackflag = true;
	}
	else if(attackflag == true){
		//離れたのでその場で移動しま
		m_state = EnState_walk;
	}

	//回転の処理
	if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		//わからん
		return;
	}


	CVector3 enemyForward = { 0.0f, 0.0f, -1.0f };

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

void EnemyMan::ManDeath()
{
	DeleteGO(this);
}
void EnemyMan::Animation() {
	if (m_state == EnState_idle) {
		m_skinModelRender->PlayAnimation(0);
	}
	else if ( m_state == EnState_walk) {
		m_skinModelRender->PlayAnimation(1);
	}
	else if (m_state == enAnimationClip_prostrate) {
		m_skinModelRender->PlayAnimation(4);

	}
}
void EnemyMan::ManHP() {
	//寿命ゲージを動かす
	//寿命のを計算
	LifeY = (float)HP / (float)MAX_HP;
	//???
	LifeScale = { LifeY,1.0f,1.0f };
	m_skin2->SetScale(LifeScale);
}
void EnemyMan::Update()
{
	//↓これで変更する
	//スクリーンPos自分

	//子供とカメラと距離を計算する。
	CVector3 cameraPos = MainCamera().GetPosition();
	CVector3 Pos = cameraPos - m_position;
	float len = Pos.Length();
	if (len < 300.0f) {
		m_skin->SetActiveFlag(true);
		m_skin2->SetActiveFlag(true);
		//2Dを非表示にするには、m_skin->SetActiveFlag(false);
		//2Dを表示にするには、m_skin->SetActiveFlag(true);
		CVector3 screenPos;
		CVector3 atamaNoPos = m_position;
		atamaNoPos.y += 40.0f;
		MainCamera().CalcScreenPositionFromWorldPosition2(screenPos, atamaNoPos);

		if (screenPos.z > 0.0f) {
			screenPos.z = 0.0f;
			m_skin->SetPosition(screenPos);
			CVector3 hoge = screenPos;
			hoge.x += -50.0f;
			hoge.y += -10.0f;
			hoge.z += 0.0f;
			m_skin2->SetPosition(hoge);
			m_skin3->SetPosition(screenPos);

		}
	}
	else {
		m_skin->SetActiveFlag(false);
		m_skin2->SetActiveFlag(false);
		m_skin3->SetActiveFlag(false);
	}

	switch (m_state)
	{
	case EnemyMan::EnState_idle:
		ManIdle();
		break;
	case EnemyMan::EnState_walk:
		ManWalk();
		break;
	case EnemyMan::EnState_attack:
		ManAttack();
		break;
	case EnemyMan::EnState_death:
		ManDeath();
		break;

	}
	ManHorizon();
	Animation();
	//ペンとの衝突判定
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		//撃たれた....
		if (diff.Length() < DeadLength) {
			//ペンも消滅]			
			EffectManager* effect = EffectManager::GetInstance();
			effect->EffectPlayer(EffectManager::BloodZonbi, m_position, { 10.0f,10.0f,10.0f });
			m_sound2 = NewGO<prefab::CSoundSource>(0);
			m_sound2->Init(L"sound/sasu3.wav");
			m_sound2->Play(false);
			m_sound2->SetVolume(0.5f);

			pen->SetDeath();
			HP -= 25;
			ManHP();
			if (HP < 0) {
				HP = 0;
			}
			if (HP <= 0) {
				GameData* gamedata = GameData::GetInstance();
				gamedata->DeadHkasan(1);
				gamedata->ResultDeadkasan(GameData::DeadMan);
				m_sound = NewGO<prefab::CSoundSource>(0);
				m_sound->Init(L"sound/MAuke.wav");
				m_sound->Play(false);
				m_sound->SetVolume(0.5f);
				m_state = EnState_death;//死にます。
			}
		}
		return true;
		});

	//移動と回転
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
