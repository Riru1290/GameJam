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
}

void TutorialScene::Update()
{
	auto& input = InputManager::GetInstance();

	// 次のページへ
	if (input.IsPadBtnTrgDown(InputManager::JOYPAD_NO::PAD1, InputManager::JOYPAD_BTN::RIGHT)) {
		nowPage_++;
		if (nowPage_ >= PAGE_NUM) {
			nowPage_ = PAGE_NUM;
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
}

void TutorialScene::Release()
{
}
