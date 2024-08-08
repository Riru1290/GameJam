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

	// ��ʂ�������
	ClearDrawScreen();

	scene_->Draw();

	// �Ó]�E���]
	fader_->Draw();


}

void SceneManager::Terminate()
{
}

void SceneManager::ChangeScene(SCENE_ID sceneID)
{
	nextSceneID_ = sceneID;

	// �t�F�[�h�A�E�g(�Ó])���J�n����
	fader_->SetFade(Fader::STATE::FADE_OUT);
	isSceneChanging_ = true;
}

SceneManager::SceneManager()
{
	fader_ = std::make_unique<Fader>();
	fader_->Init();

	// �����V�[���̐ݒ�
	nextSceneID_ = SCENE_ID::PLAY;
	sceneID_ = SCENE_ID::PLAY;
	DoChangeScene();
}

void SceneManager::DoChangeScene()
{

	// ���
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
		// ���]��
		if (fader_->IsEnd())
		{
			// ���]���I��������A�t�F�[�h�����I��
			fader_->SetFade(Fader::STATE::NONE);
			isSceneChanging_ = false;
		}
		break;
	case Fader::STATE::FADE_OUT:
		// �Ó]��
		if (fader_->IsEnd())
		{
			// ���S�ɈÓ]���Ă���V�[���J��
			DoChangeScene();
			// �Ó]���疾�]��
			fader_->SetFade(Fader::STATE::FADE_IN);
		}
		break;
	}
}
