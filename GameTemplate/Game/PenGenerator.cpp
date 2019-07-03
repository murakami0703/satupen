#include "stdafx.h"
#include "Pen.h"
#include "PenGenerator.h"
#include "GameData.h"

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
	GameData* gamedata = GameData::GetInstance();
	int Zandan = gamedata->GetZandan();

	if (Zandan > 0) {
		//残弾あるので打てまーーす。
		if (Pad(0).IsTrigger(enButtonLB1) || Pad(0).IsTrigger(enButtonRB1)) {
			NewGO<Pen>(0, "pen");
			gamedata->Zandannkasan(-1);
		}
	}
	else if (Zandan <= 0) {
		//撃てません！！！！！集めて！！！！テキスト表示
	}

}

