#include "stdafx.h"
#include "Pen.h"
#include "PenGenerator.h"
#include "GameData.h"
#include "Player.h"

PenGenerator* PenGenerator::m_instance = nullptr;

PenGenerator::PenGenerator()
{
	if (m_instance != nullptr) {
		std::abort(); //すでに出ているためクラッシュ
	}

	//このインスタンスを唯一のインスタンスとして記録する
	m_instance = this;
}


PenGenerator::~PenGenerator()
{
	//インスタンスが破棄されたので、nullptrを代入
	m_instance = nullptr;
}

bool PenGenerator::Start()
{

	return true;
}
void PenGenerator::Update()
{
	Player* pl = FindGO<Player>("player");
	GameData* gamedata = GameData::GetInstance();
	int Zandan = gamedata->GetZandan();

	if (Zandan > 0) {
		//残弾ある。
		if(pl->IsSetup() == true)
			//構えてる。
		if (Pad(0).IsTrigger(enButtonRB1)) {
			//発射
			m_isFire = true;
			NewGO<Pen>(0, "pen");
			gamedata->Zandannkasan(-1);
		}
		else {
			m_isFire = false;

		}
	}
	else if (Zandan <= 0) {
		//撃てません！！！！！集めて！！！！テキスト表示
	}
	
}

