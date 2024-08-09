#pragma once
class SoundManager
{
public:
	//�V���O���g����
	static bool CreateInstance(void);		//�C���X�^���X�̐���
	static SoundManager& GetInstance(void);	//�C���X�^���X�̎擾

	void Init(void);
	void Relese(void);

	void PlayBgmOfTitle(void);
	void StopBgmOfTitle(void);
	void PlayBgmOfGame(void);
	void StopBgmOfGame(void);
	void PlayBgmOfAnswer(void);
	void StopBgmOfAnswer(void);

	void PlaySndAnswer(void);
	void PlaySndEnter(void);
	void PlaySndMove(void);
	void PlaySndGet(void);

private:

	int titleBgm_;
	int gameBgm_;
	int answerBgm_;

	int answerSnd_;
	int enterSnd_;
	int moveSnd_;
	int getSnd_;

	SoundManager(void);
	void Destroy(void);	//�f�X�g���N�^
	static SoundManager* instance_;
};

