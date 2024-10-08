#include "Apple.h"

Apple::Apple(Vector2F spawnPos)
{
	pos_ = spawnPos;
	objectID_ = OBJECT_ID::APPLE;
	isLive_ = true;
	preIsLive_ = isLive_;
}

Apple::~Apple()
{
	DeleteGraph(img_);
}

void Apple::Init(void)
{

	img_ = LoadGraph("Data/Img/Fruit/Apple Red.png");
	GetGraphSize(img_, &imgSize_.x, &imgSize_.y);
	size_ = 3.0f;
	angle_ = 0.0f;
}

void Apple::Update(void)
{
	preIsLive_ = isLive_;
}

void Apple::Draw(void)
{
	//DrawCircle(pos_.x, pos_.y, 80, 0x00ff00, true);
	if(isLive_)
	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, img_, true);
}

void Apple::Release(void)
{
}

void Apple::Dead(void)
{
	isLive_ = false;
}
