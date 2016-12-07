#include<iostream>
using namespace std;
#include<malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;
void InitList(SqList *&l)//初始化表
{
	//l=(SqList*)malloc(sizeof(SqList));//开辟空间
	//l=(SqList*)new(SqList);
	l = new(SqList);
	l->length = 0;//表长度
}
void DestroyList(SqList *l)//释放顺序表
{
	//free(l);
	delete l;//释放空间
}
int ListEmpty(SqList *l)//判断顺序表是否为空
{
	return l->length == 0;
}
int ListLength(SqList*l)//求顺序表的长度
{
	return l->length;
}
void DispList(SqList *l)//输出顺序表
{
	if(ListEmpty(l))//判断顺序表是否为空
		return;
	for(int i = 0; i < l->length; i++)
		cout << l->data[i] << " ";
	cout << endl;
}
int GetElem(SqList *l, int i, ElemType &e)//获取顺序表中第i个元素
{
	if(i < 1 || i > l->length)//i值非法
		return 0;
	e = l->data[i - 1];
	return 1;
}
int LocateElem(SqList *l, ElemType e)//查找第一个元素e
{
	int i = 0;
	while(i < l->length && l->data[i] != e)//未找到
		i++;
	if(i >= l->length)//未找到
		return 0;
	else
		return i + 1;
}
int ListInsert(SqList *&l, int i, ElemType e)//在第i个位置插入元素e
{
	if(i < 1 ||i > l->length + 1)//i值非法
		return 0;
	i--;
	for(int j = l->length; j > i; j--)
		l->data[j] = l->data[j - 1];//元素后移
	l->data[i] = e;//插入成功
	l->length++;//顺序表长度加1
	return 1;
}
int ListDelete(SqList*&l, int i, ElemType e)//删除第i个元素
{
	if(i < 1 || i > l->length)//i值非法
		return 0;
	i--;
	for(int j = i; j < l->length; j++)
		l->data[j] = l->data[j + 1];//元素前移
	l->length--;//表长度减1
	return 1;
}