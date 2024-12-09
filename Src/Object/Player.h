#pragma once
#include"CharacterBase.h"

class Apple;

class Player:
	public CharacterBase
{
public:
	//’è”
	static constexpr float UNIT_DIR_DEG = 45.0f;

	Player(void);
	~Player(void)override;

	void Update(void)override;
	void SetParam(void)override;
	void Move(void)override;
	void SetNearFruit(const bool flag, weak_ptr<Apple> apple);



private:
	void GamePadController(void);	// ƒQ[ƒ€ƒpƒbƒh‚Ì‘€ì
	DIR CheckDir(float deg);					//•ûŒüŒˆ‚ß

	// ƒŠƒ“ƒSæ“¾
	void GetApple();
	
	bool nearFruit_;

	// Å‚à‹ß‚¢ƒŠƒ“ƒS‚Ìweak_ptr
	weak_ptr<Apple> nearApple_;
};

