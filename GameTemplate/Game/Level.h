#pragma once
class Level : public IGameObject
{
	static Level* m_instance;
public:
	Level();
	~Level();

	bool Start();
	void Update();
	//�C���X�^���X�̎擾
	static Level* Level::GetInstance() {
		return m_instance;
	}

private:
	CLevel m_level;	//���x���f�[�^�B

};

