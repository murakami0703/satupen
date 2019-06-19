#pragma once
class Pen : public IGameObject
{
public:
	Pen();
	~Pen();
	bool Start();
	void Update();
private:

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::Zero; // �X�P�[��



	const float moveSpeed = 60.0f; //���x
	CVector3 buvec = CVector3::Zero;

	int m_timer = 0;
	bool keisannflag = false;
	const float pendelete = 150.0f; //�ʂ������܂ł̃^�C�}�[
};

