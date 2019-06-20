#pragma once
class EnemyMan : public IGameObject
{
public:
	EnemyMan();
	~EnemyMan();
	enum EnState {
		EnState_idle,	//‘Ò‹@
		EnState_walk,	//•à‚«
		EnState_attack,	//UŒ‚

	};
	bool Start();
	void Update();
private:
	void Manidle();
	void ManWalk();
	void ManAttack();

	EnState m_state = EnState_idle;//ó‘Ô

};

