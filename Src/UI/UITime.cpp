#include "UITime.h"

UITime::UITime() : UIBase()
{
	imgs_ = new int[10 * 1];
	LoadDivGraph("Data/Img/UI/number.png", 10, 10, 1, 160, 172, imgs_);
	imgColon_ = LoadGraph("Data/Img/UI/colon.png");
	imgTimer_ = LoadGraph("Data/Img/UI/Icon_Clock.png");
	imgFrame_ = LoadGraph("Data/Img/UI/Item5.png");
	pos_ = { 170.0f,70.0f };
	size_ = 0.35f;
	angle_ = 0.0f;
}

UITime::~UITime()
{
	for (int i = 0; i < 10; i++) {

		DeleteGraph(imgs_[i]);
	}
	DeleteGraph(imgColon_);
	DeleteGraph(imgTimer_);
	DeleteGraph(imgFrame_);
}


void UITime::Draw()
{
	Vector2F data = pos_;


	// 表示数計算
	static Vector2F offset = { 35.0f,0.0f };

	// フレーム
	Vector2F fData = data;
	DrawRotaGraph(fData.x, fData.y, size_, angle_, imgFrame_, true);

	// タイマー
	Vector2F tData = data;
	tData -= {100.0f, 10.0f};
	DrawRotaGraph(tData.x, tData.y, size_ * 1.5f, angle_, imgTimer_, true);

	float time = MyTimer.GetTime("GAME_TIME");

	float offsetSize = 0.0f;

	if (time < 5.0f) {
		offsetSize = ((sinf(time * 5.0f)) + 1.0f) / 4.0f;
	}


	// 分
	int mini = (int)(time / 60.0f);

	data -= {30.0f, 0.0f};
	//DrawRotaGraph(data.x, data.y, size_, angle_, imgs_[mini / 10], true);
	//data += offset;




	DrawRotaGraph(data.x, data.y, (size_ + offsetSize) * 0.5f, angle_, imgs_[mini % 10], true);
	data += offset;


	// コロン
	Vector2F cData = data;
	DrawRotaGraph(cData.x, cData.y, (size_ + offsetSize) * 0.5f, angle_, imgColon_, true);
	data += offset;

	int sec = (int)(time - (float)mini * 60.0f);

	DrawRotaGraph(data.x, data.y, (size_ + offsetSize) * 0.5f, angle_, imgs_[sec / 10], true);
	data += offset;
	DrawRotaGraph(data.x, data.y, (size_ + offsetSize) * 0.5f, angle_, imgs_[sec % 10], true);
	data += offset;


	//// コロン
	//cData = data;
	//DrawRotaGraph(cData.x, cData.y, size_, angle_, img_, true);
	//data += offset;

	//int miri = (int)((time - (float)mini * 60.0f - (float)sec) * 100.0f);

	//render_->Draw(data, miri / 10);
	//data.pos_ += offset;
	//render_->Draw(data, miri % 10);
}
