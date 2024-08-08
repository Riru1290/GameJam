#include "Apple.h"

Apple::Apple()
{
}

Apple::~Apple()
{
}

void Apple::Init(void)
{

	img_ = LoadGraph("Data/Img/Fruit/Apple Red.png");
	pos_ = { 100.0f,100.0f };
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
