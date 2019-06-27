#include "stdafx.h"
#include "Level.h"
#include "Background.h"
#include "EnemyChildren.h"
#include "EnemyWoman.h"
#include "EnemyMan.h"

Level* Level::m_instance = nullptr;
Level::Level()
{
	if (m_instance != nullptr) {
		std::abort(); //すでに出ているためクラッシュ
	}

	//このインスタンスを唯一のインスタンスとして記録する
	m_instance = this;
}


Level::~Level()
{
	//インスタンスが破棄されたので、nullptrを代入
	m_instance = nullptr;
}
bool Level::Start() {

		m_level.Init(L"level/level_02.tkl", [&](LevelObjectData& objData) {

			if (objData.EqualObjectName(L"ste")) {
				//背景
				Background* back = NewGO<Background>(0, "background");
				back->SetPosition(objData.position);
				back->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"kodomo120")) {
				//子供
				EnemyChildren* Children = NewGO<EnemyChildren>(0, "children");
				Children->SetPosition(objData.position);
				Children->SetRotation(objData.rotation);
				//フックしたのでtrueを返す。
				return true;
			}
			return false;
			});

	return true;
}
void Level::Update() {

}