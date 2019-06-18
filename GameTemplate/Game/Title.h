#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();

	enum Estate{
		Estate_New,	//初めから
		Estate_Load,	//続きから
		Estate_Exit,		//終了
	};

	bool Start();
	void Update();
private:
	void New();
	void Load();
	void Exit();

	std::vector<prefab::CSpriteRender*> m_spriteRender;
	prefab::CSpriteRender* sp;

	Estate m_state = Estate_New; //状態

};

