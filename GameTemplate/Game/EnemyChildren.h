#pragma once
class EnemyChildren : public IGameObject
{
public:
	EnemyChildren();
	~EnemyChildren();
	enum EnState {
		EnState_idle,	//�ҋ@
		EnState_walk,	//����
		EnState_runaway,	//������
	};
	bool Start();
	void Update();
private:
	void Childrenidle();
	void ChildrenWalk();
	void ChildrenRunaway();

	EnState m_state = EnState_idle;//���

};

