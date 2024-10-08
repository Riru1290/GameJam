#pragma once
#include"CharacterBase.h"

class Apple;

class Player:
	public CharacterBase
{
public:
	//定数
	static constexpr float UNIT_DIR_DEG = 45.0f;

	Player(void);
	~Player(void)override;

	void Update(void)override;
	void SetParam(void)override;
	void Move(void)override;
	void SetNearFruit(const bool flag, weak_ptr<Apple> apple);



private:
	void GamePadController(void);	// ゲームパッドの操作
	DIR CheckDir(float deg);					//方向決め

	// リンゴ取得
	void GetApple();
	
	bool nearFruit_;

	// 最も近いリンゴのweak_ptr
	weak_ptr<Apple> nearApple_;
};

