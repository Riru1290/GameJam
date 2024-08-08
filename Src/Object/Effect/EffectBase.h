#pragma once
#include "../../Common/ResourceManager.h"
#include "../Object.h"

class Animation2DController;

class EffectBase : public Object
{
public:

	EffectBase(
		bool isFollow,
		bool isLoop,
		reference_wrapper<const Vector2F> follower,
		ResourceManager::SRC src,
		bool isRevXDraw,
		bool isRevYDraw, 
		Vector2F pos, 
		float angle, 
		float size, 
		Vector2F relativePos,
		int animNoSt, int animNoEd, float speed = 1.0f, bool isReversible = false);
	~EffectBase();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

	[[nodiscard]] float GetFootPos()const override;

private:

	int* imgs_;
	bool isRevX_;
	bool isRevY_;

	unique_ptr<Animation2DController> animCon_;

	reference_wrapper<const Vector2F> follower_;
	bool isFollow_;

	Vector2F relativePos_;
};

