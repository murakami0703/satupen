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
	//�ߐl�x�̒l��Ԃ�
	float ResultDiagnostic::GetZaininP() {
		return ZaininP;
	}
	//�P�l�x�̒l��Ԃ�
	float ResultDiagnostic::GetZenninP() {
		return ZenninP;
	}
private:
	Enstate m_state = Zainin;
	int DH = 0; //���v�E�Q��
	int DHMan = 0;//�j���E�Q��
	int DHWoman = 0;//�����E�Q��
	int DHChildren = 0;//�q���E�Q��
	int DADog = 0;//�C�k�E�Q��
	int DACat = 0;//�l�R�E�Q��
	int DABird = 0;//�g���E�Q��
	int DAnimals = 0;//�����E�Q��
	int Item = 0;//�A�C�e���󂵂���
	int BigItem = 0;//�傫���A�C�e���󂵂���
	int EnCount = 0; //�G�̐�
	int ItCount = 0; //�A�C�e���̐�

	///////////////////////////////
	float ZaininP = 0.0f;//�ߐl�x�̒l
	float ZenninP = 0.0f;//�P�l�x�̒l
	//////////////////////////////
	float Getlife = 0.0f;
	float Maxlife = 0.0f;
};
const int Diagnostic = 1; //���ڐ�

const wchar_t Setumei[Diagnostic][255]{
	{ L"" },
};

