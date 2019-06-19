#include "stdafx.h"
#include "Status.h"
#include"GameData.h"
#include"Player.h"


Status::Status()
{

}


Status::~Status()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite1);
	DeleteGO(m_sprite2);
	DeleteGO(m_sprite3);
	DeleteGO(m_sprite4);
	DeleteGO(m_sprite5);
	DeleteGO(m_sprite6);
	DeleteGO(m_sprite7);
}
bool Status::Start()
{
	//�X�v���C�h��������
	//�S�̂�Bar�̃X�v���C�g
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/midriwaku1.dds", 1280.0f, 720.0f);
	//���v�X�v���C�g
	m_sprite1 = NewGO<prefab::CSpriteRender>(0);
	m_sprite1->Init(L"sprite/taim.dds", 1280.0f, 720.0f);
	//��A�y����Bar
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/wakuwaku.dds", 1280.0f, 720.0f);
	//�y���̃X�v���C�g
	m_sprite3 = NewGO<prefab::CSpriteRender>(0);
	m_sprite3->Init(L"sprite/pen.dds", 1280.0f, 720.0f);
	m_position = { -250.0f,49.0f,0.0f };//���W
	m_sprite3->SetPosition(m_position);//���W�𔽉f
	//�y���̃X�v���C�g�Q
	m_sprite12 = NewGO<prefab::CSpriteRender>(0);
	m_sprite12->Init(L"sprite/pen2.dds", 1280.0f, 720.0f);
	m_position = { -190.0f,49.0f,0.0f };//���W
	m_sprite12->SetPosition(m_position);//���W�𔽉f
	//�y���̃X�v���C�g�R
	m_sprite13 = NewGO<prefab::CSpriteRender>(0);
	m_sprite13->Init(L"sprite/pen3.dds", 1280.0f, 720.0f);
	m_position = { -130.0f,49.0f,0.0f };//���W
	m_sprite13->SetPosition(m_position);//���W�𔽉f
	//�y���̃X�v���C�g�S
	m_sprite14 = NewGO<prefab::CSpriteRender>(0);
	m_sprite14->Init(L"sprite/pen4.dds", 1280.0f, 720.0f);
	m_position = { -70.0f,49.0f,0.0f };//���W
	m_sprite14->SetPosition(m_position);//���W�𔽉f
	//�y���̃X�v���C�g�T
	m_sprite15 = NewGO<prefab::CSpriteRender>(0);
	m_sprite15->Init(L"sprite/pen5.dds", 1280.0f, 720.0f);
	m_position = { -10.0f,49.0f,0.0f };//���W
	m_sprite15->SetPosition(m_position);//���W�𔽉f
	//�y���̃X�v���C�g�U
	m_sprite16 = NewGO<prefab::CSpriteRender>(0);
	m_sprite16->Init(L"sprite/pen6.dds", 1280.0f, 720.0f);
	m_position = { 50.0f,49.0f,0.0f };//���W
	m_sprite16->SetPosition(m_position);//���W�𔽉f
	//HPBar�킭
	m_sprite4 = NewGO<prefab::CSpriteRender>(0);
	m_sprite4->Init(L"sprite/waku4.dds", 1280.0f, 720.0f);
	//HpWbar��
	m_sprite7 = NewGO<prefab::CSpriteRender>(0);
	m_sprite7->Init(L"sprite/HPWbar.dds", 1280.0f, 720.0f);
	//HPBbar��
	m_sprite18 = NewGO<prefab::CSpriteRender>(0);
	m_sprite18->Init(L"sprite/HPbar.dds", 1280.0f, 720.0f);
	//HPbar��
	m_sprite17 = NewGO<prefab::CSpriteRender>(0);
	m_sprite17->Init(L"sprite/HPBbar.dds", 1280.0f, 720.0f);
	//��̃X�v���C�g�P
	m_sprite5 = NewGO<prefab::CSpriteRender>(0);
	m_sprite5->Init(L"sprite/kao .dds", 1280.0f, 720.0f);
	m_position= { -200.0f, 151.5f, 0.0f };//���W
	m_sprite5->SetPosition(m_position);//���W�𔽉f
	//��̃X�v���C�g�Q
	m_sprite6 = NewGO<prefab::CSpriteRender>(0);
	m_sprite6->Init(L"sprite/kao2.dds", 1280.0f, 720.0f);
	m_position = { -130.0f, 151.5f, 0.0f };//���W
	m_sprite6->SetPosition(m_position);//���W�𔽉f
	//��̃X�v���C�g�R
	m_sprite8 = NewGO<prefab::CSpriteRender>(0);
	m_sprite8->Init(L"sprite/kao3.dds", 1280.0f, 720.0f);
	m_position = { -60.0f,151.5f,0.0f };//���W
	m_sprite8->SetPosition(m_position);//���W�͔��f/
	//��̃X�v���C�g�S
	m_sprite9 = NewGO<prefab::CSpriteRender>(0);
	m_sprite9->Init(L"sprite/kao4.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 10.0f,151.5f,0.0f };//���W
	m_sprite9->SetPosition(m_position);
	//��̃X�v���C�g5
	m_sprite10 = NewGO<prefab::CSpriteRender>(0);
	m_sprite10->Init(L"sprite/kao5.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 80.0f,151.5f,0.0f };//���W
	m_sprite10->SetPosition(m_position);
	//��̃X�v���C�g6
	m_sprite11 = NewGO<prefab::CSpriteRender>(0);
	m_sprite11->Init(L"sprite/kao6.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 150.0f,151.5f,0.0f };//���W
	m_sprite11->SetPosition(m_position);
	return true;

}
void Status::Update()
{
    //HP
	CVector3 LifeScale = CVector3::Zero;
	Player* player = FindGO<Player>();
	Player * player = Player::GetInstance();
	GameData * gamedata = GameData::GetInstance();
	//�����Q�[�W�𓮂���
	float DEF_Life = (float)gamedata->GetDEF_Life();
	float NOW_Life = (float)player->Life();

	//�����̂��v�Z
	float LifeY = NOW_Life / DEF_Life;

	//�����o�[�̐F���ς��
	float RED_Life = DEF_Life / 2.0f;
	//�����o�[�̐F�ς�
	if()
}
