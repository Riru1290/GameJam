#include "UIFade.h"

UIFade::UIFade(Vector2F pos, float inDisplayTime, float fadeInTime, float fadeOutTime, float displayTime, bool isFadeOut, string fileName)
{
	pos_ = pos;

	a_ = 0.0f;
	timeCount_ = 0.0f;

	inDisplayTime_ = inDisplayTime;

	fadeInTime_ = fadeInTime;
	fadeOutTime_ = fadeOutTime;
	displayTime_ = displayTime;

	isFadeOut_ = isFadeOut;

	img_ = LoadGraph(fileName.c_str());
}

UIFade::~UIFade()
{
	DeleteGraph(img_);
}

void UIFade::Draw()
{
	if (inDisplayTime_ >= timeCount_) {
		timeCount_ += MyTimer.GetDelta();
		return;
	}
	else if (fadeInTime_ >= timeCount_ - inDisplayTime_) {
		a_ = 1.0f - ((timeCount_ - inDisplayTime_) / fadeInTime_);
	}
	else if (fadeInTime_ + displayTime_ >= timeCount_ - inDisplayTime_) {
		a_ = 0.0f;
	}
	else if (!isFadeOut_) {
		a_ = 0.0f;
	}
	else if (fadeInTime_ + displayTime_ + fadeOutTime_ >= timeCount_ - inDisplayTime_) {
		a_ = ((timeCount_ - inDisplayTime_ - displayTime_ - fadeInTime_) / fadeOutTime_);
	}
	else {
		a_ = 0.0f;
	}

	timeCount_ += MyTimer.GetDelta();

	
	float a = (float)255 * (1.0f - a_);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)a);

	DrawRotaGraph(pos_.x, pos_.y, 1.0f, 0.0f, img_, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);



}
