#pragma once
class GameOver:public IGameObject
{
public:
	GameOver();
	~GameOver();

	enum EnStar {
		en_Start,
	};

	bool Start();
	void Update();

private:
	//�Q�[���I�[�o�[
	prefab::CSpriteRender* m_sprite;//���̃o�b�N
	prefab::CSpriteRender* m_sprite2;//�Q�[���I�[�o�[

	CVector3 m_position;//���W

	EnStar m_Sart = en_Start;

	float GO = 0.0f;

};

