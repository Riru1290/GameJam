#pragma once
#include"../Utility/Utility.h"

class CPUBase
{
public:
	void Move(void);

private:
	Position2D pos_;
	bool isMove_;	//移動しているかどうか

};