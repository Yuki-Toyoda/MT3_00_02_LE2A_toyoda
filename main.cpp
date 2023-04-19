#include <Novice.h>
#include <Matrix4x4.h>

const char kWindowTitle[] = "MT3_00_02_LE2A_11_トヨダユウキ";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

/// <summary>
/// 4x4行列の要素表示をする関数
/// </summary>
/// <param name="x">横</param>
/// <param name="y">縦</param>
/// <param name="matrix">表示する行列</param>
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* Name) {

	Novice::ScreenPrintf(x, y, "%s", Name);

	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			// 要素描画
			Novice::ScreenPrintf(
				x + column * kColumnWidth,
				y + row * kRowHeight + kRowHeight,
				"%6.02f",
				matrix.m[row][column]
			);
		}
	}
}

/// <summary>
/// 行列の加算
/// </summary>
/// <param name="m1">加算する行列1</param>
/// <param name="m2">加算する行列2</param>
/// <returns>加算された行列</returns>
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {

	// 結果格納用
	Matrix4x4 result;

	// 計算処理
	result.m[0][0] = m1.m[0][0] + m2.m[0][0];
	result.m[1][0] = m1.m[1][0] + m2.m[1][0];
	result.m[2][0] = m1.m[2][0] + m2.m[2][0];
	result.m[3][0] = m1.m[3][0] + m2.m[3][0];

	result.m[0][1] = m1.m[0][1] + m2.m[0][1];
	result.m[1][1] = m1.m[1][1] + m2.m[1][1];
	result.m[2][1] = m1.m[2][1] + m2.m[2][1];
	result.m[3][1] = m1.m[3][1] + m2.m[3][1];

	result.m[0][2] = m1.m[0][2] + m2.m[0][2];
	result.m[1][2] = m1.m[1][2] + m2.m[1][2];
	result.m[2][2] = m1.m[2][2] + m2.m[2][2];
	result.m[3][2] = m1.m[3][2] + m2.m[3][2];

	result.m[0][3] = m1.m[0][3] + m2.m[0][3];
	result.m[1][3] = m1.m[1][3] + m2.m[1][3];
	result.m[2][3] = m1.m[2][3] + m2.m[2][3];
	result.m[3][3] = m1.m[3][3] + m2.m[3][3];

	return result;

}

/// <summary>
/// 行列の減算
/// </summary>
/// <param name="m1">減算する行列1</param>
/// <param name="m2">減算する行列2</param>
/// <returns>減算された行列</returns>
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {

	// 結果格納用
	Matrix4x4 result;

	// 計算処理
	result.m[0][0] = m1.m[0][0] - m2.m[0][0];
	result.m[1][0] = m1.m[1][0] - m2.m[1][0];
	result.m[2][0] = m1.m[2][0] - m2.m[2][0];
	result.m[3][0] = m1.m[3][0] - m2.m[3][0];

	result.m[0][1] = m1.m[0][1] - m2.m[0][1];
	result.m[1][1] = m1.m[1][1] - m2.m[1][1];
	result.m[2][1] = m1.m[2][1] - m2.m[2][1];
	result.m[3][1] = m1.m[3][1] - m2.m[3][1];

	result.m[0][2] = m1.m[0][2] - m2.m[0][2];
	result.m[1][2] = m1.m[1][2] - m2.m[1][2];
	result.m[2][2] = m1.m[2][2] - m2.m[2][2];
	result.m[3][2] = m1.m[3][2] - m2.m[3][2];

	result.m[0][3] = m1.m[0][3] - m2.m[0][3];
	result.m[1][3] = m1.m[1][3] - m2.m[1][3];
	result.m[2][3] = m1.m[2][3] - m2.m[2][3];
	result.m[3][3] = m1.m[3][3] - m2.m[3][3];

	return result;

}

