#pragma once
class EnemyMan : public IGameObject
{
public:
	EnemyMan();
	~EnemyMan();
	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_yobi,	//�\������
		EnState_attack,	//�U��
		EnState_death,	//�E���ꂽ
	};
	//�A�j���[�V����
	enum  EnAnimationClip {
		enAnimationClip_idle, //�ҋ@
		enAnimationClip_walk,  //����
		enAnimationClip_yobi,  //�\��
		enAnimationClip_attack, //�U��
		enAnimationClip_prostrate, //�y����
		enAnimationClip_Num,  //�A�j���[�V�����N���b�v
	};
	bool Start();
	void Update();

	//Hp��Ԃ��֐�
	int EnemyMan::GetHp() {
		return HP;
	}
	//MAX_Hp��Ԃ��֐�
	int EnemyMan::GetMAX_Hp() {
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
	void ManIdle();
	void ManWalk();
	void ManAttack();
	void ManDeath();
	void ManHorizon();
	void Animation();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::One; // �X�P�[��
	CVector3 moveVec = CVector3::Zero; // ���W�B
	EnState m_state = EnState_walk;//���
	CAnimationClip  m_animClips[enAnimationClip_Num];		//�A�j���[�V����
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
	const float attackSpeed = 40.0f; //�����鑬�x

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

