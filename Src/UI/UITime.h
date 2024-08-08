#pragma once
#include "UIBase.h"

class UITime : public UIBase
{
public:

	UITime();
	~UITime();

private:

	void Draw() override;

	int* imgs_;
	int imgColon_;
	int imgTimer_;
	int imgFrame_;
};

