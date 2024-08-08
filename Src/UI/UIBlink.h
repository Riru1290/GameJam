#pragma once
#include "UIBase.h"

class UIBlink : public UIBase
{
public:

	UIBlink(Vector2F pos,string filePath);
	~UIBlink();

private:


	void Draw() override;

	int img_;

	float a_;
	float timeCount_;
};

