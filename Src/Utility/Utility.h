#pragma once

using Microsoft::WRL::ComPtr;
using namespace std;

// weak_ptr比較用
template<class T>
struct WeakPtrComparator {
	bool operator()(const weak_ptr<T>& lPtr, const weak_ptr<T>& rPtr) const{
		if (auto l = lPtr.lock()) {
			if (auto r = rPtr.lock()) {
				return l < r;
			}
			return false;
		}
		return rPtr.lock() != nullptr;
	}

};

// ハッシュ関数の定義
template<class T>
struct WeakPtrHash {
	size_t operator()(const weak_ptr<T>& wp) const {
		if (auto sp = wp.lock()) {
			return hash<T*>()(sp.get());
		}
		else {
			return 0; // 無効な weak_ptr の場合
		}
	}
};

// 等価比較関数の定義
template<class T>
struct WeakPtrEqual {
	bool operator()(const weak_ptr<T>& lhs, const weak_ptr<T>& rhs) const {
		return !lhs.owner_before(rhs) && !rhs.owner_before(lhs);
	}
};

//using Scale = DirectX::XMFLOAT3;
//using Size2D = DirectX::XMFLOAT2;

struct UV {
	float u = 0.0f, v = 0.0f;
};

struct Vector2
{
	float x = 0.0f, y = 0.0f;

	Vector2 operator+(const Vector2& rval)const {
		return Vector2(x + rval.x, y + rval.y);
	};
	Vector2 operator-(const Vector2& rval)const {
		return Vector2(x - rval.x, y - rval.y);
	};
	Vector2 operator*(float scale)const {
		return Vector2(x * scale, y * scale);
	};
	Vector2 operator/(float div)const {
		return Vector2(x / div, y / div);
	};
	Vector2 operator*(Vector2 scale)const {
		return Vector2(x * scale.x, y * scale.y);
	};

	void operator+=(const Vector2& rval){
		x += rval.x;
		y += rval.y;
	};
	void operator-=(const Vector2& rval) {
		x -= rval.x;
		y -= rval.y;
	};
	void operator*=(float scale) {
		x *= scale;
		y *= scale;
	};
	void operator/=(float div) {
		x /= div;
		y /= div;
	};

	bool operator==(const Vector2& vec) {
		return (x == vec.x && y == vec.y);
	};
	bool operator!=(const Vector2& vec) {
		return (x != vec.x || y != vec.y);
	};

	// ベクトルの長さ(ノルム)を返す
	float Length()const {
		return hypotf(x, y);
	};

	// 正規化
	void Normalize(void) {
		float len = Length();
		if (len == 0.0f) {
			x = 0;
			y = 0;
		}
		x /= len;
		y /= len;
	};

	// 自分を正規化したベクトルを返す
	Vector2 Normalized(void)const {
		float len = Length();
		if (len == 0.0f)return Vector2(0, 0);
		return Vector2(x / len, y / len);
	};

	// std::setで、作成した構造体を使う場合は比較演算子のオーバーロードが必要
	bool operator<(const Vector2& vec) const {
		if (vec.x == x)
			return  vec.y > y;
		else
			return vec.x > x;
	}
};



using Position2D = Vector2;
using Size2D = Vector2;
using Scale2D = Vector2;
using Direction2D = Vector2;

template<typename T>
struct Test
{
	T x, y;
};

using TestInt = Test<int>;
using TestFloat = Test<float>;


struct Vector3
{
	float x, y, z;

	Vector3 operator+(const Vector3& rval)const {
		return Vector3(x + rval.x, y + rval.y, z + rval.z);
	};
	Vector3 operator-(const Vector3& rval)const {
		return Vector3(x - rval.x, y - rval.y, z - rval.z);
	};
	Vector3 operator*(float scale)const {
		return Vector3(x * scale, y * scale , z * scale);
	};
	Vector3 operator/(float div)const {
		return Vector3(x / div, y / div, z / div);
	};


	void operator+=(const Vector3& rval) {
		x += rval.x;
		y += rval.y;
		z += rval.z;
	};
	void operator-=(const Vector3& rval) {
		x -= rval.x;
		y -= rval.y;
		z -= rval.z;
	};
	void operator*=(float scale) {
		x *= scale;
		y *= scale;
	};
	void operator/=(float div) {
		x /= div;
		y /= div;
		z /= div;
	};

