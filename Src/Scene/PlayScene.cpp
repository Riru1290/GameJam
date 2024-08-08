#include "SceneManager.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
}

void PlayScene::Init()
{
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
	if (CheckHitKey(KEY_INPUT_E)) {
		SceneMng.ChangeScene(SCENE_ID::ANSWER);
	}
	DrawFormatString(0, 0, 0xffffff, "PlayScene");
}

void PlayScene::Release()
{
}
