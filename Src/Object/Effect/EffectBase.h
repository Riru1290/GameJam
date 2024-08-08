#pragma once
#include "../../Common/ResourceManager.h"
#include "../Object.h"

class Animation2DController;

class EffectBase : public Object
{
public:

	EffectBase(ResourceManager::SRC src,int animNoSt, int animNoEd, float speed = 1.0f, bool isReversible = false);
	~EffectBase();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

private:

	int* imgs_;

	unique_ptr<Animation2DController> animCon_;
};

