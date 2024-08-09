#include "../Object/Fruit/Apple.h"
#include"../Common/ResourceManager.h"
#include"../Object/CharacterBase.h"
#include"../Object/CPUBase.h"
#include"../Object/Player.h"
#include"../Object/Stage.h"
#include "../Object/Car/Car.h"
#include "../Object/Building/Building.h"
#include "../Object/Effect/EffectBase.h"
#include "../UI/UITime.h"
#include "../UI/UIApple.h"
#include "../UI/UICountDown.h"
#include "../UI/UIBasic.h"
#include "SceneManager.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
	auto& rsM = ResourceManager::GetInstance();
	charaImg_ = {
	rsM.Load(ResourceManager::SRC::CHARACTER_1).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_2).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_3).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_4).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_5).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_6).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_7).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_8).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_9).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_10).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_11).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_12).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_13).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_14).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_15).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_16).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_17).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_18).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_19).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_20).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_21).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_22).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_23).handleIds_,
	rsM.Load(ResourceManager::SRC::CHARACTER_24).handleIds_,
	};
}

void PlayScene::Init()
{
	MyTimer.SetTimer("GAME_TIME", 60.0f);
	MyTimer.SetTimer("GAME_START_TIME", 3.0f,true);
	MyTimer.SetTimer("CAR_SPAWN_TIME", 2.0f,true);


	int playerNum = GetRand(charaImg_.size() - 1);
	lupinNo_ = playerNum;
	for (int i = 0; i < charaImg_.size(); i++)
	{
		if (i != playerNum)
		{
			auto CPU = make_shared<CPUBase>();
			CPU->Init(charaImg_[i]);

			objects_.emplace_back(CPU);
			//cpu_.push_back(CPU);
		}
		else
		{
			auto player = make_shared<Player>();
			player->Init(charaImg_[i]);
			player_ = player;

			objects_.emplace_back(player);
		}
	}
	stage_ = make_shared<Stage>();
	stage_->Init();

	// ビル
	{
		shared_ptr<Object> bill = make_shared<Building>(
			Vector2F(0.0f,0.0f),
			ResourceManager::SRC::BILL_1);
		objects_.emplace_back(bill);
	}

	appleSpawnPos_[0] = { 300.0f,100.0f};
	appleSpawnPos_[1] = { 600.0f,600.0f };
	appleSpawnPos_[2] = { 300.0f,600.0f };
	appleSpawnPos_[3] = { 600.0f,100.0f };

	appleNum_ = 0;
	for (int i = 0; i < APPLE_NUM_MAX; i++) {
		shared_ptr<Object> apple = make_shared<Apple>(appleSpawnPos_[i]);
		apple->Init();
		objects_.emplace_back(apple);

		apples_.emplace_back(dynamic_pointer_cast<Apple>(apple));
		appleNum_++;
	}


	shared_ptr<UIBase> tempUI;
	tempUI = make_shared<UITime>();
	UIs_.emplace_back(tempUI);

	tempUI = make_shared<UIApple>(cref(GetAppleNum()));
	UIs_.emplace_back(tempUI);

	tempUI = make_shared<UICountDown>();
	UIs_.emplace_back(tempUI);

	tempUI = make_shared<UIBasic>(Vector2F(150.0f,650.0f),0.65f, "Data/Img/UI/appleTuto.png");
	UIs_.emplace_back(tempUI);

	createEffectFlag_ = false;
}

