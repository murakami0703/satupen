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

	Getlife = gamedata->Get_Life();
	Maxlife = gamedata->GetDEF_Life();
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
		if (DH > 50 && Getlife >= Maxlife) {
			//50�l�ȏ�E�������m�[�_���[�W
		}
		else if (DH > 50 && Getlife < Maxlife) {
			//50�l�ȏ�E�������m�[�_���[�W�ł͂Ȃ�
		}
		else if (DH == 0) {
			//�N���E���Ă��Ȃ�
		}
		else if (DHMan == 7 && DHWoman == 5 && DHChildren) {
			//�j����7�l�A������5�l�A�q����3�l�E��
		}
		else if (DH > 35 && DAnimals==0) {
			//�l�Ԃ�35�l�ȏ�E�������������E���Ă��Ȃ�
		}
		else if (DHMan > 40 && DHWoman == 0) {
			//�j����40�l�ȏ�E�������������E���Ă��Ȃ�
		}
		else if (DHWoman > 40 && DHMan == 0) {
			//������40�l�ȏ�E�������j�����E���Ă��Ȃ�
		}
		else if (DHChildren > 40 && DHMan == 0 && DHWoman == 0 && DAnimals == 0) {
			//�q��������40�l�E�����i��l�Ɠ������E���Ȃ��j
		}
		else if (DAnimals > 30 && DH == 0) {
			//����������50�C�ȏ�E�����i�l�Ԃ͎E���Ȃ��j
		}
		else if (Item > 70) {
			//�I�u�W�F�N�g��70�ȏ�j��
		}

		else if (ZaininP > 1.0f) {
			//�ߐl�x��100����������

		}
		else if (ZaininP > 0.9f) {
			//�ߐl�x��90���ȏゾ������

		}
		else if (ZaininP > 0.8f) {
			//�ߐl�x��80���ȏゾ������

		}
		else if (ZaininP > 0.7f) {
			//�ߐl�x��70���ȏゾ������

		}
		else if (ZaininP > 0.6f) {
			//�ߐl�x��60���ȏゾ������

		}
		else if (ZaininP > 0.5f) {
			//�ߐl�x��50���ȏゾ������

		}
		else if (ZaininP > 0.4f) {
			//�ߐl�x��40���ȏゾ������

		}
		else if (ZaininP > 0.3f) {
			//�ߐl�x��30���ȏゾ������

		}
		else if (ZaininP > 0.2f) {
			//�ߐl�x��20���ȏゾ������

		}
		else if (ZaininP > 0.1f) {
			//�ߐl�x��10���ȏゾ������

		}
		else {
			//�ߐl�x��0����������

		}

		break;
	}
	}
}

