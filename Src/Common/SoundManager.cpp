#include "../../pch.h"
#include"ResourceManager.h"
#include "SoundManager.h"

SoundManager* SoundManager::instance_ = nullptr;

SoundManager::SoundManager(void)
{

}

void SoundManager::Destroy(void)
{
	delete instance_;
}

bool SoundManager::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new SoundManager;
	}
	instance_->Init();
	//ê≥ÇµÇ≠èàóùÇ™èIóπÇµÇΩÇÃÇ≈
	return true;
}

SoundManager& SoundManager::GetInstance(void)
{
	return *instance_;
}

void SoundManager::Init(void)
{
	auto& rsM = ResourceManager::GetInstance();

	titleBgm_ = rsM.Load(ResourceManager::SRC::TITLE_BGM).handleId_;
	gameBgm_ = rsM.Load(ResourceManager::SRC::GAME_BGM).handleId_;
	answerBgm_ = rsM.Load(ResourceManager::SRC::ANSWER_BGM).handleId_;

	ChangeVolumeSoundMem(255 * 70 / 100, titleBgm_);
	ChangeVolumeSoundMem(255 * 70 / 100, gameBgm_);
}

void SoundManager::Relese(void)
{
	DeleteSoundMem(titleBgm_);
	DeleteSoundMem(gameBgm_);
	DeleteSoundMem(answerBgm_);
}

void SoundManager::PlayBgmOfTitle(void)
{
	PlaySoundMem(titleBgm_, DX_PLAYTYPE_LOOP);
}

void SoundManager::StopBgmOfTitle(void)
{
	StopSoundMem(titleBgm_);
}

void SoundManager::PlayBgmOfGame(void)
{
	PlaySoundMem(gameBgm_, DX_PLAYTYPE_LOOP);
}

void SoundManager::StopBgmOfGame(void)
{
	StopSoundMem(gameBgm_);
}

void SoundManager::PlayBgmOfAnswer(void)
{
	PlaySoundMem(answerBgm_, DX_PLAYTYPE_LOOP);
}

void SoundManager::StopBgmOfAnswer(void)
{
	StopSoundMem(answerBgm_);
}
