#include "stdafx.h"
#include "Player.h"

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
	m_animClips[enAnimationClip_idle].Load(L"animData/playeridel.tka"); //�ҋ@
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].Load(L"animData/playerwalk.tka"); //����
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);
	m_animClips[enAnimationClip_jump].Load(L"animData/playerjump.tka"); //����
	m_animClips[enAnimationClip_pre].Load(L"animData/Kamae.tka"); //�\��

	m_animClips[enAnimationClip_attack].Load(L"animData/Nageru.tka"); //�U��
	//�X�L�����f��
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Children/kodomo.cmo", m_animClips, enAnimationClip_Num);
	m_skinModelRender->PlayAnimation(1);
	m_scale = { 1.0f,1.0f,1.0f };
	m_position = { 0.0f,0.0f,0.0f };
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetPosition(m_position);

	//�L�����R��
	m_charaCon.Init(
		10.0f,  //���a�B
		15.0f,  //�����B
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
	moveVec += cameraForward * stick.x * 100.0f;	//�������ւ̈ړ����x�����Z�B

	//�n�ʏォ�\�����삵�Ă��Ȃ��Ƃ�
	if (m_charaCon.IsOnGround() == true && m_isSet == false) {
			if (fabsf(stick.x) < 0.001f && fabsf(stick.z) < 0.001f) {
				//�p�b�h���͂��Ȃ��̂őҋ@�A�j���V��
				m_state = Estate_idle;
				return;
			}
			else {
				m_state = Estate_move;
		}
	}
	//�d��
	moveVec.y -= 2.0f;
	m_position = m_charaCon.Execute(moveVec);
	
}

void Player::Animation()
{
	if (m_state == Estate_idle) {
		m_skinModelRender->PlayAnimation(0);
	}
	else if (m_state == Estate_move) {
		m_skinModelRender->PlayAnimation(1);
	}
	else if (m_state == Estate_jump) {
		m_skinModelRender->PlayAnimation(2, 0.3f);
	}
	else if (m_state == Estate_pre) {
		m_skinModelRender->PlayAnimation(3, 0.3f);

	}
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
	if (Pad(0).IsPress(enButtonA)) {
		m_isDash = true;
		moveVec *= 2.0f;
		CVector3 old = m_position - m_oldpos;
		old.Normalize();
		if (old.x>0.03f||old.z>0.03f) {
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/Mwalk.wav");
			m_sound->Play(false);
			m_sound->SetVolume(0.5f);
		}
	}
	else {
		m_isDash = false;

	}
	m_position = m_charaCon.Execute(moveVec);
}
void Player::Turn() {
	//180����]
	if (Turnflag == false) {	
		//�^�[��������Ȃ��Ƃ��ɉ�]��
		if (Pad(0).IsTrigger(enButtonLB3)) {
			TurnTimer = 0;
			Turnflag = true;
		}
	}
	else {
		TurnTimer++;
		if (TurnTimer < TurnEnd) {
			//�O���O�����܂��B�B
			CQuaternion Rot;
			Rot.SetRotation(CVector3::AxisY, 0.055f);
			m_rotation.Multiply(Rot);
		}
		else {
			Turnflag = false;
		}
	}
}
void Player::Jump()
{
	//�W�����v���܂��B
	if (m_charaCon.IsOnGround() == true) {
		if (Pad(0).IsTrigger(enButtonB) ) {
			m_state = Estate_jump;
			moveVec.y = 50.0f;
		}
	}
	m_position = m_charaCon.Execute(moveVec);
}
void Player::yobi() {
	if (Pad(0).IsPress(enButtonLB1)) {
		//�U�����悤�Ƃ��Ă��那�A�j����
		//�\����
		m_state = Estate_pre;
		m_isSet = true;
	}
	else {
		m_isSet = false;
	}

}
void Player::Update()
{
	Movestick();	//�p�b�h�ړ�
	Animation();	//�A�j���[�V����
	Rotation();		//��]
	Dash();			//����悧����
	Turn();			//180����]
	Jump();			//�W�����v���܂��B
	yobi();			//�\���܂�

	//�ړ��Ɖ�]
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
