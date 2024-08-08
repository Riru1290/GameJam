#include"../Common/ResourceManager.h"
#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Init(void)
{
	auto& rsM = ResourceManager::GetInstance();
	stageCsv_ =
		rsM.Load(ResourceManager::SRC::STAGE).dmcHandleIds_;

	tile_ =
		rsM.Load(ResourceManager::SRC::MAP_TILE).handleIds_;
}

void Stage::Update(void)
{
}

void Stage::Draw(void)
{
	for (int y = 0; y < TILE_NOM_Y; y++)
	{
		for (int x = 0; x < TILE_NOM_X; x++)
		{
			int  i = DrawGraph(x * TILE_SIZE, y * TILE_Y,tile_[ stageCsv_[y][x]], true);
		}
	}
}

void Stage::Release(void)
{
}
