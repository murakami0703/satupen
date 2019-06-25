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
	//スプライトタイトル殺戮の剣
	prefab::CSpriteRender* m_sprite;  //赤いBK
	prefab::CSpriteRender* m_sprite1; //さつりくのペン
	prefab::CSpriteRender* m_sprite2; //殺戮の剣
	prefab::CSpriteRender* m_sprite3; //しろのペン
	prefab::CSpriteRender* m_sprite4; //選択
	prefab::CSpriteRender* m_sprite5; //はじめる。
	prefab::CSpriteRender* m_sprite6; //おわる。
	std::vector<prefab::CSpriteRender*> m_spriteRender;
	prefab::CSpriteRender* sp;

	Estate m_state = Estate_New; //状態
	CVector3 m_position; //座標
};

