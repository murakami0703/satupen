#include "stdafx.h"
#include "Player.h"
#include "GameData.h"

Player* Player::m_instance = nullptr;

Player::Player()
{
	if (m_instance != nullptr) {
		std::abort(); //���łɏo�Ă��邽�߃N���b�V��
	}

	//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
	m_instance = this;

}


Player::~Player()
{
	//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
	m_instance = nullptr;


	DeleteGO(m_skinModelRender);
}


bool Player::Start()
{
	//�A�j���[�V����
	/*m_animClips[enAnimationClip_idle].Load(L"animData/pltaiki.tka");
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_run].Load(L"animData/plrun.tka");
	m_animClips[enAnimationClip_run].SetLoopFlag(true);
	m_animClips[enAnimationClip_attack].Load(L"animData/plkougeki.tka");
	m_animClips[enAnimationClip_attack].SetLoopFlag(true);*/
	//�X�L�����f��
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Children/kodomo.cmo");
	//m_skinModelRender->PlayAnimation(0);
	m_scale = { 1.0f,1.0f,1.0f };
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetPosition(m_position);

	//�Q�[���f�[�^�[����̗͂����������Ă���
	GameData* gamedata = GameData::GetInstance();
	m_Life = gamedata->Get_Life();
	//�L�����R��
	m_charaCon.Init(
		20.0f,  //���a�B
		68.0f,  //�����B
		m_position //�������W�B
	);
	return true;
}

void Player::Movestick()
{
	//�ړ�
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
	moveVec += cameraForward * stick.x * 100.0f;	//�������ւ̈ړ����x�����Z�B
	


	m_position = m_charaCon.Execute(moveVec);
}

void Player::Animation()
{
		
}

void Player::Rotation()
{


	//��]
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
void Player::Turn() {
	if (Turnflag == false) {
		if (Pad(0).IsTrigger(enButtonLB3)) {
			TurnTimer = 0;
			Turnflag = true;
		}
	}
	else {
		TurnTimer++;
		if (TurnTimer < TurnEnd) {
			CQuaternion Rot;
			Rot.SetRotation(CVector3::AxisY, 0.055f);
			m_rotation.Multiply(Rot);
		}
		else {
			Turnflag = false;
		}
	}
}
void Player::Update()
{
	Movestick();	//�p�b�h�ړ�
	Animation();	//�A�j���[�V����
	Rotation();		//��]
	Dash();		//����悧����
	Turn();
	//�ړ��Ɖ�]
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
