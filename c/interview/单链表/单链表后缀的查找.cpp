#include"LinkList.h"
/*
	判断是否有相同的后缀，若有，则返回true；否则返回false。 
*/
bool isCommonTail(LinkList* list1, LinkList *list2)
{
	LinkList *p = list1, *q = list2;
	while(p != NULL) {
//		cout << p->data << " " << q->data << endl;
		if(p->data != q->data) {
			return false;
		}
		p = p->next;
		q = q->next;
	}
	return true;
}
/*
	寻找相同的后缀，找到返回开始节点；否则返回NULL。 
*/ 
LinkList* getCommonTail(LinkList* list1, LinkList *list2)
{
	LinkList* p = NULL, *q = NULL;
	int length1 = ListLength(list1);
	int length2 = ListLength(list2);
	int i = 0;
	//p指向长度较长链表中第length1 - length2 + 1个节点 
	if(length1 > length2) {
		i = length1 - length2 + 1;
		p = list1;
		q = list2->next;
	} else {
		i = length2 - length1 + 1;
		p = list2;
		q = list1->next;
	}
	while(i--) {
		p = p->next;
	}
	while(p != NULL) {
		if(p->data == q->data) {
			if(isCommonTail(p, q)) {
				return p;
			}
		}
		p = p->next;
		q = q->next;
	}
	return NULL;
}
void testGetCommonTail()
{
	LinkList *list1, *list2;
	InitList(list1);
	ListInsert(list1, 1, 'b');
	ListInsert(list1, 2, 'e');
	ListInsert(list1, 3, 'i');
	ListInsert(list1, 4, 'm');
	ListInsert(list1, 5, 'g');
	DispList(list1);
	
	InitList(list2);
	ListInsert(list2, 1, 's');
	ListInsert(list2, 2, 'w');
	ListInsert(list2, 3, 'i');
	ListInsert(list2, 4, 'm');
	ListInsert(list2, 5, 'i');
	ListInsert(list2, 6, 'n');
	ListInsert(list2, 7, 'g');
	DispList(list2);
	
	LinkList *r = getCommonTail(list1, list2);
	if(r == NULL) {
		cout << "No" << endl;
	} else {
		cout << r->data << endl; 
	}
	
	cout<<"释放顺序表"<<endl;
    DestroyList(list1);
    DestroyList(list2);
}
/*
	在后缀中寻找第一个相同元素的节点 
*/ 
LinkList* getTail(LinkList* list1, LinkList *list2)
{
	LinkList* p = NULL, *q = NULL;
	int length1 = ListLength(list1);
	int length2 = ListLength(list2);
	int i = 0;
	//p指向长度较长链表中第length1 - length2 + 1个节点 
	if(length1 > length2) {
		i = length1 - length2 + 1;
		p = list1;
		q = list2->next;
	} else {
		i = length2 - length1 + 1;
		p = list2;
		q = list1->next;
	}
	while(i--) {
		p = p->next;
	}
	while(p != NULL) {
		if(p->data != q->data) {
			p = p->next;
			q = q->next;
		} else {
			return p;
		}
	}
	return NULL;
}
void testGetTail()
{
	LinkList *list1, *list2;
	InitList(list1);
	ListInsert(list1, 1, 'b');
	ListInsert(list1, 2, 'e');
	ListInsert(list1, 3, 'i');
	ListInsert(list1, 4, 'n');
	ListInsert(list1, 5, 'g');
	DispList(list1);
	
	InitList(list2);
	ListInsert(list2, 1, 's');
	ListInsert(list2, 2, 'w');
	ListInsert(list2, 3, 'i');
	ListInsert(list2, 4, 'm');
	ListInsert(list2, 5, 'i');
	ListInsert(list2, 6, 'n');
	ListInsert(list2, 7, 'g');
	DispList(list2);
	
	LinkList *r = getTail(list1, list2);
	if(r == NULL) {
		cout << "No" << endl;
	} else {
		cout << r->data << endl; 
	}
	
	cout<<"释放顺序表"<<endl;
    DestroyList(list1);
    DestroyList(list2);
}
int main()
{
//	testGetTail();
	testGetCommonTail();
	return 0;
}