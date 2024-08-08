#pragma once
#include "SceneBase.h"

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

	unordered_map<OBJECT_ID,shared_ptr<Object>> objects_;

	//shared_ptr<Apple> apple_;

	//// ŽÔ
	//vector<shared_ptr<Car>> cars_;

	// UI
	vector<shared_ptr<UIBase>> UIs_;
};

