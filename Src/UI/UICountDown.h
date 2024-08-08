#pragma once
#include "UIBase.h"

class UICountDown : public UIBase
{
public:

	UICountDown();
	~UICountDown();

private:

	void Draw() override;

	int* imgs_;
	int imgGameStart_;
};

