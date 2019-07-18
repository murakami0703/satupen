#pragma once
class ResultDiagnostic : public IGameObject
{
public:
	ResultDiagnostic();
	~ResultDiagnostic();
	enum Enstate {
		Zainin,
		Zennin,
		Gokei,
	};
	bool Start();
	void Update();
	//ßl“x‚Ì’l‚ğ•Ô‚·
	float ResultDiagnostic::GetZaininP() {
		return ZaininP;
	}
	//‘Pl“x‚Ì’l‚ğ•Ô‚·
	float ResultDiagnostic::GetZenninP() {
		return ZenninP;
	}
private:
	Enstate m_state = Zainin;
	int DH = 0; //‡ŒvEŠQ”
	int DHMan = 0;//’j«EŠQ”
	int DHWoman = 0;//—«EŠQ”
	int DHChildren = 0;//q‹ŸEŠQ”
	int DADog = 0;//ƒCƒkEŠQ”
	int DACat = 0;//ƒlƒREŠQ”
	int DABird = 0;//ƒgƒŠEŠQ”
	int DAnimals = 0;//“®•¨EŠQ”
	int Item = 0;//ƒAƒCƒeƒ€‰ó‚µ‚½”
	int BigItem = 0;//‘å‚«‚¢ƒAƒCƒeƒ€‰ó‚µ‚½”
	int EnCount = 0; //“G‚Ì”
	int ItCount = 0; //ƒAƒCƒeƒ€‚Ì”

	///////////////////////////////
	float ZaininP = 0.0f;//ßl“x‚Ì’l
	float ZenninP = 0.0f;//‘Pl“x‚Ì’l
	//////////////////////////////
	float Getlife = 0.0f;
	float Maxlife = 0.0f;
};
const int Diagnostic = 1; //€–Ú”

const wchar_t Setumei[Diagnostic][255]{
	{ L"" },
};

