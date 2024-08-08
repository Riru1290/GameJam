#pragma once
#include"CharacterBase.h"
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
	void SetNearFruit(const bool flag);

private:
	void GamePadController(void);	// �Q�[���p�b�h�̑���
	DIR CheckDir(float deg);					//��������
	
	bool nearFruit_;
};

