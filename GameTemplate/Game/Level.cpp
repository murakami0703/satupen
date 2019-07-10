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

		m_level.Init(L"level/level_05.tkl", [&](LevelObjectData& objData) {

			if (objData.EqualObjectName(L"sute")) {
				//�w�i
				Background* back = NewGO<Background>(0, "background");
				back->SetPosition(objData.position);
				back->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"kodomo120")) {
				//�q��
				EnemyChildren* Children = NewGO<EnemyChildren>(0, "children");
				Children->SetPosition(objData.position);
				Children->SetRotation(objData.rotation);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"S_mado")) {
				//��
				Window* windo = NewGO<Window>(0, "window");
				windo->SetPosition(objData.position);
				windo->SetRotation(objData.rotation);
				windo->SetScale(objData.scale);
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
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Big_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_black);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Big_rad")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Big_rad);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Blackstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackstripe);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Blackteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Blackteapot);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Bulegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Bulegas);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Buleteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Buleteapot);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Chocodonatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Chocodonatu);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Currybread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Currybread);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Donatu")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Donatu);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Dumpling")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Dumpling);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Eggbread")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Eggbread);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"GGrapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::GGrapes);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Goldring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Goldring);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Grapes")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Grapes);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Greenteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Greenteapot);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Konbu_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Konbu_onigiri);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Matcha_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Matcha_ole);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Mini_black")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_black);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Mini_red")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Mini_red);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Muscat")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Muscat);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Orange")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orange);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Orangegas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangegas);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Orangestripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Orangestripe);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Pinkgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Pinkgas);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Redstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Redstripe);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Skinring")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Skinring);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Strawberry_ole")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Strawberry_ole);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Ume_onigiri")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Ume_onigiri);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Yellowgas")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowgas);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Yellowstripe")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowstripe);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			if (objData.EqualObjectName(L"Yellowteapot")) {
				StoreItem* store = NewGO<StoreItem>(0, "store");
				store->SetPosition(objData.position);
				store->SetRotation(objData.rotation);
				store->SetScale(objData.scale);
				store->SetState(StoreItem::Yellowteapot);
				//�t�b�N�����̂�true��Ԃ��B
				return true;
			}
			//�����܂�
			////////////////////////////////////////
			return false;
			});

	return true;
}
void Level::Update() {

}