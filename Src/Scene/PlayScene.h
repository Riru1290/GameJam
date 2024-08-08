#pragma once
#include "SceneBase.h"
#include "../Common/ResourceManager.h"

<<<<<<< HEAD
class CPUBase;
class Player;
class Apple;
=======
class Object;
class UIBase;
>>>>>>> 0d07b3ad952a44b8839f43943c6d655a51bfa52d

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

<<<<<<< HEAD
	vector<int*> charaImg_;

	vector<shared_ptr<CPUBase>> cpu_;
	shared_ptr<Player> player_;
	shared_ptr<Apple> apple_;
=======
	unordered_map<OBJECT_ID,shared_ptr<Object>> objects_;

	//shared_ptr<Apple> apple_;

	//// ŽÔ
	//vector<shared_ptr<Car>> cars_;

	// UI
	vector<shared_ptr<UIBase>> UIs_;
>>>>>>> 0d07b3ad952a44b8839f43943c6d655a51bfa52d
};

