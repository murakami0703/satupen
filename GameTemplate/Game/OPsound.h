#pragma once
class OPsound:public IGameObject
{
	static OPsound* m_instance;
public:
	OPsound();
	~OPsound();

	bool Start();
	
	//インスタンスの取得
	static OPsound* OPsound::GetInstance() {
		return m_instance;
	}
private:
	prefab::CSoundSource* m_sound;

};

