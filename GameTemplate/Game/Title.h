#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();

	enum EnState {
		enState_new,
		enState_2,//なかったけんとりあえず書いたやつ
		enState_3,
		enState_4,
	};
	enum EnSart{
		enStart_new,
		enStart_restart,
	};

	bool Start();
	void Update();

private:
	//殺戮の剣文字大きい
	CVector3 movepos = { 0.0f,120.0f,0.0f }; //座標
	//白いペン
	bool sasitaflag = false;

	int Pentimer = 0;
	float SP1 = 0.0f;

	//スプライトタイトル殺戮の剣
	prefab::CSpriteRender* m_sprite;  //赤いBK
	prefab::CSpriteRender* m_sprite1; //さつりくのペン
	prefab::CSpriteRender* m_sprite2; //殺戮の剣
	prefab::CSpriteRender* m_sprite3; //しろのペン
	prefab::CSpriteRender* m_sprite4; //選択
	prefab::CSpriteRender* m_sprite5; //はじめる。
	prefab::CSpriteRender* m_sprite6; //おわる。
	prefab::CSpriteRender* m_sprite7;//➡
	std::vector<prefab::CSpriteRender*> m_spriteRender;
	prefab::CSpriteRender* sp;

	EnSart m_Sart = enStart_new;//状態 矢印の指定したら色付きで指定してないやつは半透明。
	EnState m_state = enState_new; //状態
	CVector3 m_position; //座標

	//定数
	const CVector3 PenDef = { 900.0f,800.0f,0.0f };
	const CVector3 PenDropPos = { 200.0f,100.0f,0.0f };
	const CVector3 PenRemovePos = { 250.0f,150.0f,0.0f };
	const int DropLimit = 20; //落ちる時間（ここをいじると落ちる速さ変わる）
	const int RemoveLimit = 10; //戻る時間

};

