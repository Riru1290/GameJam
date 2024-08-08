#pragma once
#include "UIBase.h"

class UIBasic : public UIBase
{
public:

	UIBasic(Vector2F pos, float size, string path);
	~UIBasic();

private:

	void Draw() override;

	int img_;

};

