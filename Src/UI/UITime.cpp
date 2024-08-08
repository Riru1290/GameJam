#include "UITime.h"

UITime::UITime() : UIBase()
{
	imgs_ = new int[10 * 1];
	LoadDivGraph("Data/Img/UI/number.png", 10, 10, 1, 160, 172, imgs_);
	imgColon_ = LoadGraph("Data/Img/UI/colon.png");
	imgTimer_ = LoadGraph("Data/Img/UI/Icon_Clock.png");
	imgFrame_ = LoadGraph("Data/Img/UI/Item5.png");
	pos_ = { 100.0f,100.0f };
	size_ = 0.75f;
	angle_ = 0.0f;
}

UITime::~UITime()
{
	for (int i = 0; i < 10; i++) {

		DeleteGraph(imgs_[i]);
	}
}


void UITime::Draw()
{
	Vector2F data = pos_;


	// 表示数計算
	static Vector2F offset = { 100.0f,0.0f };

	// フレーム
	Vector2F fData = data;
	fData += {710.0f / 2.0f, 0.0f};
	DrawRotaGraph(fData.x, fData.y, size_ * 1.2f, angle_, imgFrame_, true);

	// タイマー
	Vector2F tData = data;
	DrawRotaGraph(tData.x, tData.y, size_ * 1.2f, angle_, imgTimer_, true);

	float time = MyTimer.GetTime("GAME_TIME");
	// 分
	int mini = (int)(time / 60.0f);

	data += {150.0f, 0.0f};
	DrawRotaGraph(data.x, data.y, size_, angle_, imgs_[mini / 10], true);
	data += offset;
	DrawRotaGraph(data.x, data.y, size_, angle_, imgs_[mini % 10], true);
	data += offset;


	// コロン
	Vector2F cData = data;
	DrawRotaGraph(cData.x, cData.y, size_, angle_, imgColon_, true);
	data += offset;

	int sec = (int)(time - (float)mini * 60.0f);

	DrawRotaGraph(data.x, data.y, size_, angle_, imgs_[sec / 10], true);
	data += offset;
	DrawRotaGraph(data.x, data.y, size_, angle_, imgs_[sec % 10], true);
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
