#pragma once

#include <memory>
#include <map>
#include <string>
#include "Resource.h"

class ResourceManager
{

public:

	//使用する複数枚の画像（アニメーション）などの定数登録

	static constexpr int CHARACTER_ORIGIN_SIZE_X = 96;
	static constexpr int CHARACTER_ORIGIN_SIZE_Y_2 = 256;

	// リソース名
	enum class SRC
	{
		//画像
		MAP_TILE,
		//キャラクター
		CHARACTER_1,
		CHARACTER_2,
		CHARACTER_3,
		CHARACTER_4,
		CHARACTER_5,
		CHARACTER_6,
		CHARACTER_7,
		CHARACTER_8,
		CHARACTER_9,
		CHARACTER_10,
		CHARACTER_11,
		CHARACTER_12,
		CHARACTER_13,
		CHARACTER_14,
		CHARACTER_15,
		CHARACTER_16,
		CHARACTER_17,
		CHARACTER_18,
		CHARACTER_19,
		CHARACTER_20,
		CHARACTER_21,
		CHARACTER_22,
		CHARACTER_23,
		CHARACTER_24,
		CHARACTER_25,
		CHARACTER_26,
		CHARACTER_27,
		CHARACTER_28,
		CHARACTER_29,
		CHARACTER_30,
		CHARACTER_31,
		CHARACTER_32,

		//CSV
		STAGE,

		//効果音
		
		//BGM
		
		//エフェクト
	};

	// 明示的にインステンスを生成する
	static void CreateInstance(void);

	// 静的インスタンスの取得
	static ResourceManager& GetInstance(void);

	// 初期化
	void Init(void);

	// 解放(シーン切替時に一旦解放)
	void Release(void);

	// リソースの完全破棄
	void Destroy(void);

	// リソースのロード
	const Resource& Load(SRC src);

	// リソースの複製ロード(モデル用)
	int LoadModelDuplicate(SRC src);

private:

	// 静的インスタンス
	static ResourceManager* instance_;

	//未登録
	Resource unregistered;

	// リソース管理の対象
	std::map<SRC, std::unique_ptr<Resource>> resourcesMap_;
	//std::map<SRC, Resource> resourcesMap_;
	 
	
	// 読み込み済みリソース
	std::map<SRC, Resource&> loadedMap_;
	//std::map<SRC, Resource*> loadedMap_;

	// デフォルトコンストラクタをprivateにして、
	// 外部から生成できない様にする
	ResourceManager(void);

	// デストラクタも同様
	~ResourceManager(void) = default;

	// 内部ロード
	Resource& _Load(SRC src);

};

