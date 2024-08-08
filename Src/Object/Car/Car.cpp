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

	isCheckOffScreen_ = false;
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

	if (isCheckOffScreen_ &&
		Utility::IsIncludedInArea(1280.0f, 720.0f, Vector2F(640.0f, 360.0f), pos_)) {

	}

}

void Car::Draw(void)
{
	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, img_, true);
}

void Car::Release(void)
{

}
