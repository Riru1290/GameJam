#include "Animation2DController.h"

// 無名ネームスペース
// このcpp内(翻訳単位)のみで使いますよ
// かぶり防止
namespace {
	// constexprはコンパイル時にただの値に置き換わる
	int test;
	constexpr float TEST = (0.0f);
}

Animation2DController::Animation2DController()
{
}

Animation2DController::~Animation2DController()
{
	animData_.clear();
}

void Animation2DController::Playing()
{
	if (animData_.size() <= 0) return;
	animData_.at(key_).Playing();
}

void Animation2DController::SetAnimData(string key, int animNoSt, int animNoEd, float speed , bool isReversible)
{
	ANIM_DATA data = {};
	data.animNoSt_ = animNoSt;
	data.animNoEd_ = animNoEd;
	data.speed_ = speed;
	data.isStop_ = false;
	data.isReversible_ = isReversible;
	data.displayNo_ = isReversible ? animNoEd : animNoSt;
	

	animData_.emplace(key, data);

	key_ = key;
}

void Animation2DController::ChangeAnimation(string key)
{
	if (key_ == key)return;

	if (!animData_.contains(key))return;

	animData_.at(key).Reset();
	key_ = key;
}

int Animation2DController::GetDisplayNo()const
{
	if (!animData_.contains(key_))return 0;

	return animData_.at(key_).displayNo_;
}

void Animation2DController::Reset()
{
	if (!animData_.contains(key_))return;

	animData_.at(key_).Reset();
}

void Animation2DController::Reset(string key)
{
	if (!animData_.contains(key))return;

	animData_.at(key).Reset();
}

void Animation2DController::SetDisplayNo(int no)
{
	if (!animData_.contains(key_))return;

	animData_.at(key_).displayNo_ = no;
}

void Animation2DController::SetDisplayNo(string key, int no)
{
	if (!animData_.contains(key))return;

	animData_.at(key).displayNo_ = no;
}

void Animation2DController::SetSpeed(float speed)
{
	if (!animData_.contains(key_))return;

	animData_.at(key_).speed_ = speed;
}

void Animation2DController::SetSpeed(string key, float speed)
{
	if (!animData_.contains(key))return;

	animData_.at(key).speed_ = speed;
}

void Animation2DController::Play()
{
	animData_.at(key_).isStop_ = false;
}

void Animation2DController::Play(string key)
{
	if (!animData_.contains(key))return;

	animData_.at(key).isStop_ = false;
}

void Animation2DController::Stop()
{
	if (!animData_.contains(key_))return;

	animData_.at(key_).isStop_ = true;
}

void Animation2DController::Stop(string key)
{
	if (!animData_.contains(key))return;

	animData_.at(key).isStop_ = true;
}

void Animation2DController::Reversible(bool on)
{
	if (!animData_.contains(key_))return;

	if (animData_.at(key_).isReversible_ != on) {
		animData_.at(key_).isStop_ = false;
	}

	animData_.at(key_).isReversible_ = on;
}

void Animation2DController::Reversible(string key, bool on)
{
	if (!animData_.contains(key))return;

	if (animData_.at(key).isReversible_ != on) {
		animData_.at(key).isStop_ = false;
	}

	animData_.at(key).isReversible_ = on;
}

void Animation2DController::SetStopAfterPlay(string key, bool on)
{
	if (!animData_.contains(key))return;

	animData_.at(key).isStopAfterPlay_ = on;
}

bool Animation2DController::IsEnd(string key)
{
	if (!animData_.contains(key))return true;

	return animData_.at(key).isEnd_;
}

