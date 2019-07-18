#pragma once
class EffectManager : public IGameObject
{
	static EffectManager* m_instance;
public:

	//エフェクト名前
	enum Effect {
		Null,
		Bakuhatu, //どかーん
		Blood, //血ドバー
		BloodZonbi, //ゾンビの血ドバー
	};

	EffectManager();
	~EffectManager();

	//引数1→再生するエフェクト（種類はヘッダーに）
	//引数2→position
	//引数3→scale
	void EffectPlayer(Effect EF, CVector3 position, CVector3 scale);

	//インスタンスの取得
	static EffectManager* EffectManager::GetInstance() {
		return m_instance;
	}

private:
	prefab::CSpriteRender* m_skin = nullptr;//枠
	prefab::CSpriteRender* m_skin2 = nullptr;//白色
	//KOTOが3Dカメラのために作ったやつ
	CVector3 m_positioin;//これ枠
	CVector3 m_position2;//これ白いやつ
	//エフェクトファイル名
	wchar_t DetaBase[10][30]{
		{ L"" },//Nullなので何もない
		{ L"effect/bakuha.efk" },
		{ L"effect/Blood.efk" },
		{ L"effect/BloodZonbi.efk" },
		
	};

	CVector3 m_scale = CVector3::One;
	CVector3 m_position = CVector3::Zero;

	Effect m_stete = Null;		 //エフェクト状態
	wchar_t EF_Name[30] = { L"" };	//エフェクト名保管用
};

