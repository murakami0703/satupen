#pragma once
class GameOver:public IGameObject
{
public:
	GameOver();
	~GameOver();

	enum EnStar {
		en_Start,
	};

	bool Start();
	void Update();

private:
	//ゲームオーバー
	prefab::CSpriteRender* m_sprite;//黒のバック
	prefab::CSpriteRender* m_sprite2;//ゲームオーバー

	CVector3 m_position;//座標

	EnStar m_Sart = en_Start;

	float GO = 0.0f;

};

