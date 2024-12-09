#include "UIBasic.h"

UIBasic::UIBasic(Vector2F pos, float size, string path)
{
	img_ = LoadGraph(path.c_str());
	pos_ = pos;
	size_ = size;
	angle_ = 0.0f;
}

UIBasic::~UIBasic()
{
	DeleteGraph(img_);
}

void UIBasic::Draw()
{
	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, img_, true);
}
