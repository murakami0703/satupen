#pragma once
class Result:public IGameObject
{
public:
	Result();
	~Result();

	enum EnStart {
		enStart_new,
		enStart_1,
		enStart_2,
		enStart_3,
		enStart_4,
		enStart_5,
	};

	bool Start();
	void Update();

private:

	
	prefab::CFontRender* m_font;        //�t�H���g

	prefab::CSpriteRender* m_sprite;//���U���g��ʂ̐X�̔w�i�B
	prefab::CSpriteRender* m_sprite1;//����
	prefab::CSpriteRender* m_sprite2;//�߂тƓx
	prefab::CSpriteRender* m_sprite3;//Tti
	prefab::CSpriteRender* m_sprite4;//ti2
	prefab::CSpriteRender* m_sprite5;//�P�l�x
	prefab::CSpriteRender* m_sprite6;//ZH
	prefab::CSpriteRender* m_sprite7;//��
	prefab::CSpriteRender* m_sprite8;//���Ȃ���

	CVector3 m_postion;//���W

	EnStart m_start = enStart_new;//���

	const CVector3 movepos{ 0.0f,280.0f,0.0f };  //�����̏ꏊ��������
	const CVector3 tumipos2{-380.0f,120.0f,0.0f}; //�߂̍��W��������
	const CVector3 zenpos2{-390.0f,-80.0f,0.0f };//�P�l�x���W�����Ȃ����

};

