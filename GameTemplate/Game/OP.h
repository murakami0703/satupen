#pragma once
class OP :public IGameObject
{
public:
	OP();
	~OP();

	enum EnStar {
		en_Start,
		/*en_Start2,
		en_Start3,*/
	};
	bool Start();
	void Update();

private:
	prefab::CSoundSource* m_sound;//�I�[�v�j���O���y
	prefab::CSpriteRender* m_sprite;//�I�[�v�j���O�P
	prefab::CSpriteRender* m_sprite2;//�I�[�v�j���O�Q
	
	CVector3 m_position;//���W

	EnStar m_Sart = en_Start;

	float MOZI1 = 0.0f;

};

