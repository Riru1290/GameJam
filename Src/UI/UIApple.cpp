#include "UIApple.h"

UIApple::UIApple(reference_wrapper<const int> score) : UIBase(),
score_(score.get())
{
	imgs_ = new int[10 * 1];
	LoadDivGraph("Data/Img/UI/number.png", 10, 10, 1, 160, 172, imgs_);
	imgScore_ = LoadGraph("Data/Img/UI/scoreUI.png");
	imgApple_ = LoadGraph("Data/Img/UI/apple.png");
	imgFrame_ = LoadGraph("Data/Img/UI/Item2.png");
	pos_ = { SCREEN_SIZE_X - 170.0f,70.0f };
	size_ = 0.35f;
	angle_ = 0.0f;
}

UIApple::~UIApple()
{
}

void UIApple::Draw()
{
	Vector2F data = pos_;


	// 表示数計算

	// フレーム
	Vector2F fData = data;
	DrawRotaGraph(fData.x, fData.y, size_ * 0.5f, angle_, imgFrame_, true);

	// スコア
	Vector2F sData = data;	
	sData += {-20.0f, 0.0f};
	DrawRotaGraph(sData.x, sData.y, size_ * 2.0f, angle_, imgScore_, true);

	// リンゴ
	Vector2F tData = data;
	tData += {110.0f, -15.0f};
	DrawRotaGraph(tData.x, tData.y, size_ * 1.5f, angle_, imgApple_, true);

	int score = score_.get();

	data += {-7.0f, 0.0f};
	DrawRotaGraph(data.x, data.y, size_ * 0.5f, angle_, imgs_[score], true);

}
