#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"
class Player : public IGameObject
{
public:
	Player();
	~Player();
	enum EnState {
		Estate_idle,
		Estate_move,
		Estate_attack,
	};
	//�U��
	enum EnAttackItem {
		Estate_Wait,	//�������Ȃ�
		Estate_Pen,		//�y��

	};
	//�A�j���[�V����
	enum EnAnimationClip {
		enAnimationClip_idle, //�ҋ@
		enAnimationClip_run,  //����
		enAnimationClip_walk, //����
		enAnimationClip_Num,  //�A�j���[�V�����N���b�v
	};

	bool Start();
	void Update();

	//�|�W�V������Ԃ��֐�
	CVector3 Player::Getm_Position() {
		return m_position;
	}
	CVector3 Player::Getm_stick() {
		return stick;
	}
private:
	void Move();	//�\���L�[�ړ�
	void Movestick();	//�p�b�h�ړ�
	void Animation();	//�A�j���[�V����
	void Rotation();	//��]
	void Dash();		//����悧����
	void Attack();		//�U�����

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::Zero; // ���W�B
	CQuaternion qrot = CQuaternion::Identity; //�X�e�B�b�N�p
	CVector3 moveVec = CVector3::Zero; //�ړ����x
	CVector3 stick = CVector3::Zero;//�X�e�B�b�N
	CCharacterController m_charaCon; //�L�����R��

	CAnimationClip  m_animClips[enAnimationClip_Num];//�A�j���[�V����
	//�ړ��֘A
	const float movespeed = 30.0f;
	//�U���֘A
	EnAttackItem m_attackstate = Estate_Wait;	//�U�����
};

