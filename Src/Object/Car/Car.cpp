#include "Car.h"

Car::Car(Vector2F moveDir, Vector2F pos)
{
	objectID_ = OBJECT_ID::CAR;
	state_ = STATE::MOVE;
	moveDir_ = moveDir;
	img_ = LoadGraph("Data/Img/Obstacle/car.png");

	pos_ = pos;
	size_ = 3.0f;
	angle_ = 0.0f;
}

Car::~Car()
{
}

void Car::Init(void)
{

}

void Car::Update(void)
{
	pos_ += moveDir_ * MOVE_POW;
}

void Car::Draw(void)
{
	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, img_, true);
}

void Car::Release(void)
{

}
