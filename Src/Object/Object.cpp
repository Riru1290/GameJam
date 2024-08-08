#include "Object.h"

Object::Object()
{
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
    float foosPos = pos_.y + imgSize_.y / 2.0f;
    return foosPos;
}
