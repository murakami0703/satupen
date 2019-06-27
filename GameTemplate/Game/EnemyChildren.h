#pragma once
class EnemyChildren : public IGameObject
{
public:
	EnemyChildren();
	~EnemyChildren();

	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_runaway,	//������
		EnState_death,	//�E���ꂽ
	};
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

private:
	void ChildrenIdle();
	void ChildrenWalk();
	void ChildrenRunaway();
	void ChildrenDeath();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::Zero; // �X�P�[��
	EnState m_state = EnState_walk;//���
	CVector3 moveVec = CVector3::Zero; // ���W�B

	CCharacterController m_charaCon; //�L�����R��

	//��~��Ԋ֘A
	int stoptimer = 0;//��~�p�^�C�}�[
	const float stopendtimer = 60.0f; //��~�����߂܂���
	//�����֘A
	CVector3 walkmove = CVector3::Zero; // ���W�B
	int count = 0; //�ړ��p�J�E���g
	int wrandom = 0; //�ړ��̕�������
	const int randomCount = 300; //�����_���ňړ������؂�ւ��^�C�}�[
	const float randomSpeed = 1.0f; //�ړ����x
	//�����֘A
	const float followRange = 300.0f; //�����鋗���i�v���C���[���痣��鋗���j
	const float runaway = 1000.0f; //������̂���߂鋗��
	const float followSpeed = 50.0f; //�����鑬�x
	
};

