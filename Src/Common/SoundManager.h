#pragma once
class SoundManager
{
public:
	//シングルトン化
	static bool CreateInstance(void);		//インスタンスの生成
	static SoundManager& GetInstance(void);	//インスタンスの取得

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
	void Destroy(void);	//デストラクタ
	static SoundManager* instance_;
};

