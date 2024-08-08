#include "SceneManager.h"
#include "AnswerScene.h"

AnswerScene::AnswerScene()
{
}

void AnswerScene::Init()
{
}

void AnswerScene::Update()
{
}

void AnswerScene::Draw()
{
	if (CheckHitKey(KEY_INPUT_E)) {
		SceneMng.ChangeScene(SCENE_ID::PLAY);
	}
	DrawFormatString(0, 0, 0xffffff, "AnswerScene");
}

void AnswerScene::Release()
{
}
