#include"LinkList.h"
/*
	1. 求单链表的倒数第k个节点。 
	2. 通过两指针间的间距为k，而后从头开始移动，若
	最后一根指针为空，则前面的指针则为倒数第k个节点。
	3. 若有则返回该节点指针，否则返回NULL。 
*/
LinkList* getKNode(LinkList *l, int k)
{
	if(k <= 0) {
		return NULL;
	}
	LinkList *p = NULL, *q = NULL;
	p = l;
	//q point to -> the first node
	q = l->next;
	int i = 0;
	//p point to(->) the k-th node
	while(i < k && p != NULL) {
		i++;
		p = p->next;
	}
	//That means don't have the node
	if(p == NULL) {
		return NULL;
	}
	/*
		p and q get the next and when p->next == NULL then finish the circle.
		That means the p is the last node and the q is the answer.
	*/
	while(p->next != NULL) {
		q = q->next;
		p = p->next;
	}
	return q;
}
int main()
{
	LinkList *l;
	char e;
	InitList(l);
	cout<<"单链表为:"<<(ListEmpty(l) ? "空":"非空")<<endl;
	ListInsert(l,1,'a');
	ListInsert(l,2,'b');
	ListInsert(l,3,'c');
	ListInsert(l,4,'d');
	ListInsert(l,5,'e');
	cout<<"单链表为:"<<(ListEmpty(l)?"空":"非空")<<endl;
	cout<<"顺序表为:";
	DispList(l);
	cout<<"表长:"<<ListLength(l)<<endl;
	
	LinkList *p = getKNode(l, 1);
	cout << p->data << endl;
	
	p = getKNode(l, 2);
	cout << p->data << endl;
	
	p = getKNode(l, 3);
	cout << p->data << endl;
	
	p = getKNode(l, 4);
	cout << p->data << endl;
	
	p = getKNode(l, 5);
	cout << p->data << endl;
	
	p = getKNode(l, 6);
	cout << p << endl;
	
	cout<<"释放顺序表"<<endl;
    DestroyList(l);
    cout << sizeof(l) << endl;
	return 0;
}
