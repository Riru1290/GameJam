#pragma once
class Object : public std::enable_shared_from_this<Object>
{
public:

	Object();
	~Object();


	// é©ï™é©êgÇÃshared_ptrÇï‘Ç∑
	shared_ptr<Object> GetPtr() { return shared_from_this(); }

	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Release(void);

	[[nodiscard]] const Vector2F& GetPosition()const { return pos_; };
	[[nodiscard]] const float& GetAngle()const { return angle_; };
	[[nodiscard]] const float& GetSize()const { return size_; };

	void SetPosition(const Vector2F& pos) { pos_ = pos; };
	void SetAngle(const float& angle) { angle_ = angle; };
	void SetSize(const float& size) { size_ = size; };


protected:

	Vector2F pos_;
	float angle_;
	float size_ = 1.0f;


};

