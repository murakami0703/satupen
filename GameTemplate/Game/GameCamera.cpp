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
	CameraPos.Set(0.0f, 70.0f, -100.0f);
	return true;
}

void GameCamera::Update()
{
	//�J�����̍X�V
	//�v���C���[�̌����ɍ��킹�ē�����
	Player* player = FindGO<Player>("player");
	CVector3 target = player->Getm_Position();

	CVector3 st = player->Getm_stick();
	CVector3 CameraPosOld = CameraPos;
	//Y������̉�]
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * st.z);
	qRot.Multiply(CameraPos);

	CVector3 pos = target + CameraPos;
	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);
	//�J�����̍X�V
	MainCamera().Update();

}
