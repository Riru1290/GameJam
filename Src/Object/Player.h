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
	void GamePadController(void);	// �Q�[���p�b�h�̑���
	DIR CheckDir(float deg);					//��������

};

