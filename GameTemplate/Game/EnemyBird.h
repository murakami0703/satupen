#pragma once
class EnemyBird : public IGameObject
{
public:
	EnemyBird();
	~EnemyBird();

	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_fly,	//���
		EnState_death,	//�E���ꂽ
	};

	bool Start();
	void Update();

	//Hp��Ԃ��֐�
	int EnemyBird::GetHp() {
		return HP;
	}
	//MAX_Hp��Ԃ��֐�
	int EnemyBird::GetMAX_Hp() {
		return MAX_HP;
	}

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

	void BirdIdle();
	void BirdWalk();
	void BirdFly();
	void BirdDeath();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::Zero; // �X�P�[��
	EnState m_state = EnState_walk;//���
	CVector3 moveVec = CVector3::Zero; // ���W�B

	CCharacterController m_charaCon; //�L�����R��

	//�ҋ@�֘A
	int stoptimer = 0;					//��~�p�^�C�}�[
	const float stopendtimer = 60.0f;	//��~�����߂܂���
	//�����֘A
	CVector3 walkmove = CVector3::Zero;		// ���W�B
	int count = 0;							//�ړ��p�J�E���g
	int wrandom = 0;						//�ړ��̕�������
	const int randomCount = 300;			//�����_���ňړ������؂�ւ��^�C�}�[
	const float randomSpeed = 1.0f;			//�ړ����x
	//��ъ֘A
	const float flyRange = 300.0f;		//�����鋗���i�v���C���[���痣��鋗���j

	int HP = 100;
	const int MAX_HP = 100;

};
