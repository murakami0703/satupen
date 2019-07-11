#pragma once
class EnemyMan : public IGameObject
{
public:
	EnemyMan();
	~EnemyMan();
	enum EnState {
		EnState_idle,	//待機
		EnState_walk,	//歩き
		EnState_yobi,	//予備動作
		EnState_attack,	//攻撃
		EnState_death,	//殺された
	};
	//アニメーション
	enum  EnAnimationClip {
		enAnimationClip_idle, //待機
		enAnimationClip_walk,  //歩き
		enAnimationClip_yobi,  //予備
		enAnimationClip_attack, //攻撃
		enAnimationClip_prostrate, //土下座
		enAnimationClip_Num,  //アニメーションクリップ
	};
	bool Start();
	void Update();

	//Hpを返す関数
	int EnemyMan::GetHp() {
		return HP;
	}
	//MAX_Hpを返す関数
	int EnemyMan::GetMAX_Hp() {
		return MAX_HP;
	}

	//座標を設定。
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	//回転を設定。
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}

	
private:
	void ManIdle();
	void ManWalk();
	void ManAttack();
	void ManDeath();
	void ManHorizon();
	void Animation();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::One; // スケール
	CVector3 moveVec = CVector3::Zero; // 座標。
	EnState m_state = EnState_walk;//状態
	CAnimationClip  m_animClips[enAnimationClip_Num];		//アニメーション
	CCharacterController m_charaCon; //キャラコン

	//待機関連
	int stoptimer = 0;//停止用タイマー
	const float stopendtimer = 60.0f; //停止を辞めますぅ
	//歩き関連
	CVector3 walkmove = CVector3::Zero; // 座標。
	int count = 0; //移動用カウント
	int wrandom = 0; //移動の方向乱数
	const int randomCount = 300; //ランダムで移動方向切り替えタイマー
	const float randomSpeed = 8.0f; //移動速度
	//攻撃関連
	const float attackSpeed = 40.0f; //逃げる速度

	//視野角
	const float horilong = 350.0f;	//視野角判定の距離
	const float horiAngle = 45.0f;	//視野角判定の角度

	//エフェクト関連
	const CVector3 EfeSize = { 5.0f,5.0f,5.0f };	//エフェクトの大きさ

	const float DeadLength = 30.0f;	//ペンとの当たり判定距離

	//体力ぅぅぅ
	int HP = 100;				//現在の体力
	const int MAX_HP = 100;		//最大体力
};

