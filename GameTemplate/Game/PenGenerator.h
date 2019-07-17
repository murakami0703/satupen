#pragma once
class PenGenerator :public IGameObject
{
	static PenGenerator* m_instance;
public:
	PenGenerator();
	~PenGenerator();
	bool Start();
	void Update();

	bool IsFire() const	//	���˔���
	{
		return m_isFire;
	}

private:
	bool m_isFire = false;
};

