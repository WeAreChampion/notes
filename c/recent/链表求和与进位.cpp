#include<iostream>
using namespace std;
typedef int Type;
typedef struct LNode
{
	Type data;
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
int ListInsert(LinkList *&l, int i, Type e)//To insert the data into List
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
void ListInsert(LinkList *&p, Type data) {
	LinkList *s = (LinkList *) new (LinkList);
	s->data = data;
	s->next = p->next;
	p->next = s;
}
int getSum(LinkList *&sum, LinkList *p, LinkList *q) {
	int flag = 0;
	// The exit
	if(p == NULL && q == NULL) {
		return 0;	
	}
	if(p != NULL && q != NULL) {
		// To get the next
		return flag + getSum(sum, p->next, q->next);
	}
	if(p != NULL) {                             
		sum = flag + p->data;
		if(sum >= 10) {
			sum -= 10;
			flag = 1;
		}
		ListInsert(sum, data);
		return flag + getSum(sum, p->next, NULL);
	}
	
	if(q != NULL) {
		sum = flag + q->data;
		if(sum >= 10) {
			sum -= 10;
			flag = 1;
		}
		ListInsert(sum, data);
		return flag + getSum(sum, NULL, q->next);
	}
	
	// is the last node
	if(p->next == NULL && q->next == NULL) {
		int data = p->data + q->data;
		if(data >= 10) {
			data -= 10;
			flag = 1;
		}
		ListInsert(sum, data);
		return flag;
	}
}
LinkList *getSumList(LinkList *p, LinkList *q) {
		LinkList *sum;
		InitList(sum);
		
		// To calculate the sum
		getSum(sum, p, q);
		
		return sum;
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

void test() {
	LinkList *p, *q;
	InitList(p);
	InitList(q);
	ListInsert(p, 1, 9);
	ListInsert(p, 2, 8);
	ListInsert(p, 3, 7);
	ListInsert(p, 4, 9);
	ListInsert(p, 5, 3);
	DispList(p);
	
	
	ListInsert(q, 1, 9);
	ListInsert(q, 1, 8);
	ListInsert(q, 1, 7);
	ListInsert(q, 1, 9);
	ListInsert(q, 1, 3);
	DispList(q);
	
	Linklist *sum = getSumList(p, q);
	DispList(sum);
	DestroyList(p);
	DestroyList(q);
	DestroyList(sum);
	system("pause");
}
int main() {
	test();
	return 0;
}
[DefaultSettings]
Syntax=0
