#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	struct Node *next;
	ElemType data;
}Queue;
void InitQueue(Queue *&queue)
{
	queue=new Queue();
	queue->next=NULL;
}
void InQueueAtFront(Queue *&queue,ElemType data)
{
	Queue *p=new Queue();
	p->data=data;
	p->next=queue->next;
	queue->next=p;
}
void InQueueAtRear(Queue *&queue,ElemType data)
{
	Queue *q=new Queue();
	q->data=data;
	Queue *p=queue;
	while(p->next!=NULL)//not the last
	{
		p=p->next;
	}
	q->next=p->next;//or NULL
	p->next=q;
}
void InQueueBigToSmall(Queue *&queue,ElemType data)
{
	Queue *q=new Queue();
	q->data=data;
	Queue *p=queue;
	if(queue->next==NULL)//is the first node
	{
		q->next=NULL;
		queue->next=q;
		return ;
	}
	while(p->next!=NULL&&p->next->data>=data)
	{
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
}
void InQueueSmallToBig(Queue *&queue,ElemType data)//sort small to big
{
	Queue *q=new Queue();
	q->data=data;
	Queue *p=queue;
	if(queue->next==NULL)//is the first node
	{
		q->next=NULL;
		queue->next=q;
		return ;
	}
	while(p->next!=NULL&&p->next->data<=data)
	{
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
}
void Destroy(Queue* &queue)
{
	Queue *p=queue->next;
	while(p!=NULL)
	{
		queue->next=p->next;
		delete p;
		p=queue->next; 
	}
	delete queue;
}
void DeQueueAtFront(Queue *&queue,ElemType data)
{
	Queue *p=queue->next;
	queue->next=p->next;
	data=p->data;
	delete p;
}
ElemType DeQueueAtFront(Queue *&queue)
{
	Queue *p=queue->next;
	queue->next=p->next;
	ElemType data=p->data;
	delete p;
	return data;
}/*
void DeQueueAtRear(Queue *&queue,ElemType data)
{
	Queue *p=queue;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	data=p->data;
	delete p;
}
ElemType DeQueueAtRear(Queue *&queue)
{
	
}*/
void DispQueue(Queue *queue)
{
	cout<<"The elem:  ";
	Queue *p=queue->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int GetLength(Queue *queue)
{
	int i=0;
	Queue *p=queue;
	while(p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	return i;
}
bool IsEmpty(Queue *queue)
{
	return queue->next==NULL; 
}
void Test1()
{
	Queue *queue;
	InitQueue(queue);
	InQueueSmallToBig(queue,3);
	InQueueSmallToBig(queue,1);
	InQueueSmallToBig(queue,2);
	InQueueSmallToBig(queue,5);
	InQueueSmallToBig(queue,4);
	DispQueue(queue);
	cout<<"The length is :"<<GetLength(queue)<<endl;
	Destroy(queue);
}
void Test2()
{
	Queue *queue;
	InitQueue(queue);
	InQueueBigToSmall(queue,3);
	InQueueBigToSmall(queue,1);
	InQueueBigToSmall(queue,2);
	InQueueBigToSmall(queue,5);
	InQueueBigToSmall(queue,4);
	DispQueue(queue);
	cout<<"The length is :"<<GetLength(queue)<<endl;
	Destroy(queue);
}
int main()
{
	Test1();
	Test2();
	return 0;
} 