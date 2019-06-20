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
	m_position.y = pos.y + 20.0f;
	m_rotation = qRot;
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_scale = { 1.0f,1.0f,1.0f };
	m_skinModelRender->SetScale(m_scale);

	return true;
}

void Pen::Update()
{
	//��΂��您
	if (keisannflag == false) {

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
	CQuaternion qRot;
	qRot.SetRotation({ 0.0, 0.0f, 1.0f }, diff);
	//CVector3 vBase = { 0.0f,0.0f,1.0f };
	//m_rotation.Apply(vBase);
	m_position += diff * moveSpeed ;
	m_skinModelRender->SetRotation(qRot);
	//���W��`����B
	m_skinModelRender->SetPosition(m_position);
	m_timer++;
	if (m_timer == pendelete) {
		//���Ԃ���������C���X�^���X���폜����B
		DeleteGO(this);
	}
}

