#pragma once
class GameData
{
	static GameData* m_instance;
public:
	GameData();
	~GameData();

	//�c�e�擾
	int GameData::GetZandan() {

		return Zandan;
	}

	//��{�U���͎擾
	int GameData::GetATK() {

		return ATK;
	}
	//�ő�̗͎擾
	int GameData::GetDEF_Life() {

		return DEF_Life;
	}
	
	//���݂̗̑�
	int GameData::tairyokuKeisan() {
		return Life;
		
	}
	//�����ɐݒ肵���l��̗͂ɉ��Z����@���̐���ݒ肵���猸������
	void  GameData::tiryokugennsyou(int x) {
		Life += x;
	}
	//�����c�e�擾
	int GameData::GetDEF_Zandan() {

		return DEF_Zandan;
	}
private:
	int Zandan = 50; //�c�e

	int ATK = 100; //��{�U����
	int DEF_Zandan = 50; //�f�t�H���g�c�e
	int DEF_Life = 100; //�f�t�H���g����
	int Life = DEF_Life; //���ݑ̗�
};

