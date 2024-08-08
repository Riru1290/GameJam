#pragma once
#include"CharacterBase.h"
class Player:
	public CharacterBase
{
public:
	//定数
	static constexpr float UNIT_DIR_DEG = 45.0f;

	Player(void);
	~Player(void)override;

	void SetParam(void)override;
	void Move(void)override;

private:
	void GamePadController(void);	// ゲームパッドの操作
	DIR CheckDir(float deg);					//方向決め

};

