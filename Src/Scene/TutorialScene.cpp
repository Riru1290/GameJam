#include "../Common/InputManager.h"
#include "../Common/ResourceManager.h"
#include "SceneManager.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	nowPage_ = 0;
}

void TutorialScene::Init()
{
	auto& res = ResourceManager::GetInstance();
	imgs_[0] = res.Load(ResourceManager::SRC::TUTORIAL_1).handleId_;
	imgs_[1] = res.Load(ResourceManager::SRC::TUTORIAL_2).handleId_;
	imgs_[2] = res.Load(ResourceManager::SRC::TUTORIAL_3).handleId_;
	imgs_[3] = res.Load(ResourceManager::SRC::TUTORIAL_4).handleId_;
	imgs_[4] = res.Load(ResourceManager::SRC::TUTORIAL_5).handleId_;

	auto& rsM = ResourceManager::GetInstance();
	charaImg_ = {
	rsM.Load(ResourceManager::SRC::CHARACTER_1).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_2).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_3).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_4).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_5).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_6).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_7).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_8).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_9).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_10).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_11).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_12).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_13).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_14).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_15).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_16).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_17).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_18).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_19).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_20).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_21).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_22).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_23).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_24).handleIds_,
	};

	SceneMng.SetImageLupinNo(GetRand(charaImg_.size() - 1));
}

void TutorialScene::Update()
{
	auto& input = InputManager::GetInstance();

	// 次のページへ
	if (input.IsPadBtnTrgDown(InputManager::JOYPAD_NO::PAD1, InputManager::JOYPAD_BTN::RIGHT)) {
		nowPage_++;
		if (nowPage_ >= PAGE_NUM) {
			nowPage_ = PAGE_NUM - 1;
			SceneMng.ChangeScene(SCENE_ID::PLAY);
		}
	}
	else if (input.IsPadBtnTrgDown(InputManager::JOYPAD_NO::PAD1, InputManager::JOYPAD_BTN::LEFT) && nowPage_ < TUTORIAL_PAGE) {
		// Tutorialスキップ
		nowPage_ = TUTORIAL_PAGE;
	}
}

void TutorialScene::Draw()
{
	DrawGraph(0, 0, imgs_[nowPage_],true);

	if (nowPage_ == 3) {
		DrawRotaGraph(SCREEN_SIZE_X / 2.0f, SCREEN_SIZE_Y / 2.0f, 3.0f, 0.0f, charaImg_[SceneMng.GetImageLupinNo()][0], true);
	}
}

void TutorialScene::Release()
{
}
