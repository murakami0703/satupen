#pragma once
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	CVector3 CameraPos = CVector3::Zero;
	int timer = 0;
};

