#include"LinkList.h" 
void reverseLinkList(LinkList *&l)
{
	//no node
	if(l->next == NULL) {
		return ;
	}
	//only one node
	if(l->next->next == NULL) {
		return ;
	}
	LinkList *p = l->next;
	LinkList *q = p->next;
	while(p->next != NULL) {
		//save the q's next in p->next
		p->next = q->next;
		//save the l->next in q->next
		q->next = l->next;
		//insert the q behind l
		l->next = q;
		//q point to p->next
		q = p->next;
	}
}
int main()
{
	LinkList *l;
	char e;
	InitList(l);
	cout << "单链表为:" << (ListEmpty(l) ? "空" : "非空") << endl;
	ListInsert(l,1,'a');
	ListInsert(l,2,'b');
	ListInsert(l,3,'c');
	ListInsert(l,4,'d');
	ListInsert(l,5,'e');
	cout << "单链表为:" << (ListEmpty(l) ? "空" : "非空") << endl;
	cout << "顺序表为:";
	DispList(l);
	cout << "表长:" << ListLength(l) << endl;
	cout << "反转单链表后：" << endl;
	reverseLinkList(l);
	cout << "表长:" << ListLength(l) << endl;
	DispList(l);
	cout << "释放顺序表" << endl;
    DestroyList(l);
    cout << sizeof(l) << endl;
	return 0;
}