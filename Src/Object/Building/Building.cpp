#include "Building.h"

Building::Building(Vector2F pos, ResourceManager::SRC src)
{
	pos_ = pos;
	img_ = ResourceManager::GetInstance().Load(src).handleId_;
	GetGraphSize(img_, &imgSize_.x, &imgSize_.y);
}

Building::~Building()
{
}

void Building::Init(void)
{
}

void Building::Update(void)
{
}

void Building::Draw(void)
{
	DrawRotaGraph(pos_.x, pos_.y, 1.0f, 0.0f, img_, true);
}

void Building::Release(void)
{
}
