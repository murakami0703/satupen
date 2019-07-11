#include "stdafx.h"
#include "GameData.h"

GameData* GameData::m_instance = nullptr;

GameData::GameData()
{
	if (m_instance != nullptr) {
		std::abort(); //���łɏo�Ă��邽�߃N���b�V��
	}

	//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
	m_instance = this;

}

GameData::~GameData()
{
	//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
	m_instance = nullptr;

}
int GameData::GetResultDead(ResultDead dead)
{
	//Result�p	�J�E���g��Ԃ��B
	switch (dead)
	{
	case GameData::DeadMan:
		return Man;
		break;
	case GameData::DeadWoman:
		return Woman;
		break;
	case GameData::DeadChildren:
		return Children;
		break;
	case GameData::DeadDog:
		return Dog;
		break;
	case GameData::DeadCat:
		return Cat;
		break;
	case GameData::DeadBird:
		return Bird;
		break;
	case GameData::DeadAnimals:
		return Animals;
		break;
	case GameData::DesItem:
		return Item;
		break;
	case GameData::DesBigItem:
		return BigItem;
		break;
	}
}
void GameData::ResultDeadkasan(ResultDead dead)
{
	//Result�p �����ɐݒ肵���l�ɉ��Z����B
	switch (dead)
	{
	case GameData::DeadMan:
		Man++;
		if (MAX_Dead < Man) {
			Man = MAX_Dead;
		}
		break;
	case GameData::DeadWoman:
		Woman++;
		if (MAX_Dead < Woman) {
			Woman = MAX_Dead;
		}
		break;
	case GameData::DeadChildren:
		Children++;
		if (MAX_Dead < Children) {
			Children = MAX_Dead;
		}
		break;
	case GameData::DeadDog:
		Dog++;
		if (MAX_Dead < Dog) {
			Dog = MAX_Dead;
		}
		break;
	case GameData::DeadCat:
		Cat++;
		if (MAX_Dead < Cat) {
			Cat = MAX_Dead;
		}
		break;
	case GameData::DeadBird:
		Bird++;
		if (MAX_Dead < Bird) {
			Bird = MAX_Dead;
		}
		break;
	case GameData::DeadAnimals:
		Animals++;
		if (MAX_Dead < Animals) {
			Animals = MAX_Dead;
		}
		break;
	case GameData::DesItem:
		Item++;
		if (MAX_Dead < Item) {
			Item = MAX_Dead;
		}
		break;
	case GameData::DesBigItem:
		BigItem++;
		if (MAX_Dead < BigItem) {
			BigItem = MAX_Dead;
		}
		break;
	}

}

