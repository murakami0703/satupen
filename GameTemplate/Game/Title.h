#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();

	enum EnState {
		enState_new,
		enState_2,//�Ȃ���������Ƃ肠�������������
		enState_3,
		enState_4,
	};

	bool Start();
	void Update();

private:
	//�E�C�̌������傫��
	CVector3 movepos = { 0.0f,120.0f,0.0f }; //���W
	//�����y��
	bool sasitaflag = false;

	int Pentimer = 0;
	float SP1 = 0.0f;

	//�X�v���C�g�^�C�g���E�C�̌�
	prefab::CSpriteRender* m_sprite;  //�Ԃ�BK
	prefab::CSpriteRender* m_sprite1; //���肭�̃y��
	prefab::CSpriteRender* m_sprite2; //�E�C�̌�
	prefab::CSpriteRender* m_sprite3; //����̃y��
	prefab::CSpriteRender* m_sprite4; //�I��
	prefab::CSpriteRender* m_sprite5; //�͂��߂�B
	prefab::CSpriteRender* m_sprite6; //�����B
	std::vector<prefab::CSpriteRender*> m_spriteRender;
	prefab::CSpriteRender* sp;

	EnState m_state = enState_new; //���
	CVector3 m_position; //���W

	//�萔
	const CVector3 PenDef = { 900.0f,800.0f,0.0f };
	const CVector3 PenDropPos = { 200.0f,100.0f,0.0f };
	const CVector3 PenRemovePos = { 250.0f,150.0f,0.0f };
	const int DropLimit = 20; //�����鎞�ԁi������������Ɨ����鑬���ς��j
	const int RemoveLimit = 10; //�߂鎞��

};

