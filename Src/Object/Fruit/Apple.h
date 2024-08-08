#pragma once
#include "../Object.h"

class Apple final : public Object
{
public:

	Apple();
	~Apple();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

private:

	int img_;
};

