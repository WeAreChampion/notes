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
	cout << "������Ϊ:" << (ListEmpty(l) ? "��" : "�ǿ�") << endl;
	ListInsert(l,1,'a');
	ListInsert(l,2,'b');
	ListInsert(l,3,'c');
	ListInsert(l,4,'d');
	ListInsert(l,5,'e');
	cout << "������Ϊ:" << (ListEmpty(l) ? "��" : "�ǿ�") << endl;
	cout << "˳���Ϊ:";
	DispList(l);
	cout << "��:" << ListLength(l) << endl;
	cout << "��ת�������" << endl;
	reverseLinkList(l);
	cout << "��:" << ListLength(l) << endl;
	DispList(l);
	cout << "�ͷ�˳���" << endl;
    DestroyList(l);
    cout << sizeof(l) << endl;
	return 0;
}