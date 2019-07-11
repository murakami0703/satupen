#pragma once
class Window : public IGameObject
{
public:
	Window();
	~Window();

	bool Start();
	void Update();

	//���W��ݒ�B
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}
	void SetScale(CVector3 sca)
	{
		m_scale = sca;
	}

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSoundSource* m_sound = nullptr; //�����ꂽ�Ƃ��̉�
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::One; // �X�P�[��

	CPhysicsStaticObject m_physicsStaticObject; //�ÓI�����I�u�W�F�N�g

};

