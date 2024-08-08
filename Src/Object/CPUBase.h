#pragma once
#include"CharacterBase.h"

class CPUBase :
	public CharacterBase
{
public:

	CPUBase();
	~CPUBase();

	void SetParam(void)override;
	void Move(void)override;
	

protected:
	VECTOR moveDir_;	//動く方向のベクター
	float speed_;		//動きの速さ
	int moveLimit_;		//動きの速さ
private:
	Vector2F moveStartPos_;	//動き始めの場所を保持int moveLimit_;	//一回での移動マス量限度
	bool isMove_;	//移動しているかどうか

	void SetIsMove(const bool flag);
	void DecideDir(void);					//方向決め


};