	bool operator==(const Vector3& vec) {
		return (x == vec.x && y == vec.y && z == vec.z);
	};

	// ベクトルの長さ(ノルム)を返す
	float Length()const {
		return hypotf(hypotf(x, y),z);
	};

	// 正規化
	void Normalize(void) {
		float len = Length();
		x /= len;
		y /= len;
		z /= len;
	};

	// 自分を正規化したベクトルを返す
	Vector3 Normalized(void)const {
		float len = Length();
		return Vector3(x / len, y / len, z / len);
	};
};

using Position3D = Vector3;
using Scale3D = Vector3;
using Direction3D = Vector3;

static inline Vector2 ToVector2(Vector3 vec3) {
	return Vector2(vec3.x, vec3.y);
}

static inline Vector3 ToVector3(Vector2 vec2) {
	return Vector3(vec2.x, vec2.y, 0.0f);
}

#define SCREEN_CENTER Vector2(SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT / 2.0f)


enum class DIR
{
	UP,
	LEFT,
	DOWN,
	RIGHT,
	MAX
};


static inline wstring cp_to_wide(const string& s, UINT codepage = 932)
{
	int in_length = (int)s.length();
	int out_length = MultiByteToWideChar(codepage, 0, s.c_str(), in_length, 0, 0);
	wstring result(out_length, L'\0');
	if (out_length) MultiByteToWideChar(codepage, 0, s.c_str(), in_length, &result[0], out_length);
	return result;
}

static inline string wide_to_cp(const wstring& s, UINT codepage = 932)
{
	int in_length = (int)s.length();
	int out_length = WideCharToMultiByte(codepage, 0, s.c_str(), in_length, 0, 0, 0, 0);
	string result(out_length, '\0');
	if (out_length) WideCharToMultiByte(codepage, 0, s.c_str(), in_length, &result[0], out_length, 0, 0);
	return result;
}

// 3*3行列
struct Matrix {
	float m[3][3];
};

///２つの行列の乗算を返す
///@param lmat 左辺値(行列)
///@param rmat 右辺値(行列)
///@attention 乗算の順序に注意してください
static inline Matrix
MultipleMat(const Matrix& lmat, const Matrix& rmat) {
	Matrix ret = {};

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			for (int i = 0; i < 3; i++)
			{
				ret.m[y][x] += lmat.m[y][i] * rmat.m[i][x];
			}
		}
	}

	return ret;

}

static inline Matrix operator*(const Matrix& lmat, const Matrix& rmat)
{
	return MultipleMat(lmat, rmat);
}



///ベクトルに対して行列乗算を適用し、結果のベクトルを返す
///@param mat 行列
///@param vec ベクトル
static inline Vector2
MultipleVec(const Matrix& mat, const Vector2& vec) {
	Vector2 ret = {};

	ret.x = mat.m[0][0] * vec.x + mat.m[0][1] * vec.y + mat.m[0][2] * 1.0f;
	ret.y = mat.m[1][0] * vec.x + mat.m[1][1] * vec.y + mat.m[1][2] * 1.0f;

	return ret;
}

static inline Vector2 operator*(const Matrix& mat, const Vector2& vec)
{
	return MultipleVec(mat, vec);
}

///単位行列を返す
static inline Matrix IdentityMat() {
	Matrix ret = {
		{
			{1.0f,0.0f,0.0f},
			{0.0f,1.0f,0.0f},
			{0.0f,0.0f,1.0f}
		}
	};

	return ret;
}

///平行移動行列を返す
///@param x X方向平行移動量
///@param y Y方向平行移動量
static inline Matrix TranslateMat(float x, float y) {
	Matrix ret = {
		{
			{1.0f,0.0f,x},
			{0.0f,1.0f,y},
			{0.0f,0.0f,1.0f}
		}
	};

	return ret;
}

///回転行列を返す
///@param angle 回転角度
static inline Matrix RotateMat(float angle) {
	Matrix ret = {
		{
			{cosf(angle),-sinf(angle),0.0f},
			{sinf(angle), cosf(angle),0.0f},
			{0.0f,0.0f,1.0f}
		}
	};
	return ret;
}

