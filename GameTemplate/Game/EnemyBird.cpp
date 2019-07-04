#include "stdafx.h"
#include "EnemyBird.h"
#include "Player.h"
#include "Pen.h"
#include "GameData.h"

EnemyBird::EnemyBird()
{

}
EnemyBird::~EnemyBird()
{
	DeleteGO(m_skinModelRender);

}

bool EnemyBird::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/karasu/karasuu.cmo");
	m_skinModelRender->SetPosition(m_position);

	//�L�����R��
	m_charaCon.Init(
		15.0f,  //���a�B
		25.0f,  //�����B
		m_position //�������W�B
	);
	return true;
}
void EnemyBird::BirdIdle()
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
	if (diff.Length() < flyRange) {
		//�������߂��̂Ŕ�т܂�
		m_state = EnState_fly;
	}

}
void EnemyBird::BirdWalk()
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
	else if (diff.Length() < flyRange) {
		//�������߂��̂Ŕ�т܂��I
		m_state = EnState_fly;
	}
	moveVec = walkmove * randomSpeed;
	m_position = m_charaCon.Execute(moveVec);
}
void EnemyBird::BirdFly()
{
	//���
}
void EnemyBird::BirdDeath()
{
	//��
	DeleteGO(this);
}

void EnemyBird::Update()
{
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

