#include "CPUBase.h"


CPUBase::CPUBase()
{
}

CPUBase::~CPUBase()
{
}

void CPUBase::SetParam(void)
{
	canMove_ = false;
	waitTime_ = GetRand(WAIT_MAX);
	waitCounter_ = 0;
	speed_ = 2.0f;
	moveLimit_ = MOVE_MAX;
	DecideDir();
}

void CPUBase::Move(void)
{

	if (!canMove_)
	{
		waitCounter_++;
		if (waitCounter_ > waitTime_)FinishWait();
		return;
	}
	//動いてないとき方向決め
	if (!isMove_) { DecideDir(); }
	//動いている状態に
	SetIsMove(true);

	pos_ += Vector2F{ moveDir_.x* speed_, moveDir_.y* speed_ };

	auto diff = Utility::Distance(pos_.ToVector2(), moveStartPos_.ToVector2());

	if (static_cast<int>(diff) > moveLimit_) { SetIsMove(false); }
}

void CPUBase::SetIsMove(const bool flag)
{
	isMove_ = flag;
}

void CPUBase::FinishWait(void)
{
	canMove_ = true;
}



void CPUBase::DecideDir(void)
{
	//スタートポジション設定
	moveStartPos_ = pos_;

	//移動量変更
	moveLimit_ = GetRand(MOVE_MAX - MOVE_MIN) + MOVE_MIN;

	//方向決め
	dir_ = static_cast<DIR>(rand() % static_cast<int>(DIR::MAX));
	ResetAnim(dir_);

	auto moveDir = Utility::VECTOR_ZERO;
	//動く方向に応じた単位ベクトルと回転の角度の指定
	int rot = ROT_UNIT;

	switch (dir_)
	{
	case DIR::BOTTOM:
		moveDir = { 0.0f,1.0f,0.0f };
		rot *= ROT_BTM;
		break;
	case DIR::LEFT:
		moveDir = { -1.0f,0.0f,0.0f };
		rot *= ROT_LFT;
		break;
	case DIR::RIGHT:
		moveDir = { 1.0f,0.0f,0.0f };
		rot *= ROT_RGH;
		break;
	case DIR::TOP:
		moveDir = { 0.0f,-1.0f,0.0f };
		rot *= ROT_TOP;
		break;
	case DIR::BOTTOM_LEFT:
		moveDir = { -1.0f,1.0f,0.0f };
		rot *= ROT_BTM_LFT;
		break;
	case DIR::BOTTOM_RIGHT:
		moveDir = { 1.0f,1.0f,0.0f };
		rot *= ROT_BTM_RGH;
		break;
	case DIR::TOP_LEFT:
		moveDir = { -1.0f,-1.0f,0.0f };
		rot *= ROT_TOP_LFT;
		break;
	case DIR::TOP_RIGHT:
		moveDir = { 1.0f,-1.0f,0.0f };
		rot *= ROT_TOP_RGH;
		break;
	}

	//単位行列
	MATRIX mat = MGetIdent();
	//移動方向の回転
	moveDir_ = VTransform(moveDir, mat);
}