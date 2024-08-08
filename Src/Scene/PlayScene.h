#pragma once
#include "SceneBase.h"
#include "../Common/ResourceManager.h"

class CPUBase;
class Player;
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

	vector<int*> charaImg_;

	vector<shared_ptr<CPUBase>> cpu_;
	shared_ptr<Player> player_;
	shared_ptr<Apple> apple_;
};

