#include "../Common/Animation2DController.h"
#include "EffectBase.h"

EffectBase::EffectBase(ResourceManager::SRC src, int animNoSt, int animNoEd, float speed, bool isReversible)
{
	imgs_ = ResourceManager::GetInstance().Load(src).handleIds_;

	GetGraphSize(imgs_[0], &imgSize_.x, &imgSize_.y);

	animCon_ = make_unique<Animation2DController>();
	animCon_->SetAnimData("EFFECT", animNoSt, animNoEd, speed, isReversible);
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
	animCon_->Playing();
	int animNo = animCon_->GetDisplayNo();

	DrawRotaGraph(pos_.x, pos_.y, size_, angle_, imgs_[animNo], true);
}

void EffectBase::Release(void)
{
}
