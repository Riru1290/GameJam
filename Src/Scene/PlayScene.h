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
	static constexpr float APPLE_COL = 80.0f;
	
	PlayScene();
	~PlayScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;

	[[nodiscard]] const int& GetAppleNum()const { return appleNum_; };

	void GetApple(weak_ptr<Apple> apple);
 
private:

	vector<int*> charaImg_;

	//vector<shared_ptr<CPUBase>> cpu_;
	weak_ptr<Player> player_;

	vector<weak_ptr<Apple>> apples_;

	shared_ptr<Stage> stage_;

	vector<shared_ptr<Object>> objects_;


	// UI
	vector<shared_ptr<UIBase>> UIs_;



	static constexpr int APPLE_NUM_MAX = (4);
	Vector2F appleSpawnPos_[APPLE_NUM_MAX];

	// 現在残っているアップルの数
	int appleNum_;

	bool createEffectFlag_;
	weak_ptr<Apple> nearApple_;


	void CheckNearFruit(void);

	int lupinNo_;
};

