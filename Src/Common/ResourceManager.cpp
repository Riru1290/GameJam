#include"../../pch.h"
#include "../Application.h"
#include"../Object/CharacterBase.h"
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
	
#pragma endregion


#pragma region CSV

	
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
