#pragma once
class EnemyMan : public IGameObject
{
public:
	EnemyMan();
	~EnemyMan();
	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_attack,	//�U��

	};
	bool Start();
	void Update();
private:
	void Manidle();
	void ManWalk();
	void ManAttack();

	EnState m_state = EnState_idle;//���

};

