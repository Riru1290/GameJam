#include "../Utility/Fader.h"
#include "PlayScene.h"
#include "AnswerScene.h"
#include "SceneManager.h"

SceneManager& SceneManager::GetInstance()
{
	static SceneManager sceneManager;
	return sceneManager;
}

void SceneManager::Execute()
{
	fader_->Update();
	if (isSceneChanging_) {
		Fade();
	}
	else {
		scene_->Update();
	}
}

void SceneManager::Draw()
{
	SetDrawScreen(DX_SCREEN_BACK);

	// 画面を初期化
	ClearDrawScreen();

	scene_->Draw();

	// 暗転・明転
	fader_->Draw();


}

void SceneManager::Terminate()
{
}

void SceneManager::ChangeScene(SCENE_ID sceneID)
{
	nextSceneID_ = sceneID;

	// フェードアウト(暗転)を開始する
	fader_->SetFade(Fader::STATE::FADE_OUT);
	isSceneChanging_ = true;
}

SceneManager::SceneManager()
{
	fader_ = std::make_unique<Fader>();
	fader_->Init();

	// 初期シーンの設定
	nextSceneID_ = SCENE_ID::PLAY;
	sceneID_ = SCENE_ID::PLAY;
	DoChangeScene();
}

void SceneManager::DoChangeScene()
{

	// 解放
	if (scene_ != nullptr) {
		scene_->Release();
	}

	sceneID_ = nextSceneID_;

	switch (nextSceneID_)
	{
	case SCENE_ID::PLAY:
		scene_.reset(new PlayScene());
		break;
	case SCENE_ID::ANSWER:
		scene_.reset(new AnswerScene());
		break;
	}
}

void SceneManager::Fade()
{
	Fader::STATE fState = fader_->GetState();
	switch (fState)
	{
	case Fader::STATE::FADE_IN:
		// 明転中
		if (fader_->IsEnd())
		{
			// 明転が終了したら、フェード処理終了
			fader_->SetFade(Fader::STATE::NONE);
			isSceneChanging_ = false;
		}
		break;
	case Fader::STATE::FADE_OUT:
		// 暗転中
		if (fader_->IsEnd())
		{
			// 完全に暗転してからシーン遷移
			DoChangeScene();
			// 暗転から明転へ
			fader_->SetFade(Fader::STATE::FADE_IN);
		}
		break;
	}
}
