#include "stdafx.h"
#include "Pen.h"
#include "Scope.h"
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
	//�v���C���[�̏ꏊ�ɔ���
	Player* player = FindGO<Player>("player");
	CVector3 pos = player->Getm_Position();
	CQuaternion qRot = player->Getm_Rotation();
	m_position = pos;
	m_position.y = pos.y + 30.0f;
	m_rotation = qRot;
	m_scale = { 1.0f,1.0f,1.0f };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);

	m_charaCon.Init(
		0.0f,  //���a�B
		0.0f,  //�����B
		m_position //�������W�B
	);

	return true;
}

void Pen::Update()
{
	Timer++;
	Player* pl = FindGO<Player>("player");
	//��΂��您
	if (keisannflag == false) {
		//��񂾂��v�Z���܂��B
		Scope* scope = FindGO<Scope>("scope");
		CVector3 s_pos = scope->Getm_Position();
		//�J�[�\���̍��W���X�N���[�����W�n���琳�K�����W�n�ɕϊ�����B
		CVector3 worldPos;
		MainCamera().CalcWorldPositionFromScrenPosition(worldPos, { s_pos.x, s_pos.y }, 0.95f);
		CVector3 vBase = { 0.0f,0.0f,1.0f };
		m_rotation.Apply(vBase);
		P_target = worldPos;
		
		diff = P_target - m_position;
		diff.Normalize();
		keisannflag = true;
	}
	//�i�s�����ɉ�]���Ă܂����B
	CQuaternion qRot;
	qRot.SetRotation({ 0.0, 0.0f, 1.0f }, diff);

	if (Timer == characontime) {
		m_charaCon.SetRadius(3.0f);
		m_charaCon.SetRadius(0.5f);
	}
	//�ړ����Ă��
	if (pl->IsDash() == true) {
		//�v���C���[�������Ă���Ƃ��͒e������
		m_position = m_charaCon.Execute(diff * (moveSpeed * 3), (1.0 / 60.0f));
	}
	else {
		m_position = m_charaCon.Execute(diff * moveSpeed, (1.0 / 60.0f));
	}
	//���W�Ɖ�]��`����B
	m_skinModelRender->SetRotation(qRot);
	m_skinModelRender->SetPosition(m_position);
	m_timer++;
	


	//�����֘A

	//�����ǂɓ������Ă��������
	if (m_charaCon.IsOnWall() == true) {
		DeleteGO(this);

	}
	//���Ԃ����Ə������
	if (m_timer == pendelete) {
		DeleteGO(this);
	}
	//�G�ɓ�����Ǝ������������
	if (dathflag == true) {	
		DeleteGO(this);
	}
}

