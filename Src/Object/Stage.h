#pragma once
class Stage
{
public:
	static constexpr int TILE_NOM_X = 80;	//���̃^�C������
	static constexpr int TILE_NOM_Y = 45;	//�c�̃^�C������
	static constexpr int TILE_SIZE = 16;	//�^�C���̃T�C�Y
	static constexpr int TILE_X = 64;		//�^�C���̉���
	static constexpr int TILE_Y = 64;		//�^�C���̏c��

	Stage();
	~Stage();

	void Init(void);
	void Update(void);
	void Draw(void);
	void Release(void);
private:

	vector<vector<int>> stageCsv_;
	int* tile_;
};

