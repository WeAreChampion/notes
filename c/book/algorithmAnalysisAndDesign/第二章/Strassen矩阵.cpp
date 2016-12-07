#include <iostream>
using namespace std;
//Define the size of the Matrix
const int N = 8;
template<typename T>
void Strassen(int n, T A[][N], T B[][N], T C[][N]);
template<typename T>
void input(int n, T p[][N]);
template<typename T>
void output(int n, T C[][N]);
int main()
{
	// Define three Matrices
	int A[N][N], B[N][N], C[N][N];
	// 对A和B矩阵赋值，随便赋值都可以，测试用
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			A[i][j] = i * j;
			B[i][j] = i * j;
		}
	}
	// 调用Strassen方法实现C = A * B
	Strassen(N, A, B, C);
	
	// 输出矩阵C中值
	output(N, C);
	system("pause");
	return 0;
}
/**
	input the matrix
*/
template<typename T>
void input(int n, T p[][N])
{
	for(int i = 0; i < n; i++) {
		cout << "Please Input Line " << i + 1 << endl;
		for(int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
}
/**
	output the matrix
*/
template<typename T>
void output(int n, T C[][N])
{
	cout << "The Output Matrix is :" << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
}
/**
	矩阵乘法
	C = A * B
*/
template<typename T>
void Matrix_Multiply(T A[][N], T B[][N], T C[][N]) 
{
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			C[i][j] = 0;
			for(int t = 0; t < 2; t++) {
				C[i][j] = C[i][j] + A[i][t] * B[t][j];
			}
		}
	}
}
/**
	矩阵加法
	Z = X + Y
*/
template <typename T>
void Matrix_Add(int n, T X[][N], T Y[][N], T Z[][N])
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			Z[i][j] = X[i][j] + Y[i][j];
		}
	}
}
/**
	矩阵减法
	Z = X - Y
*/
template <typename T>
void Matrix_Sub(int n, T X[][N], T Y[][N], T Z[][N])
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			Z[i][j] = X[i][j] - Y[i][j];
		}
	}
}
/**
	C11 C12	  A11 A12   B11 B12
			=         * 
	C21 C22   A21 A22   B21 B22

	
	Strassen algorithm
	
	M1 = A11(B12 - B22)
	M2 = (A11 + A12)B22
	M3 = (A21 + A22)B11
	M4 = A22(B21 - B11)
	M5 = (A11 + A22)(B11 + B22)
	M6 = (A12 - A22)(B21 + B22)
	M7 = (A11 - A21)(B11 + B12)
	
	C11 = M5 + M4 - M2 + M6
	C12 = M1 + M2
	C21 = M3 + M4
	C22 = M5 + M1 - M3 - M7
*/
template <typename T>
void Strassen(int n, T A[][N], T B[][N], T C[][N])
{
	T A11[N][N], A12[N][N], A21[N][N], A22[N][N];
	T B11[N][N], B12[N][N], B21[N][N], B22[N][N];
	T C11[N][N], C12[N][N], C21[N][N], C22[N][N];
	T M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];   //save the M
	T AA[N][N], BB[N][N];
	int i, j;
	
	// 只有两个矩阵
	if(n == 2) {
		Matrix_Multiply(A, B, C);
	} else {
		//将矩阵A和B分成阶数相同的四个子矩阵，即分治思想。
		for(i = 0; i < n / 2; i++) {
			for(j = 0; j < n / 2; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + n / 2];
				A21[i][j] = A[i + n / 2][j];
				A22[i][j] = A[i + n / 2][j + n / 2];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + n / 2];
				B21[i][j] = B[i + n / 2][j];
				B22[i][j] = B[i + n / 2][j + n / 2];
			}
		}

		//Calculate M1 = (A0 + A3) × (B0 + B3)
		Matrix_Add(n / 2, A11, A22, AA);
		Matrix_Add(n / 2, B11, B22, BB);
		Strassen(n / 2, AA, BB, M1);

		//Calculate M2 = (A2 + A3) × B0
		Matrix_Add(n / 2, A21, A22, AA);
		Strassen(n / 2, AA, B11, M2);

		//Calculate M3 = A0 × (B1 - B3)
		Matrix_Sub(n / 2, B12, B22, BB);
		Strassen(n / 2, A11, BB, M3);

		//Calculate M4 = A3 × (B2 - B0)
		Matrix_Sub(n / 2, B21, B11, BB);
		Strassen(n / 2, A22, BB, M4);

		//Calculate M5 = (A0 + A1) × B3
		Matrix_Add(n / 2, A11, A12, AA);
		Strassen(n / 2, AA, B22, M5);

		//Calculate M6 = (A2 - A0) × (B0 + B1)
		Matrix_Sub(n / 2, A21, A11, AA);
		Matrix_Add(n / 2, B11, B12, BB);
		Strassen(n / 2, AA, BB, M6);

		//Calculate M7 = (A1 - A3) × (B2 + B3)
		Matrix_Sub(n / 2, A12, A22, AA);
		Matrix_Add(n / 2, B21, B22, BB);
		Strassen(n / 2, AA, BB, M7);

		//Calculate C0 = M1 + M4 - M5 + M7
		Matrix_Add(n / 2, M1, M4, AA);
		Matrix_Sub(n / 2, M7, M5, BB);
		Matrix_Add(n/ 2, AA, BB, C11);

		//Calculate C1 = M3 + M5
		Matrix_Add(n / 2, M3, M5, C12);

		//Calculate C2 = M2 + M4
		Matrix_Add(n / 2, M2, M4, C21);

		//Calculate C3 = M1 - M2 + M3 + M6
		Matrix_Sub(n / 2, M1, M2, AA);
		Matrix_Add(n / 2, M3, M6, BB);
		Matrix_Add(n / 2, AA, BB, C22);

		//Set the result to C[][N]
		for(i = 0; i < n / 2; i++) {
			for(j = 0; j < n / 2; j++) {
				C[i][j] = C11[i][j];
				C[i][j + n / 2] = C12[i][j];
				C[i + n / 2][j] = C21[i][j];
				C[i + n / 2][j + n / 2] = C22[i][j];
			}
		}
	}
}