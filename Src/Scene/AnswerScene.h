#pragma once
#include "SceneBase.h"

class UIBase;

class AnswerScene : public SceneBase
{
public:
	AnswerScene();
	~AnswerScene()override = default;

	void Init() override;
	void Update() override;
	void Draw()override;
	void Release() override;

private:

	void SelectLupin();

	void Result();

	static constexpr int DISPLAY_CHARACTER_NUM = (8);

	vector<int*> charaImg_;

	vector<Vector2F> displayPos_;
	vector<Vector2F> pinPos_;

	vector<int*> displayImgs_;

	// ���ݑI�����Ă���ԍ�
	int selectedNo_;

	// �s���摜
	int imgPin_;

	bool changeFlag_;

	bool isResult_;

	// �Z���N�g��ʗp�摜
	int imgSelect_;

	// UI
	vector<shared_ptr<UIBase>> UIs_;
};

