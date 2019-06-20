#pragma once
class EnemyWoman : public IGameObject
{
public:
	EnemyWoman();
	~EnemyWoman();
	enum EnState {
		EnState_idle,	//待機
		EnState_walk,	//歩き
		EnState_runaway,	//逃げる
	};
	bool Start();
	void Update();
private:
	void Womanidle();
	void WomanWalk();
	void WomanRunaway();

	EnState m_state = EnState_idle;//状態

};

