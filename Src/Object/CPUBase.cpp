#include "CPUBase.h"
#include"../Common/Vector2F.h"
#include"../Utility/Utility.h"

void CPUBase::Move(void)
{
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
