#include "stdafx.h"
#include "Level.h"
#include "Background.h"
#include "Window.h"
#include "Item.h"
#include "StoreItem.h"
#include "GameData.h"
//Enemy
#include "EnemyChildren.h"
#include "EnemyWoman.h"
#include "EnemyMan.h"
#include "EnemyDog.h"
#include "EnemyCat.h"
#include "EnemyBird.h"


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

		int EnemyCount = 0;
		int ItemCount = 0;
		//@todo for test m_level.Init(L"level/level_02.tkl", [&](LevelObjectData& objData) {
		m_level.Init(L"level/level_04.tkl", [&](LevelObjectData& objData) {
			if (objData.EqualObjectName(L"stage01")) {
				//背景
				Background* back = NewGO<Background>(0, "background");
				back->SetPosition(objData.position);
				back->SetScale(objData.scale);
				return true;
			}
			/////////////////////////////////////////////////
			//敵やでぇ
			if (objData.EqualObjectName(L"kodomo120")) {
				
				//子供
				EnemyChildren* Children = NewGO<EnemyChildren>(0, "children");
				Children->SetPosition(objData.position);
				Children->SetRotation(objData.rotation);
				EnemyCount++;
				
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"otoko")) {
				//男
				EnemyMan* Man = NewGO<EnemyMan>(0, "man");
				Man->SetPosition(objData.position);
				Man->SetRotation(objData.rotation);
				EnemyCount++;
				//フックしたwomanのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"onna")) {
				//女
				EnemyWoman* Woman = NewGO<EnemyWoman>(0, "");
				Woman->SetPosition(objData.position);
				Woman->SetRotation(objData.rotation);
				EnemyCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"inuu")) {
				//犬
				EnemyDog* Dog = NewGO<EnemyDog>(0, "dog");
				Dog->SetPosition(objData.position);
				Dog->SetRotation(objData.rotation);
				Dog->SetScale(objData.scale);

				EnemyCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"neko")) {
				//猫
				EnemyCat* Cat = NewGO<EnemyCat>(0, "cat");
				Cat->SetPosition(objData.position);
				Cat->SetRotation(objData.rotation);
				Cat->SetScale(objData.scale);

				EnemyCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"karasuu")) {
				//鳥
				EnemyBird* Bird = NewGO<EnemyBird>(0, "bird");
				Bird->SetPosition(objData.position);
				Bird->SetRotation(objData.rotation);
				Bird->SetScale(objData.scale);

				EnemyCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			/////////////////////////////////////////////////


			if (objData.EqualObjectName(L"S_mado")) {
				//窓
				Window* windo = NewGO<Window>(0, "window");
				windo->SetPosition(objData.position);
				windo->SetRotation(objData.rotation);
				windo->SetScale(objData.scale);
				ItemCount++;
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
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Big_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_black);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Big_rad")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_rad);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Blackstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackstripe);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Blackteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackteapot);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Bulegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Bulegas);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Buleteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Buleteapot);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Chocodonatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Chocodonatu);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Currybread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Currybread);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Donatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Donatu);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Dumpling")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Dumpling);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Eggbread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Eggbread);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"GGrapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::GGrapes);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Goldring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Goldring);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Grapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Grapes);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Greenteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Greenteapot);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Konbu_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Konbu_onigiri);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Matcha_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Matcha_ole);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Mini_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_black);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Mini_red")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_red);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Muscat")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Muscat);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Orange")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orange);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Orangegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangegas);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Orangestripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangestripe);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Pinkgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Pinkgas);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Redstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Redstripe);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Skinring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Skinring);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Strawberry_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Strawberry_ole);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Ume_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Ume_onigiri);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Yellowgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowgas);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Yellowstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowstripe);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			if (objData.EqualObjectName(L"Yellowteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowteapot);
				ItemCount++;
				//フックしたのでtrueを返す。
				return true;
			}
			//ここまで
			////////////////////////////////////////

			return false;
			});
			//敵の数をGameDataに教える
			GameData * gamedata = GameData::GetInstance();
			gamedata->EnemyCounterSet(EnemyCount);
			gamedata->ItemCounterSet(ItemCount);

	return true;
}
void Level::Update() {

}