#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
}


Title::~Title()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite1);
	DeleteGO(m_sprite2);
	DeleteGO(m_sprite3);
	DeleteGO(m_sprite4);
	DeleteGO(m_sprite5);
	DeleteGO(m_sprite6);
}

bool Title::Start()
{
	//�X�v���C�g������
	//�X�v���C�g�@�Ԃ��o�b�N
	m_sprite= NewGO<prefab::CSpriteRender>(1);
	m_sprite->Init(L"sprite/Titel/saturikuBG.dds", 1280.0f, 720.0f);
	//�X�v���C�g�@���肭�̃y��
	m_sprite1 = NewGO<prefab::CSpriteRender>(4);
	m_sprite1->Init(L"sprite/Titel/saturikupen.dds", 500.0f, 150.0f);
	m_position = { 0.0f,-30.0f,0.0f };
	m_sprite1->SetPosition(m_position);
	m_sprite1->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	//�X�v���C�g�@�E�C�̌�
	m_sprite2 = NewGO<prefab::CSpriteRender>(3);
	m_sprite2->Init(L"sprite/Titel/saturiku.dds", 970.0f, 410.0f);
	m_position = { 0.0f,300.0f,0.0f };
	m_sprite2->SetPosition(m_position);
	//�X�v���C�g�@�E�C�̂؂�
	m_sprite3 = NewGO<prefab::CSpriteRender>(2);
	m_sprite3->Init(L"sprite/Titel/saturikunopen.dds", 300.0f, 300.0f);
	m_position = PenDef;
	m_sprite3->SetPosition(m_position);
	//�X�v���C�g�@��
	m_sprite4 = NewGO<prefab::CSpriteRender>(5);
	m_sprite4->Init(L"sprite/Titel/ti.dds", 1280.0f, 720.0f);
	m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	//�X�v���C�g�@�E�C���n�߂�
	m_sprite5 = NewGO<prefab::CSpriteRender>(6);
	m_sprite5->Init(L"sprite/Titel/hazimeru.dds", 350.0f, 100.0f);
	m_position = { 300.0f,-200.0f,0.0f };
	m_sprite5->SetPosition(m_position);
	//�X�v���C�g�@��������
	m_sprite6 = NewGO<prefab::CSpriteRender>(7);
	m_sprite6->Init(L"sprite/Titel/zange.dds", 300.0f, 100.0f);
	m_position = { 300.0f,-280.0f,0.0f };
	m_sprite6->SetPosition(m_position);

	return true;
}
	

void Title::Update()
{
	switch (m_state)
	{
	case Title::enState_new:
	{
		CVector3 satupos1 = m_sprite2->GetPosition();

		if (satupos1.y >= movepos.y) {
			satupos1.y -= 5.0f;
		}
		else {
			satupos1 = movepos;
			m_state = enState_2;
		}
		m_sprite2->SetPosition(satupos1);

		break;
	}
	case Title::enState_2:
	{

		//�h���铮��B
		CVector3 penpos = m_sprite3->GetPosition();

		if (Pentimer < DropLimit) {
			//�����Ă���
			CVector3 pos = PenDef - PenDropPos; //�����ʒu�ƖڕW�ʒu�̌v�Z
			pos /= DropLimit; //���������Ԃ�1�t���[���ł̈ړ����������܂�
			penpos -= pos;
		}
		else if (Pentimer < DropLimit+RemoveLimit) {
			//�߂�
			CVector3 pos1 = PenDropPos - PenRemovePos;//�����ʒu�ƖڕW�ʒu�̌v�Z
			pos1 /= RemoveLimit; //���������Ԃ�1�t���[���ł̈ړ����������܂�
			pos1 *= -1.0f;
			penpos += pos1;
		}
		else {
			//�X�e�[�g�ύX
			m_state = enState_3;
		}

		Pentimer++;
		m_sprite3->SetPosition(penpos);

		break;
	}
	case Title::enState_3:
	{
		CVector3 tipos = m_sprite4->GetPosition();
		m_sprite4->SetMulColor({ 1.0f,1.0,1.0f,1.0f });

		m_state = enState_4;
	}
	case Title::enState_4:
		CVector3 saturikuH = m_sprite1->GetPosition();
			m_sprite1->SetMulColor({ 1.0,1.0f,1.0f,SP1 });
			SP1 += 0.05f;
			if (SP1 >= 1.0f) {
				SP1 = 1.0f;
			}
	}
	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}