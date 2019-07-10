#pragma once
class StoreItem : public IGameObject
{
public:
	StoreItem();
	~StoreItem();
	enum EnState {
		Apple,
		Big_black,
		Big_rad,
		Blackstripe,
		Blackteapot,
		Bulegas,
		Buleteapot,
		Chocodonatu,
		Currybread,
		Donatu,
		Dumpling,
		Eggbread,
		GGrapes,
		Goldring,
		Grapes,
		Greenteapot,
		Konbu_onigiri,
		Matcha_ole,
		Mini_black,
		Mini_red,
		Muscat,
		Orange,
		Orangegas,
		Orangestripe,
		Pinkgas,
		Redstripe,
		Skinring,
		Strawberry_ole,
		Ume_onigiri,
		Yellowgas,
		Yellowstripe,
		Yellowteapot,
		Num,
	};

	bool Start();
	void Update();

	//���W��ݒ�B
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}
	void SetScale(CVector3 sca)
	{
		m_scale = sca;
	}
	void SetState(EnState state) {
		m_state = state;
	}
private:

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	prefab::CSoundSource* m_sound = nullptr; //�����ꂽ�Ƃ��̉�
	CVector3 m_position = CVector3::Zero; // ���W�B
	CQuaternion m_rotation = CQuaternion::Identity; //��]�B
	CVector3 m_scale = CVector3::One; // �X�P�[��

	CPhysicsStaticObject m_physicsStaticObject; //�ÓI�����I�u�W�F�N�g

	EnState m_state = Num;
};

