#pragma once
#define SceneMng SceneManager::GetInstance()

class SceneBase;
class Fader;
class Apple;

class SceneManager
{
public:

	static SceneManager& GetInstance();

	void Execute();

	void Draw();

	void Terminate();

	void ChangeScene(SCENE_ID sceneID);

	// ‰ö“”Ô†
	[[nodiscard]] const int& GetLupinNo()const { return lupinNo_; };
	void SetLupinNo(int no) { lupinNo_ = no; };

	static constexpr int CHARA_TYPE_NUM = (24);

	// ‰ö“‰æ‘œ”Ô†
	[[nodiscard]] const int& GetImageLupinNo()const { return imgLupinNo_; };
	void SetImageLupinNo(int no) { imgLupinNo_ = no; };

	// ‰ö“‚ª“‚İ‚ğ¬Œ÷‚³‚¹‚½‚©
	[[nodiscard]] const bool& IsSuccess()const { return isSuccess_; };
	void SetIsSuccess(bool isSuccess) { isSuccess_ = isSuccess; };

	// ‚æ‚­‚È‚¢‚¯‚Ç‹–‚µ‚Ä
	void GetApple(weak_ptr<Apple> apple);

private:

	SceneManager();
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

	shared_ptr<SceneBase> scene_;
	unique_ptr<Fader> fader_;

	SCENE_ID sceneID_;
	SCENE_ID nextSceneID_;

	void DoChangeScene();

	void Fade();

	bool isSceneChanging_;

	// ‰ö“”Ô†
	int lupinNo_;

	// ‰ö“‰æ‘œ”Ô†
	int imgLupinNo_;

	// ‰ö“‚ª“‚İ‚ğ¬Œ÷‚³‚¹‚½‚©
	bool isSuccess_;
};

