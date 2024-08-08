#pragma once
#include"../../pch.h"

class CPUBase
{
public:
	void Move(void);

protected:
	VECTOR moveDir_;	//動く方向のベクター
	float speed_;		//動きの速さ
private:
	Vector2F pos_;	//座標
	Vector2F moveStartPos_;	//動き始めの場所を保持int moveLimit_;	//一回での移動マス量限度
	bool isMove_;	//移動しているかどうか

	void SetIsMove(const bool flag);
};