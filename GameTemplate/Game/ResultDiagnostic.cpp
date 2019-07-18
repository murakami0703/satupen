#include "stdafx.h"
#include "ResultDiagnostic.h"
#include "GameData.h"

ResultDiagnostic::ResultDiagnostic()
{
}


ResultDiagnostic::~ResultDiagnostic()
{
}
bool ResultDiagnostic::Start()
{
	GameData* gamedata = GameData::GetInstance();
	DH = gamedata->GetDeadH(); //合計殺害数
	DHMan = gamedata->GetResultDead(GameData::DeadMan);//男性殺害数*0.003
	DHWoman = gamedata->GetResultDead(GameData::DeadWoman);//女性殺害数*0.004
	DHChildren = gamedata->GetResultDead(GameData::DeadChildren);//子供殺害数*0.007
	DADog = gamedata->GetResultDead(GameData::DeadDog);//イヌ殺害数*0.006
	DACat = gamedata->GetResultDead(GameData::DeadCat);//ネコ殺害数*0.08
	DABird = gamedata->GetResultDead(GameData::DeadBird);//トリ殺害数*0.007
	DAnimals = gamedata->GetResultDead(GameData::DeadAnimals);//動物殺害数
	Item = gamedata->GetResultDead(GameData::DesItem);//アイテム壊した数*0.001
	BigItem = gamedata->GetResultDead(GameData::DesBigItem);//大きいアイテム壊した数*0.002

	EnCount = gamedata->GetEnemycount(); //敵の数
	ItCount = gamedata->GetItemcount(); //アイテムの数

	Getlife = gamedata->Get_Life();
	Maxlife = gamedata->GetDEF_Life();
	return true;
}

void ResultDiagnostic::Update()
{
	//リザルトの計算するぞゾゾ
	switch (m_state)
	{
	case ResultDiagnostic::Zainin:
	{
		DHMan *= 0.003;
		DHWoman *= 0.004;
		DHChildren *= 0.007;
		DADog *= 0.006;
		DACat *= 0.008;
		DABird *= 0.007;
		Item *= 0.001;
		BigItem *= 0.002;
		ZaininP = DHMan + DHWoman + DHChildren + DADog + DACat + DABird + Item + BigItem;
		m_state = Zennin;
		break;
	}
	case ResultDiagnostic::Zennin:
	{
		//善人度
		DHMan *= 0.004;
		DHWoman *= 0.005;
		DHChildren *= 0.08;
		DADog *= 0.009;
		DACat *= 0.009;
		DABird *= 0.009;
		Item *= 0.001;
		BigItem *= 0.003;
		ZenninP = DHMan + DHWoman + DHChildren + DADog + DACat + DABird + Item + BigItem;
		m_state = Zennin;
		break;
	}
	case ResultDiagnostic::Gokei:
	{
		//あなたは
		if (DH > 50 && Getlife >= Maxlife) {
			//50人以上殺した＆ノーダメージ
		}
		else if (DH > 50 && Getlife < Maxlife) {
			//50人以上殺した＆ノーダメージではない
		}
		else if (DH == 0) {
			//誰も殺していない
		}
		else if (DHMan == 7 && DHWoman == 5 && DHChildren) {
			//男性を7人、女性を5人、子供を3人殺す
		}
		else if (DH > 35 && DAnimals==0) {
			//人間を35人以上殺した＆動物を殺していない
		}
		else if (DHMan > 40 && DHWoman == 0) {
			//男性を40人以上殺した＆女性を殺していない
		}
		else if (DHWoman > 40 && DHMan == 0) {
			//女性を40人以上殺した＆男性を殺していない
		}
		else if (DHChildren > 40 && DHMan == 0 && DHWoman == 0 && DAnimals == 0) {
			//子供だけを40人殺した（大人と動物を殺さない）
		}
		else if (DAnimals > 30 && DH == 0) {
			//動物だけを50匹以上殺した（人間は殺さない）
		}
		else if (Item > 70) {
			//オブジェクトを70個以上破壊
		}

		else if (ZaininP > 1.0f) {
			//罪人度が100％だった時

		}
		else if (ZaininP > 0.9f) {
			//罪人度が90％以上だった時

		}
		else if (ZaininP > 0.8f) {
			//罪人度が80％以上だった時

		}
		else if (ZaininP > 0.7f) {
			//罪人度が70％以上だった時

		}
		else if (ZaininP > 0.6f) {
			//罪人度が60％以上だった時

		}
		else if (ZaininP > 0.5f) {
			//罪人度が50％以上だった時

		}
		else if (ZaininP > 0.4f) {
			//罪人度が40％以上だった時

		}
		else if (ZaininP > 0.3f) {
			//罪人度が30％以上だった時

		}
		else if (ZaininP > 0.2f) {
			//罪人度が20％以上だった時

		}
		else if (ZaininP > 0.1f) {
			//罪人度が10％以上だった時

		}
		else {
			//罪人度が0％だった時

		}

		break;
	}
	}
}

