#pragma once
class Level : public IGameObject
{
	static Level* m_instance;
public:
	Level();
	~Level();

	bool Start();
	void Update();
	//インスタンスの取得
	static Level* Level::GetInstance() {
		return m_instance;
	}

private:
	CLevel m_level;	//レベルデータ。

};

