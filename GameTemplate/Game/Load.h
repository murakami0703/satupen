#pragma once
class Load:public IGameObject
{
public:
	Load();
	~Load();

	bool Start() override;
	void Update() override;
	
	enum EnStar {
		en_Start,
	};

private:
	//スキンモデルLoad
	prefab::CSpriteRender* m_skinModel = nullptr;//真っ暗な画面
	prefab::CSpriteRender* m_skinModel2 = nullptr;//loadの文字

	CVector3 m_position;

	float MP1 = 0.0f;
	EnStar m_state = en_Start; //状態
};

