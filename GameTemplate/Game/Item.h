#pragma once
class Item : public IGameObject
{
public:
	Item();
	~Item();
	enum EnState {
		Wait,	//�u���ꂽ�܂�
		Follow,	//�v���C���[�ɏW�܂��
	};
	bool Start();
	void Update();
	//���W��ݒ�B
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	//��]��ݒ�B
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSoundSource* m_sound = nullptr;//�A�C�e�����E�������B
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity;			//��]�B
	EnState m_state = Wait;

	const float itemlength = 100.0f;
	const float itemspeed = 8.0f;
	const float itemrecovery = 3.0f;
}; 

