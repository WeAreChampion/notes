#include<iostream>
using namespace std;
typedef struct LNode
{
	char data;
	struct LNode *next;
}LinkList;
void InitList(LinkList *&l)//To init the LinkList
{
	l = new (LinkList);
	l->next = NULL;
}
void DestroyList(LinkList *&l)//To destroy List
{
	LinkList *p = l->next;
	while(p != NULL) {
		l->next = p->next;
		delete p;
		p = l->next;
	}
	delete l;
}
int ListEmpty(LinkList *l)//To default the List whether is empty
{
	return (l->next == NULL);
}
int ListLength(LinkList *l)//To calculate the List's length
{
	LinkList *p = l->next;
	int i = 0;
	while(p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
int ListInsert(LinkList *&l, int i, char e)//To insert the data into List
{
	LinkList *p = l, *q, *s;
	int j = 0;
	s = (LinkList *) new (LinkList);
	while(j < i - 1 && p != NULL) {
		p = p->next;
		j++;
	}
	if(p == NULL)//can't insert and wrong i(or beyond the wides)
		return 0;
	q = p->next ;
	s->data =e;
	s->next = p->next ;
	p->next =s;
	return 1;
}
void DispList(LinkList *l)//To display the List
{
	LinkList *p = l->next;
	while(p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}
