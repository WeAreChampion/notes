#include<iostream>
using namespace std;
typedef struct LNode
{
	char data;
	struct LNode *next;
}LinkList;
void InitList(LinkList *&l)//��ʼ��������
{
	l=(LinkList *)new (LinkList);
	//l=new (LinkList);//���߶�����
	l->next=l;
}
void DestroyList(LinkList *&l)//������ͷŽڵ�
{
	LinkList *p=l->next,*q;
	while(p!=l)
	{
		q=p->next ;
		delete p;
		p=q;
		
	}
	delete p;
}
int ListEmpty(LinkList *l)//�жϵ������Ƿ�ǿ�
{
	return (l->next==l);
}
int ListLength(LinkList *l)//��������
{
	LinkList *p=l->next ;
	int i=0;
	while(p!=l)
	{
		i++;
		p=p->next;
	}
	return i;
}
int ListInsert(LinkList *&l,int i,char e)//����
{
	LinkList *p=l,*s;
	int j=0;
	s=(LinkList *) new (LinkList);
	s->data=e;
	if(i==1||p->next==l)
	{
		s->next=p->next;
		p->next=s;
	}
	else
	{
		p=l->next;//pָ���һ�����
		while(j<i-2&&p!=l)
		{
			j++;
			p=p->next;
		}
		if(p==l)
			return 0;
		else
		{
			s->next=p->next ;
			p->next =s;
		}
	}
	return 1;
}
void DispList(LinkList *l)//���������
{
	LinkList *p=l->next;
	while(p!=l)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;//����
}
int ListDelete(LinkList *&l,int i,char &e)//ɾ����i��Ԫ��
{
	LinkList *p=l,*q;
	int j=0;
	if(i==1)
	{
		q=p->next;
		l->next =q->next;
		e=q->data;
		delete q;
	}
	else
	{
		p=l->next;
		while(j<i-2&&p!=l)
		{
			p=p->next;
			j++;
		}//�ҵ�i-1���ڵ�
		if(p==l)//δ�ҵ���i-1���ڵ�
			return 0;
		q=p->next;
		e=q->data;
		p->next=q->next;
		delete q;
	}
	return 1;
}
int LocateElem(LinkList *l,char e)//����Ԫ��ֵΪe
{
	LinkList *p=l->next;
	int i=1;
	while(p!=l&&p->data !=e)
	{
		i++;
		p=p->next ;
	}
	if(p==l)//Ӧ���ж�eֵ�Ƿ�Ϸ�
		return 0;//δ�ҵ�����0
	return i;
}
int GetElem(LinkList *l,int i,char &e)//��õ�i��Ԫ�ص�ֵ
{
	LinkList *p=l->next;
	int j=1;
	while(j<i&&p!=l)
	{
		j++;
		p=p->next ;
	}
	if(p==l)//Ӧ�ÿ���i�Ƿ�Ϸ�
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
	GetElem(l,2,e);
	cout<<"���е�2��Ԫ����:"<<e<<endl;
	GetElem(l,1,e);
	cout<<"���е�1��Ԫ����:"<<e<<endl;
	GetElem(l,4,e);
	cout<<"���е�4��Ԫ����:"<<e<<endl;
	GetElem(l,5,e);
	cout<<"���е�5��Ԫ����:"<<e<<endl;
	cout<<"Ԫ��a��λ���ǣ�"<<LocateElem(l,'a')<<endl;
	ListInsert(l,4,'f');
	cout<<"�ڵ��ĸ�λ���ϲ���f"<<endl<<"˳�����:";
	DispList(l);
	ListDelete(l,3,e);
	cout<<"ɾ��������Ԫ��"<<endl<<"˳�����:";
	DispList(l);
	cout<<"�ͷ�˳���"<<endl;
    DestroyList(l);
    cout<<"������Ϊ:"<<(ListEmpty(l)?"��":"�ǿ�")<<endl;
	return 0;
}