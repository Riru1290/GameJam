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
	//�����ĂȂ��Ƃ���������
	if (!isMove_) { DecideDir(); }
	//�����Ă����Ԃ�
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
	//�X�^�[�g�|�W�V�����ݒ�
	moveStartPos_ = pos_;

	//�ړ��ʕύX
	moveLimit_ = GetRand(MOVE_MAX - MOVE_MIN) + MOVE_MIN;

	//��������
	dir_ = static_cast<DIR>(rand() % static_cast<int>(DIR::MAX));
	ResetAnim(dir_);

	auto moveDir = Utility::VECTOR_ZERO;
	//���������ɉ������P�ʃx�N�g���Ɖ�]�̊p�x�̎w��
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

	//�P�ʍs��
	MATRIX mat = MGetIdent();
	//�ړ������̉�]
	moveDir_ = VTransform(moveDir, mat);
}