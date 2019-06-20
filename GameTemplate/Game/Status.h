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

	//tHg_[
	prefab::CFontRender* m_font;
	const CVector2 LifePivot = { 0.05f,0.1f };//HPΜξ{
	
    CVector4 LifeColor = { 1.0f,1.0f,1.0f,1.0f };//HPΞ[ΜF
	prefab::CSpriteRender* m_sprite;
	prefab::CSpriteRender* m_sprite1; //vB
	prefab::CSpriteRender* m_sprite20;//j
	prefab::CSpriteRender* m_sprite21;//j¬
	prefab::CSpriteRender* m_sprite2;
	prefab::CSpriteRender* m_sprite3;  //y
	prefab::CSpriteRender* m_sprite12; //yQ
	prefab::CSpriteRender* m_sprite13; //yR
	prefab::CSpriteRender* m_sprite14; //yS
	prefab::CSpriteRender* m_sprite15; //yT
	prefab::CSpriteRender* m_sprite16; //yU
	prefab::CSpriteRender* m_sprite19; //yV
	prefab::CSpriteRender* m_sprite4;  //HPBarg
	prefab::CSpriteRender* m_sprite7;  //HPBar
	prefab::CSpriteRender* m_sprite17; //HPbar
	prefab::CSpriteRender* m_sprite18; //HPbar
	prefab::CSpriteRender* m_sprite5;  //η
	prefab::CSpriteRender* m_sprite6;  //ηQ
	prefab::CSpriteRender* m_sprite8;  //ηR
	prefab::CSpriteRender* m_sprite9;  //ηS
	prefab::CSpriteRender* m_sprite10; //ηT
	prefab::CSpriteRender* m_sprite11; //ηU
	CVector3   m_position;  //ΐW
	CQuaternion m_rotation; //ρ]
};

