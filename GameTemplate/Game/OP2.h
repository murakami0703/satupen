#pragma once
class OP2:public IGameObject
{
public:
	OP2();
	~OP2();
	enum En_Start {
		en_Start,
		en_Start2,
		en_Start3,
		en_Start4,

	};

	bool Start();
	void Update();


private:
	prefab::CSpriteRender* m_sprite;//はじめ
	prefab::CSpriteRender* m_sprite1;//言葉
	prefab::CSpriteRender* m_sprite2;//ペン
	prefab::CSpriteRender* m_sprite3;//言葉２
	prefab::CSpriteRender* m_sprite4;//びっくり

	CVector3 m_position;//座標
	En_Start m_Star = en_Start;

	float OP2mozi = 0.0f;
	float OP2mozi2 = 0.0f;
};

