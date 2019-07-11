#include "stdafx.h"
#include "Result.h"
#include "Game.h"

Result::Result()
{
}


Result::~Result()
{
	DeleteGO(m_sprite); //背景
	DeleteGO(m_sprite1);//総合　250*150
	DeleteGO(m_sprite2);//罪人度　330*150
	DeleteGO(m_sprite3);//Tti
	DeleteGO(m_sprite4);//ti2
	DeleteGO(m_sprite5);//善人度　330*150
	DeleteGO(m_sprite6);//ZH
	DeleteGO(m_sprite7);//光　1280*720
	DeleteGO(m_sprite8);//あなたは　400*150

	DeleteGO(m_font);
	DeleteGO(m_font2);

}
bool Result::Start()
{
	//スプライト初期化　　背景
	m_sprite = NewGO<prefab::CSpriteRender>(1);
	m_sprite->Init(L"sprite/Result/RH.dds", 1280.0f, 720.0f);

	//総合
	m_sprite1 = NewGO<prefab::CSpriteRender>(1);
	m_sprite1->Init(L"sprite/Result/sougou.dds", 250.0f,150.0f);
	m_postion = SDrop;
	m_sprite1->SetPosition(m_postion);
	//m_sprite1->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	
	//罪人度
	m_sprite2 = NewGO<prefab::CSpriteRender>(1);
	m_sprite2->Init(L"sprite/Result/tumido.dds", 330.0f, 150.0f);
	m_postion = { -800.0f,120.0f,0.0f };
	m_sprite2->SetPosition(m_postion);
	//m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//Tti
	m_sprite3 = NewGO<prefab::CSpriteRender>(1);
	m_sprite3->Init(L"sprite/Result/Tti.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite3->SetPosition(m_postion);
	m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//ti2
	m_sprite4 = NewGO<prefab::CSpriteRender>(1);
	m_sprite4->Init(L"sprite/Result/ti2.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite4->SetPosition(m_postion);
	m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//善人度
	m_sprite5 = NewGO<prefab::CSpriteRender>(1);
	m_sprite5->Init(L"sprite/Result/zennindo.dds", 330.0f, 150.0f);
	m_postion = { -800.0f,-80.0f,0.0f };
	m_sprite5->SetPosition(m_postion);
	//m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//ZH
	m_sprite6 = NewGO<prefab::CSpriteRender>(1);
	m_sprite6->Init(L"sprite/Result/ZH.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite6->SetPosition(m_postion);
	m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//光
	m_sprite7 = NewGO<prefab::CSpriteRender>(1);
	m_sprite7->Init(L"sprite/Result/hikari.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite7->SetPosition(m_postion);
	m_sprite7->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//あなた
	m_sprite8 = NewGO<prefab::CSpriteRender>(1);
	m_sprite8->Init(L"sprite/Result/anata.dds", 400.0f, 150.0f);
	m_postion = { -400.0f,-300.0f,0.0f };
	m_sprite8->SetPosition(m_postion);
	m_sprite8->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	m_font = NewGO<prefab::CFontRender>(2);
	m_font2 = NewGO<prefab::CFontRender>(2);
	return true;
}
void Result::Update()
{
	switch (m_start)
    {
	case Result::enStart_new:
	{
		//総合
		CVector3 soupos = m_sprite1->GetPosition();//総合
		if (Sugoutimer < DropLimitS) {
			//落ちてくる
			CVector3 pos = SDrop - movepos;//初期位置から目的の位置へ降りてくてくる
			pos /= DropLimitS;//距離÷時間
			soupos -= pos;

		}
		else if (Sugoutimer < DropLimitS + RemoveLimitS) {
			//落ちる時間と戻る時間を足す。
			//戻り。
			CVector3 pos1 = SDrop - SDroppos;//初期位置
			pos1 /= RemoveLimitS;
			soupos += pos1;
		}
		else {
			m_start = enStart_1;
		}

		Sugoutimer++;
		m_sprite1->SetPosition(soupos);
		break;
	}

	case Result::enStart_1:
	{
		//罪度
		CVector3 tumipos = m_sprite2->GetPosition();//罪度
		if (tumipos.x <= tumipos2.x) {

			tumipos.x += 10.0f;
		}
		else {
			tumipos = tumipos2;
			m_start = enStart_2;
		}
		m_sprite2->SetPosition(tumipos);
		break;
	}
	case Result::enStart_2:
	{
		////血
		CVector3 Ttipos = m_sprite3->GetPosition();//罪人の血
		m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = enStart_3;
		break;
	}

	case Result::enStart_3:
	{
		//善人度
		CVector3 zenpos = m_sprite5->GetPosition();//善人度
		if (zenpos.x <= zenpos2.x) {
			zenpos.x += 10.0f;
		}
		else {
			zenpos = zenpos2;
			m_start = enStart_4;
		}
		m_sprite5->SetPosition(zenpos);
		break;
		
	}
	case Result::enStart_4:
	{
		//光
		CVector3 ZH = m_sprite6->GetPosition();//善人の光
		m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = enStart_5;
		break;
	}
	case Result::enStart_5:
	{
		//罪人
		if (Tumipaflag == false) {
			TT++;
			if (TT <= Tu) {
				wchar_t text[256];
				swprintf(text, L"%02d%%",TT);
				m_font->SetText(text);
				m_font->SetPosition({ 150.0f,100.0f });
				m_font->SetPivot({ 0.0f,0.0f });
				m_font->SetScale(3.5f);
			}
			else {
				Tumipaflag = true;
			}
		}
		else if (Tumipaflag == true) {
			m_start = enStart_6;
		}
		break;

	}
	case Result::enStart_6:
	{
		//血全体のやつ
		CVector3 titi = m_sprite4->GetPosition();
		m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = enStart_7;
		break;
	}
	case Result::enStart_7:
	{
		//善人度パーセント
		if (Zenpaflag == false) {
			ZZ++;
			if(ZZ<=Ze){
				wchar_t text[256];
				swprintf(text, L"%02d%%", ZZ);
				m_font2->SetText(text);
				m_font2->SetPosition({ 150.0f,-150.0f });
				m_font2->SetPivot({ 0.0f,0.0f });
				m_font2->SetScale(3.5f);
			}
			else {
				Zenpaflag = true;
			}
		}
		else if(Zenpaflag == true){
			m_start = enStart_8;
		}
		break;
	}
	case Result::enStart_8:
	{
		//光パーセントがでたときの　全体の光
		CVector3 Hkari = m_sprite7->GetPosition();
		m_sprite7->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = enStart_9;
		break;
	}
	case Result::enStart_9:
	{
		//あなたは徐々に出していくやつうう
		CVector3 anataha = m_sprite8->GetPosition();
		m_sprite8->SetMulColor({ 1.0,1.0f,1.0f,Ana });
		Ana += 0.05f;
		if (Ana >= 1.0f) {
			Ana = 1.0f;
		}
		break;
	}
	case Result::enStart_10:
	{
		//一定時間経過またはボタンを押すとゲームの選択ができる
		//フェードイン
	}

    }
	
}