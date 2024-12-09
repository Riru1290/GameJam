#pragma once
class Animation2DController
{
public:

	Animation2DController();
	~Animation2DController();

	void Playing();

	/// アニメーション追加
	/// @param key 任意のキー
	/// @param animNoSt 分割画像の何番目
	void SetAnimData(string key, int animNoSt, int animNoEd, 
		float speed = 1.0f , bool isReversible = false);

	void ChangeAnimation(string key);

	// 表示されるアニメーション番号を取得
	[[nodiscard]] int GetDisplayNo()const;

	// 現在再生中のアニメーションキー
	[[nodiscard]] const string& GetAnimationKey()const { return key_; };

	void Reset();
	void Reset(string key);

	// アニメーション再生位置を指定
	void SetDisplayNo(int no);
	void SetDisplayNo(string key,int no);

	// アニメーション倍率を設定
	void SetSpeed(float speed);
	void SetSpeed(string key,float speed);

	// アニメーションを再生
	void Play();
	void Play(string key);

	// アニメーションをストップ
	void Stop();
	void Stop(string key);

	// アニメーションを逆再生
	void Reversible(bool on);
	void Reversible(string key, bool on);

	// アニメーション再生後ストップさせる
	void SetStopAfterPlay(string key, bool on);

	// アニメーションが終了しているかどうか
	bool IsEnd(string key);

private:

	static constexpr float ANIM_CHANGE_TIME = 0.1f;	// 次の画像に切り替える時間

	struct ANIM_DATA
	{
		// 変更しない
		int animNoSt_ = 0;		// アニメーション番号(初期値)
		int animNoEd_ = 0;		// アニメーション番号(最後)

		// 変更の可能性あり
		int displayNo_ = 0;
		float speed_ = 1.0f;	// 再生倍率(通常は1秒で次の画像に切り替わる)
		bool isStop_ = false;		// 再生ストップ
		bool isReversible_ = false;	// 逆再生
		bool isStopAfterPlay_ = false;

		float animTime_ = 0.0f;

		bool isEnd_ = false;

		void Playing() {


			if (isStop_) return;

			animTime_ += MyTimer.GetDelta() * speed_;
			isEnd_ = false;
			if (animTime_ < ANIM_CHANGE_TIME) return;

			if (isReversible_) {


				isEnd_ = (isStopAfterPlay_ && (displayNo_ == animNoSt_));

				displayNo_--;

				if (isStopAfterPlay_) {
					displayNo_ = (displayNo_ < animNoSt_) ? animNoSt_ : displayNo_;
				}
				else {
					displayNo_ = (displayNo_ < animNoSt_) ? animNoEd_ : displayNo_;
				}


			}
			else{

				isEnd_ = (isStopAfterPlay_ && (displayNo_ == animNoEd_));

				displayNo_++;

				if (isStopAfterPlay_) {
					displayNo_ = (displayNo_ > animNoEd_) ? animNoEd_ : displayNo_;
				}
				else {
					displayNo_ = (displayNo_ > animNoEd_) ? animNoSt_ : displayNo_;
				}

			}

			if (isEnd_ && isStopAfterPlay_) {
				isStop_ = true;
			}

			animTime_ = 0.0f;
		}

		void Reset() {
			isStop_ = false;
			animTime_ = 0.0f;
			if (isReversible_) {
				displayNo_ = animNoEd_;
				isEnd_ = (isStopAfterPlay_ && (displayNo_ == animNoSt_));
			}
			else{
				displayNo_ = animNoSt_;
				isEnd_ = (isStopAfterPlay_ && (displayNo_ == animNoEd_));
			}


				
		}
	};

	unordered_map<string, ANIM_DATA> animData_;

	string key_ = "";
};

