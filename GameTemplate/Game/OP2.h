#pragma once
class OP2:public IGameObject
{
public:
	OP2();
	~OP2();
	enum En_Start {
		en_Start,
		en_Start2,
		en_Start3,
		en_Start4,

	};

	bool Start();
	void Update();


private:
	prefab::CSpriteRender* m_sprite;//�͂���
	prefab::CSpriteRender* m_sprite1;//���t
	prefab::CSpriteRender* m_sprite2;//�y��
	prefab::CSpriteRender* m_sprite3;//���t�Q
	prefab::CSpriteRender* m_sprite4;//�т�����

	CVector3 m_position;//���W
	En_Start m_Star = en_Start;

	float OP2mozi = 0.0f;
	float OP2mozi2 = 0.0f;
};

