#include "stdafx.h"
#include "EnemyWoman.h"
#include "Player.h"
#include "Pen.h"
#include "GameData.h"
#include "EffectManager.h"
#include "Background.h"
EnemyWoman::EnemyWoman() 
{

}
EnemyWoman::~EnemyWoman()
{
	DeleteGO(m_skinModelRender);
}

bool EnemyWoman::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Woman/onna.cmo");
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

	//�L�����R��
	m_charaCon.Init(
		15.0f,  //���a�B
		25.0f,  //�����B
		m_position //�������W�B
	);

	return true;
}

void EnemyWoman::WomanHorizon()
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
	if (fabsf(angle) < CMath::DegToRad(horiAngle) && toPlayerLen < horilong)
	{
		//�߂��I�I�I�I�I
		m_state = EnState_runaway;

	}

}

void EnemyWoman::WomanIdle()
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

void EnemyWoman::WomanWalk()
{
	//�������
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	count++;

	if (count == randomCount) {
		//�����_���ŕ��������肵�ē����܂�
		wrandom = rand() % 360;
		m_rotation.SetRotation(CVector3::AxisY, (float)wrandom);
		walkmove = { 0.0f, 0.0f,1.0f };
		m_rotation.Multiply(walkmove);
		count = 0;
	}
	m_position = m_charaCon.Execute(walkmove * randomSpeed, (1.0 / 60.0f));

}
void EnemyWoman::WomanRunaway()
{
	//�����Ă���
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	if (diff.Length() < runaway) {
		//����܁[�[�[�[�[�X
		diff.y = 0.0f;
		diff.Normalize();
		moveVec = diff * followSpeed * -1.0f;
	}
	else {
		//���̏�ňړ�
		m_state = EnState_walk;
	}

	//��]�̏���
	if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		//�킩���
		return;
	}


	CVector3 enemyForward = { 0.0f, 0.0f, 1.0f };

	//�@���������������̃x�N�g�����v�Z����B
	CVector3 targetVector = P_Position - m_position;
	//�@Y�����͏������Đ��K������BY����������Ƌ���������肷���B
	targetVector.y = 0.0f;
	targetVector.Normalize();
	CQuaternion qRot;
	qRot.SetRotation(enemyForward, targetVector);
	m_rotation = qRot;
	m_position += moveVec;

	m_position = m_charaCon.Execute(moveVec);

}
void EnemyWoman::WomanDeath()
{
	EffectManager* effect = EffectManager::GetInstance();
	effect->EffectPlayer(EffectManager::Bakuhatu, m_position, { 5.0f,5.0f,5.0f });
	DeleteGO(this);
}


void EnemyWoman::Update()
{
	WomanHorizon();	//����p
	switch (m_state)
	{
	case EnState_idle:	//�ҋ@���
		WomanIdle();
		break;
	case EnState_walk:	//�������
		WomanWalk();
		break;
	case EnState_runaway:	//�����Ă���
		WomanRunaway();
		break;
	case EnState_death:		//�E����܂����B
		WomanDeath();
		break;

	}
	//�y���Ƃ̏Փ˔���
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		if (diff.Length() < DeadLength) {
			//�����ꂽ....
			GameData* gamedata = GameData::GetInstance();
			gamedata->DeadHkasan(1);
			gamedata->ResultDeadkasan(GameData::DeadWoman);
			//�y��������
			pen->SetDeath();
			m_state = EnState_death;//���ɂ܂��B
		}
		return true;
		});

	//�ړ��Ɖ�]
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}

