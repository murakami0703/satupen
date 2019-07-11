#pragma once
class EnemyChildren : public IGameObject
{
public:
	EnemyChildren();
	~EnemyChildren();

	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_runaway,//������
		EnState_death,	//�E���ꂽ
	};
	bool Start();
	void Update();

	//Hp��Ԃ��֐�
	int EnemyChildren::GetHp() {
		return HP;
	}
	//MAX_Hp��Ԃ��֐�
	int EnemyChildren::GetMAX_Hp() {
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
	void ChildrenIdle();
	void ChildrenWalk();
	void ChildrenRunaway();
	void ChildrenDeath();
	void ChildrenHorizon();

	//�X�L��
	prefab::CSpriteRender* m_skin = nullptr;//�g
	prefab::CSpriteRender* m_skin2 = nullptr;//���F
	//KOTO��3D�J�����̂��߂ɍ�������
	CVector3 m_position2;//����g
	//CVector3 m_position2;//���ꔒ�����


	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	//prefab::CSoundSource* m_sound = nullptr; //���G�ɓ����������ɂȂ鉹
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
	const float followSpeed = 5.0f; //�����鑬�x
	
	//����p
	const float horilong = 350.0f;	//����p����̋���
	const float horiAngle = 45.0f;	//����p����̊p�x

	//�G�t�F�N�g�֘A
	const CVector3 EfeSize = { 5.0f,5.0f,5.0f };	//�G�t�F�N�g�̑傫��

	const float DeadLength = 30.0f;	//�y���Ƃ̓����蔻�苗��

	//�̗͂�����
	int HP = 100;				//���݂̗̑�
	const int MAX_HP = 100;		//�ő�̗�

};

