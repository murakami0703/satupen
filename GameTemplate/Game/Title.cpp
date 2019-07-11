#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Result.h"
#include "Load.h"

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
	DeleteGO(m_sprite7);

	//���y����
	DeleteGO(m_sound);//�o�b�N�T�E���h
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

	//�X�v���C�g�@�߂��d�˂�
	m_sprite5 = NewGO<prefab::CSpriteRender>(6);
	m_sprite5->Init(L"sprite/Titel/hazimeru1.dds", 350.0f, 100.0f);
	m_position = { 300.0f,-200.0f,0.0f };
	m_sprite5->SetPosition(m_position);

	//�X�v���C�g�@��������
	m_sprite6 = NewGO<prefab::CSpriteRender>(7);
	m_sprite6->Init(L"sprite/Titel/zange.dds", 300.0f, 100.0f);
	m_position = { 280.0f,-280.0f,0.0f };
	m_sprite6->SetPosition(m_position);

	//�X�v���C�g�@���
	m_sprite7 = NewGO<prefab::CSpriteRender>(8);
	m_sprite7->Init(L"sprite/Titel/yazirusi.dds", 100.0f, 100.0f);
	m_position = { 100.0f,-200.0f,0.0f };
	m_sprite7->SetPosition(m_position);
	

	//���y�ݒ�
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/aaa.wav");
	m_sound->Play(true);
	m_sound->SetVolume(1.0f);
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
		else if (Pentimer < DropLimit + RemoveLimit) {
			//�߂�
			CVector3 pos1 = PenDropPos - PenRemovePos;//�����ʒu�ƖڕW�ʒu�̌v�Z
			pos1 /= RemoveLimit; //���������Ԃ�1�t���[���ł̈ړ����������܂�
			pos1 *= -1.0f;
			penpos += pos1;
			if (Sasuotoflag == false) {
				m_sound2 = NewGO<prefab::CSoundSource>(0);
				m_sound2->Init(L"sound/sasu3.wav");
				m_sound2->Play(false);
				m_sound2->SetVolume(1.0f);
				Sasuotoflag = true;
			}
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
		//���̉�
		m_sound4 = NewGO<prefab::CSoundSource>(0);
		m_sound4->Init(L"sound/blood_flow.wav");
		m_sound4->Play(false);
		m_sound4->SetVolume(1.0f);
		Tiflag = true;

		m_state = enState_4;
	}
	case Title::enState_4:
	{
		CVector3 saturikuH = m_sprite1->GetPosition();
		m_sprite1->SetMulColor({ 1.0,1.0f,1.0f,SP1 });
		SP1 += 0.05f;
		if (SP1 >= 1.0f) {
			SP1 = 1.0f;
		}
	}
	case Title::enState_5:
	{
		switch (m_Sart)
		{
		case Title::enStart_new:
		{
			//���ꂪ�߂��d�˂�B5
			m_sprite7->SetPosition({ 100.0f,-200.0f,0.0f });
			m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
			m_sprite6->SetMulColor({ 0.5f,0.5f,0.5f,0.5f });
			break;
		}
		case Title::enStart_restart:
		{
			//���ꂪ��������B6
			m_sprite7->SetPosition({ 100.0f,-280.0f,0.0f });
			m_sprite5->SetMulColor({ 0.5f,0.5f,0.5f,0.5f });
			m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
			break;
		}
		}
		if (Pad(0).IsTrigger(enButtonDown) || Pad(0).IsTrigger(enButtonUp)) {
			if (m_Sart == enStart_new) {
				m_Sart = enStart_restart;

			}
			else if (m_Sart == enStart_restart) {
				m_Sart = enStart_new;
			}
			//�I�����邽�тɉ�����悤�ɂ���
			m_sound3 = NewGO<prefab::CSoundSource>(0);
			m_sound3->Init(L"sound/ketteion.wav");
			m_sound3->Play(false);
			m_sound3->SetVolume(1.0f);

		}
		if (Pad(0).IsTrigger(enButtonStart)) {
			NewGO<Game>(0, "game");
			DeleteGO(this);

		}

	}
	}
	/*if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Load>(0, "load");
		DeleteGO(this);
	}*/
}