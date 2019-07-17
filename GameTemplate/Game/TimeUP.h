#pragma once
class TimeUP:public IGameObject
{
public:
	TimeUP();
	~TimeUP();

	enum EnStar {
		en_Start,
	};

	bool Start();
	void Update();

private:
	//�^�C���A�b�v
	prefab::CSpriteRender* m_sprite;//���̉��
	prefab::CSpriteRender* m_sprite2;//�^�C���A�b�v
	prefab::CSoundSource* m_sound;//�҂��ҁ[
	CVector3 m_position;//���W

	EnStar m_Sart = en_Start;

	float TUP = 0.0f;
};

