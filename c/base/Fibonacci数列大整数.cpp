#include<iostream>
#include<assert.h>
using namespace std;
/*
	求出Fibonacci数列的第N项值.
*/
// A 2 by 2 matrix
typedef struct tagMatrix2By2
{
	tagMatrix2By2(long long m00 = 0, 
		long long m01 = 0, 
		long long m10 = 0, 
		long long m11 = 0)
			:m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}
	long long m_00;
	long long m_01;
	long long m_10;
	long long m_11;
}S_Matrix2By2;
// Multiply two matrices
// Input: sMatrix1 - the first matrix
//        sMatrix2 - the second matrix
//Output: the production of two matrices
S_Matrix2By2 MatrixMultiply(const S_Matrix2By2& sMatrix1, const S_Matrix2By2& sMatrix2)
{
      return S_Matrix2By2(
		sMatrix1.m_00 * sMatrix2.m_00 + sMatrix1.m_01 * sMatrix2.m_10,
		sMatrix1.m_00 * sMatrix2.m_01 + sMatrix1.m_01 * sMatrix2.m_11,
		sMatrix1.m_10 * sMatrix2.m_00 + sMatrix1.m_11 * sMatrix2.m_10,
		sMatrix1.m_10 * sMatrix2.m_01 + sMatrix1.m_11 * sMatrix2.m_11);
}
// The nth power of matrix 
// 1  1
// 1  0
S_Matrix2By2 MatrixPower(int i32N)
{
	assert(i32N > 0);
	S_Matrix2By2 sMatrix;
	if(i32N == 1) {
		sMatrix = S_Matrix2By2(1, 1, 1, 0);
	} else if(i32N % 2 == 0) {//快速乘方，为偶数时 
		sMatrix = MatrixPower(i32N / 2);
  		sMatrix = MatrixMultiply(sMatrix, sMatrix);
	} else if(i32N % 2 == 1) {//快速乘方，为奇数时 
		sMatrix = MatrixPower((i32N - 1) / 2);
   		sMatrix = MatrixMultiply(sMatrix, sMatrix);
		sMatrix = MatrixMultiply(sMatrix, S_Matrix2By2(1, 1, 1, 0));
	}
      return sMatrix;
}
long long FibNItemValue_3(int i32NItem)
{
	int aryRes[2] = {0, 1};
	if(i32NItem < 2)
   		return aryRes[i32NItem];
	S_Matrix2By2 sPowerNMinus2 = MatrixPower(i32NItem - 1);
	return sPowerNMinus2.m_00;
}
int main()
{
	printf("N item value is %u.\n", FibNItemValue_3(10));
	return 0;
}
