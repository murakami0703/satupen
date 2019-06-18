#pragma once
class Background : public IGameObject
{
public:
	Background();
	~Background();
	bool Start();
	void Update();

private:
	prefab::CSkinModelRender* skinModelRender = nullptr; //スキンモデルレンダー
	CPhysicsStaticObject m_physicsStaticObject; //静的物理オブジェクト
};

