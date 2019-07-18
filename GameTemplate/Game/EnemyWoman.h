#pragma once
class EnemyWoman : public IGameObject
{
public:
	EnemyWoman();
	~EnemyWoman();
	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_runaway,//������
		EnState_death,	//�E���ꂽ
	};

	//�A�j���[�V����
	enum EnAnimationClip {
		enAnimationClip_idle, //�ҋ@
		enAnimationClip_walk,  //����
		enAnimationClip_Num,  //�A�j���[�V�����N���b�v
	};

	bool Start();
	void Update();

	//Hp��Ԃ��֐�
	int EnemyWoman::GetHp() {
		return HP;
	}
	//MAX_Hp��Ԃ��֐�
	int EnemyWoman::GetMAX_Hp() {
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

	void WomanIdle();
	void WomanWalk();
	void WomanRunaway();
	void WomanDeath();
	void WomanHorizon();
	void Animation();	//�A�j���[�V����
	void WomanHP();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::Zero; // �X�P�[��
	EnState m_state = EnState_walk;//���
	CVector3 moveVec = CVector3::Zero; // ���W�B
	CVector3 LifeScale = CVector3::Zero;

	CCharacterController m_charaCon; //�L�����R��
	CAnimationClip  m_animClips[enAnimationClip_Num];		//�A�j���[�V����

	//�X�L��
	prefab::CSpriteRender* m_skin = nullptr;//�g
	prefab::CSpriteRender* m_skin2 = nullptr;//���F
	prefab::CSpriteRender* m_skin3 = nullptr;//bar�̌��̐F

	const CVector2 LifePivot = { 0.0f,0.1f };//HP�̊�{

	//KOTO��3D�J�����̂��߂ɍ�������
	CVector3 m_position2;//����g
	//CVector3 m_position2;//���ꔒ�����

	prefab::CSoundSource* m_sound = nullptr; //���G�ɓ����������ɂȂ鉹
	prefab::CSoundSource* m_sound2 = nullptr; //���G�ɓ����������ɂȂ鉹


	//��~��Ԋ֘A
	int stoptimer = 0;//��~�p�^�C�}�[
	const float stopendtimer = 60.0f; //��~�����߂܂���
	//�����֘A
	CVector3 walkmove = CVector3::Zero; // ���W�B
	int count = 0; //�ړ��p�J�E���g
	int wrandom = 0; //�ړ��̕�������
	const int randomCount = 300; //�����_���ňړ������؂�ւ��^�C�}�[
	const float randomSpeed = 20.0f; //�ړ����x
	//�����֘A
	const float followRange = 300.0f; //�����鋗���i�v���C���[���痣��鋗���j
	const float runaway = 1000.0f; //������̂���߂鋗��
	const float followSpeed = 50.0f; //�����鑬�x

	//����p
	const float horilong = 350.0f;	//����p����̋���
	const float horiAngle = 45.0f;	//����p����̊p�x

	//�G�t�F�N�g�֘A
	const CVector3 EfeSize = { 5.0f,5.0f,5.0f };	//�G�t�F�N�g�̑傫��

	const float DeadLength = 30.0f;	//�y���Ƃ̓����蔻�苗��

	//�̗͂�����
	int HP = 100;				//���݂̗̑�
	const int MAX_HP = 100;		//�ő�̗�};
	float LifeY = 0.0f;

};