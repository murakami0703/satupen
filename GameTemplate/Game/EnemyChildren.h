#pragma once
class EnemyChildren : public IGameObject
{
public:
	EnemyChildren();
	~EnemyChildren();
	enum EnState {
		EnState_idle,	//待機
		EnState_walk,	//歩き
		EnState_runaway,	//逃げる
	};
	bool Start();
	void Update();
private:
	void Childrenidle();
	void ChildrenWalk();
	void ChildrenRunaway();

	EnState m_state = EnState_idle;//状態

};

