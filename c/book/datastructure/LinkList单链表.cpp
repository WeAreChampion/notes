//������
#include<iostream>
using namespace std;
typedef struct LNode
{
	char data;
	struct LNode *next;
}LinkList;
void InitList(LinkList *&l)//��ʼ��������
{
//	l=(LinkList *)new (LinkList);//���߶�����
//	l=(LinkList *)malloc(sizeof(LinkList));
	l=new (LinkList);
	l->next=NULL;
}
void DestroyList(LinkList *&l)//������ͷŽڵ�
{
	LinkList *p=l->next;
	while(p!=NULL)
	{
		l->next = p->next ;
		delete p;
		p = l->next ;
	}
	delete l;
	/*
	LinkList *p=l,*q=p->next;//�������ϵģ����ϴ��󣬰�ͷ����ͷ��ˣ�
	while(p!=NULL)
	{
		delete p;
		p=q;
		p=p->next ;
	}
	delete p;
	//*/
}
int ListEmpty(LinkList *l)//�жϵ������Ƿ�ǿ�
{
	return (l->next==NULL);
}
int ListLength(LinkList *l)//��������
{
	LinkList *p=l->next;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
int ListInsert(LinkList *&l,int i,char e)//����
{
	LinkList *p=l,*q,*s;
	int j=0;
	s=(LinkList *) new (LinkList);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)//Ӧ�жϲ���λ��i�Ƿ�Ϸ�
		return 0;
	q=p->next ;
	s->data =e;
	s->next=p->next ;
	p->next =s;
	return 1;
}
void DispList(LinkList *l)//���������
{
	LinkList *p=l->next;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;//Ӧ�û���
}
int ListDelete(LinkList *&l,int i,char &e)//ɾ����i��Ԫ��
{
	LinkList *p=l,*q;
	int j=0;
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	q=p->next;
	e=q->data;
	if(q==NULL)//Ӧ���ж�iֵ�Ƿ�Ϸ�
		return 0;
	p->next=q->next;
	delete q;
	return 1;
}
int LocateElem(LinkList *l,char e)//����Ԫ��ֵΪe
{
	LinkList *p=l;
	int i=0;
	while(p!=NULL&&p->data !=e)
	{
		i++;
		p=p->next ;
	}
	if(p==NULL)//Ӧ���ж�eֵ�Ƿ�Ϸ�
		return 0;//δ�ҵ�����0
	return i;
}
int GetElem(LinkList *l,int i,char &e)//��õ�i��Ԫ�ص�ֵ
{
	LinkList *p=l;
	int j=0;
	while(j<i&&p!=NULL)
	{
		j++;
		p=p->next ;
	}
	if(p==NULL)//Ӧ�ÿ���i�Ƿ�Ϸ�
		return 0;
	e=p->data;
	return 1;
}
int main()
{
	LinkList *l;
	char e;
	InitList(l);
	cout<<"������Ϊ:"<<(ListEmpty(l)?"��":"�ǿ�")<<endl;
	ListInsert(l,1,'a');
	ListInsert(l,2,'b');
	ListInsert(l,3,'c');
	ListInsert(l,4,'d');
	ListInsert(l,5,'e');
	cout<<"������Ϊ:"<<(ListEmpty(l)?"��":"�ǿ�")<<endl;
	cout<<"˳���Ϊ:";
	DispList(l);
	cout<<"��:"<<ListLength(l)<<endl;
	GetElem(l,3,e);
	cout<<"���е�3��Ԫ����:"<<e<<endl;
	cout<<"Ԫ��a��λ���ǣ�"<<LocateElem(l,'a')<<endl;
	ListInsert(l,4,'f');
	cout<<"�ڵ��ĸ�Ԫ��λ���ϲ���f"<<endl<<"˳�����:";
	DispList(l);
	ListDelete(l,3,e);
	cout<<"ɾ��������Ԫ��"<<endl<<"˳�����:";
	DispList(l);
	cout<<"�ͷ�˳���"<<endl;
    DestroyList(l);
	cout<<"������Ϊ:"<<(ListEmpty(l)?"��":"�ǿ�")<<endl;
	return 0;
}