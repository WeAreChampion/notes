#include<iostream>
using namespace std;
#define MAX_SIZE 12500
typedef int ElemType;
/**
	元素节点
*/
typedef struct {
	int row, column;
	ElemType e;
}Triple;

/**
	三元组，稀疏矩阵存储
*/
typedef struct {
	Triple data[MAX_SIZE + 1];
	int mu;//行
	int nu;//列
	int tu;//非零元素个数
}TSMatrix;