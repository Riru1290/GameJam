#include "UIBlink.h"

UIBlink::UIBlink(Vector2F pos, string filePath)
{
	img_ = LoadGraph(filePath.c_str());

	pos_ = pos;
	a_ = 0.0f;
	timeCount_ = 0.0f;
}

UIBlink::~UIBlink()
{
	DeleteGraph(img_);
}

void UIBlink::Draw()
{
	a_ = pow(sinf(timeCount_), 20.0f);
	timeCount_ += MyTimer.GetDelta();

	float a = (float)255 * (1.0f - a_);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)a);

	DrawRotaGraph(pos_.x, pos_.y, 1.0f, 0.0f, img_, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
