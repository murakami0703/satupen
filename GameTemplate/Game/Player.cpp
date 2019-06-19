#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
}


bool Player::Start()
{
	//�A�j���[�V����
	m_animClips[enAnimationClip_idle].Load(L"animData/unityChan/idle.tka");
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_run].Load(L"animData/unityChan/run.tka");
	m_animClips[enAnimationClip_run].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].Load(L"animData/unityChan/walk.tka");
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);

	//�X�L�����f��
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo", m_animClips, enAnimationClip_Num, enFbxUpAxisY);
	m_skinModelRender->PlayAnimation(0);
	m_scale = { 0.3f,0.3f,0.3f };
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetPosition(m_position);
	//�L�����R��
	m_charaCon.Init(
		20.0f,  //���a�B
		68.0f,  //�����B
		m_position //�������W�B
	);
	return true;
}

void Player::Move()
{
	moveVec.x = 0.0f;
	moveVec.z = 0.0f;
	//�\���{�^���ړ�
	if (Pad(0).IsPress(enButtonUp)) {
		moveVec.z -= movespeed;
	}
	if (Pad(0).IsPress(enButtonDown)) {
		moveVec.z += movespeed;

	}
	if (Pad(0).IsPress(enButtonLeft)) {
		moveVec.x += movespeed;

	}
	if (Pad(0).IsPress(enButtonRight)) {
		moveVec.x -= movespeed;

	}
	m_position = m_charaCon.Execute(moveVec);

}

void Player::Movestick()
{
	//�X�e�B�b�N�ړ���������
	stick.x = Pad(0).GetLStickYF();
	stick.y = 0.0f;
	stick.z = Pad(0).GetLStickXF();

	//�J�����̑O�������ƉE�������擾�B
	CVector3 cameraForward = MainCamera().GetForward();
	//CVector3 cameraRight = MainCamera().GetRight();
	//XZ���ʂł̑O�������A�E�����ɕϊ�����B
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	
	//XZ�����̈ړ����x���N���A�B
	moveVec.x = 0.0f;
	moveVec.z = 0.0f;
	//moveVec.y -= 980.0f * GameTime().GetFrameDeltaTime();
	moveVec += cameraForward * stick.x * 15.0f;	//�������ւ̈ړ����x�����Z�B
	


	m_position = m_charaCon.Execute(moveVec);
}

void Player::Animation()
{
	//�A�j���[�V����
		if (Pad(0).IsPress(enButtonRight)||Pad(0).IsPress(enButtonLeft)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else if (Pad(0).IsPress(enButtonLeft)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else if (Pad(0).IsPress(enButtonUp)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else if (Pad(0).IsPress(enButtonDown)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else {
			m_skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
		
}

void Player::Rotation()
{
	CQuaternion qAddRot;
	qAddRot.SetRotation(CVector3::AxisY, Pad(0).GetLStickXF() * 0.05f);
	m_rotation.Multiply(qAddRot);

}
void Player::Dash() {
	//����悧����
	if (Pad(0).IsTrigger(enButtonA)) {
		moveVec *= 2.0f;
	}
	m_position = m_charaCon.Execute(moveVec);
}

void Player::Update()
{
	//Move();			//�\���L�[�ړ�
	Movestick();	//�p�b�h�ړ�
	Animation();	//�A�j���[�V����
	Rotation();		//��]
	Dash();		//����悧����

	//�ړ��Ɖ�]
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
