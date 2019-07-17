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
	//罪人度の値を返す
	float ResultDiagnostic::GetZaininP() {
		return ZaininP;
	}
	//善人度の値を返す
	float ResultDiagnostic::GetZenninP() {
		return ZenninP;
	}
private:
	Enstate m_state = Zainin;
	int DH = 0; //合計殺害数
	int DHMan = 0;//男性殺害数
	int DHWoman = 0;//女性殺害数
	int DHChildren = 0;//子供殺害数
	int DADog = 0;//イヌ殺害数
	int DACat = 0;//ネコ殺害数
	int DABird = 0;//トリ殺害数
	int DAnimals = 0;//動物殺害数
	int Item = 0;//アイテム壊した数
	int BigItem = 0;//大きいアイテム壊した数
	int EnCount = 0; //敵の数
	int ItCount = 0; //アイテムの数

	///////////////////////////////
	float ZaininP = 0.0f;//罪人度の値
	float ZenninP = 0.0f;//善人度の値

};
const int Diagnostic = 1; //項目数

const wchar_t Setumei[Diagnostic][255]{
	{ L"" },
};

