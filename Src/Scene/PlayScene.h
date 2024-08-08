#pragma once
#include "SceneBase.h"
#include "../Common/ResourceManager.h"


class CPUBase;
class Player;
class Apple;
class Object;
class UIBase;
class Stage;

class PlayScene : public SceneBase
{
public:

	PlayScene();
	~PlayScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;

	[[nodiscard]] const int& GetAppleNum()const { return appleNum_; };
 
private:

	vector<int*> charaImg_;

	vector<shared_ptr<CPUBase>> cpu_;
	shared_ptr<Player> player_;
	shared_ptr<Stage> stage_;
	//unordered_map<OBJECT_ID,shared_ptr<Object>> objects_;
	//unordered_map<OBJECT_ID,vector<shared_ptr<Object>>> objects_;
	vector<shared_ptr<Object>> objects_;


	// UI
	vector<shared_ptr<UIBase>> UIs_;

	static constexpr int APPLE_NUM_MAX = (4);
	Vector2F appleSpawnPos_[APPLE_NUM_MAX];

	// 現在残っているアップルの数
	int appleNum_;
};

