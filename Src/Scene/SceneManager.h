#pragma once
#define SceneMng SceneManager::GetInstance()

class SceneBase;
class Fade;

class SceneManager
{
public:

	static SceneManager& GetInstance();

	void Execute();

	void Terminate();

	void ChangeScene(SCENE_ID sceneID);

	[[nodiscard]] const SCENE_ID& GetPreScene()const { return preSceneID_; };

private:

	SceneManager();
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

	std::unique_ptr<SceneBase> scene_;
	unique_ptr<Fade> fade_;

	SCENE_ID sceneID_;
	SCENE_ID preSceneID_;
	SCENE_ID nextSceneID_;

	void DoChangeScene();

	
};

