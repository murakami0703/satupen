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

		m_level.Init(L"level/level_02.tkl", [&](LevelObjectData& objData) {

			if (objData.EqualObjectName(L"ste")) {
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
			return false;
			});

	return true;
}
void Level::Update() {

}