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
	DH = gamedata->GetDeadH(); //���v�E�Q��
	DHMan = gamedata->GetResultDead(GameData::DeadMan);//�j���E�Q��*0.003
	DHWoman = gamedata->GetResultDead(GameData::DeadWoman);//�����E�Q��*0.004
	DHChildren = gamedata->GetResultDead(GameData::DeadChildren);//�q���E�Q��*0.007
	DADog = gamedata->GetResultDead(GameData::DeadDog);//�C�k�E�Q��*0.006
	DACat = gamedata->GetResultDead(GameData::DeadCat);//�l�R�E�Q��*0.08
	DABird = gamedata->GetResultDead(GameData::DeadBird);//�g���E�Q��*0.007
	DAnimals = gamedata->GetResultDead(GameData::DeadAnimals);//�����E�Q��
	Item = gamedata->GetResultDead(GameData::DesItem);//�A�C�e���󂵂���*0.001
	BigItem = gamedata->GetResultDead(GameData::DesBigItem);//�傫���A�C�e���󂵂���*0.002

	EnCount = gamedata->GetEnemycount(); //�G�̐�
	ItCount = gamedata->GetItemcount(); //�A�C�e���̐�

	return true;
}

void ResultDiagnostic::Update()
{
	//���U���g�̌v�Z���邼�]�]
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
		//�P�l�x
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
		//���Ȃ���
		if (ZaininP > 0.5f) {
			//�ߐl�x��50���ȏゾ������
		}
		else if (ZaininP > 0.7f) {

		}
		else if (ZaininP > 0.85f) {

		}
		else if (ZenninP > 0.5f) {
			//�P�l�x��50���ȏゾ������
		}
		else if (ZenninP > 0.7f) {

		}
		else if (ZenninP > 0.85f) {

		}
		break;
	}
	}
}

