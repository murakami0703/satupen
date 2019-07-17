#pragma once
class TimeUP:public IGameObject
{
public:
	TimeUP();
	~TimeUP();

	enum EnStar {
		en_Start,
	};

	bool Start();
	void Update();

private:
	//タイムアップ
	prefab::CSpriteRender* m_sprite;//翠の画面
	prefab::CSpriteRender* m_sprite2;//タイムアップ
	prefab::CSoundSource* m_sound;//ぴっぴー
	CVector3 m_position;//座標

	EnStar m_Sart = en_Start;

	float TUP = 0.0f;
};

