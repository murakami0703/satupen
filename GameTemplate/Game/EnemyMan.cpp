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
	//�A�j���[�V����
	m_animClips[enAnimationClip_idle].Load(L"animData/Manidel.tka"); //�ҋ@
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].Load(L"animData/Manwalk.tka"); //����
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);
	m_animClips[enAnimationClip_yobi].Load(L"animData/ManAttackYobi.tka"); //�\��
	m_animClips[enAnimationClip_attack].Load(L"animData/ManAttack.tka"); //�U��
	m_animClips[enAnimationClip_prostrate].Load(L"animData/ManDogeza.tka"); //�y����

	//�G��HPbar
	m_skin = NewGO<prefab::CSpriteRender>(2);
	m_skin->Init(L"sprite/AHP/Awaku.dds", 100.0f, 30.0f);//500.0f, 45.0f
	m_position2 = { 0.0f, 150.0f, 0.0f };
	m_skin->SetPosition(m_position2);
	//�G�̔��F�̃o�[
	m_skin2 = NewGO<prefab::CSpriteRender>(1);
	m_skin2->Init(L"sprite/AHP/AWhp.dds", 100.0f, 30.0f);//500.0f, 80.0f
	m_position2 = { -50.0f,135.0f,0.0f };
	m_skin2->SetPosition(m_position2);
	m_skin2->SetMulColor({ 0.0f,1.0f,0.0f,1.0f });
	m_skin2->SetPivot(LifePivot);
	//HPBbar��
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

	//�L�����R��
	m_charaCon.Init(
		20.0f,  //���a�B
		35.0f,  //�����B
		m_position //�������W�B
	);
	m_skinModelRender->SetShadowCasterFlag(true);

	return true;
}
void EnemyMan::ManHorizon()
{
	Player* player = Player::GetInstance();
	//�G�l�~�[�̑O�����������߂�B
	//�O��������{0, 0, 1}�̃x�N�g����m_rotation�ŉ񂵂ċ��߂Ă݂�B
	CVector3 enemyForward = { 0.0f, 0.0f, -1.0f };
	m_rotation.Multiply(enemyForward);

	//�G�l�~�[����v���C���[�ɐL�т�x�N�g�������߂�B
	CVector3 toPlayerDir = player->Getm_Position() - m_position;

	//���K�����s���O�ɁA�v���C���[�܂ł̋��������߂Ă����B
	float toPlayerLen = toPlayerDir.Length();
	//���K��
	toPlayerDir.Normalize();

	//enemyForward��toPlayerDir�Ƃ̓��ς��v�Z����B
	float d = enemyForward.Dot(toPlayerDir);

	//���ς̌��ʂ�acos�֐��ɓn���āAenemyForward��toPlayerDir�̂Ȃ��p�����߂�B
	float angle = acos(d);


	//����p����
	//fabsf�͐�Βl�����߂�֐��I
	//�p�x�̓}�C�i�X�����݂��邩��A��Βl�ɂ���B
	if (attackflag == false) {
		if (fabsf(angle) < CMath::DegToRad(horiAngle) && toPlayerLen < horilong)
		{
			//�߂��I�I�I�I�I
			m_state = EnState_attack;

		}

	}

}
void EnemyMan::ManIdle()
{
	//�ҋ@���
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	stoptimer++;
	moveVec = moveVec * 0.0f;	//�����܂��[�[��
	if (stoptimer >= stopendtimer) {
		m_state = EnState_walk;
	}
}
void EnemyMan::ManWalk()
{
	//�������
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;
	if (count > randomCount) {
		count = 0;
	}
	count++;

	if (count == randomCount ) {
		//�����_���ŕ��������肵�ē����܂�
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
	//�U�����
	GameData* gamedata = GameData::GetInstance();
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;
	move = diff;
	if (diff.Length() < 600.0f && diff.Length() > 50.0f) {
		//�߂Â��܂�
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
		//���ꂽ�̂ł��̏�ňړ�����
		m_state = EnState_walk;
	}

	//��]�̏���
	if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		//�킩���
		return;
	}


	CVector3 enemyForward = { 0.0f, 0.0f, -1.0f };

	//�@���������������̃x�N�g�����v�Z����B
	CVector3 targetVector = P_Position - m_position;
	//�@Y�����͏������Đ��K������BY����������Ƌ���������肷���B
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
	//�����Q�[�W�𓮂���
	//�����̂��v�Z
	LifeY = (float)HP / (float)MAX_HP;
	//???
	LifeScale = { LifeY,1.0f,1.0f };
	m_skin2->SetScale(LifeScale);
}
void EnemyMan::Update()
{
	//������ŕύX����
	//�X�N���[��Pos����

	//�q���ƃJ�����Ƌ������v�Z����B
	CVector3 cameraPos = MainCamera().GetPosition();
	CVector3 Pos = cameraPos - m_position;
	float len = Pos.Length();
	if (len < 300.0f) {
		m_skin->SetActiveFlag(true);
		m_skin2->SetActiveFlag(true);
		//2D���\���ɂ���ɂ́Am_skin->SetActiveFlag(false);
		//2D��\���ɂ���ɂ́Am_skin->SetActiveFlag(true);
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
	//�y���Ƃ̏Փ˔���
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		//�����ꂽ....
		if (diff.Length() < DeadLength) {
			//�y��������]			
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
				m_state = EnState_death;//���ɂ܂��B
			}
		}
		return true;
		});

	//�ړ��Ɖ�]
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
