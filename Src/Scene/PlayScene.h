#pragma once
#include "SceneBase.h"
#include "../Common/ResourceManager.h"


class CPUBase;
class Player;
class Apple;
class Object;
class UIBase;

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
	//unordered_map<OBJECT_ID,vector<shared_ptr<Object>>> objects_;
	vector<shared_ptr<Object>> objects_;


	// UI
	vector<shared_ptr<UIBase>> UIs_;
};

