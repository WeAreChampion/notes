//单链表
#include<iostream>
using namespace std;
typedef struct LNode
{
	char data;
	struct LNode *next;
}LinkList;
void InitList(LinkList *&l)//初始化单链表
{
//	l=(LinkList *)new (LinkList);//两者都可以
//	l=(LinkList *)malloc(sizeof(LinkList));
	l=new (LinkList);
	l->next=NULL;
}
void DestroyList(LinkList *&l)//清除表，释放节点
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
	LinkList *p=l,*q=p->next;//这是书上的，书上错误，把头结点释放了！
	while(p!=NULL)
	{
		delete p;
		p=q;
		p=p->next ;
	}
	delete p;
	//*/
}
int ListEmpty(LinkList *l)//判断单链表是否非空
{
	return (l->next==NULL);
}
int ListLength(LinkList *l)//求单链表长度
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
int ListInsert(LinkList *&l,int i,char e)//插入
{
	LinkList *p=l,*q,*s;
	int j=0;
	s=(LinkList *) new (LinkList);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)//应判断插入位置i是否合法
		return 0;
	q=p->next ;
	s->data =e;
	s->next=p->next ;
	p->next =s;
	return 1;
}
void DispList(LinkList *l)//输出单链表
{
	LinkList *p=l->next;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;//应该换行
}
int ListDelete(LinkList *&l,int i,char &e)//删除第i个元素
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
	if(q==NULL)//应该判断i值是否合法
		return 0;
	p->next=q->next;
	delete q;
	return 1;
}
int LocateElem(LinkList *l,char e)//查找元素值为e
{
	LinkList *p=l;
	int i=0;
	while(p!=NULL&&p->data !=e)
	{
		i++;
		p=p->next ;
	}
	if(p==NULL)//应该判断e值是否合法
		return 0;//未找到返回0
	return i;
}
int GetElem(LinkList *l,int i,char &e)//获得第i个元素的值
{
	LinkList *p=l;
	int j=0;
	while(j<i&&p!=NULL)
	{
		j++;
		p=p->next ;
	}
	if(p==NULL)//应该考虑i是否合法
		return 0;
	e=p->data;
	return 1;
}
int main()
{
	LinkList *l;
	char e;
	InitList(l);
	cout<<"单链表为:"<<(ListEmpty(l)?"空":"非空")<<endl;
	ListInsert(l,1,'a');
	ListInsert(l,2,'b');
	ListInsert(l,3,'c');
	ListInsert(l,4,'d');
	ListInsert(l,5,'e');
	cout<<"单链表为:"<<(ListEmpty(l)?"空":"非空")<<endl;
	cout<<"顺序表为:";
	DispList(l);
	cout<<"表长:"<<ListLength(l)<<endl;
	GetElem(l,3,e);
	cout<<"表中第3个元素是:"<<e<<endl;
	cout<<"元素a的位置是："<<LocateElem(l,'a')<<endl;
	ListInsert(l,4,'f');
	cout<<"在第四个元素位置上插入f"<<endl<<"顺序表是:";
	DispList(l);
	ListDelete(l,3,e);
	cout<<"删除第三个元素"<<endl<<"顺序表是:";
	DispList(l);
	cout<<"释放顺序表"<<endl;
    DestroyList(l);
	cout<<"单链表为:"<<(ListEmpty(l)?"空":"非空")<<endl;
	return 0;
}