#pragma once
#include "SceneBase.h"

class TutorialScene : public SceneBase
{
public:
	TutorialScene();
	~TutorialScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;

private:

	static constexpr int PAGE_NUM = (5);
	static constexpr int TUTORIAL_PAGE = (2);

	int imgs_[PAGE_NUM];

	int nowPage_;

	vector<int*> charaImg_;
};

