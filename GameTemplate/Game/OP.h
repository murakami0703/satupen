#pragma once
class OP :public IGameObject
{
public:
	OP();
	~OP();

	enum EnStar {
		en_Start,
		/*en_Start2,
		en_Start3,*/
	};
	bool Start();
	void Update();

private:
	prefab::CSoundSource* m_sound;//オープニング音楽
	prefab::CSpriteRender* m_sprite;//オープニング１
	prefab::CSpriteRender* m_sprite2;//オープニング２
	
	CVector3 m_position;//座標

	EnStar m_Sart = en_Start;

	float MOZI1 = 0.0f;

};

