#pragma once
class GameData
{
	static GameData* m_instance;
public:
	GameData();
	~GameData();

	//残弾取得
	int GameData::GetZandan() {

		return Zandan;
	}

	//基本攻撃力取得
	int GameData::GetATK() {

		return ATK;
	}
	//最大体力取得
	int GameData::GetDEF_Life() {

		return DEF_Life;
	}
	
	//現在の体力
	int GameData::tairyokuKeisan() {
		return Life;
		
	}
	//引数に設定した値を体力に加算する　負の数を設定したら減少する
	void  GameData::tiryokugennsyou(int x) {
		Life += x;
	}
	//初期残弾取得
	int GameData::GetDEF_Zandan() {

		return DEF_Zandan;
	}
private:
	int Zandan = 50; //残弾

	int ATK = 100; //基本攻撃力
	int DEF_Zandan = 50; //デフォルト残弾
	int DEF_Life = 100; //デフォルト寿命
	int Life = DEF_Life; //現在体力
};

