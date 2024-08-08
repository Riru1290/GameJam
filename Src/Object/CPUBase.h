#pragma once
#include"../../pch.h"
#include"CharacterBase.h"

class CPUBase :
	public CharacterBase
{
public:
	void SetParam(void)override;
	void Move(void)override;
	

protected:
	VECTOR moveDir_;	//���������̃x�N�^�[
	float speed_;		//�����̑���
private:
	Vector2F moveStartPos_;	//�����n�߂̏ꏊ��ێ�int moveLimit_;	//���ł̈ړ��}�X�ʌ��x
	bool isMove_;	//�ړ����Ă��邩�ǂ���

	void SetIsMove(const bool flag);
	void DecideDir(void);					//��������
};