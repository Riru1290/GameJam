#pragma once
class Animation2DController
{
public:

	Animation2DController();
	~Animation2DController();

	void Playing();

	/// �A�j���[�V�����ǉ�
	/// @param key �C�ӂ̃L�[
	/// @param animNoSt �����摜�̉��Ԗ�
	void SetAnimData(string key, int animNoSt, int animNoEd, 
		float speed = 1.0f , bool isReversible = false);

	void ChangeAnimation(string key);

	// �\�������A�j���[�V�����ԍ����擾
	[[nodiscard]] int GetDisplayNo()const;

	// ���ݍĐ����̃A�j���[�V�����L�[
	[[nodiscard]] const string& GetAnimationKey()const { return key_; };

	void Reset();
	void Reset(string key);

	// �A�j���[�V�����Đ��ʒu���w��
	void SetDisplayNo(int no);
	void SetDisplayNo(string key,int no);

	// �A�j���[�V�����{����ݒ�
	void SetSpeed(float speed);
	void SetSpeed(string key,float speed);

	// �A�j���[�V�������Đ�
	void Play();
	void Play(string key);

	// �A�j���[�V�������X�g�b�v
	void Stop();
	void Stop(string key);

	// �A�j���[�V�������t�Đ�
	void Reversible(bool on);
	void Reversible(string key, bool on);

	// �A�j���[�V�����Đ���X�g�b�v������
	void SetStopAfterPlay(string key, bool on);

	// �A�j���[�V�������I�����Ă��邩�ǂ���
	bool IsEnd(string key);

private:

	static constexpr float ANIM_CHANGE_TIME = 0.1f;	// ���̉摜�ɐ؂�ւ��鎞��

	struct ANIM_DATA
	{
		// �ύX���Ȃ�
		int animNoSt_ = 0;		// �A�j���[�V�����ԍ�(�����l)
		int animNoEd_ = 0;		// �A�j���[�V�����ԍ�(�Ō�)

		// �ύX�̉\������
		int displayNo_ = 0;
		float speed_ = 1.0f;	// �Đ��{��(�ʏ��1�b�Ŏ��̉摜�ɐ؂�ւ��)
		bool isStop_ = false;		// �Đ��X�g�b�v
		bool isReversible_ = false;	// �t�Đ�
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

