#pragma once
#include"../Utility/Utility.h"

class CPUBase
{
public:
	void Move(void);

private:
	Position2D pos_;
	bool isMove_;	//�ړ����Ă��邩�ǂ���

};