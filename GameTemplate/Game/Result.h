#pragma once
class Result:public IGameObject
{
public:
	Result();
	~Result();

	enum EnStart {
		enStart_new,
		enStart_1,
		enStart_2,
		enStart_3,
		enStart_4,
		enStart_5,
	};

	bool Start();
	void Update();

private:

	
	prefab::CFontRender* m_font;        //フォント

	prefab::CSpriteRender* m_sprite;//リザルト画面の森の背景。
	prefab::CSpriteRender* m_sprite1;//総合
	prefab::CSpriteRender* m_sprite2;//罪びと度
	prefab::CSpriteRender* m_sprite3;//Tti
	prefab::CSpriteRender* m_sprite4;//ti2
	prefab::CSpriteRender* m_sprite5;//善人度
	prefab::CSpriteRender* m_sprite6;//ZH
	prefab::CSpriteRender* m_sprite7;//光
	prefab::CSpriteRender* m_sprite8;//あなたは

	CVector3 m_postion;//座標

	EnStart m_start = enStart_new;//状態

	const CVector3 movepos{ 0.0f,280.0f,0.0f };  //総合の場所見えんやつ
	const CVector3 tumipos2{-380.0f,120.0f,0.0f}; //罪の座標見えんやつ
	const CVector3 zenpos2{-390.0f,-80.0f,0.0f };//善人度座標見えないやつ

};

