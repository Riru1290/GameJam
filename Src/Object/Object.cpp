#include "Object.h"

Object::Object()
{
    size_ = 1.0f;
}

Object::~Object()
{
}

void Object::Init(void)
{
}

void Object::Update(void)
{
}

void Object::Draw(void)
{
}

void Object::Release(void)
{
}

float Object::GetFootPos() const
{
    float foosPos = pos_.y + (imgSize_.y / 2.0f * size_);
    return foosPos;
}
