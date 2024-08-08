#pragma once
#include "../../Common/ResourceManager.h"
#include "../Object.h"

class Car : public Object
{
public:

	enum class STATE
	{
		MOVE,
		END
	};

	Car();
	~Car();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

private:



	static constexpr ResourceManager::SRC CAR_TYPE_SRC[] =
	{
		ResourceManager::SRC::CAR_1,
		ResourceManager::SRC::CAR_2,
		ResourceManager::SRC::CAR_3,
		ResourceManager::SRC::CAR_4,
		ResourceManager::SRC::CAR_5,
		ResourceManager::SRC::CAR_6,
	};





	int img_;

	static constexpr float MOVE_POW = (8.0f);

	Vector2F moveDir_;

	STATE state_;

	bool isCheckOffScreen_;

	bool revFlagX_;
	bool revFlagY_;

	// ç¿ïWÅAï˚å¸
	vector<pair<Vector2F, Vector2F>> spawnInfoHor_;	// â°
	vector<pair<Vector2F, Vector2F>> spawnInfoVer_;	// èc
};

