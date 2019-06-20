#pragma once
class EnemyWoman : public IGameObject
{
public:
	EnemyWoman();
	~EnemyWoman();
	enum EnState {
		EnState_idle,	//‘Ò‹@
		EnState_walk,	//•à‚«
		EnState_runaway,	//“¦‚°‚é
	};
	bool Start();
	void Update();
private:
	void Womanidle();
	void WomanWalk();
	void WomanRunaway();

	EnState m_state = EnState_idle;//ó‘Ô

};

