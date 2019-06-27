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
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero; // ���W�B
	EnState m_state = Wait;
};

