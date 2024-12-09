#pragma once
class UIBase
{
public:

	UIBase();
	~UIBase();

	virtual void Draw();

protected:


	Vector2F pos_;
	float angle_;
	float size_ = 1.0f;
};

