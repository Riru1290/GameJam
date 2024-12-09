#include"../Common/ResourceManager.h"
#include"../Common/InputManager.h"
#include"../Common/SoundManager.h"
#include"../UI/UIMove.h"
#include"../UI/UIFade.h"
#include"../UI/UIBasic.h"
#include "SceneManager.h"
#include "AnswerScene.h"

AnswerScene::AnswerScene()
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

	displayPos_ = {
		Vector2F(SCREEN_SIZE_X / 2.0f - 360.0f,SCREEN_SIZE_Y / 2.0f - 100.0f),
		Vector2F(SCREEN_SIZE_X / 2.0f - 120.0f,SCREEN_SIZE_Y / 2.0f - 100.0f),
		Vector2F(SCREEN_SIZE_X / 2.0f + 120.0f,SCREEN_SIZE_Y / 2.0f - 100.0f),
		Vector2F(SCREEN_SIZE_X / 2.0f + 360.0f,SCREEN_SIZE_Y / 2.0f - 100.0f),
		Vector2F(SCREEN_SIZE_X / 2.0f - 360.0f,SCREEN_SIZE_Y / 2.0f + 100.0f),
		Vector2F(SCREEN_SIZE_X / 2.0f - 120.0f,SCREEN_SIZE_Y / 2.0f + 100.0f),
		Vector2F(SCREEN_SIZE_X / 2.0f + 120.0f,SCREEN_SIZE_Y / 2.0f + 100.0f),
		Vector2F(SCREEN_SIZE_X / 2.0f + 360.0f,SCREEN_SIZE_Y / 2.0f + 100.0f)
	};

	pinPos_ = displayPos_;
	for (auto& pos : pinPos_) {
		pos -= {0.0f, 50.0f};
	}
	imgPin_ = LoadGraph("Data/Img/UI/Icon_Pin.png");

	imgSelect_ = LoadGraph("Data/Img/UI/select.png");

	imgBg_ = LoadGraph("Data/Img/UI/bg.png");



	selectedNo_ = 0;

	changeFlag_ = !SceneMng.IsSuccess();
	isResult_ = !SceneMng.IsSuccess();

	MyTimer.SetTimer("RESULT_TIME", 3.0f);
}

void AnswerScene::Init()
{
	SoundManager::GetInstance().PlayBgmOfAnswer();

	int lupinNo = SceneMng.GetLupinNo();


	auto lupinImgPtr = charaImg_[lupinNo];

	charaImg_.erase(charaImg_.begin() + lupinNo);

	int randLupinNo = GetRand(DISPLAY_CHARACTER_NUM - 2);
	SceneMng.SetLupinNo(randLupinNo);

	// 怪盗も含めた8体を表示
	for (int i = 0; i < DISPLAY_CHARACTER_NUM - 1; i++) {

		if (randLupinNo == i) {
			displayImgs_.emplace_back(lupinImgPtr);
		}

		int randNo = GetRand(charaImg_.size() - 1);
		displayImgs_.emplace_back(charaImg_[randNo]);
		charaImg_.erase(charaImg_.begin() + randNo);
	}

	shared_ptr<UIBase> tempUI = make_shared<UIBasic>(Vector2F(SCREEN_SIZE_X / 2.0f, 650.0f), 1.0f, "Data/Img/UI/you are lupin.png");
	UIs_.emplace_back(tempUI);

	if (isResult_) {
		SoundManager::GetInstance().PlayBgmOfZenigata();
		string filePath =  "Data/Img/UI/DetectiveWin.png";

		UIs_.clear();

		shared_ptr<UIBase> tempUI;
		Vector2F pos = { SCREEN_SIZE_X / 2.0f,SCREEN_SIZE_Y / 2.0f - 50.0f };
		tempUI = make_shared<UIMove>(pos - Vector2F(0.0f, 1000.0f), pos, 3.0f, filePath.c_str());
		UIs_.emplace_back(tempUI);

		Vector2F lpos = { SCREEN_SIZE_X / 2.0f - 200.0f,SCREEN_SIZE_Y / 2.0f + 200.0f };
		tempUI = make_shared<UIFade>(
			lpos,
			3.0f,
			0.5f, 0.0f, 1.0f, false,
			"Data/Img/UI/gotoTitle.png"
		);
		UIs_.emplace_back(tempUI);

		Vector2F rpos = { SCREEN_SIZE_X / 2.0f + 200.0f,SCREEN_SIZE_Y / 2.0f + 200.0f };
		tempUI = make_shared<UIFade>(
			rpos,
			3.0f,
			0.5f, 0.0f, 1.0f, false,
			"Data/Img/UI/continue.png"
		);
		UIs_.emplace_back(tempUI);

		MyTimer.Restart("RESULT_TIME");
	}
}

void AnswerScene::Update()
{
	if (!isResult_) {
		SelectLupin();

	}
	else {
		Result();
	}
}

