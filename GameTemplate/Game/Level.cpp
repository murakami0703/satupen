#include "stdafx.h"
#include "Level.h"
#include "Background.h"
#include "EnemyChildren.h"
#include "EnemyWoman.h"
#include "EnemyMan.h"
#include "Window.h"
#include "Item.h"
#include "StoreItem.h"

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

		m_level.Init(L"level/level_05.tkl", [&](LevelObjectData& objData) {

			if (objData.EqualObjectName(L"sute")) {
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
			if (objData.EqualObjectName(L"S_mado")) {
				//窓
				Window* windo = NewGO<Window>(0, "window");
				windo->SetPosition(objData.position);
				windo->SetRotation(objData.rotation);
				windo->SetScale(objData.scale);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Item")) {
				//弾
				Item* item = NewGO<Item>(0, "it");
				item->SetPosition(objData.position);
				item->SetRotation(objData.rotation);
				//フックしたのでtrueを返す。
				return true;
			}

			///////////////////////////////////////
			//ここからコンビニのアイテム
			if (objData.EqualObjectName(L"Apple")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Apple);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Big_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_black);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Big_rad")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_rad);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Blackstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackstripe);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Blackteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackteapot);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Bulegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Bulegas);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Buleteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Buleteapot);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Chocodonatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Chocodonatu);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Currybread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Currybread);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Donatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Donatu);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Dumpling")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Dumpling);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Eggbread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Eggbread);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"GGrapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::GGrapes);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Goldring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Goldring);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Grapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Grapes);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Greenteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Greenteapot);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Konbu_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Konbu_onigiri);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Matcha_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Matcha_ole);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Mini_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_black);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Mini_red")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_red);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Muscat")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Muscat);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Orange")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orange);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Orangegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangegas);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Orangestripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangestripe);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Pinkgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Pinkgas);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Redstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Redstripe);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Skinring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Skinring);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Strawberry_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Strawberry_ole);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Ume_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Ume_onigiri);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Yellowgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowgas);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Yellowstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowstripe);
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Yellowteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowteapot);
				//フックしたのでtrueを返す。
				return true;
			}
			//ここまで
			////////////////////////////////////////
			return false;
			});

	return true;
}
void Level::Update() {

}