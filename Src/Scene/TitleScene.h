#pragma once
#include "SceneBase.h"

class UIBase;

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;

private:

	int imgTitle_;

	// UI
	vector<shared_ptr<UIBase>> UIs_;
};

