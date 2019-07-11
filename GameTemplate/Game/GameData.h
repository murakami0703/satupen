#pragma once
class GameData : public IGameObject
{
	static GameData* m_instance;
public:
	GameData();
	~GameData();
	enum ResultDead {
		DeadMan,
		DeadWoman,
		DeadChildren,
		DeadDog,
		DeadCat,
		DeadBird,
		DeadAnimals,
		DesItem,
		DesBigItem,
	};
	int GameData::GetResultDead(ResultDead dead);	//Result�p	�J�E���g��Ԃ��B
	void GameData::ResultDeadkasan(ResultDead dead);	//Result�p �����ɐݒ肵���l�ɉ��Z����B

	//�C���X�^���X�̎擾
	static GameData* GameData::GetInstance() {
		return m_instance;
	}

	//�c�e�擾
	int GameData::GetZandan() {

		return Zandan;
	}
	//�U���͎擾
	int GameData::GetATK() {

		return ATK;
	}
	//�ő�̗͎擾
	int GameData::GetDEF_Life() {

		return DEF_Life;
	}
	//�̗͎擾
	int GameData::Get_Life() {
		return Life;
	}
	//�G���E���������擾
	int GameData::GetDeadH() {
		return DeadH;
	}
	//�����ɐݒ肵���l��̗͂ɉ��Z����@���̐���ݒ肵���猸������
	void  GameData::tiryokugennsyou(int x) {
		Life += x;
		if (Life < 0) {
			Life = 0;
		}
		if (DEF_Life < Life) {
			Life = DEF_Life;
		}
	}
	//�����ɐݒ肵���l���c�e�ɉ��Z����@���̐���ݒ肵���猸������
	void GameData::Zandannkasan(int x) {
		Zandan += x;
		if (Zandan < 0) {
			Zandan = 0;
		}

		if (MAX_Zandann < Zandan) {
			Zandan = MAX_Zandann;
		}

	}
	//�����ɐݒ肵���l���E�Q���ɉ��Z����@���̐���ݒ肵���猸������
	void GameData::DeadHkasan(int x) {
		DeadH += x;
		if (DeadH < 0) {
			DeadH = 0;
		}

		if (MAX_DeadH < DeadH) {
			DeadH = MAX_DeadH;
		}

	}
	//�������G�l�~�[�J�E���^�[�ɑ��
	void GameData::EnemyCounterSet(int x) {
		EnemyCount = x;
	}
	//�������A�C�e���J�E���^�[�ɑ��
	void GameData::ItemCounterSet(int x) {
		ItemCount = x;
	}
	//////////////////////////////////////
	//���U���g�p�@�����v�Z



private:
	int Zandan = 50; //�c�e
	int DeadH = 0;	//�E������
	int ATK = 100; //��{�U����
	int DEF_Life = 100; //�f�t�H���g�̗�
	int Life = 100; //�̗͎擾
	const int MAX_Zandann = 99;//�ő�c�e
	const int MAX_DeadH = 999;//�ő�c�s��

	int EnemyCount = 0; //�G�̐�
	int ItemCount = 0; //�A�C�e���̐�

	///////////////////////
	//���U���g�p��ޕʎE�Q���Ȃ�
	int Man = 0;//�j���E�Q��
	int Woman = 0;//�����E�Q��
	int Children = 0;//�q���E�Q��
	int Dog = 0;//�C�k�E�Q��
	int Cat = 0;//�l�R�E�Q��
	int Bird = 0;//�g���E�Q��
	int Animals = 0;//�����E�Q��
	int Item = 0;//�A�C�e���󂵂���
	int BigItem = 0;//�傫���A�C�e���󂵂���

	const int MAX_Dead = 999;//�ő�c�s���j��
	
	///////////////////////

	//�萔
};

