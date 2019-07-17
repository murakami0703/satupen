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
	DH = gamedata->GetDeadH(); //‡ŒvEŠQ”
	DHMan = gamedata->GetResultDead(GameData::DeadMan);//’j«EŠQ”*0.003
	DHWoman = gamedata->GetResultDead(GameData::DeadWoman);//—«EŠQ”*0.004
	DHChildren = gamedata->GetResultDead(GameData::DeadChildren);//q‹ŸEŠQ”*0.007
	DADog = gamedata->GetResultDead(GameData::DeadDog);//ƒCƒkEŠQ”*0.006
	DACat = gamedata->GetResultDead(GameData::DeadCat);//ƒlƒREŠQ”*0.08
	DABird = gamedata->GetResultDead(GameData::DeadBird);//ƒgƒŠEŠQ”*0.007
	DAnimals = gamedata->GetResultDead(GameData::DeadAnimals);//“®•¨EŠQ”
	Item = gamedata->GetResultDead(GameData::DesItem);//ƒAƒCƒeƒ€‰ó‚µ‚½”*0.001
	BigItem = gamedata->GetResultDead(GameData::DesBigItem);//‘å‚«‚¢ƒAƒCƒeƒ€‰ó‚µ‚½”*0.002

	EnCount = gamedata->GetEnemycount(); //“G‚Ì”
	ItCount = gamedata->GetItemcount(); //ƒAƒCƒeƒ€‚Ì”

	return true;
}

void ResultDiagnostic::Update()
{
	//ƒŠƒUƒ‹ƒg‚ÌŒvZ‚·‚é‚¼ƒ]ƒ]
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
		//‘Pl“x
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
		//‚ ‚È‚½‚Í
		if (ZaininP > 0.5f) {
			//ßl“x‚ª50“ˆÈã‚¾‚Á‚½
		}
		else if (ZaininP > 0.7f) {

		}
		else if (ZaininP > 0.85f) {

		}
		else if (ZenninP > 0.5f) {
			//‘Pl“x‚ª50“ˆÈã‚¾‚Á‚½
		}
		else if (ZenninP > 0.7f) {

		}
		else if (ZenninP > 0.85f) {

		}
		break;
	}
	}
}

