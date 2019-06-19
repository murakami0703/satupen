#pragma once
class PenGenerator :public IGameObject
{
	static PenGenerator* m_instance;
public:
	PenGenerator();
	~PenGenerator();
	bool Start();
	void Update();
private:
};

