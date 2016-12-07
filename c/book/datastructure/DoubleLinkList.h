#include<iostream>
using namespace std;
typedef struct DNode
{
	struct DNode *prior;//ǰ��
	struct DNode *next;//���
	char data;//��������
}DLinkList;
void InitList(DLinkList *&l)//��ʼ����
{
	l = (DLinkList *)new(DLinkList);
	l->next = l->prior = NULL;
}
int ListLength(DLinkList *l)//���
{
	DLinkList *p = l->next;
	int i = 0;
	while(p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
int ListEmpty(DLinkList *l)//�ж����Ƿ�ǿ�
{
	return (l-> next == NULL);
}
void ClearList(DLinkList *&l)//�����
{
	DLinkList *p = l, *q;
	while(p->next != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	delete p;
}
void ListInsert(DLinkList *&l, int i, char e)//����
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
	if(p->next != NULL)//Ҫ�ж�
		p->next->prior = p;
	s->prior = p;
	p->next = s;
	//s->next->prior = s;�Ƿ�
}
void ListDelete(DLinkList *&l, int i, char &e)//ɾ��
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