void AnswerScene::Draw()
{
	DrawGraph(0, 0, imgBg_, true);

	//DrawFormatString(0, 0, 0xffffff, "AnswerScene");


	DrawRotaGraph(SCREEN_SIZE_X / 2.0f, SCREEN_SIZE_Y / 2.0f - 250.0f, 1.5f, 0.0f, imgSelect_, true);

	// キャラクター描画
	for (int i = 0; i < DISPLAY_CHARACTER_NUM; i++) {
		auto pos = displayPos_[i];
		DrawRotaGraph(pos.x, pos.y, 3.0f, 0.0f, displayImgs_[i][0], true);
	}

	auto pos = pinPos_[selectedNo_];
	DrawRotaGraph(pos.x, pos.y,0.25f,0.0f, imgPin_, true);

	if (isResult_) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawBox(
			0, 0,
			SCREEN_SIZE_X,
			SCREEN_SIZE_Y,
			0x777777, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	}

	for (auto UI : UIs_) {
		UI->Draw();
	}

}

void AnswerScene::Release()
{
	DeleteGraph(imgPin_);
	DeleteGraph(imgSelect_);
	DeleteGraph(imgBg_);

	MyTimer.Delete("RESULT_TIME");
}

void AnswerScene::SelectLupin()
{

	auto& input = InputManager::GetInstance();
	auto pad = input.GetJPadInputState(InputManager::JOYPAD_NO::PAD1);

	// 決定
	if (input.IsPadBtnTrgDown(InputManager::JOYPAD_NO::PAD1,InputManager::JOYPAD_BTN::RIGHT)) {
		SoundManager::GetInstance().PlaySndAnswer();
		SoundManager::GetInstance().StopBgmOfAnswer();
		isResult_ = true;

		string filePath = "";
		int lupinNo = SceneMng.GetLupinNo();
		if (selectedNo_ == lupinNo) {
			SoundManager::GetInstance().PlayBgmOfZenigata();
			filePath = "Data/Img/UI/DetectiveWin.png";
		}
		else {
			SoundManager::GetInstance().PlayBgmOfLupin();
			filePath = "Data/Img/UI/lupinWin.png";
		}
		
		UIs_.clear();

		shared_ptr<UIBase> tempUI;
		Vector2F pos = { SCREEN_SIZE_X / 2.0f,SCREEN_SIZE_Y / 2.0f - 50.0f };
		tempUI = make_shared<UIMove>(pos - Vector2F(0.0f, 1000.0f), pos, 3.0f, filePath.c_str());
		UIs_.emplace_back(tempUI);

		Vector2F lpos = { SCREEN_SIZE_X / 2.0f - 200.0f,SCREEN_SIZE_Y / 2.0f + 200.0f };
		tempUI = make_shared<UIFade>(
			lpos,
			3.0f, 
			0.5f, 0.0f,1.0f,false, 
			"Data/Img/UI/gotoTitle.png"
		);
		UIs_.emplace_back(tempUI);

		Vector2F rpos = { SCREEN_SIZE_X / 2.0f + 200.0f,SCREEN_SIZE_Y / 2.0f + 200.0f };
		tempUI = make_shared<UIFade>(
			rpos,
			3.0f,
			0.5f, 0.0f, 1.0f, false,
			"Data/Img/UI/continue.png"
		);
		UIs_.emplace_back(tempUI);

		MyTimer.Restart("RESULT_TIME");

		return;
	}

	
	auto leftX = pad.AKeyLX;
	auto leftY = pad.AKeyLY;


	if (leftX == 0.0f && leftY == 0.0f)
	{
		changeFlag_ = false;
		return;
	}

	if (changeFlag_)return;

	float angle = Utility::Rad2DegF(atan2f(leftY, leftX));


	SoundManager::GetInstance().PlaySndMove();
	if (angle == 0.0f) {
		// 右
		selectedNo_++;
		if (selectedNo_ == 4) {
			selectedNo_ = 0;
		}
		if (selectedNo_ == 8) {
			selectedNo_ = 4;
		}
	}else if (angle == 90.0f) {
		// 下
		selectedNo_ += 4;
		selectedNo_ %= 8;
	}
	else if (angle == -90.0f) {
		// 上
		selectedNo_ -= 4;
		if (selectedNo_ < 0) {
			selectedNo_ += 8;
		}
		selectedNo_ %= 8;
	}
	else if (angle == 180.0f) {
		// 左
		selectedNo_--;
		if (selectedNo_ == -1) {
			selectedNo_ = 3;
		}
		else if (selectedNo_ == 3) {
			selectedNo_ = 7;
		}
	}

	changeFlag_ = true;
}

void AnswerScene::Result()
{
	if (MyTimer.InProgress("RESULT_TIME"))return;

	auto& input = InputManager::GetInstance();
	auto pad = input.GetJPadInputState(InputManager::JOYPAD_NO::PAD1);
	auto& snM = SoundManager::GetInstance();

	// 決定
	if (input.IsPadBtnTrgDown(InputManager::JOYPAD_NO::PAD1, InputManager::JOYPAD_BTN::RIGHT)) {
		snM.StopBgmOfLupin();
		snM.StopBgmOfZenigata();
		SceneMng.ChangeScene(SCENE_ID::TUTORIAL);
	}
	else if (input.IsPadBtnTrgDown(InputManager::JOYPAD_NO::PAD1, InputManager::JOYPAD_BTN::LEFT)) {
		snM.StopBgmOfLupin();
		snM.StopBgmOfZenigata();
		SceneMng.ChangeScene(SCENE_ID::TITLE);
	}
}
