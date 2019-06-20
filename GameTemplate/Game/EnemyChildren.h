#pragma once
class EnemyChildren : public IGameObject
{
public:
	EnemyChildren();
	~EnemyChildren();
	enum EnState {
		EnState_idle,	//‘Ò‹@
		EnState_walk,	//•à‚«
		EnState_runaway,	//“¦‚°‚é
	};
	bool Start();
	void Update();
private:
	void Childrenidle();
	void ChildrenWalk();
	void ChildrenRunaway();

	EnState m_state = EnState_idle;//ó‘Ô

};

