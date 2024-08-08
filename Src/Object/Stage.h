#pragma once
class Stage
{
public:
	static constexpr int TILE_NOM_X = 80;	//横のタイル枚数
	static constexpr int TILE_NOM_Y = 45;	//縦のタイル枚数
	static constexpr int TILE_SIZE = 16;	//タイルのサイズ
	static constexpr int TILE_X = 64;		//タイルの横数
	static constexpr int TILE_Y = 64;		//タイルの縦数

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