/// <summary>
/// 行列の乗算
/// </summary>
/// <param name="m1">乗算する行列1</param>
/// <param name="m2">乗算する行列2</param>
/// <returns></returns>
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {

	// 結果格納用
	Matrix4x4 result;

	// 計算処理
	result.m[0][0] = (m1.m[0][0] * m2.m[0][0]) + (m1.m[0][1] * m2.m[1][0]) + (m1.m[0][2] * m2.m[2][0]) + (m1.m[0][3] * m2.m[3][0]);
	result.m[1][0] = (m1.m[1][0] * m2.m[0][0]) + (m1.m[1][1] * m2.m[1][0]) + (m1.m[1][2] * m2.m[2][0]) + (m1.m[1][3] * m2.m[3][0]);
	result.m[2][0] = (m1.m[2][0] * m2.m[0][0]) + (m1.m[2][1] * m2.m[1][0]) + (m1.m[2][2] * m2.m[2][0]) + (m1.m[2][3] * m2.m[3][0]);
	result.m[3][0] = (m1.m[3][0] * m2.m[0][0]) + (m1.m[3][1] * m2.m[1][0]) + (m1.m[3][2] * m2.m[2][0]) + (m1.m[3][3] * m2.m[3][0]);

	result.m[0][1] = (m1.m[0][0] * m2.m[0][1]) + (m1.m[0][1] * m2.m[1][1]) + (m1.m[0][2] * m2.m[2][1]) + (m1.m[0][3] * m2.m[3][1]);
	result.m[1][1] = (m1.m[1][0] * m2.m[0][1]) + (m1.m[1][1] * m2.m[1][1]) + (m1.m[1][2] * m2.m[2][1]) + (m1.m[1][3] * m2.m[3][1]);
	result.m[2][1] = (m1.m[2][0] * m2.m[0][1]) + (m1.m[2][1] * m2.m[1][1]) + (m1.m[2][2] * m2.m[2][1]) + (m1.m[2][3] * m2.m[3][1]);
	result.m[3][1] = (m1.m[3][0] * m2.m[0][1]) + (m1.m[3][1] * m2.m[1][1]) + (m1.m[3][2] * m2.m[2][1]) + (m1.m[3][3] * m2.m[3][1]);

	result.m[0][2] = (m1.m[0][0] * m2.m[0][2]) + (m1.m[0][1] * m2.m[1][2]) + (m1.m[0][2] * m2.m[2][2]) + (m1.m[0][3] * m2.m[3][2]);
	result.m[1][2] = (m1.m[1][0] * m2.m[0][2]) + (m1.m[1][1] * m2.m[1][2]) + (m1.m[1][2] * m2.m[2][2]) + (m1.m[1][3] * m2.m[3][2]);
	result.m[2][2] = (m1.m[2][0] * m2.m[0][2]) + (m1.m[2][1] * m2.m[1][2]) + (m1.m[2][2] * m2.m[2][2]) + (m1.m[2][3] * m2.m[3][2]);
	result.m[3][2] = (m1.m[3][0] * m2.m[0][2]) + (m1.m[3][1] * m2.m[1][2]) + (m1.m[3][2] * m2.m[2][2]) + (m1.m[3][3] * m2.m[3][2]);

	result.m[0][3] = (m1.m[0][0] * m2.m[0][3]) + (m1.m[0][1] * m2.m[1][3]) + (m1.m[0][2] * m2.m[2][3]) + (m1.m[0][3] * m2.m[3][3]);	
	result.m[1][3] = (m1.m[1][0] * m2.m[0][3]) + (m1.m[1][1] * m2.m[1][3]) + (m1.m[1][2] * m2.m[2][3]) + (m1.m[1][3] * m2.m[3][3]);
	result.m[2][3] = (m1.m[2][0] * m2.m[0][3]) + (m1.m[2][1] * m2.m[1][3]) + (m1.m[2][2] * m2.m[2][3]) + (m1.m[2][3] * m2.m[3][3]);
	result.m[3][3] = (m1.m[3][0] * m2.m[0][3]) + (m1.m[3][1] * m2.m[1][3]) + (m1.m[3][2] * m2.m[2][3]) + (m1.m[3][3] * m2.m[3][3]);

	return result;

}

