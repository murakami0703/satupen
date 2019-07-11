#pragma once
class Status :public IGameObject
{
public:
	Status();
	~Status();

	bool Start()override;
	void Update()override;
	std::vector<prefab::CSpriteRender*> m_spriteRender;
	std::vector<prefab::CSpriteRender*> m_spriteRenderHP;

private:

	//フォントレンダラー
	prefab::CFontRender* m_font;
	prefab::CFontRender* m_fontP;
	const CVector2 LifePivot = { 0.05f,0.1f };//HPの基本

	CVector4 LifeColor = { 1.0f,1.0f,1.0f,1.0f };//HPばーの色
	prefab::CSpriteRender* m_sprite;
	prefab::CSpriteRender* m_sprite1; //時計。
	prefab::CSpriteRender* m_sprite20;//針
	prefab::CSpriteRender* m_sprite2;
	prefab::CSpriteRender* m_sprite3;  //ペン
	prefab::CSpriteRender* m_sprite12; //ペン２
	prefab::CSpriteRender* m_sprite13; //ペン３
	prefab::CSpriteRender* m_sprite14; //ペン４
	prefab::CSpriteRender* m_sprite15; //ペン５
	prefab::CSpriteRender* m_sprite16; //ペン６
	prefab::CSpriteRender* m_sprite4;  //HPBar枠
	prefab::CSpriteRender* m_sprite7;  //HPBar白
	prefab::CSpriteRender* m_sprite17; //HPbar黒
	prefab::CSpriteRender* m_sprite18; //HPbar翠
	prefab::CSpriteRender* m_sprite5;  //顔
	prefab::CSpriteRender* m_sprite6;  //顔２
	prefab::CSpriteRender* m_sprite8;  //顔３
	prefab::CSpriteRender* m_sprite9;  //顔４
	prefab::CSpriteRender* m_sprite10; //顔５
	CVector3   m_position;  //座標
	CQuaternion m_rotation; //回転

	//リザルト遷移
	float rag = 0;
};

