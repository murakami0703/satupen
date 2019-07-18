#pragma once
class GamePad:public IGameObject
{
public:
	GamePad();
	~GamePad();
	bool Start();
	void Update();

private:
	prefab::CSpriteRender* m_sprite;

};

