#pragma once
class GameData : public IGameObject
{
	static GameData* m_instance;
public:
	GameData();
	~GameData();
	enum ResultDead {
		DeadMan,
		DeadWoman,
		DeadChildren,
		DeadDog,
		DeadCat,
		DeadBird,
		DeadAnimals,
		DesItem,
		DesBigItem,
	};
	int GameData::GetResultDead(ResultDead dead);	//Result用	カウントを返す。
	void GameData::ResultDeadkasan(ResultDead dead);	//Result用 引数に設定した値に加算する。

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
	//敵を殺した数を取得
	int GameData::GetDeadH() {
		return DeadH;
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
	//引数をエネミーカウンターに代入
	void GameData::EnemyCounterSet(int x) {
		EnemyCount = x;
	}
	//引数をアイテムカウンターに代入
	void GameData::ItemCounterSet(int x) {
		ItemCount = x;
	}
	//////////////////////////////////////
	//リザルト用　総合計算



private:
	int Zandan = 50; //残弾
	int DeadH = 0;	//殺した数
	int ATK = 100; //基本攻撃力
	int DEF_Life = 100; //デフォルト体力
	int Life = 100; //体力取得
	const int MAX_Zandann = 99;//最大残弾
	const int MAX_DeadH = 999;//最大残虐数

	int EnemyCount = 0; //敵の数
	int ItemCount = 0; //アイテムの数

	///////////////////////
	//リザルト用種類別殺害数など
	int Man = 0;//男性殺害数
	int Woman = 0;//女性殺害数
	int Children = 0;//子供殺害数
	int Dog = 0;//イヌ殺害数
	int Cat = 0;//ネコ殺害数
	int Bird = 0;//トリ殺害数
	int Animals = 0;//動物殺害数
	int Item = 0;//アイテム壊した数
	int BigItem = 0;//大きいアイテム壊した数

	const int MAX_Dead = 999;//最大残虐＆破壊数
	
	///////////////////////

	//定数
};

