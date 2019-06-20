#pragma once
class GameData : public IGameObject
{
	static GameData* m_instance;
public:
	GameData::GameData()
	{
		if (m_instance != nullptr) {
			std::abort(); //���łɏo�Ă��邽�߃N���b�V��
		}

		//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
		m_instance = this;

	}

	GameData::~GameData()
	{
		//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
		m_instance = nullptr;

	}

	//�C���X�^���X�̎擾
	static GameData* GameData::GetInstance() {
		return m_instance;
	}

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
	//�̗�
	int GameData::Get_Life() {
		return Life;
	}
	//�����ɐݒ肵���l��̗͂ɉ��Z����@���̐���ݒ肵���猸������
	void  GameData::tiryokugennsyou(int x) {
		Life += x;
		if (Life < 0) {
			Life = 0;
		}
		if (DEF_Life < Life) {
			DEF_Life = Life;
		}
	}
	//�����c�e�擾
	int GameData::GetDEF_Zandan() {

		return DEF_Zandan;
	}
private:
	int Zandan = 50; //�c�e

	int ATK = 100; //��{�U����
	int DEF_Zandan = 50; //�f�t�H���g�c�e
	int DEF_Life = 100; //�f�t�H���g�̗�
	int Life = 100; //�̗͎擾

};

