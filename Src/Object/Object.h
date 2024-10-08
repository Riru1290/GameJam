#pragma once
class Object : public std::enable_shared_from_this<Object>
{
public:

	Object();
	~Object();


	// 自分自身のshared_ptrを返す
	shared_ptr<Object> GetPtr() { return shared_from_this(); }

	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Release(void);

	[[nodiscard]] const OBJECT_ID& GetObjectID()const { return objectID_; };

	[[nodiscard]] const Vector2F& GetPosition()const { return pos_; };
	[[nodiscard]] const float& GetAngle()const { return angle_; };
	[[nodiscard]] const float& GetSize()const { return size_; };

	void SetPosition(const Vector2F& pos) { pos_ = pos; };
	void SetAngle(const float& angle) { angle_ = angle; };
	void SetSize(const float& size) { size_ = size; };

	virtual [[nodiscard]] float GetFootPos()const;


protected:

	Vector2F pos_;
	float angle_;
	float size_ = 1.0f;

	Vector2 imgSize_;

	OBJECT_ID objectID_;
};

