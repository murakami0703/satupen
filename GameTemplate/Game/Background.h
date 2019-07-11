#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"

class Background : public IGameObject
{
public:
	Background();
	~Background();
	bool Start();
	void Update();

	//���W��ݒ�B
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	void SetScale(CVector3 sca)
	{
		m_scale = sca;
	}
	void Background::GetGhost() {
		
	}
private:
	prefab::CSkinModelRender* skinModelRender = nullptr; //�X�L�����f�������_�[
	prefab::CSoundSource* m_sound = nullptr;//�h�b�g�̉��y
	CVector3 m_position = CVector3::Zero; // ���W�B
	CVector3 m_scale = CVector3::One; // �X�P�[��
	CPhysicsGhostObject m_ghost;							//�S�[�X�g


	CPhysicsStaticObject m_physicsStaticObject; //�ÓI�����I�u�W�F�N�g
};

