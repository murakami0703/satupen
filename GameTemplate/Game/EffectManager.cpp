#include "stdafx.h"
#include "EffectManager.h"
#include "EffectPlay.h"

EffectManager* EffectManager::m_instance = nullptr;

EffectManager::EffectManager()
{

	if (m_instance != nullptr) {
		std::abort(); //���łɏo�Ă��邽�߃N���b�V��
	}

	//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
	m_instance = this;
}


EffectManager::~EffectManager()
{
	//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
	m_instance = nullptr;
}

//�G�t�F�N�g�Đ�����
void EffectManager::EffectPlayer(Effect EF, CVector3 position, CVector3 scale) {
	//�쐬
	EffectPlay* p = NewGO<EffectPlay>(0);
	//���O�����������Ă���
	int len = (int)wcslen(DetaBase[EF]);
	for (int x = 0; x < len+1; x++) {
		EF_Name[x] = DetaBase[EF][x];
	}
	//�ݒ�
	p->SetAnimation(EF_Name);
	p->SetPosition(position);
	p->SetScale(scale);

}