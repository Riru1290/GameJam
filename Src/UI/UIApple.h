#pragma once
#include "UIBase.h"

class UIApple : public UIBase
{
public:

	UIApple(reference_wrapper<const int> score);
	~UIApple();

private:

	void Draw() override;

	int* imgs_;
	int imgScore_;
	int imgApple_;
	int imgFrame_;

	reference_wrapper<const int> score_;
};