/// <summary>
/// 逆行列
/// </summary>
/// <param name="m">計算する行列</param>
/// <returns></returns>
Matrix4x4 Inverse(const Matrix4x4& m) {

	// 結果格納用
	Matrix4x4 result = {};

	// 行列式
	float d;

	// 行列式を求める
	d = (m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3]) + 
		(m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1]) + 
		(m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]) - 

		(m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1]) - 
		(m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3]) - 
		(m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2]) - 

		(m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3]) - 
		(m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1]) - 
		(m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2]) +

		(m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1]) + 
		(m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3]) + 
		(m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2]) + 

		(m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3]) + 
		(m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]) + 
		(m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2]) - 

		(m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1]) - 
		(m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3]) - 
		(m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]) - 

		(m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0]) - 
		(m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0]) - 
		(m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0]) + 

		(m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0]) + 
		(m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0]) + 
		(m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0]);

	// 計算処理
	if (d != 0) {

		result.m[0][0] = (1.0f / d) *
			(m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[1][3] * m.m[2][1] * m.m[3][2]
				- m.m[1][3] * m.m[2][2] * m.m[3][1] - m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][1] * m.m[2][3] * m.m[3][2]);
		result.m[0][1] = (1.0f / d) *
			(-m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] - m.m[0][3] * m.m[2][1] * m.m[3][2]
				+ m.m[0][3] * m.m[2][2] * m.m[3][1] + m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[2][3] * m.m[3][2]);
		result.m[0][2] = (1.0f / d) *
			(+m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[3][2]
				- m.m[0][3] * m.m[1][2] * m.m[3][1] - m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[3][2]);
		result.m[0][3] = (1.0f / d) *
			(-m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] - m.m[0][3] * m.m[1][1] * m.m[2][2]
				+ m.m[0][3] * m.m[1][2] * m.m[2][1] + m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][1] * m.m[1][3] * m.m[2][2]);


		result.m[1][0] = (1.0f / d) *
			(-m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] - m.m[1][3] * m.m[2][0] * m.m[3][2]
				+ m.m[1][3] * m.m[2][2] * m.m[3][0] + m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][0] * m.m[2][3] * m.m[3][2]);
		result.m[1][1] = (1.0f / d) *
			(m.m[0][0] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][0] + m.m[0][3] * m.m[2][0] * m.m[3][2]
				- m.m[0][3] * m.m[2][2] * m.m[3][0] - m.m[0][2] * m.m[2][0] * m.m[3][3] - m.m[0][0] * m.m[2][3] * m.m[3][2]);
		result.m[1][2] = (1.0f / d) *
			(-m.m[0][0] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][0] - m.m[0][3] * m.m[1][0] * m.m[3][2]
				+ m.m[0][3] * m.m[1][2] * m.m[3][0] + m.m[0][2] * m.m[1][0] * m.m[3][3] + m.m[0][0] * m.m[1][3] * m.m[3][2]);
		result.m[1][3] = (1.0f / d) *
			(m.m[0][0] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] + m.m[0][3] * m.m[1][0] * m.m[2][2]
				- m.m[0][3] * m.m[1][2] * m.m[2][0] - m.m[0][2] * m.m[1][0] * m.m[2][3] - m.m[0][0] * m.m[1][3] * m.m[2][2]);


		result.m[2][0] = (1.0f / d) *
			(m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] + m.m[1][3] * m.m[2][0] * m.m[3][1]
				- m.m[1][3] * m.m[2][1] * m.m[3][0] - m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][0] * m.m[2][3] * m.m[3][1]);
		result.m[2][1] = (1.0f / d) *
			(-m.m[0][0] * m.m[2][1] * m.m[3][3] - m.m[0][1] * m.m[2][3] * m.m[3][0] - m.m[0][3] * m.m[2][0] * m.m[3][1]
				+ m.m[0][3] * m.m[2][1] * m.m[3][0] + m.m[0][1] * m.m[2][0] * m.m[3][3] + m.m[0][0] * m.m[2][3] * m.m[3][1]);
		result.m[2][2] = (1.0f / d) *
			(m.m[0][0] * m.m[1][1] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[3][0] + m.m[0][3] * m.m[1][0] * m.m[3][1]
				- m.m[0][3] * m.m[1][1] * m.m[3][0] - m.m[0][1] * m.m[1][0] * m.m[3][3] - m.m[0][0] * m.m[1][3] * m.m[3][1]);
		result.m[2][3] = (1.0f / d) *
			(-m.m[0][0] * m.m[1][1] * m.m[2][3] - m.m[0][1] * m.m[1][3] * m.m[2][0] - m.m[0][3] * m.m[1][0] * m.m[2][1]
				+ m.m[0][3] * m.m[1][1] * m.m[2][0] + m.m[0][1] * m.m[1][0] * m.m[2][3] + m.m[0][0] * m.m[1][3] * m.m[2][1]);


		result.m[3][0] = (1.0f / d) *
			(-m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][2] * m.m[3][0] - m.m[1][2] * m.m[2][0] * m.m[3][1]
				+ m.m[1][2] * m.m[2][1] * m.m[3][0] + m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[1][0] * m.m[2][2] * m.m[3][1]);
		result.m[3][1] = (1.0f / d) *
			(m.m[0][0] * m.m[2][1] * m.m[3][2] + m.m[0][1] * m.m[2][2] * m.m[3][0] + m.m[0][2] * m.m[2][0] * m.m[3][1]
				- m.m[0][2] * m.m[2][1] * m.m[3][0] - m.m[0][1] * m.m[2][0] * m.m[3][2] - m.m[0][0] * m.m[2][2] * m.m[3][1]);
		result.m[3][2] = (1.0f / d) *
			(-m.m[0][0] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][2] * m.m[3][0] - m.m[0][2] * m.m[1][0] * m.m[3][1]
				+ m.m[0][2] * m.m[1][1] * m.m[3][0] + m.m[0][1] * m.m[1][0] * m.m[3][2] + m.m[0][0] * m.m[1][2] * m.m[3][1]);
		result.m[3][3] = (1.0f / d) *
			(m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] + m.m[0][2] * m.m[1][0] * m.m[2][1]
				- m.m[0][2] * m.m[1][1] * m.m[2][0] - m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][2] * m.m[2][1]);

	}

	return result;

}

