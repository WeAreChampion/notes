#include<iostream>
using namespace std;
typedef struct LNode
{
	char data;
	struct LNode *next;
}LinkList;
void InitList(LinkList *&l)//初始化单链表
{
	l=(LinkList *)new (LinkList);
	//l=new (LinkList);//两者都可以
	l->next=l;
}
void DestroyList(LinkList *&l)//清除表，释放节点
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
int ListEmpty(LinkList *l)//判断单链表是否非空
{
	return (l->next==l);
}
int ListLength(LinkList *l)//求单链表长度
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
int ListInsert(LinkList *&l,int i,char e)//插入
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
		p=l->next;//p指向第一个结点
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
void DispList(LinkList *l)//输出单链表
{
	LinkList *p=l->next;
	while(p!=l)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;//换行
}
int ListDelete(LinkList *&l,int i,char &e)//删除第i个元素
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
		}//找第i-1个节点
		if(p==l)//未找到第i-1个节点
			return 0;
		q=p->next;
		e=q->data;
		p->next=q->next;
		delete q;
	}
	return 1;
}
int LocateElem(LinkList *l,char e)//查找元素值为e
{
	LinkList *p=l->next;
	int i=1;
	while(p!=l&&p->data !=e)
	{
		i++;
		p=p->next ;
	}
	if(p==l)//应该判断e值是否合法
		return 0;//未找到返回0
	return i;
}
int GetElem(LinkList *l,int i,char &e)//获得第i个元素的值
{
	LinkList *p=l->next;
	int j=1;
	while(j<i&&p!=l)
	{
		j++;
		p=p->next ;
	}
	if(p==l)//应该考虑i是否合法
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
	GetElem(l,2,e);
	cout<<"表中第2个元素是:"<<e<<endl;
	GetElem(l,1,e);
	cout<<"表中第1个元素是:"<<e<<endl;
	GetElem(l,4,e);
	cout<<"表中第4个元素是:"<<e<<endl;
	GetElem(l,5,e);
	cout<<"表中第5个元素是:"<<e<<endl;
	cout<<"元素a的位置是："<<LocateElem(l,'a')<<endl;
	ListInsert(l,4,'f');
	cout<<"在第四个位置上插入f"<<endl<<"顺序表是:";
	DispList(l);
	ListDelete(l,3,e);
	cout<<"删除第三个元素"<<endl<<"顺序表是:";
	DispList(l);
	cout<<"释放顺序表"<<endl;
    DestroyList(l);
    cout<<"单链表为:"<<(ListEmpty(l)?"空":"非空")<<endl;
	return 0;
}