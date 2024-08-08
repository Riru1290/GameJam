#pragma once
#include"../../pch.h"

class CPUBase
{
public:
	void Move(void);

protected:
	VECTOR moveDir_;	//���������̃x�N�^�[
	float speed_;		//�����̑���
private:
	Vector2F pos_;	//���W
	Vector2F moveStartPos_;	//�����n�߂̏ꏊ��ێ�int moveLimit_;	//���ł̈ړ��}�X�ʌ��x
	bool isMove_;	//�ړ����Ă��邩�ǂ���

	void SetIsMove(const bool flag);
};