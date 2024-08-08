#include "SceneManager.h"

SceneManager& SceneManager::GetInstance()
{
	static SceneManager sceneManager;
	return sceneManager;
}

void SceneManager::Execute()
{
}

void SceneManager::Terminate()
{
}

void SceneManager::ChangeScene(SCENE_ID sceneID)
{
}

void SceneManager::DoChangeScene()
{
}
