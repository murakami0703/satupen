#pragma once
class EnemyChildren : public IGameObject
{
public:
	EnemyChildren();
	~EnemyChildren();

	enum EnState {
		EnState_idle,	//待機
		EnState_walk,	//歩き
		EnState_runaway,	//逃げる
		EnState_death,	//殺された
	};
	bool Start();
	void Update();
	//座標を設定。
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}

private:
	void ChildrenIdle();
	void ChildrenWalk();
	void ChildrenRunaway();
	void ChildrenDeath();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::Zero; // スケール
	EnState m_state = EnState_walk;//状態
	CVector3 moveVec = CVector3::Zero; // 座標。

	CCharacterController m_charaCon; //キャラコン

	//停止状態関連
	int stoptimer = 0;//停止用タイマー
	const float stopendtimer = 60.0f; //停止を辞めますぅ
	//歩き関連
	CVector3 walkmove = CVector3::Zero; // 座標。
	int count = 0; //移動用カウント
	int wrandom = 0; //移動の方向乱数
	const int randomCount = 300; //ランダムで移動方向切り替えタイマー
	const float randomSpeed = 1.0f; //移動速度
	//逃げ関連
	const float followRange = 300.0f; //逃げる距離（プレイヤーから離れる距離）
	const float runaway = 1000.0f; //逃げるのをやめる距離
	const float followSpeed = 50.0f; //逃げる速度
	
};

