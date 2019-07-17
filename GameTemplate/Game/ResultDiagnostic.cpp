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
		if (ZaininP > 0.5f) {
			//罪人度が50％以上だった時
		}
		else if (ZaininP > 0.7f) {

		}
		else if (ZaininP > 0.85f) {

		}
		else if (ZenninP > 0.5f) {
			//善人度が50％以上だった時
		}
		else if (ZenninP > 0.7f) {

		}
		else if (ZenninP > 0.85f) {

		}
		break;
	}
	}
}

