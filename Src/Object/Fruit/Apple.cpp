#include "Apple.h"

Apple::Apple(Vector2F spawnPos)
{
	pos_ = spawnPos;
	objectID_ = OBJECT_ID::APPLE;
}

Apple::~Apple()
{
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
}

void Apple::Draw(void)
{
	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, img_, true);
}

void Apple::Release(void)
{
	DeleteGraph(img_);
}
