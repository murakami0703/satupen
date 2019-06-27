#pragma once
class GameData : public IGameObject
{
	static GameData* m_instance;
public:
	GameData();
	~GameData();


	//インスタンスの取得
	static GameData* GameData::GetInstance() {
		return m_instance;
	}

	//残弾取得
	int GameData::GetZandan() {

		return Zandan;
	}
	//攻撃力取得
	int GameData::GetATK() {

		return ATK;
	}
	//最大体力取得
	int GameData::GetDEF_Life() {

		return DEF_Life;
	}
	//体力取得
	int GameData::Get_Life() {
		return Life;
	}
	//現在の時間の経過を取得
	float GameData::GetTimer() {
		return Timer;
	}
	//最大のタイムを取得
	float GameData::GetMAX_Timer() {
		return MAX_Timer;
	}
	//敵を殺した数を取得
	int GameData::GetDeadH() {
		return DeadH;
	}
	//殺した数をを1増やす
	//やったときに実行
	void GameData::DeadHCounter() {
		DeadH++;
	}
	//引数に設定した値を時間に加算する　負の数を設定したら減少する
	void GameData::TimeKeika(float x) {
		Timer += x;
		if (Timer < 0) {
			Timer = 0;
		}

		if (MAX_Timer < Timer) {
			Timer = MAX_Timer;
		}

	}
	//引数に設定した値を体力に加算する　負の数を設定したら減少する
	void  GameData::tiryokugennsyou(int x) {
		Life += x;
		if (Life < 0) {
			Life = 0;
		}
		if (DEF_Life < Life) {
			Life = DEF_Life;
		}
	}
	//引数に設定した値を残弾に加算する　負の数を設定したら減少する
	void GameData::Zandannkasan(int x) {
		Zandan += x;
		if (Zandan < 0) {
			Zandan = 0;
		}

		if (MAX_Zandann < Zandan) {
			Zandan = MAX_Zandann;
		}

	}
	//引数に設定した値を殺害数に加算する　負の数を設定したら減少する
	void GameData::DeadHkasan(int x) {
		DeadH += x;
		if (DeadH < 0) {
			DeadH = 0;
		}

		if (MAX_DeadH < DeadH) {
			DeadH = MAX_DeadH;
		}

	}

	
private:
	int Zandan = 50; //残弾
	int DeadH = 0;	//殺した数
	int ATK = 100; //基本攻撃力
	int DEF_Life = 100; //デフォルト体力
	int Life = 100; //体力取得
	float Timer = 0.0f;//タイマー
	float MAX_Timer = 180.0f;//最大タイム
	const int MAX_Zandann = 99;
	const int MAX_DeadH = 99;

};

