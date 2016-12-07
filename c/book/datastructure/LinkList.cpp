#include<iostream>
using namespace std; 
typedef char Type;
typedef struct Node
{
	struct Node *next;
	Type data;
}LinkList; 
void DeLinkList(LinkList *&L,Type &data)//delete the Front Node
{
	LinkList *p=L->next;
	data=p->data;
	L->next=p->next;
	delete p;
}
Type DeLinkList(LinkList *&L)//delete the Front Node and return data
{
	Type data1;
	LinkList *p=L->next;
	data1=p->data;
	L->next=p->next;
	delete p;
	return data1;
}
void Destroy(LinkList *&L)//destroy the LinkList
{
	LinkList *p;
	while(p!=NULL)
	{
		p=L->next;
		L->next=p->next;
		delete p;
	}
	delete L;
}
void DispLinkList(LinkList *L)//output the data 
{
	cout<<"链表元素有："<<endl;
	LinkList *p=L->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
//find elem and return the position
//not find return -1
int FindElem(LinkList *L,Type data)
{
	LinkList *p=L->next;
	int i=1;
	while(p!=NULL&&p->data!=data)
	{
		p=p->next;
		i++;
	}
	if(p==NULL)
		return -1;
	return i;
}
void InitLinkList(LinkList *&L)//Init the LinkList
{
	L=new LinkList();
	L->next=NULL;
}
bool Insert(LinkList *&L,int i,Type data)//insert as the i-st node
{
	LinkList *p=L;
	int j=0;
	while(p->next!=NULL&&j<i-1)
	{
		j++;
		p=p->next;
	}
	LinkList *q=new LinkList();
	q->data=data;
	q->next=p->next;
	p->next=q;
}
void InsertAtHead(LinkList *&L,Type data)//insert node as head 
{
	LinkList *q=new LinkList();
	q->data=data;
	q->next=L->next;
	L->next=q;
}
void InsertAtTail(LinkList *&L,Type data)//insert node as tail 
{
	LinkList *p=L;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	LinkList *q=new LinkList();
	q->data=data;
	q->next=NULL;
	p->next=q;
}
bool IsEmpty(LinkList *L)//Judge is empty
{
	return L->next==NULL;
}
int GetLength(LinkList *L)//get the LinkList Length
{
	LinkList*p=L->next;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
Type GetFront(LinkList *L)//get the front node's data
{
	if(!IsEmpty(L))
	{
		return L->next->data;
	}
}
Type GetRear(LinkList *L)//get the rear node's data
{
	LinkList *p=L;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p->data;
}
//not considerate the bound value
Type GetElem(LinkList *L,int i)
{
	int j=0;
	LinkList *p=L;
	while(p->next!=NULL&&j!=i)
	{
		p=p->next;
		j++;
	}
	return p->data;
}
int main()
{
	LinkList *L;
	//Test InitLinkList(L)
	InitLinkList(L);
	//Test IsEmpty(L)
	cout<<"链表"<<(IsEmpty(L)?"为空":"不为空")<<endl;
	//Test InsertXXX(L,data)
	InsertAtHead(L,'b');
	InsertAtTail(L,'c');
	InsertAtHead(L,'a');
	Insert(L,4,'e');
	Insert(L,4,'d');
	//Test DispLinkList(L)
	DispLinkList(L);
	//Test GetLength(L)
	cout<<"链表长度为："<<GetLength(L)<<endl;
	//Test GetFront(L)
	cout<<"第一个元素是："<<GetFront(L)<<endl;
	//Test GetRear(L)
	cout<<"最后一个元素是："<<GetRear(L)<<endl;
	//Test GetElem(L,data)
	cout<<"第4个元素是："<<GetElem(L,4)<<endl;
	//test FindElem(L,data)
	int pos=FindElem(L,'e');
	if(pos!=-1)
		cout<<"元素d的位置在："<<pos<<endl;
	else
		cout<<"Not Find It!"<<endl;
	pos=FindElem(L,'f');
	if(pos!=-1)
		cout<<"元素d的位置在："<<pos<<endl;
	else
		cout<<"Not Find It!"<<endl;
	//Test Destroy(L)
	Destroy(L);
	return 0;
}