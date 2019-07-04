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
		enStart_6,
		enStart_7,
		enStart_8,
		enStart_9,
		enStart_10,
	};

	bool Start();
	void Update();

private:

	float Ana = 0.0f; //あなたは
	int Sugoutimer = 0.0f;//総合のタイム
	int ZZ = 0; //ここに入れる善人
	int TT = 0;//ここに入れる罪人
	int Ze = 50;//善人の変数仮
	int Tu = 50;//罪人の変数仮
	bool Zenpaflag = false;//善人
	bool Tumipaflag = false;//罪人
	prefab::CFontRender* m_font;        //フォント
	prefab::CFontRender* m_font2; //フォンとおお

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

	const CVector3 SDrop{ 0.0f,400.0f,0.0f };      //総合見えない場所

	const CVector3 movepos{ 0.0f,150.0f,0.0f };    //総合最終地点

	const CVector3 SDroppos{ 0.0f,280.0f,0.0f };  //動く距離

	const int DropLimitS = 20;                     //落ちる時間
	const int RemoveLimitS = 10;                   //戻る時間
	const CVector3 tumipos2{-380.0f,120.0f,0.0f};  //罪の座標見えんやつ
	const CVector3 zenpos2{-390.0f,-80.0f,0.0f };  //善人度座標見えないやつ

};

