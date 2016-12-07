#include<iostream>//自己写的
using namespace std;
#define MaxSize 100
/*队头删除，队尾插入，front保存队头指针，
rear保存队尾指针。其中包括删除操作，插入
操作，清除操作，判断是否为空的操作，初始
化操作，求队列长度的操作*/
typedef struct
{
	char data[MaxSize];
	int front,rear;
}SqQueue;
/*
void InitQueue(SqQueue *&q)//初始化队列
{
	q=(SqQueue *)new SqQueue;
	q->rear=q->front=-1;
}
*/
void InitQueue(SqQueue *&q)//初始化队列
{
	q=(SqQueue *)new SqQueue;
	q->rear=q->front=0;
}
void ClearQueue(SqQueue *&q)//清除队列
{
	delete q;
}
/*
int QueueEmpty(SqQueue *q)//确定队列是否为空
{
	return q->rear==q->front ;
}
*/
int QueueEmpty(SqQueue *q)//确定队列是否为空
{
	return q->rear==q->front ;
}
/*
int QueueLength(SqQueue *q)//求队列的长度
{
	return (q->rear-q->front);//q->front=-1
}
*/
int QueueLength(SqQueue *q)//求队列的长度
{
	return (q->rear-q->front);//q->front=-1
}
/*
void enQueue(SqQueue *q,char e)//入队
{
	//q->rear++;
	//q->data[q->rear]=e;
	q->data[++q->rear]=e;
}
*/
int enQueue(SqQueue *q,char e)//入队
{
	if((q->rear +1)%MaxSize==q->front)
		return 0;
	q->data[q->rear]=e;
	q->rear++;
	return 1;
}
/*
void deQueue(SqQueue *q,char &e)//出队
{
	//q->front++;
	//e=q->data[q->front];
	e=q->data[++q->front];
}
*/
int deQueue(SqQueue *q,char &e)//出队
{
	if(q->rear ==q->front )//队满
		return 0;
	e=q->data[q->front++];
	return 0;
}
int main()
{
	char e;
	SqQueue *q;
	InitQueue(q);
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	enQueue(q,'d');
	enQueue(q,'e');
	cout<<"队列长度是:"<<QueueLength(q)<<endl;
	while(!QueueEmpty(q))
	{
		deQueue(q,e);
		cout<<e<<" ";
	}
	cout<<endl;
	ClearQueue(q);
	return 0;
}
