#pragma once
class Load:public IGameObject
{
public:
	Load();
	~Load();

	bool Start() override;
	void Update() override;
	
	enum EnStar {
		en_Start,
	};

private:
	//�X�L�����f��Load
	prefab::CSpriteRender* m_skinModel = nullptr;//�^���Âȉ��
	prefab::CSpriteRender* m_skinModel2 = nullptr;//load�̕���

	CVector3 m_position;

	float MP1 = 0.0f;
	EnStar m_state = en_Start; //���
};

