#pragma once
#include "../Object.h"

class Apple final : public Object
{
public:
	Apple(Vector2F spawnPos);
	~Apple();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

	void Dead(void);

private:

	int img_;
	bool isLive_;
};

