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
void InitList(SqList *&l)//��ʼ����
{
	//l=(SqList*)malloc(sizeof(SqList));//���ٿռ�
	//l=(SqList*)new(SqList);
	l = new(SqList);
	l->length = 0;//����
}
void DestroyList(SqList *l)//�ͷ�˳���
{
	//free(l);
	delete l;//�ͷſռ�
}
int ListEmpty(SqList *l)//�ж�˳����Ƿ�Ϊ��
{
	return l->length == 0;
}
int ListLength(SqList*l)//��˳���ĳ���
{
	return l->length;
}
void DispList(SqList *l)//���˳���
{
	if(ListEmpty(l))//�ж�˳����Ƿ�Ϊ��
		return;
	for(int i = 0; i < l->length; i++)
		cout << l->data[i] << " ";
	cout << endl;
}
int GetElem(SqList *l, int i, ElemType &e)//��ȡ˳����е�i��Ԫ��
{
	if(i < 1 || i > l->length)//iֵ�Ƿ�
		return 0;
	e = l->data[i - 1];
	return 1;
}
int LocateElem(SqList *l, ElemType e)//���ҵ�һ��Ԫ��e
{
	int i = 0;
	while(i < l->length && l->data[i] != e)//δ�ҵ�
		i++;
	if(i >= l->length)//δ�ҵ�
		return 0;
	else
		return i + 1;
}
int ListInsert(SqList *&l, int i, ElemType e)//�ڵ�i��λ�ò���Ԫ��e
{
	if(i < 1 ||i > l->length + 1)//iֵ�Ƿ�
		return 0;
	i--;
	for(int j = l->length; j > i; j--)
		l->data[j] = l->data[j - 1];//Ԫ�غ���
	l->data[i] = e;//����ɹ�
	l->length++;//˳����ȼ�1
	return 1;
}
int ListDelete(SqList*&l, int i, ElemType e)//ɾ����i��Ԫ��
{
	if(i < 1 || i > l->length)//iֵ�Ƿ�
		return 0;
	i--;
	for(int j = i; j < l->length; j++)
		l->data[j] = l->data[j + 1];//Ԫ��ǰ��
	l->length--;//���ȼ�1
	return 1;
}