#pragma once
class EnemyMan : public IGameObject
{
public:
	EnemyMan();
	~EnemyMan();
	enum EnState {
		EnState_idle,	//待機
		EnState_walk,	//歩き
		EnState_attack,	//攻撃

	};
	bool Start();
	void Update();
private:
	void Manidle();
	void ManWalk();
	void ManAttack();

	EnState m_state = EnState_idle;//状態

};

