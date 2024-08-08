#pragma once
#include"CharacterBase.h"

class Apple;

class Player:
	public CharacterBase
{
public:
	//�萔
	static constexpr float UNIT_DIR_DEG = 45.0f;

	Player(void);
	~Player(void)override;

	void Update(void)override;
	void SetParam(void)override;
	void Move(void)override;
	void SetNearFruit(const bool flag, weak_ptr<Apple> apple);



private:
	void GamePadController(void);	// �Q�[���p�b�h�̑���
	DIR CheckDir(float deg);					//��������

	// �����S�擾
	void GetApple();
	
	bool nearFruit_;

	// �ł��߂������S��weak_ptr
	weak_ptr<Apple> nearApple_;
};

