#pragma once
#include "UIBase.h"

class UIMove : public UIBase
{
public:

	UIMove(Vector2F stPos,Vector2F edPos,float time,string fileName);
	~UIMove();

private:

	void Draw() override;

	int img_;

	bool isStart_;

	Vector2F stPos_;
	Vector2F edPos_;
};

