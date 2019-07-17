#include "stdafx.h"
#include "Background.h"


Background::Background()
{
}


Background::~Background()
{
	TK_LOG("~Background()");
	DeleteGO(skinModelRender);

	DeleteGO(m_sound);
}

bool Background::Start()
{
	//�}�b�v�̃��[�h
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/ste/sute.cmo");
	skinModelRender->SetScale(m_scale);
	skinModelRender->SetPosition(m_position);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	//�S�[�X�g�̏�����
	//�S�[�X�g�̃��C���[�t���[���\����L���ɂ���B
	//PhysicsWorld().SetDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);
	//�{�b�N�X�`��̃S�[�X�g���쐬����B
	m_ghost.CreateBox(
		{ 0.0f, 0.0f, 0.0f },	//�������͍��W�B
		CQuaternion::Identity,		//�������͉�]�N�H�[�^�j�I���B
		{ 600.0f, 200.0f, 300.0f }	//��O�����̓{�b�N�X�̃T�C�Y�B
	);
	// CPhysicsStaticObject�̏�����
	m_physicsStaticObject.CreateMesh(m_position, CQuaternion::Identity, m_scale, skinModelRender);

	//���y�h�b�g��
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/tw088.wav");
	m_sound->Play(true);
	m_sound->SetVolume(0.5f);

	return true;
}
void Background::Update()
{
	skinModelRender->SetPosition(m_position);

}