///とある点を中心に回転して、その回転後の座標を返します。
///@param center 回転中心点
///@param angle 回転角度
///@param pos 元の座標
///@return 変換後の座標
static inline Vector2 RotatePosition(const Vector2& center, float angle,const Vector2& pos) {
	//①中心を原点に平行移動して
	//②原点中心に回転して
	//③中心を元の座標へ戻す

	Matrix mat = TranslateMat(center.x, center.y)	// ③
		* RotateMat(angle)	// ②
		* TranslateMat(-center.x, -center.y);	// ①

	auto ret = mat * pos;
	return Vector2(ret.x, ret.y);
	//これを書き換えて、特定の点を中心に回転を行うようにしてください。

	// 単位行列は何かにかけて全く変わらない行列で、右からかけても
	//左からかけても変わりません
}

static inline Matrix RotateMatrix(const Vector2& center, float angle) {
	//①中心を原点に平行移動して
	//②原点中心に回転して
	//③中心を元の座標へ戻す

	return TranslateMat(center.x, center.y)	// ③
		* RotateMat(angle)	// ②
		* TranslateMat(-center.x, -center.y);	// ①
}

template <typename T>
concept LerpPossibleType = 
is_same_v<T, int>		|| 
is_same_v<T, float>		|| 
is_same_v<T, double>	|| 
is_same_v<T, Vector2>	||
is_same_v<T, Vector3>;

template <LerpPossibleType T>
static inline T Lerp(T start, T end, float rate)
{
	return start + ((end - start) * rate);
}



template <typename T>
concept AnglePossibleType =
is_same_v<T, int>	||
is_same_v<T, float> ||
is_same_v<T, double>;

template <AnglePossibleType T>
static inline T Radian2Deg(const T& radian)
{
	return radian * static_cast<T>(180) / static_cast<T>(M_PI);
}

template <AnglePossibleType T>
static inline T Deg2Radian(const T& deg)
{
	return deg * static_cast<T>(M_PI) / static_cast<T>(180);
}

template <AnglePossibleType T>
static inline T DegIn360(T deg)
{
	float ret = static_cast<float>(deg);
	ret = fmodf(ret, 360.0f);
	if (ret < 0.0f)
	{
		ret += 360.0f;
	}
	return static_cast<T>(ret);
}

template <AnglePossibleType T>
static inline T RadIn2PI(T rad)
{
	float ret = static_cast<float>(rad);
	ret = fmodf(ret, static_cast<float>(M_PI) * 2.0f);
	if (ret < 0.0f)
	{
		ret += static_cast<float>(M_PI) * 2.0f;
	}
	return static_cast<T>(ret);
}

template <AnglePossibleType T>
static inline T RadInPI(T rad)
{
	float ret = static_cast<float>(rad);
	ret = fmodf(ret, static_cast<float>(M_PI));
	if (ret < 0.0f)
	{
		ret += static_cast<float>(M_PI);
	}
	return static_cast<T>(ret);
}

static inline int DirNearAroundRad(float from, float to)
{
	int ret = 1;

	float diff = to - from;

	if (diff >= 0.0f){
		// 比較元よりも時計回りに位置する
		if (diff > M_PI){
			// でも、180度以上離れているので、反時計回りの方が近い
			ret = -1;
		}
		else{
			// 時計回り
			ret = 1;
		}
	}else{
		// 比較元よりも反時計回りに位置する
		if (diff < -M_PI){
			// でも、180度以上離れているので、時計回りの方が近い
			ret = 1;
		}else{
			// 反時計回り
			ret = -1;
		}
	}

	return ret;
}

// 文字列の分割
static inline vector<std::string> Split(string line, char delmiter)
{
	// 可変長配列の返り値を準備
	vector<std::string> result;

	// stringをファイルストリームに変換
	istringstream stream(line);

	// 読み込んだ文字列を格納する用変数
	string field;

	// streamを順番に読み込み
	// 第3引数で指定された文字までを第2引数に返す
	while (getline(stream, field, delmiter))
	{
		// 可変長配列に追加
		result.push_back(field);
	}

	return result;
}

static random_device rd;
static mt19937 gen(rd());
static inline int GetRand()
{
	return gen();
}

template<typename T>
static inline T GetRand(T min, T max)
{
	uniform_real_distribution<> urd(min, max);
	return urd(gen);
}

