#pragma once
#include "SceneBase.h"

class AnswerScene : public SceneBase
{
public:
	AnswerScene();
	~AnswerScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;
};

