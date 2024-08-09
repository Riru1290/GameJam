#include "../Common/InputManager.h"
#include "../UI/UIBlink.h"
#include "SceneManager.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	imgTitle_ = LoadGraph("Data/Img/UI/title.png");
}

void TitleScene::Init()
{
	shared_ptr<UIBase> tempUI;
	tempUI = make_shared<UIBlink>(Vector2F(SCREEN_SIZE_X / 2.0f, SCREEN_SIZE_Y / 2.0f + 200.0f), "Data/Img/UI/pressB.png");
	UIs_.emplace_back(tempUI);
}

void TitleScene::Update()
{
	auto& input = InputManager::GetInstance();
	if (input.IsPadBtnTrgDown(InputManager::JOYPAD_NO::PAD1, InputManager::JOYPAD_BTN::RIGHT)) {
		SceneMng.ChangeScene(SCENE_ID::TUTORIAL);
	}
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, imgTitle_, true);

	for (auto UI : UIs_) {
		UI->Draw();
	}
}

void TitleScene::Release()
{
	DeleteGraph(imgTitle_);
}
