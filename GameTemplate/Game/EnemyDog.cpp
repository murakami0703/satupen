#include "stdafx.h"
#include "EnemyDog.h"
#include "Player.h"
#include "Pen.h"
#include "GameData.h"


EnemyDog::EnemyDog()
{

}
EnemyDog::~EnemyDog()
{
	DeleteGO(m_skinModelRender);
}

bool EnemyDog::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/inu/inuu.cmo");
	m_skinModelRender->SetPosition(m_position);

	//�L�����R��
	m_charaCon.Init(
		15.0f,  //���a�B
		25.0f,  //�����B
		m_position //�������W�B
	);
	return true;
}
void EnemyDog::DogIdle()
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
	if (diff.Length() < attackRange) {
		//�������߂��̂œ����܂��I
		m_state = EnState_attack;
	}
}
void EnemyDog::DogWalk()
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
		walkmove = { 0.0f, 0.0f,-1.0f };
		m_rotation.Multiply(walkmove);
		count = 0;
	}
	else if (diff.Length() < attackRange) {
		//�������߂��̂ōU�����܁I
		m_state = EnState_attack;
	}
	moveVec = walkmove * randomSpeed;
	m_position = m_charaCon.Execute(moveVec);
}
void EnemyDog::DogAttack()
{
	//�U�����
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	if (diff.Length() < 600.0f) {
		//�߂Â��܂�
		diff.y = 0.0f;
		diff.Normalize();
		moveVec = diff * attackSpeed;
	}
	else if (diff.Length() < 20.0f) {
		//�A�j���[�V���������čU������
	}
	else {
		//���ꂽ�̂ł��̏�ňړ�����
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
	m_position = m_charaCon.Execute(moveVec);


}
void EnemyDog::DogDeath()
{
	//��
	DeleteGO(this);
}

void EnemyDog::Update()
{
	switch (m_state)
	{
	case EnemyDog::EnState_idle:
		DogIdle();
		break;
	case EnemyDog::EnState_walk:
		DogWalk();
		break;
	case EnemyDog::EnState_attack:
		DogAttack();
		break;
	case EnemyDog::EnState_death:
		DogDeath();
		break;

	}

	//�y���Ƃ̏Փ˔���
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		if (diff.Length() < 30.0f) {
			//�����ꂽ....
			GameData* gamedata = GameData::GetInstance();
			gamedata->DeadHkasan(1);
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