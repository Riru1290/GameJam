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
	lupinBgm_ = rsM.Load(ResourceManager::SRC::LUPIN_WIN_BGM).handleId_;
	zenigataBgm_ = rsM.Load(ResourceManager::SRC::ZENIGATA_WIN_BGM).handleId_;

	ChangeVolumeSoundMem(255 * 70 / 100, titleBgm_);
	ChangeVolumeSoundMem(255 * 70 / 100, gameBgm_);
	ChangeVolumeSoundMem(255 * 80 / 100, lupinBgm_);
	ChangeVolumeSoundMem(255 * 80 / 100, zenigataBgm_);

	answerSnd_ = rsM.Load(ResourceManager::SRC::ANSWER_SND).handleId_;
	enterSnd_ = rsM.Load(ResourceManager::SRC::ENTER_SND).handleId_;
	moveSnd_ = rsM.Load(ResourceManager::SRC::MOVE_SND).handleId_;
	getSnd_ = rsM.Load(ResourceManager::SRC::GET_SND).handleId_;

	ChangeVolumeSoundMem(255 * 120 / 100, getSnd_);
	ChangeVolumeSoundMem(255 * 120 / 100, moveSnd_);
	ChangeVolumeSoundMem(255 * 120 / 100, answerSnd_);
}

void SoundManager::Relese(void)
{
	DeleteSoundMem(titleBgm_);
	DeleteSoundMem(gameBgm_);
	DeleteSoundMem(answerBgm_);
	DeleteSoundMem(lupinBgm_);
	DeleteSoundMem(zenigataBgm_);
	DeleteSoundMem(answerSnd_);
	DeleteSoundMem(enterSnd_);
	DeleteSoundMem(moveSnd_);
	DeleteSoundMem(getSnd_);
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

void SoundManager::PlayBgmOfLupin(void)
{
	PlaySoundMem(lupinBgm_, DX_PLAYTYPE_LOOP);
}

void SoundManager::StopBgmOfLupin(void)
{
	StopSoundMem(lupinBgm_);
}

void SoundManager::PlayBgmOfZenigata(void)
{
	PlaySoundMem(zenigataBgm_, DX_PLAYTYPE_LOOP);
}

void SoundManager::StopBgmOfZenigata(void)
{
	StopSoundMem(zenigataBgm_);
}

void SoundManager::PlaySndAnswer(void)
{
	PlaySoundMem(answerSnd_, DX_PLAYTYPE_BACK);
}

void SoundManager::PlaySndEnter(void)
{
	PlaySoundMem(enterSnd_, DX_PLAYTYPE_BACK);
}

void SoundManager::PlaySndMove(void)
{
	PlaySoundMem(moveSnd_, DX_PLAYTYPE_BACK);
}

void SoundManager::PlaySndGet(void)
{
	PlaySoundMem(getSnd_, DX_PLAYTYPE_BACK);
}


