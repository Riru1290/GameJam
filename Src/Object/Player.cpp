#include "../../pch.h"
#include"../Common/InputManager.h"
#include "Player.h"

Player::Player(void)
{
	nearFruit_ = false;
}

Player::~Player(void)
{
}

void Player::Update(void)
{
	CharacterBase::Update();

}

void Player::SetParam(void)
{
	pos_ = Vector2F{ 0.0f,0.0f };
}

void Player::Move(void)
{
	GamePadController();
}

void Player::SetNearFruit(const bool flag)
{
	if (nearFruit_ != flag)
	{
		if (flag)
			StartJoypadVibration(DX_INPUT_PAD1, 400, -1, -1);
		else 
			StopJoypadVibration(DX_INPUT_PAD1, -1);
	}
	nearFruit_ = flag;
}


void Player::GamePadController(void)
{
	InputManager& ins = InputManager::GetInstance();

	//ダッシュON
	if (ins.IsPadBtnNew(InputManager::JOYPAD_NO::PAD1, InputManager::JOYPAD_BTN::DOWN))
	{
		
	}

	auto prevDir = dir_;

	// 左スティックの横軸
	auto leftStickX = ins.GetInstance().GetJPadInputState(InputManager::JOYPAD_NO::PAD1).AKeyLX;
	// 左スティックの縦軸
	auto leftStickY = ins.GetInstance().GetJPadInputState(InputManager::JOYPAD_NO::PAD1).AKeyLY;
	//スティックの動きを合わせて保存
	Vector2 inputStick = { leftStickX,leftStickY };

	//移動
	if (inputStick.x > 0)pos_.x += move_/* * dash_*/;
	else if (inputStick.x < 0)pos_.x -= move_/* * dash_*/;

	if (inputStick.y > 0)pos_.y += move_/* * dash_*/;
	else  if (inputStick.y < 0) pos_.y -= move_ /** dash_*/;

	//方向決め
	auto stickRad = static_cast<float>(atan2(static_cast<double>(inputStick.y), static_cast<double>(inputStick.x)));
	auto stickDeg = static_cast<float>(Utility::DegIn360(Utility::Rad2DegF(stickRad)));

	auto dir = CheckDir(stickDeg);

	if (pos_.x != prevPos_.x || pos_.y != prevPos_.y)
	{
		SetDir(dir);
	}
	if (prevDir != dir_)ResetAnim(dir);
}

CharacterBase::DIR Player::CheckDir(float deg)
{
	//方向決め
	//各方向４５°ずつ
	int counter = 0;	//方向決めを何回行ったかをカウント。これに応じて方向をセット
	DIR ret = DIR::RIGHT;
	for (int i = 1; i <= static_cast<int>(DIR::MAX); i++)
	{
		if (deg <= (UNIT_DIR_DEG * i) + UNIT_DIR_DEG / 2 &&
			deg > (UNIT_DIR_DEG * i) - UNIT_DIR_DEG / 2)
		{
			counter = i;
			break;
		}
	}

	switch (counter)
	{
	case DIR_TOP:
		ret = DIR::TOP;
		break;
	case DIR_TOP_RGH:
		ret = DIR::TOP_RIGHT;
		break;
	case DIR_RGH:
		ret = DIR::RIGHT;
		break;
	case DIR_BTM_RGH:
		ret = DIR::BOTTOM_RIGHT;
		break;
	case DIR_BTM:
		ret = DIR::BOTTOM;
		break;
	case DIR_BTM_LFT:
		ret = DIR::BOTTOM_LEFT;
		break;
	case DIR_LFT:
		ret = DIR::LEFT;
		break;
	case DIR_TOP_LFT:
		ret = DIR::TOP_LEFT;
		break;
	}

	return ret;
}

