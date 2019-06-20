#pragma once
class Status:public IGameObject
{
public:
	Status();
	~Status();

	bool Start()override;
	void Update()override;
	std::vector<prefab::CSpriteRender*> m_spriteRender;
	std::vector<prefab::CSpriteRender*> m_spriteRenderHP;

private:

	//ƒtƒHƒ“ƒgƒŒƒ“ƒ_ƒ‰[
	prefab::CFontRender* m_font;
	const CVector2 LifePivot = { 0.05f,0.1f };//HP‚ÌŠî–{
	
    CVector4 LifeColor = { 1.0f,1.0f,1.0f,1.0f };//HP‚Î[‚ÌF
	prefab::CSpriteRender* m_sprite;
	prefab::CSpriteRender* m_sprite1; //ŒvB
	prefab::CSpriteRender* m_sprite20;//j
	prefab::CSpriteRender* m_sprite21;//j¬
	prefab::CSpriteRender* m_sprite2;
	prefab::CSpriteRender* m_sprite3;  //ƒyƒ“
	prefab::CSpriteRender* m_sprite12; //ƒyƒ“‚Q
	prefab::CSpriteRender* m_sprite13; //ƒyƒ“‚R
	prefab::CSpriteRender* m_sprite14; //ƒyƒ“‚S
	prefab::CSpriteRender* m_sprite15; //ƒyƒ“‚T
	prefab::CSpriteRender* m_sprite16; //ƒyƒ“‚U
	prefab::CSpriteRender* m_sprite19; //ƒyƒ“‚V
	prefab::CSpriteRender* m_sprite4;  //HPBar˜g
	prefab::CSpriteRender* m_sprite7;  //HPBar”’
	prefab::CSpriteRender* m_sprite17; //HPbar•
	prefab::CSpriteRender* m_sprite18; //HPbar‰
	prefab::CSpriteRender* m_sprite5;  //Šç
	prefab::CSpriteRender* m_sprite6;  //Šç‚Q
	prefab::CSpriteRender* m_sprite8;  //Šç‚R
	prefab::CSpriteRender* m_sprite9;  //Šç‚S
	prefab::CSpriteRender* m_sprite10; //Šç‚T
	prefab::CSpriteRender* m_sprite11; //Šç‚U
	CVector3   m_position;  //À•W
	CQuaternion m_rotation; //‰ñ“]
};

