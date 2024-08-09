#pragma once
#include"CharacterBase.h"

class CPUBase :
	public CharacterBase
{
public:
	static constexpr int MOVE_MAX = 100;
	static constexpr int MOVE_MIN = 50;
	static constexpr int WAIT_MAX = 120;

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
	bool canMove_;	//移動していいかどうか
	int waitTime_;	//待ち時間設定
	int waitCounter_;	//待ち時間のカウンター

	void SetIsMove(const bool flag);		//移動が終了したか
	void FinishWait(void);		//待機時間が終了したか
	void DecideDir(void);					//方向決め
};