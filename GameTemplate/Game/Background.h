#pragma once
class Background : public IGameObject
{
public:
	Background();
	~Background();
	bool Start();
	void Update();

private:
	prefab::CSkinModelRender* skinModelRender = nullptr; //�X�L�����f�������_�[
	CPhysicsStaticObject m_physicsStaticObject; //�ÓI�����I�u�W�F�N�g
};

