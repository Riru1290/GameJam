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

	if (!isCheckOffScreen_){
		if (Utility::IsIncludedInArea(1280.0f, 720.0f, Vector2F(640.0f, 360.0f), pos_)) {
			isCheckOffScreen_ = true;
		}
	}
	else {
		if (!Utility::IsIncludedInArea(1280.0f, 720.0f, Vector2F(640.0f, 360.0f), pos_)) {
			state_ = STATE::END;
		}
	}
}

void Car::Draw(void)
{
	if (state_ != STATE::MOVE)return;
	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, img_, true);
}

void Car::Release(void)
{

}
