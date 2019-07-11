#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"
class Player : public IGameObject
{
	static Player* m_instance;

public:
	Player();
	~Player();
	//�s�����
	enum EnState {
		Estate_idle,	//�ҋ@
		Estate_move,	//�s����
		Estate_jump,	//�s����
		Estate_pre,		//�\��
		Estate_attack,		//��΂���
	};
	//�A�j���[�V����
	enum EnAnimationClip {
		enAnimationClip_idle, //�ҋ@
		enAnimationClip_walk,  //����
		enAnimationClip_jump,  //�W�����v
		enAnimationClip_pre,  //�\��
		enAnimationClip_attack, //��΂���
		enAnimationClip_Num,  //�A�j���[�V�����N���b�v
	};

	bool Start();
	void Update();

	//�|�W�V������Ԃ��֐�
	CVector3 Player::Getm_Position() {
		return m_position;
	}
	//��]��Ԃ��֐�
	CQuaternion Player::Getm_Rotation() {
		return m_rotation;
	}
	//�C���X�^���X�̎擾
	static Player* Player::GetInstance() {
		return m_instance;
	}

	bool IsDash() const		//	�_�b�V������
	{
		return m_isDash;
	}
	bool IsSetup() const	//	�\������
	{
		return m_isSet;
	}

private:
	void Movestick();	//�p�b�h�ړ�
	void Animation();	//�A�j���[�V����
	void Rotation();	//��]
	void Dash();		//����悧����
	void Turn();		//180����]
	void Jump();		//�W�����v���܂�
	void yobi();		//�\����悧

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSoundSource* m_sound = nullptr;//������

	CVector3 m_oldpos = CVector3::Zero;//�ŏ��ɒǂ����ꏊ�B
	CVector3 m_position = CVector3::Zero;  // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity;  //��]�B
	CVector3 m_scale = CVector3::Zero;  // �X�P�[��
	CVector3 moveVec = CVector3::Zero;  //�ړ����x
	CVector3 stick = CVector3::Zero;    //�X�e�B�b�N
	CCharacterController m_charaCon;    //�L�����R��

	EnState m_state = Estate_idle;							//���
	CAnimationClip  m_animClips[enAnimationClip_Num];		//�A�j���[�V����

	//�ړ��֘A
	const float movespeed = 30.0f;							//�ړ����x
	//��]
	bool Turnflag = false;									//180����]�t���O
	int TurnTimer = 0;										//��]�^�C�}�[
	const float  TurnEnd = 60.0f;							//��]�I���܂ł̎���

	bool m_isDash = false;									//�_�b�V������
	bool m_isSet = false;									//�\������

};

