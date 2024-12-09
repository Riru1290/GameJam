#pragma once
#include "../../Common/ResourceManager.h"
#include "../Object.h"

class Building : public Object
{
public:
	Building(Vector2F pos, ResourceManager::SRC src);
	~Building();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

private:

	int img_;

};
