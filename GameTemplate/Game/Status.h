#pragma once
class Status:public IGameObject
{
public:
	Status();
	~Status();

	bool Start()override;
	void Update()override;
	prefab::CSpriteRender* m_sprite;
	prefab::CSpriteRender* m_sprite1;
	prefab::CSpriteRender* m_sprite2;
	prefab::CSpriteRender* m_sprite3;
	prefab::CSpriteRender* m_sprite4;
	prefab::CSpriteRender* m_sprite5;
	CVector3   m_position;  //À•W
	CQuaternion m_rotation; //‰ñ“]
};

