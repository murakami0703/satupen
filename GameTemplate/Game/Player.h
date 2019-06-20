#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"
class Player : public IGameObject
{
	static Player* m_instance;

public:
	Player();
	~Player();
	enum EnState {
		Estate_idle,
		Estate_move,
		Estate_attack,
	};
	//�A�j���[�V����
	enum EnAnimationClip {
		enAnimationClip_idle, //�ҋ@
		enAnimationClip_walk,  //����
		enAnimationClip_attack, //�U��
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

private:
	void Movestick();	//�p�b�h�ړ�
	void Animation();	//�A�j���[�V����
	void Rotation();	//��]
	void Dash();		//����悧����
	void Turn();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::Zero; // �X�P�[��
	CVector3 moveVec = CVector3::Zero; //�ړ����x
	CVector3 stick = CVector3::Zero;//�X�e�B�b�N
	CCharacterController m_charaCon; //�L�����R��

	CAnimationClip  m_animClips[enAnimationClip_Num];//�A�j���[�V����

	//�ړ��֘A
	const float movespeed = 30.0f;
	//��]
	bool Turnflag = false;
	int TurnTimer = 0;
	const float keisann = 180.0f / TurnEnd;
	const float  TurnEnd = 60.0f;

};

