#pragma once
class Scope :public IGameObject
{
public:
	Scope();
	~Scope();
	bool Start();
	void Update();
	//�|�W�V������Ԃ��֐�
	CVector3 Scope::Getm_Position() {
		return m_position;
	}
private:
	prefab::CSpriteRender* m_sprite;
	CVector3 m_position = CVector3::Zero; // ���W�B
	CVector3 R_stick = CVector3::Zero; // �X�e�B�b�N

};

