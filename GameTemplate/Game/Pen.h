#pragma once

#include "tkEngine/physics/tkPhysicsGhostObject.h"

class Pen : public IGameObject
{
public:
	Pen();
	~Pen();
	bool Start();
	void Update();

	//�|�W�V������Ԃ��֐�
	CVector3 Pen::Getm_Position() {
		return m_position;
	}
	//������������֐�
	int Pen::SetDeath() {
		dathflag = true;
		return 0;
	}
private:

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSoundSource* m_sound = nullptr;//�y���𓊂��鉹��炷
	CVector3 m_position = CVector3::Zero;					// ���W�B
	CQuaternion m_rotation = CQuaternion::Identity;			//��]�B
	CPhysicsGhostObject m_ghost;							//�S�[�X�g
	CVector3 m_scale = CVector3::Zero;						// �X�P�[��


	const float moveSpeed = 600.0f;		//�ړ����x
	CVector3 P_target = CVector3::Zero;	//worldPos�����܂�
	CVector3 diff = CVector3::Zero;		//�x�N�g���v�Z�p
	bool dathflag = false;				//���������������t���O
	bool keisannflag = false;			//��x����̕����v�Z�t���O
	int m_timer = 0;					//�e�����p�^�C�}�[
	const float pendelete = 150.0f;		//�e�������܂ł̎���
	CCharacterController m_charaCon;	 //�L�����R��

	int Timer = 0;
	const int characontime = 30;
};

