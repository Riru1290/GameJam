#include "../Object/Fruit/Apple.h"
#include "../Object/Car/Car.h"
#include "../UI/UITime.h"
#include "../UI/UIBase.h"
#include"../Common/ResourceManager.h"
#include"../Object/CharacterBase.h"
#include"../Object/CPUBase.h"
#include"../Object/Player.h"
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
	shared_ptr<Object> apple = make_shared<Apple>();
	apple->Init();

	objects_.emplace(OBJECT_ID::APPLE, apple);

	shared_ptr<UIBase> tempUI;
	tempUI = make_shared<UITime>();
	UIs_.emplace_back(tempUI);
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
	for (auto& c : cpu_)c->Update();
	player_->Update();
	apple_->Update();
}

void PlayScene::Draw()
{
	if (CheckHitKey(KEY_INPUT_E)) {
		SceneMng.ChangeScene(SCENE_ID::ANSWER);
	}
	DrawFormatString(0, 0, 0xffffff, "PlayScene");
	DrawFormatString(0, 20, 0xffffff, "GameTime : %f", MyTimer.GetTime("GAME_TIME"));
	DrawFormatString(0, 40, 0xffffff, "GameStartTime : %f", MyTimer.GetTime("GAME_START_TIME"));


	for (auto [id, obj] : objects_) {
		obj->Draw();
	}

	for (auto UI : UIs_) {
		UI->Draw();
	}
	for (auto& c : cpu_)c->Draw();
	player_->Draw();
	apple_->Draw();
}

void PlayScene::Release()
{
	MyTimer.Delete("GAME_TIME");
	MyTimer.Delete("GAME_START_TIME");

	for (auto& c : cpu_)c->Release();
	player_->Release();
	apple_->Release();
	for (auto [id, obj] : objects_) {
		obj->Release();
	}
}