/// <summary>
/// 転置行列
/// </summary>
/// <param name="m">転置する行列</param>
/// <returns></returns>
Matrix4x4 Transpose(const Matrix4x4& m) {

	// 結果格納用
	Matrix4x4 result;

	// 計算処理
	result.m[0][0] = m.m[0][0];
	result.m[0][1] = m.m[1][0];
	result.m[0][2] = m.m[2][0];
	result.m[0][3] = m.m[3][0];

	result.m[1][0] = m.m[0][1];
	result.m[1][1] = m.m[1][1];
	result.m[1][2] = m.m[2][1];
	result.m[1][3] = m.m[3][1];

	result.m[2][0] = m.m[0][2];
	result.m[2][1] = m.m[1][2];
	result.m[2][2] = m.m[2][2];
	result.m[2][3] = m.m[3][2];

	result.m[3][0] = m.m[0][3];
	result.m[3][1] = m.m[1][3];
	result.m[3][2] = m.m[2][3];
	result.m[3][3] = m.m[3][3];

	return result;

}

/// <summary>
/// 単位行列を作成する関数
/// </summary>
/// <returns></returns>
Matrix4x4 MakeIdentity4x4() {

	// 結果格納用
	Matrix4x4 result{};

	// 生成処理
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	/// 変数宣言
	// 行列1
	Matrix4x4 m1 = { 3.2f, 0.7f, 9.6f, 4.4f,
					 5.5f, 1.3f, 7.8f, 2.1f,
					 6.9f, 8.0f, 2.6f, 1.0f,
					 0.5f, 7.2f, 5.1f, 3.3f };

	// 行列1
	Matrix4x4 m2 = { 4.1f, 6.5f, 3.3f, 2.2f,
					 8.8f, 0.6f, 9.9f, 7.7f,
					 1.1f, 5.5f, 6.6f, 0.0f,
					 3.3f, 9.9f, 8.8f, 2.2f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// 加算
		Matrix4x4 resultAdd = Add(m1, m2);

		// 減算
		Matrix4x4 resultSubtract = Subtract(m1, m2);

		// 乗算
		Matrix4x4 resultMultiply = Multiply(m1, m2);

		// 逆行列
		Matrix4x4 resultInverseM1 = Inverse(m1);
		Matrix4x4 resultInverseM2 = Inverse(m2);

		// 転置行列
		Matrix4x4 resultTransposeM1 = Transpose(m1);
		Matrix4x4 resultTransposeM2 = Transpose(m2);

		// 単位行列の生成
		Matrix4x4 resultIdentity = MakeIdentity4x4();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 加算結果の表示
		MatrixScreenPrintf(0, 0, resultAdd, "Add");

		// 減算結果の表示
		MatrixScreenPrintf(0, kRowHeight * 5, resultSubtract, "Subtract");

		// 乗算結果の表示
		MatrixScreenPrintf(0, kRowHeight * 5 * 2, resultMultiply, "Multiply");

		// 逆行列の表示
		MatrixScreenPrintf(0, kRowHeight * 5 * 3, resultInverseM1, "InverseM1");
		MatrixScreenPrintf(0, kRowHeight * 5 * 4, resultInverseM2, "InverseM2");

		// 転置行列の表示
		MatrixScreenPrintf(kColumnWidth * 5, 0, resultTransposeM1, "transposeM1");
		MatrixScreenPrintf(kColumnWidth * 5, kRowHeight * 5, resultTransposeM2, "transposeM2");

		// 単位行列の表示
		MatrixScreenPrintf(kColumnWidth * 5, kRowHeight * 5 * 2, resultIdentity, "identity");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
