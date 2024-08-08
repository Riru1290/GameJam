#pragma once
#include "../Object.h"

class Car : public Object
{
public:

	enum class STATE
	{
		MOVE,
		END
	};

	Car(Vector2F moveDir,Vector2F pos);
	~Car();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;

private:



	int img_;

	static constexpr float MOVE_POW = (5.0f);

	Vector2F moveDir_;

	STATE state_;
};

