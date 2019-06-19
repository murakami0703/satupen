#include "stdafx.h"
#include "Player.h"
#include "GameCamera.h"


GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}

bool GameCamera::Start()
{
	//�j�A�N���b�v�ƃt�@�[�N���b�v�̐ݒ�B
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(15000.0f);
	//�J������ݒ�B

	//�x�N�g���̐ݒ�
	//CameraPos.Set(0.0f, 20.0f, -50.0f);
	return true;
}

void GameCamera::Update()
{
	//�J�����̍X�V
	//�v���C���[�̌����ɍ��킹�ē�����
	Player* player = FindGO<Player>("player");
	CVector3 target = player->Getm_Position();
	CVector3 vBase = { 0.0f,0.0f,1.0f };
	CVector3 vyoBase = { -1.0f,0.0f,0.0f };
	CQuaternion p_qRot = player->Getm_Rotation();
	p_qRot.Apply(vBase);
	p_qRot.Apply(vyoBase);
	CVector3 vpos = vBase * -50.0f;

	CVector3 pos = vpos + target;
	pos.y = pos.y + 20.0f;
	target.y = 30.0f;
	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);
	
	//�J�����̍X�V
	MainCamera().Update();
	CVector3 cameraposOld = CameraPos;
}
