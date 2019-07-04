#pragma once
class EnemyMan : public IGameObject
{
public:
	EnemyMan();
	~EnemyMan();
	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_attack,	//�U��
		EnState_death,	//�E���ꂽ
	};
	bool Start();
	void Update();

	//���W��ݒ�B
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	//��]��ݒ�B
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}

	
private:
	void ManIdle();
	void ManWalk();
	void ManAttack();
	void ManDeath();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::One; // �X�P�[��
	EnState m_state = EnState_walk;//���
	CVector3 moveVec = CVector3::Zero; // ���W�B

	CCharacterController m_charaCon; //�L�����R��

	//�ҋ@�֘A
	int stoptimer = 0;//��~�p�^�C�}�[
	const float stopendtimer = 60.0f; //��~�����߂܂���
	//�����֘A
	CVector3 walkmove = CVector3::Zero; // ���W�B
	int count = 0; //�ړ��p�J�E���g
	int wrandom = 0; //�ړ��̕�������
	const int randomCount = 300; //�����_���ňړ������؂�ւ��^�C�}�[
	const float randomSpeed = 8.0f; //�ړ����x
	//�U���֘A
	const float attackSpeed = 80.0f; //�����鑬�x

};

