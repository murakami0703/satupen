#include "stdafx.h"
#include "EffectPlay.h"

EffectPlay::EffectPlay()
{
}


EffectPlay::~EffectPlay()
{
}

bool EffectPlay::Start()
{
	//�G�t�F�N�g�̃C���X�^���X�̍쐬�B
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	effect->Play(animation.c_str());	//�Đ�
	effect->SetScale(scale);
	effect->SetPosition(position);

	return true;
}
