#pragma once
class EnemyBird : public IGameObject
{
public:
	EnemyBird();
	~EnemyBird();

	enum EnState {
		EnState_idle,	//待機
		EnState_walk,	//歩き
		EnState_fly,	//飛ぶ
		EnState_death,	//殺された
	};
	//アニメーション
	enum  EnAnimationClip {
		enAnimationClip_walk,  //歩き
		enAnimationClip_fly,  //歩き
		enAnimationClip_Num,  //アニメーションクリップ
	};

	bool Start();
	void Update();

	//Hpを返す関数
	int EnemyBird::GetHp() {
		return HP;
	}
	//MAX_Hpを返す関数
	int EnemyBird::GetMAX_Hp() {
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
	//大きさを設定。
	void SetScale(CVector3 sca)
	{
		m_scale = sca;
	}

private:

	void BirdIdle();
	void BirdWalk();
	void BirdFly();
	void BirdDeath();
	void BirdHorizon();
	void Animation();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::Zero; // スケール
	EnState m_state = EnState_walk;//状態
	CVector3 moveVec = CVector3::Zero; // 座標。

	CCharacterController m_charaCon; //キャラコン
	CAnimationClip  m_animClips[enAnimationClip_Num];		//アニメーション

	//スキン
	//prefab::CSpriteRender* m_skin = nullptr;//枠
	//prefab::CSpriteRender* m_skin2 = nullptr;//白色
	//KOTOが3Dカメラのために作ったやつ
	//CVector3 m_position2;//これ枠
	//CVector3 m_position2;//これ白いやつ
	//音楽
	prefab::CSoundSource* m_sound = nullptr; //音敵に当たった時に
	prefab::CSoundSource* m_sound2 = nullptr; //泣く音
	prefab::CSoundSource* m_sound3 = nullptr; //飛ぶ音
	

	//待機関連
	int stoptimer = 0;					//停止用タイマー
	const float stopendtimer = 60.0f;	//停止を辞めますぅ
	//歩き関連
	CVector3 walkmove = CVector3::Zero;		// 座標。
	int count = 0;							//移動用カウント
	int wrandom = 0;						//移動の方向乱数
	const int randomCount = 300;			//ランダムで移動方向切り替えタイマー
	const float randomSpeed = 40.0f;			//移動速度
	//飛び関連
	const float flyRange = 300.0f;		//逃げる距離（プレイヤーから離れる距離）
	const float fleeSpeed = 70.0f;		//逃げる速度

	bool flyflag = false;
	bool haneflag = false;
	//視野角
	const float horilong = 200.0f;	//視野角判定の距離
	const float horiAngle = 45.0f;	//視野角判定の角度

	//エフェクト関連
	const CVector3 EfeSize = { 5.0f,5.0f,5.0f };	//エフェクトの大きさ

	const float DeadLength = 30.0f;	//ペンとの当たり判定距離

	//体力ぅぅぅ
	int HP = 100;				//現在の体力
	const int MAX_HP = 100;		//最大体力
};

