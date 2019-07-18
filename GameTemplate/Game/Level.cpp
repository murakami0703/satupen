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
		std::abort(); //���łɏo�Ă��邽�߃N���b�V��
	}

	//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
	m_instance = this;
}


Level::~Level()
{
	//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
	m_instance = nullptr;
}
bool Level::Start() {

		int EnemyCount = 0;
		int ItemCount = 0;
		//@todo for test m_level.Init(L"level/level_02.tkl", [&](LevelObjectData& objData) {
		m_level.Init(L"level/level_04.tkl", [&](LevelObjectData& objData) {
			if (objData.EqualObjectName(L"stage01")) {
				//�w�i
				Background* back = NewGO<Background>(0, "background");
				back->SetPosition(objData.position);
				back->SetScale(objData.scale);
				return true;
			}
			/////////////////////////////////////////////////
			//�G��ł�
			if (objData.EqualObjectName(L"kodomo120")) {
				
				//�q��
				EnemyChildren* Children = NewGO<EnemyChildren>(0, "children");
				Children->SetPosition(objData.position);
				Children->SetRotation(objData.rotation);
				EnemyCount++;
				
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"otoko")) {
				//�j
				EnemyMan* Man = NewGO<EnemyMan>(0, "man");
				Man->SetPosition(objData.position);
				Man->SetRotation(objData.rotation);
				EnemyCount++;
				//�t�b�N����woman�̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"onna")) {
				//��
				EnemyWoman* Woman = NewGO<EnemyWoman>(0, "");
				Woman->SetPosition(objData.position);
				Woman->SetRotation(objData.rotation);
				EnemyCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"inuu")) {
				//��
				EnemyDog* Dog = NewGO<EnemyDog>(0, "dog");
				Dog->SetPosition(objData.position);
				Dog->SetRotation(objData.rotation);
				Dog->SetScale(objData.scale);

				EnemyCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"neko")) {
				//�L
				EnemyCat* Cat = NewGO<EnemyCat>(0, "cat");
				Cat->SetPosition(objData.position);
				Cat->SetRotation(objData.rotation);
				Cat->SetScale(objData.scale);

				EnemyCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"karasuu")) {
				//��
				EnemyBird* Bird = NewGO<EnemyBird>(0, "bird");
				Bird->SetPosition(objData.position);
				Bird->SetRotation(objData.rotation);
				Bird->SetScale(objData.scale);

				EnemyCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			/////////////////////////////////////////////////


			if (objData.EqualObjectName(L"S_mado")) {
				//��
				Window* windo = NewGO<Window>(0, "window");
				windo->SetPosition(objData.position);
				windo->SetRotation(objData.rotation);
				windo->SetScale(objData.scale);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Item")) {
				//�e
				Item* item = NewGO<Item>(0, "it");
				item->SetPosition(objData.position);
				item->SetRotation(objData.rotation);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}

			///////////////////////////////////////
			//��������R���r�j�̃A�C�e��
			if (objData.EqualObjectName(L"Apple")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Apple);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Big_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_black);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Big_rad")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_rad);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Blackstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackstripe);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Blackteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackteapot);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Bulegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Bulegas);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Buleteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Buleteapot);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Chocodonatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Chocodonatu);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Currybread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Currybread);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Donatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Donatu);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Dumpling")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Dumpling);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Eggbread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Eggbread);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"GGrapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::GGrapes);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Goldring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Goldring);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Grapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Grapes);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Greenteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Greenteapot);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Konbu_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Konbu_onigiri);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Matcha_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Matcha_ole);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Mini_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_black);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Mini_red")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_red);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Muscat")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Muscat);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Orange")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orange);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Orangegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangegas);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Orangestripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangestripe);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Pinkgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Pinkgas);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Redstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Redstripe);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Skinring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Skinring);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Strawberry_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Strawberry_ole);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Ume_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Ume_onigiri);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Yellowgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowgas);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Yellowstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowstripe);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Yellowteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowteapot);
				ItemCount++;
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			//�����܂�
			////////////////////////////////////////

			return false;
			});
			//�G�̐���GameData�ɋ�����
			GameData * gamedata = GameData::GetInstance();
			gamedata->EnemyCounterSet(EnemyCount);
			gamedata->ItemCounterSet(ItemCount);

	return true;
}
void Level::Update() {

}