#pragma once
#include "UIBase.h"

class UIFade : public UIBase
{
public:

	UIFade(Vector2F pos,float inDisplayTime, float fadeInTime, float fadeOutTime, float displayTime, bool isFadeOut_,string fileName);
	~UIFade();

private:

	void Draw() override;

	float a_;
	float timeCount_;

	// •\Ž¦‚µŽn‚ß‚é‚Ü‚Å‚ÌŽžŠÔ
	float inDisplayTime_;

	float fadeInTime_;
	float fadeOutTime_;
	float displayTime_;

	bool isFadeOut_;

	int img_;
};

