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

	std::vector<prefab::CSpriteRender*> m_spriteRender;
	prefab::CSpriteRender* sp;

	Estate m_state = Estate_New; //���

};

