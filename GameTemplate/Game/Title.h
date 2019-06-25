#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();

	enum Estate{
		Estate_New,	//���߂���
		Estate_Load,	//��������
		Estate_Exit,		//�I��
	};

	bool Start();
	void Update();
private:
	void New();
	void Load();
	void Exit();
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

	Estate m_state = Estate_New; //���
	CVector3 m_position; //���W
};

