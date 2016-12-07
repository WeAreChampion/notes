#include"LinkList.h"
/*
	1. ������ĵ�����k���ڵ㡣 
	2. ͨ����ָ���ļ��Ϊk�������ͷ��ʼ�ƶ�����
	���һ��ָ��Ϊ�գ���ǰ���ָ����Ϊ������k���ڵ㡣
	3. �����򷵻ظýڵ�ָ�룬���򷵻�NULL�� 
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
	cout<<"������Ϊ:"<<(ListEmpty(l) ? "��":"�ǿ�")<<endl;
	ListInsert(l,1,'a');
	ListInsert(l,2,'b');
	ListInsert(l,3,'c');
	ListInsert(l,4,'d');
	ListInsert(l,5,'e');
	cout<<"������Ϊ:"<<(ListEmpty(l)?"��":"�ǿ�")<<endl;
	cout<<"˳���Ϊ:";
	DispList(l);
	cout<<"��:"<<ListLength(l)<<endl;
	
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
	
	cout<<"�ͷ�˳���"<<endl;
    DestroyList(l);
    cout << sizeof(l) << endl;
	return 0;
}
