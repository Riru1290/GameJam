#pragma once

class CPUBase
{
public:
	void Move(void);

private:
	Vector2F pos_;
	bool isMove_;	//移動しているかどうか

};