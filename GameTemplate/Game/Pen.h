#pragma once
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
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::Zero; // �X�P�[��


	const float moveSpeed = 200.0f; //���x
	CVector3 P_target = CVector3::Zero;
	CVector3 diff = CVector3::Zero;
	bool dathflag = false;		//���������������t���O
	int m_timer = 0;
	bool keisannflag = false;
	const float pendelete = 150.0f; //�ʂ������܂ł̃^�C�}�[
	CCharacterController m_charaCon; //�L�����R��


};

