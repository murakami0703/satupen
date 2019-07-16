#pragma once
class OP3:public IGameObject
{
public:
	OP3();
	~OP3();

	enum EnSta {
		en_Start,
		en_Start2,
		en_Start3,
		en_Start4,
	};

	bool Start();
	void Update();

private:
	prefab::CSpriteRender* m_sprite;
	prefab::CSpriteRender* m_sprite1;
	prefab::CSpriteRender* m_sprite2;
	prefab::CSpriteRender* m_sprite3;
	prefab::CSpriteRender* m_sprite4;
	prefab::CSpriteRender* m_sprite5;
	prefab::CSoundSource* m_sound;

	EnSta m_start = en_Start;

	CVector3 m_position;//ç¿ïW

	float OP3mozi = 0.0f;
	float OP3mozi2 = 0.0f;
};

