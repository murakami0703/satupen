#include "stdafx.h"
#include "Pen.h"
#include "PenGenerator.h"

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

	if (Pad(0).IsTrigger(enButtonLB1) || Pad(0).IsTrigger(enButtonRB1)) {
		NewGO<Pen>(0, "pen");
	}
}

