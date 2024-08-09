#include"../../pch.h"
#include "../Application.h"
#include"../Object/CharacterBase.h"
#include"../Object/Stage.h"
#include "Resource.h"
#include "ResourceManager.h"

ResourceManager* ResourceManager::instance_ = nullptr;

using namespace std;
void ResourceManager::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new ResourceManager();
	}
	instance_->Init();
}

ResourceManager& ResourceManager::GetInstance(void)
{
	return *instance_;
}

void ResourceManager::Init(void)
{

	unique_ptr<Resource> res;

#pragma region IMG

	// 車
	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Obstacle/car.png"
	);
	resourcesMap_.emplace(SRC::CAR_1, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Obstacle/car2.png"
	);
	resourcesMap_.emplace(SRC::CAR_2, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Obstacle/bus.png"
	);
	resourcesMap_.emplace(SRC::CAR_3, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Obstacle/bus2.png"
	);
	resourcesMap_.emplace(SRC::CAR_4, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Obstacle/car3.png"
	);
	resourcesMap_.emplace(SRC::CAR_5, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Obstacle/police.png"
	);
	resourcesMap_.emplace(SRC::CAR_6, move(res));

	// 建物
	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building1.png"
	);
	resourcesMap_.emplace(SRC::BILL_1, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building2.png"
	);
	resourcesMap_.emplace(SRC::BILL_2, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building3.png"
	);
	resourcesMap_.emplace(SRC::BILL_3, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building4.png"
	);
	resourcesMap_.emplace(SRC::BILL_4, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building5.png"
	);
	resourcesMap_.emplace(SRC::BILL_5, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building6.png"
	);
	resourcesMap_.emplace(SRC::BILL_6, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building7.png"
	);
	resourcesMap_.emplace(SRC::BILL_7, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building8.png"
	);
	resourcesMap_.emplace(SRC::BILL_8, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building9.png"
	);
	resourcesMap_.emplace(SRC::BILL_9, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building10.png"
	);
	resourcesMap_.emplace(SRC::BILL_10, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building11.png"
	);
	resourcesMap_.emplace(SRC::BILL_11, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMG,
		"Data/Img/Building/building12.png"
	);
	resourcesMap_.emplace(SRC::BILL_12, move(res));
	
#pragma endregion


#pragma region IMGS
	//キャラクター
	//プレイヤー

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/Hayate.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
		);
	resourcesMap_.emplace(SRC::CHARACTER_1, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/maid.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_2, move(res)); 
	
	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/Player_1.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_3, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/Oldman.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_4, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hayate1.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_5, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hime1.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_6, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/made1.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_7, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/old1.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_8, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hayate2.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_9, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hime2.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_10, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/made2.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_11, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/old2.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_12, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hayate3.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_13, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hime3.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_14, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/made3.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_15, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/old3.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_16, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hayate4.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_17, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hime4.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_18, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/made4.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_19, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/old4.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_20, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hayate5.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_21, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/hime5.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_22, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/made5.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_23, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Character/old5.png",
		CHARACTER_ORIGIN_SIZE_X / CharacterBase::CHARACTER_SIZE_X,
		CHARACTER_ORIGIN_SIZE_Y_2 / CharacterBase::CHARACTER_SIZE_Y,
		CharacterBase::CHARACTER_SIZE_X,
		CharacterBase::CHARACTER_SIZE_Y
	);
	resourcesMap_.emplace(SRC::CHARACTER_24, move(res));
	

	//マップ
	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Image/Stage/tile.png",
		Stage::TILE_X,
		Stage::TILE_Y,
		Stage::TILE_SIZE,
		Stage::TILE_SIZE
	);
	resourcesMap_.emplace(SRC::MAP_TILE, move(res));

	// エフェクト(マジックナンバー許して)
	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Effect/carSmoke.png",
		10,
		1,
		64,
		27
	);
	resourcesMap_.emplace(SRC::EFFECT_1, move(res));

	res = make_unique<Resource>(
		Resource::TYPE::IMGS,
		"Data/Img/Effect/Effect_PuffAndStars_1_120x109.png",
		7,
		6,
		120,
		109
	);
	resourcesMap_.emplace(SRC::EFFECT_2, move(res));


#pragma endregion


#pragma region CSV
		res = make_unique<Resource>(

			Resource::TYPE::CSV,

			"Data/map.csv"

		);

	resourcesMap_.emplace(SRC::STAGE, move(res));
	
#pragma endregion

#pragma region SOUND

	
#pragma endregion
}

void ResourceManager::Release(void)
{
	for (auto& p : loadedMap_)
	{
		p.second.Release();
		//delete p.second;
	}

	loadedMap_.clear();
}

void ResourceManager::Destroy(void)
{
	Release();
	resourcesMap_.clear();
	delete instance_;
}

const Resource& ResourceManager::Load(SRC src)
{
	Resource& res = _Load(src);
	if (res.resType_ == Resource::TYPE::NONE)
	{
		//未登録
		return unregistered;
	}
	//Resource ret = *res;
	return res;
}

int ResourceManager::LoadModelDuplicate(SRC src)
{
	Resource& res = _Load(src);
	if (res.resType_ == Resource::TYPE::NONE)
	{
		return -1;
	}

	int duId = MV1DuplicateModel(res.handleId_);
	res.duplicateModelIds_.push_back(duId);

	return duId;
}

ResourceManager::ResourceManager(void)
{
}

Resource& ResourceManager::_Load(SRC src)
{
	const auto& lPair = loadedMap_.find(src);
	if (lPair != loadedMap_.end())
	{
		return lPair->second;
	}

	const auto& rPair = resourcesMap_.find(src);
	if (rPair == resourcesMap_.end())
	{
		// 登録されていない
		return unregistered;
	}

	rPair->second->Load();


	loadedMap_.emplace(src, *rPair->second);

	return *rPair->second;
}
