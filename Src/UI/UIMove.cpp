#include "UIMove.h"

UIMove::UIMove(Vector2F stPos, Vector2F edPos, float time, string fileName)
{
	stPos_ = stPos;
	edPos_ = edPos;
	MyTimer.SetTimer("UIMove" + to_string(stPos_.y), time);

	img_ = LoadGraph(fileName.c_str());

	isStart_ = false;
}

UIMove::~UIMove()
{
	DeleteGraph(img_);
	MyTimer.Delete("UIMove" + to_string(stPos_.y));
}

void UIMove::Draw()
{
	if (!MyTimer.InProgress("UIMove" + to_string(stPos_.y)) && !isStart_) {
		MyTimer.Restart("UIMove" + to_string(stPos_.y));
		isStart_ = true;
	}

	float rate = 1.0f - MyTimer.GetTime("UIMove" + to_string(stPos_.y)) / MyTimer.GetMaxTime("UIMove" + to_string(stPos_.y));
	pos_ = Lerp(stPos_, edPos_, rate);

	DrawRotaGraph(pos_.x, pos_.y, 1.0f, 0.0f, img_, true);
}
