#pragma once
#include"CharacterBase.h"

class CPUBase :
	public CharacterBase
{
public:
	static constexpr int MOVE_MAX = 100;
	static constexpr int MOVE_MIN = 50;
	static constexpr int WAIT_MAX = 120;

	CPUBase();
	~CPUBase();

	void SetParam(void)override;
	void Move(void)override;
	

protected:
	VECTOR moveDir_;	//���������̃x�N�^�[
	float speed_;		//�����̑���
	int moveLimit_;		//�����̑���
private:
	Vector2F moveStartPos_;	//�����n�߂̏ꏊ��ێ�int moveLimit_;	//���ł̈ړ��}�X�ʌ��x
	bool isMove_;	//�ړ����Ă��邩�ǂ���
	bool canMove_;	//�ړ����Ă������ǂ���
	int waitTime_;	//�҂����Ԑݒ�
	int waitCounter_;	//�҂����Ԃ̃J�E���^�[

	void SetIsMove(const bool flag);		//�ړ����I��������
	void FinishWait(void);		//�ҋ@���Ԃ��I��������
	void DecideDir(void);					//��������
};