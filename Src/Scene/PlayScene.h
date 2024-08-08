#pragma once
#include "SceneBase.h"

class Apple;

class PlayScene : public SceneBase
{
public:

	PlayScene();
	~PlayScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;

private:

	shared_ptr<Apple> apple_;
};

