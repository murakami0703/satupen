#pragma once
class EnemyWoman : public IGameObject
{
public:
	EnemyWoman();
	~EnemyWoman();
	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_runaway,	//������
	};
	bool Start();
	void Update();
private:
	void Womanidle();
	void WomanWalk();
	void WomanRunaway();

	EnState m_state = EnState_idle;//���

};