void PlayScene::Update()
{
	if (MyTimer.IsEndTimer("GAME_TIME") || 
		appleNum_ <= 0) {
		SceneMng.ChangeScene(SCENE_ID::ANSWER);
		SceneMng.SetLupinNo(lupinNo_);
	}

	if (MyTimer.IsEndTimer("GAME_START_TIME") &&
		!MyTimer.InProgress("GAME_TIME")) {
		MyTimer.Start("GAME_TIME");
	}

	//for (auto& c : cpu_)c->Update();
	//player_->Update();
	if (MyTimer.IsEndTimer("CAR_SPAWN_TIME")) {
		MyTimer.Restart("CAR_SPAWN_TIME");
		shared_ptr<Object> tempCar;
		tempCar = make_shared<Car>();
		objects_.emplace_back(tempCar);

		bool isRevXDraw = false;
		bool isRevYDraw = false;
		float angle = 0.0f;
		Vector2F relativePos = {};
		auto moveDir = dynamic_pointer_cast<Car>(tempCar)->GetMoveDir();
		if (moveDir.x == 1.0f) {
			isRevXDraw = true;
			relativePos = { -150.0f,-5.0f };
		}
		else if (moveDir.x == -1.0f) {

			isRevXDraw = false;
			relativePos = { 150.0f,-5.0f };
		}
		else if (moveDir.y == 1.0f) {

			relativePos = { -5.0f,-150.0f };
			angle = Utility::Deg2RadF(-90.0f);
		}
		else if (moveDir.y == -1.0f) {

			relativePos = { 5.0f,150.0f };
			angle = Utility::Deg2RadF(90.0f);
		}

		// エフェクト
		shared_ptr<Object> tempSmoke;
		tempSmoke = make_shared<EffectBase>(
			true,
			true,
			cref(tempCar->GetPosition()),
			ResourceManager::SRC::EFFECT_1,
			isRevXDraw,
			isRevYDraw,
			tempCar->GetPosition(),
			angle,
			tempCar->GetSize(),
			relativePos,
			0, 9
		);
		objects_.emplace_back(tempSmoke);

	}

	if (createEffectFlag_) {
		// エフェクト
		shared_ptr<Object> tempSmoke;
		tempSmoke = make_shared<EffectBase>(
			false,
			false,
			cref(nearApple_.lock()->GetPosition()),
			ResourceManager::SRC::EFFECT_2,
			false,
			false,
			nearApple_.lock()->GetPosition(),
			0.0f,
			2.0f,
			Vector2F(),
			0, 41, 2.0f
		);
		objects_.emplace_back(tempSmoke);

		createEffectFlag_ = false;
	}

	for (auto obj : objects_) {
		obj->Update();
	}

	CheckNearFruit();
}

void PlayScene::Draw()
{
	if (CheckHitKey(KEY_INPUT_E)) {
		SceneMng.ChangeScene(SCENE_ID::ANSWER);
	}
	DrawFormatString(0, 0, 0xffffff, "PlayScene");
	DrawFormatString(0, 20, 0xffffff, "GameTime : %f", MyTimer.GetTime("GAME_TIME"));
	DrawFormatString(0, 40, 0xffffff, "GameStartTime : %f", MyTimer.GetTime("GAME_START_TIME"));


	//for (auto& c : cpu_)c->Draw();
	//player_->Draw();

	sort(objects_.begin(), objects_.end(), [](weak_ptr<Object> a, weak_ptr<Object> b) {
		return a.lock()->GetFootPos() < b.lock()->GetFootPos();
		});

	for (auto obj : objects_) {
		obj->Draw();
	}

	for (auto UI : UIs_) {
		UI->Draw();
	}

	stage_->Draw();
}

void PlayScene::Release()
{
	MyTimer.Delete("GAME_TIME");
	MyTimer.Delete("GAME_START_TIME");
	StopJoypadVibration(DX_INPUT_PAD1, -1);

	//for (auto& c : cpu_)c->Release();
	//player_->Release();
	for (auto obj : objects_) {
		obj->Release();
	}

	objects_.clear();
}

void PlayScene::GetApple(weak_ptr<Apple> apple)
{
	if (apple.expired())return;

	apple.lock()->Dead();

	appleNum_--;

	nearApple_ = apple;

	createEffectFlag_ = true;

}

void PlayScene::CheckNearFruit(void)
{
	bool ret = false;
	int i = -1;
	for (auto& app : appleSpawnPos_)
	{

		i++;
		auto diff = Utility::Distance(player_.lock()->GetPos().ToVector2(), app.ToVector2());
		if (diff < APPLE_COL && apples_[i].lock()->IsAlive())
		{
			ret = true;
			break;
		}
	}

	if(ret)player_.lock()->SetNearFruit(true,apples_[i]);
	else player_.lock()->SetNearFruit(false, apples_[i]);


}
