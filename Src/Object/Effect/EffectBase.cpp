#include "../Common/Animation2DController.h"
#include "EffectBase.h"

EffectBase::EffectBase(
	bool isFollow,
	bool isLoop ,
	reference_wrapper<const Vector2F> follower,
	ResourceManager::SRC src, 
	bool isRevXDraw,
	bool isRevYDraw, 
	Vector2F pos,
	float angle,
	float size,
	Vector2F relativePos,
	int animNoSt, int animNoEd, float speed, bool isReversible) :
	follower_(follower)
{
	relativePos_ = relativePos;
	isFollow_ = isFollow;

	imgs_ = ResourceManager::GetInstance().Load(src).handleIds_;
	pos_ = pos;
	angle_ = angle;
	size_ = size;
	GetGraphSize(imgs_[0], &imgSize_.x, &imgSize_.y);

	animCon_ = make_unique<Animation2DController>();
	animCon_->SetAnimData("EFFECT", animNoSt, animNoEd, speed, isReversible);
	if (!isLoop) {
		animCon_->SetStopAfterPlay("EFFECT", true);
	}

	isRevX_ = isRevXDraw;
	isRevY_ = isRevYDraw;
}

EffectBase::~EffectBase()
{
}

void EffectBase::Init(void)
{


}

void EffectBase::Update(void)
{
}

void EffectBase::Draw(void)
{
	if (animCon_->IsEnd("EFFECT"))return;

	animCon_->Playing();
	int animNo = animCon_->GetDisplayNo();

	if (isFollow_) {
		pos_ = follower_.get();
	}

	auto pos = pos_ + relativePos_;
	DrawRotaGraph(pos.x, pos.y, size_, angle_, imgs_[animNo], true, isRevX_, isRevY_);
}

void EffectBase::Release(void)
{
}

float EffectBase::GetFootPos() const
{
	auto pos = pos_ + relativePos_;
	float foosPos = pos.y + (imgSize_.y / 2.0f * size_);
	return foosPos;
}
