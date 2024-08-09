#include "Car.h"

Car::Car()
{
	objectID_ = OBJECT_ID::CAR;
	state_ = STATE::MOVE;
	moveDir_ = {};



	int radCarNo = GetRand(_countof(CAR_TYPE_SRC) - 1);

	img_ = ResourceManager::GetInstance().Load(CAR_TYPE_SRC[radCarNo]).handleId_;

	GetGraphSize(img_, &imgSize_.x, &imgSize_.y);

	spawnInfoHor_ = { pair(Vector2F(-100.0f,100.0f),Vector2F(1.0f,0.0f)),
					  pair(Vector2F(1300.0f,570.0f),Vector2F(-1.0f,0.0f)) };
	spawnInfoVer_ = { pair(Vector2F(160.0f,-100.0f),Vector2F(0.0f,1.0f)),
					  pair(Vector2F(630.0f,800.0f),Vector2F(0.0f,-1.0f)) };

	if (CAR_TYPE_SRC[radCarNo] == ResourceManager::SRC::CAR_5 ||
		CAR_TYPE_SRC[radCarNo] == ResourceManager::SRC::CAR_6) {

		int randNo = GetRand(spawnInfoVer_.size() - 1);

		// ècà⁄ìÆ
		pos_ = spawnInfoVer_[randNo].first;
		moveDir_ = spawnInfoVer_[randNo].second;


		revFlagY_ = (moveDir_.y == -1.0f);
	}
	else {

		int randNo = GetRand(spawnInfoHor_.size() - 1);

		// â°à⁄ìÆ
		pos_ = spawnInfoHor_[randNo].first;
		moveDir_ = spawnInfoHor_[randNo].second;

		revFlagX_ = (moveDir_.x == 1.0f);
	}


	
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
		if (Utility::IsIncludedInArea(1500.0f, 800.0f, Vector2F(640.0f, 360.0f), pos_)) {
			isCheckOffScreen_ = true;
		}
	}
	else {
		if (!Utility::IsIncludedInArea(1500.0f, 800.0f, Vector2F(640.0f, 360.0f), pos_)) {
			state_ = STATE::END;
		}
	}
}

void Car::Draw(void)
{
	if (state_ != STATE::MOVE)return;
	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, img_, true, revFlagX_, revFlagY_);
}

void Car::Release(void)
{

}