// 内積
static inline float Dot(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

// 外積
static inline float Cross(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}

// 線分同士の衝突判定
static inline Vector2 CollisionLines(const Vector2& lineAPos1, const Vector2& lineAPos2, const Vector2& lineBPos1, const Vector2& lineBPos2)
{
	auto deno = Cross(lineAPos2 - lineAPos1, lineBPos2 - lineBPos1);
	auto s = deno;
	auto t = deno;

	auto error = Vector2(0.0f, 0.0f);
	if (deno == 0.0f) {
		// 線分が平行
		return error;
	}


	s = Cross(lineBPos1- lineAPos1, lineBPos2- lineBPos1) / deno;
	t = Cross(lineAPos2-lineAPos1, lineAPos1-lineBPos1) / deno;
	if (s < 0.0f || 1.0f < s || t < 0.0f || 1.0f < t) {
		// 線分が交差していない
		return error;
	}

	auto v = lineAPos2- lineAPos1;

	return Vector2(lineAPos1.x + s * v.x, lineAPos1.y + s * v.y);
}

// 点が矩形の中に入り込んでいるか
static inline bool CollisionPointInBox(const Vector2& pointPos, const Vector2& boxpos, const Vector2& boxSize)
{
	Vector2 LTpos = { boxpos.x - boxSize.x / 2.0f,boxpos.y - boxSize.y / 2.0f };// 左上
	Vector2 RDpos = { boxpos.x + boxSize.x / 2.0f,boxpos.y + boxSize.y / 2.0f };// 右上

	if (LTpos.x <= pointPos.x && pointPos.x <= RDpos.x &&
		LTpos.y <= pointPos.y && pointPos.y <= RDpos.y) {
		return true;
	}

	return false;
}

// 点と矩形(回転あり)が当たっているかどうか
// @param point 点
// @param box 矩形(回転あり)
static inline bool CollisionPointRotateBox(const Vector2& pointPos,const Vector2 boxPos[4])
{

	Vector2 V1to2 = (boxPos[1] - boxPos[0]);
	Vector2 V2to3 = (boxPos[2] - boxPos[1]);
	Vector2 V3to4 = (boxPos[3] - boxPos[2]);
	Vector2 V4to1 = (boxPos[0] - boxPos[3]);

	// 矩形の4辺と、辺の始点から点に向かうベクトルのセット
	vector<pair<Vector2, Vector2>> datas = {
		{ V1to2, (pointPos - boxPos[0]) },
		{ V2to3, (pointPos - boxPos[1]) },
		{ V3to4, (pointPos - boxPos[2]) },
		{ V4to1, (pointPos - boxPos[3]) }
	};

	// 分離軸判定
	// 矩形の各辺をv1、辺の始点から点に向かうベクトルをv2として
	// v1とv2の外積が正の値だった場合はその時点で矩形の範囲外になるので判定を終了する
	// 4辺全てに対し、外積の結果がマイナスだった場合は矩形の中に点がある
	for (auto& data : datas)
	{
		auto cross = Cross(data.first, data.second);
		if (0 < cross) return false;
	}

	return true;
}

static inline bool CollisionBox(Position2D boxApos, Size2D boxASize, Position2D boxBpos, Size2D boxBSize) {

	return !(abs(boxApos.x - boxBpos.x) >= (boxASize.x / 2.0f + boxBSize.x / 2.0f) ||
			abs(boxApos.y - boxBpos.y) >= (boxASize.y / 2.0f + boxBSize.y / 2.0f));
}

// 指定した軸の矩形と矩形のめり込み量を返す
static inline float GetPenetrationDepth(int isX , Position2D boxApos,Size2D boxASize, Position2D boxBpos, Size2D boxBSize) {

	float ret = 0.0f;

	if (abs(boxApos.x - boxBpos.x) >= (boxASize.x / 2.0f + boxBSize.x / 2.0f) ||
		abs(boxApos.y - boxBpos.y) >= (boxASize.y / 2.0f + boxBSize.y / 2.0f)) return ret;

	if (isX) {
		ret =  (boxASize.x / 2.0f + boxBSize.x / 2.0f) - abs(boxApos.x - boxBpos.x);
	}
	else {
		ret = (boxASize.y / 2.0f + boxBSize.y / 2.0f) - abs(boxApos.y - boxBpos.y);
	}

	return ret;
}

// 円と円の衝突判定
static inline bool IsCollisionCircle(Position2D pos1, float radi1, Position2D pos2, float radi2)
{
	Position2D pos = { pos2.x - pos1.x,pos2.y - pos1.y };
	float dis = sqrt(pos.x * pos.x + pos.y * pos.y);
	float rad = radi1 + radi2;

	// 中心距離が二つの円の半径を足したものよりも短ければ当たっている
	if (dis < rad)
	{
		return true;
	}

	return false;
}

/// @brief 矩形と円の衝突判定
/// @param rectCenter  
/// @param rectSize
/// @param circleCenter 
/// @param radius 
/// @return 
static inline bool IsCollisionRect2Circle(Position2D rectCenter, Size2D rectSize, Position2D circleCenter, float radius) 
{
	Size2D size = { radius * 2.0f ,radius * 2.0f };
	if (!CollisionBox(rectCenter, rectSize, circleCenter, size)) return false;

	// 領域A衝突判定
	Position2D posA1 = { rectCenter.x - (rectSize.x / 2),rectCenter.y - (rectSize.y / 2) - radius };
	Position2D posA2 = { rectCenter.x + (rectSize.x / 2),rectCenter.y + (rectSize.y / 2) + radius };
	if (posA1.x <= circleCenter.x && circleCenter.x <= posA2.x &&
		posA1.y <= circleCenter.y && circleCenter.y <= posA2.y)
	{
		return true;
	}

	// 領域B衝突判定
	Position2D posB1 = { rectCenter.x - (rectSize.x / 2) - radius,rectCenter.y - (rectSize.y / 2) };
	Position2D posB2 = { rectCenter.x + (rectSize.x / 2) + radius,rectCenter.y + (rectSize.y / 2) };
	if (posB1.x <= circleCenter.x && circleCenter.x <= posB2.x &&
		posB1.y <= circleCenter.y && circleCenter.y <= posB2.y)
	{
		return true;
	}

	// 領域C衝突判定
	Position2D posC = { rectCenter.x - (rectSize.x / 2) ,rectCenter.y - (rectSize.y / 2) };
	if (IsCollisionCircle(posC, radius, circleCenter, radius)) return true;

	// 領域D衝突判定
	Position2D posD = { rectCenter.x + (rectSize.x / 2) ,rectCenter.y - (rectSize.y / 2) };
	if (IsCollisionCircle(posD, radius, circleCenter, radius)) return true;

	// 領域E衝突判定
	Position2D posE = { rectCenter.x - (rectSize.x / 2) ,rectCenter.y + (rectSize.y / 2) };
	if (IsCollisionCircle(posE, radius, circleCenter, radius)) return true;

	// 領域F衝突判定
	Position2D posF = { rectCenter.x + (rectSize.x / 2) ,rectCenter.y + (rectSize.y / 2) };
	if (IsCollisionCircle(posF, radius, circleCenter, radius)) return true;


	return false;
}

static inline void LoadCsvData(string filePath,vector<int>& mapVec,int& width, int& height)
{
	mapVec.clear();
	width = 0;
	height = 0;

	// ファイルのパス
	string path = filePath;

	// ファイルの読み込み
	ifstream ifs = ifstream(path.c_str());
	if (!ifs)
	{
		// エラーが発生
		return;
	}

	// ファイルを1行ずつ読み込んで、lineに格納する
	string line;					// 1行の文字情報
	vector<string> split;		// 1文字1文字の文字列情報
	int chipNo = 0;

	// ファイルを1行ずつ読み込む
	while (getline(ifs, line))
	{
		// 1行分の文字列をカンマ区切りで分割
		split = Split(line, ',');

		width = (int)split.size();

		for (int x = 0; x < split.size(); x++)
		{

			// string型からint型に変換
			int chipNo = stoi(split[x]);

			// 配列にマップチップ番号を格納
			mapVec.emplace_back(chipNo);
		}
		height++;
	}
}


class Utility
{
};

// お試し
template <typename T>
T Sum(T a, T b)
{
	return a + b;
}

// 戻り値を勝手に推論してくれる decltype
template <typename T, typename U>
auto Sum(T a, U b) -> decltype(a + b) {
	return a + b;
}

//int Fibonacchi(int N) {
//	int a[N + 1]; エラーがでる
//	a[0] = 0;
//	a[1] = 1;
//	for (auto i = 2; i <= N; ++i) {
//		a[i] = a[i - 1] + a[i - 2];
//	}
//	return a[N];
//}

// テンプレートを使うとコンパイル時に配列のサイズを指定できる
template <int N>
int Fibonacchi() {
	int a[N + 1];
	a[0] = 0;
	a[1] = 1;
	for (auto i = 2; i <= N; ++i) {
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[N];
}

template <typename T, int N>
class Array {
public:
	int size() const {
		return N;
	}

	T data_[N];
};
