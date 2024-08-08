#pragma once
#include "SceneBase.h"

class PlayScene : public SceneBase
{
public:

	PlayScene();
	~PlayScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;
};

