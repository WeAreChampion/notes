#include<iostream>
using namespace std;
typedef struct DNode
{
	struct DNode *prior;//前驱
	struct DNode *next;//后继
	char data;//保存数据
}DLinkList;
void InitList(DLinkList *&l)//初始化表
{
	l = (DLinkList *)new(DLinkList);
	l->next = l->prior = NULL;
}
int ListLength(DLinkList *l)//求表长
{
	DLinkList *p = l->next;
	int i = 0;
	while(p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
int ListEmpty(DLinkList *l)//判定表是否非空
{
	return (l-> next == NULL);
}
void ClearList(DLinkList *&l)//清除表
{
	DLinkList *p = l, *q;
	while(p->next != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	delete p;
}
void ListInsert(DLinkList *&l, int i, char e)//插入
{
	DLinkList *p = l, *s ;
	s = (DLinkList *) new (DLinkList);
	int j = 0;
	while(j < i - 1 && p != NULL) {
		p = p->next;
		j++;
	}
	s->data = e;
	s->next = p->next;
	if(p->next != NULL)//要判定
		p->next->prior = p;
	s->prior = p;
	p->next = s;
	//s->next->prior = s;非法
}
void ListDelete(DLinkList *&l, int i, char &e)//删除
{
	DLinkList *p = l, *q;
	int j = 0;
	while(p != NULL && j < i - 1) {
		p = p->next ;
		j++;
	}
	q = p->next;
	e = q->data;
	p->next = q->next;
	q->next->prior = p;
	delete q;
}
int DispList(DLinkList *l)
{
	DLinkList *p = l->next;
	if(p->next == NULL)
		return 0;
	while(p != NULL) {
		cout << p->data ;
		p = p->next ;
	}
	cout << endl;
	return 1;
}
void GetElem(DLinkList *l,int i,char &e)
{
	DLinkList *p = l;
	int j = 0;
	while(p != NULL && j < i) {
		j++;
		p = p->next;
	}
	e = p->data;
}
int LocateElem(DLinkList *l, char e)
{
	int i = 0;
	DLinkList *p = l;
	while(p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	return i;
}
