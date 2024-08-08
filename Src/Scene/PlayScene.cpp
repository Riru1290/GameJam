#include "../Object/Fruit/Apple.h"
<<<<<<< HEAD
#include"../Common/ResourceManager.h"
#include"../Object/CharacterBase.h"
#include"../Object/CPUBase.h"
#include"../Object/Player.h"
=======
#include "../Object/Car/Car.h"
#include "../UI/UITime.h"
#include "../UI/UIBase.h"
>>>>>>> 0d07b3ad952a44b8839f43943c6d655a51bfa52d
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
	};
}

void PlayScene::Init()
{
	MyTimer.SetTimer("GAME_TIME", 10.0f);
	MyTimer.SetTimer("GAME_START_TIME", 3.0f,true);
	MyTimer.SetTimer("CAR_SPAWN_TIME", 5.0f,true);

<<<<<<< HEAD
	int playerNum = GetRand(charaImg_.size());

	for (int i = 0; i < charaImg_.size(); i++)
	{
		if (i != playerNum)
		{
			auto CPU = make_shared<CPUBase>();
			CPU->Init(charaImg_[i]);
			cpu_.push_back(CPU);
		}
		else
		{
			player_ = make_shared<Player>();
			player_->Init(charaImg_[i]);
		}
	}

	apple_ = make_shared<Apple>();
	apple_->Init();
=======
	shared_ptr<Object> apple = make_shared<Apple>();
	apple->Init();

	objects_.emplace(OBJECT_ID::APPLE, apple);

	shared_ptr<UIBase> tempUI;
	tempUI = make_shared<UITime>();
	UIs_.emplace_back(tempUI);
>>>>>>> 0d07b3ad952a44b8839f43943c6d655a51bfa52d
}

void PlayScene::Update()
{
	if (MyTimer.IsEndTimer("GAME_TIME")) {
		SceneMng.ChangeScene(SCENE_ID::ANSWER);
	}

	if (MyTimer.IsEndTimer("GAME_START_TIME") &&
		!MyTimer.InProgress("GAME_TIME")) {
		MyTimer.Start("GAME_TIME");
	}

<<<<<<< HEAD
	for (auto& c : cpu_)c->Update();
	player_->Update();
	apple_->Update();
=======
	if (MyTimer.IsEndTimer("CAR_SPAWN_TIME")) {
		MyTimer.Restart("CAR_SPAWN_TIME");
		shared_ptr<Object> tempCar;
		tempCar = make_shared<Car>(Vector2F(-1.0f,0.0f), Vector2F(500.0f,500.0f));
		objects_.emplace(OBJECT_ID::CAR, tempCar);
	}

	for (auto [id,obj] : objects_) {
		obj->Update();
	}

	//apple_->Update();

	//for (auto car : cars_) {
	//	car->Update();
	//}
>>>>>>> 0d07b3ad952a44b8839f43943c6d655a51bfa52d
}

void PlayScene::Draw()
{
	if (CheckHitKey(KEY_INPUT_E)) {
		SceneMng.ChangeScene(SCENE_ID::ANSWER);
	}
	DrawFormatString(0, 0, 0xffffff, "PlayScene");
	DrawFormatString(0, 20, 0xffffff, "GameTime : %f", MyTimer.GetTime("GAME_TIME"));
	DrawFormatString(0, 40, 0xffffff, "GameStartTime : %f", MyTimer.GetTime("GAME_START_TIME"));

<<<<<<< HEAD
	for (auto& c : cpu_)c->Draw();
	player_->Draw();
	apple_->Draw();
=======

	for (auto [id, obj] : objects_) {
		obj->Draw();
	}

	for (auto UI : UIs_) {
		UI->Draw();
	}
>>>>>>> 0d07b3ad952a44b8839f43943c6d655a51bfa52d
}

void PlayScene::Release()
{
	MyTimer.Delete("GAME_TIME");
	MyTimer.Delete("GAME_START_TIME");

<<<<<<< HEAD
	for (auto& c : cpu_)c->Release();
	player_->Release();
	apple_->Release();
=======
	for (auto [id, obj] : objects_) {
		obj->Release();
	}
>>>>>>> 0d07b3ad952a44b8839f43943c6d655a51bfa52d
}
