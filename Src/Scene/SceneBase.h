#pragma once
class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase() = default;

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();
};

