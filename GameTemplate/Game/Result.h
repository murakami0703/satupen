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
		enStart_6,
		enStart_7,
		enStart_8,
		enStart_9,
		enStart_10,
	};

	bool Start();
	void Update();

private:

	float Ana = 0.0f; //���Ȃ���
	int Sugoutimer = 0.0f;//�����̃^�C��
	int ZZ = 0; //�����ɓ����P�l
	int TT = 0;//�����ɓ����ߐl
	int Ze = 50;//�P�l�̕ϐ���
	int Tu = 50;//�ߐl�̕ϐ���
	bool Zenpaflag = false;//�P�l
	bool Tumipaflag = false;//�ߐl
	prefab::CFontRender* m_font;        //�t�H���g
	prefab::CFontRender* m_font2; //�t�H���Ƃ���

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

	const CVector3 SDrop{ 0.0f,400.0f,0.0f };      //���������Ȃ��ꏊ

	const CVector3 movepos{ 0.0f,150.0f,0.0f };    //�����ŏI�n�_

	const CVector3 SDroppos{ 0.0f,280.0f,0.0f };  //��������

	const int DropLimitS = 20;                     //�����鎞��
	const int RemoveLimitS = 10;                   //�߂鎞��
	const CVector3 tumipos2{-380.0f,120.0f,0.0f};  //�߂̍��W��������
	const CVector3 zenpos2{-390.0f,-80.0f,0.0f };  //�P�l�x���W�����Ȃ����

};

