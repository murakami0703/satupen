#include "stdafx.h"
#include "Pen.h"
#include "Player.h"

Pen::Pen()
{
}


Pen::~Pen()
{
	DeleteGO(m_skinModelRender);
}

bool Pen::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/ya.cmo");
	m_skinModelRender->SetPosition(m_position);

	return true;
}
void Pen::Follow()
{
	//�v���C���[�ɕt���Ă����y��
	Player* player = FindGO<Player>("player");
	CVector3 pos = player->Getm_Position();

	if (Pad(0).IsTrigger(enButtonB)) {
		//A�{�^���������ꂽ���Ԃ�
		m_state = Estate_Attack;
	}
}
void Pen::Attack()
{
	//�U�����
	/*if (keisannflag == false) {

		Player* player = FindGO<Player>("player");
		CVector3 pos = player->Getm_Position();
		buvec = diff;
		buvec.Normalize();

		//�@��������������
		CVector3 enemyForward = { 1.0f, 0.0f, 0.0f };
		CVector3 targetVector = tes_Position - pos;
		//�@Y�����͏������Đ��K������BY����������Ƌ���������肷���B
		targetVector.y = 0.0f;
		targetVector.Normalize();
		CQuaternion qRot;
		qRot.SetRotation(enemyForward, targetVector);
		m_rotation = qRot;

		keisannflag = true;
	}*/
	m_position += buvec * moveSpeed;

	//���W��`����B
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

	m_timer++;
	if (m_timer == pendelete) {
		//���Ԃ���������C���X�^���X���폜����B
		DeleteGO(this);
	}

}

void Pen::Update()
{
	switch (m_state)
	{
	case Pen::Estate_Follow:
		Follow();
		break;
	case Pen::Estate_Attack:
		Attack();
		break;
	}
}

