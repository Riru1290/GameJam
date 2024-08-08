#pragma once
#include"CharacterBase.h"
class Player:
	public CharacterBase
{
public:

	Player(void);
	~Player(void)override;

	void SetParam(void)override;
	void Move(void)override;

private:
	void GamePadController(void);	// ゲームパッドの操作
	DIR CheckDir(float deg);					//方向決め

};

