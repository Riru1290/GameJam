#include "UICountDown.h"

UICountDown::UICountDown()
{
	imgs_ = new int[10 * 1];
	LoadDivGraph("Data/Img/UI/number.png", 10, 10, 1, 160, 172, imgs_);
	imgGameStart_ = LoadGraph("Data/Img/UI/gameStart.png");
	pos_ = { SCREEN_SIZE_X /2.0f,SCREEN_SIZE_Y / 2.0f };
	angle_ = 0.0f;
}

UICountDown::~UICountDown()
{
	for (int i = 0; i < 10; i++) {

		DeleteGraph(imgs_[i]);
	}
	DeleteGraph(imgGameStart_);
}

void UICountDown::Draw()
{
	if (MyTimer.IsEndTimer("GAME_START_TIME"))return;

	Vector2F data = pos_;



	// フレーム
	Vector2F fData = data;
	fData += {0.0f, -50.0f};
	DrawRotaGraph(fData.x, fData.y, size_, angle_, imgGameStart_, true);

	// カウントダウン
	float time = MyTimer.GetTime("GAME_START_TIME");
	Vector2F cData = data;
	cData += {0.0f, 50.0f};
	DrawRotaGraph(cData.x, cData.y, size_ * 0.5f, angle_, imgs_[(int)time % 10 + 1], true);

}
