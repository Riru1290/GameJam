#pragma once

#define MyTimer Timer::GetInstance()

class Timer
{

public:

	static Timer& GetInstance();

	void Run();
	void ResetMyTimer();

	void Reset(string key);
	void Start(string key);
	void Stop(string key);
	void Restart(string key);

	void Terminate();

	void Delete(string key);

	void SetTimer(string key ,float maxTime , bool start = false);
	void SetTime(string key ,float time);

	void MultDelta(float& val);
	float GetMultDelta(const float& val);

	// 時間を指定時間,指定のスピードで進ませる
	void SetWitchTimeOnMyTimer(float rate, float time);

	[[nodiscard]] float GetDelta()const { return deltaTime_ * whichTimeRate_; };
	[[nodiscard]] float GetTime(string key)const;
	[[nodiscard]] float GetMaxTime(string key)const;

	// 現在の時間経過の割合を返す : 経過時間1秒,設定時間10秒の場合0.1が返される
	[[nodiscard]] float GetRate(string key)const;

	bool IsEndTimer(string key)const;
	bool InProgress(string key)const;

	// デルタタイム再計算
	void RecalculationDelta();

private:

	Timer();
	~Timer();

	float deltaTime_;
	chrono::system_clock::time_point preTime_;


	struct Process
	{
		bool isRunning_ = false;
		bool isForward_ = false;

		float time_ = 0.0f;
		float maxTime_ = 0.0f;

		bool isEnd_ = false;

		void Run()
		{
			if (!isRunning_)return;

			if (isForward_) {
				time_ += MyTimer.GetDelta();
			}
			else {
				time_ -= MyTimer.GetDelta();
				if (time_ <= 0.0f) {
					isEnd_ = true;
					isRunning_ = false;
					time_ = 0.0f;
				}
			}
		}

		void Reset()
		{
			if (isForward_) {
				time_ = 0.0f;
			}
			else {
				time_ = maxTime_;
			}

			isRunning_ = false;
			isEnd_ = false;
		}
	};

	unordered_map<string, Process> processes_;

	// 時間の経過速度
	float whichTimeRate_;
	float whichTime_;

};

