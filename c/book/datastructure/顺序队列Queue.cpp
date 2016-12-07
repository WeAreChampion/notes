#include<iostream>//�Լ�д��
using namespace std;
#define MaxSize 100
/*��ͷɾ������β���룬front�����ͷָ�룬
rear�����βָ�롣���а���ɾ������������
����������������ж��Ƿ�Ϊ�յĲ�������ʼ
������������г��ȵĲ���*/
typedef struct
{
	char data[MaxSize];
	int front,rear;
}SqQueue;
/*
void InitQueue(SqQueue *&q)//��ʼ������
{
	q=(SqQueue *)new SqQueue;
	q->rear=q->front=-1;
}
*/
void InitQueue(SqQueue *&q)//��ʼ������
{
	q=(SqQueue *)new SqQueue;
	q->rear=q->front=0;
}
void ClearQueue(SqQueue *&q)//�������
{
	delete q;
}
/*
int QueueEmpty(SqQueue *q)//ȷ�������Ƿ�Ϊ��
{
	return q->rear==q->front ;
}
*/
int QueueEmpty(SqQueue *q)//ȷ�������Ƿ�Ϊ��
{
	return q->rear==q->front ;
}
/*
int QueueLength(SqQueue *q)//����еĳ���
{
	return (q->rear-q->front);//q->front=-1
}
*/
int QueueLength(SqQueue *q)//����еĳ���
{
	return (q->rear-q->front);//q->front=-1
}
/*
void enQueue(SqQueue *q,char e)//���
{
	//q->rear++;
	//q->data[q->rear]=e;
	q->data[++q->rear]=e;
}
*/
int enQueue(SqQueue *q,char e)//���
{
	if((q->rear +1)%MaxSize==q->front)
		return 0;
	q->data[q->rear]=e;
	q->rear++;
	return 1;
}
/*
void deQueue(SqQueue *q,char &e)//����
{
	//q->front++;
	//e=q->data[q->front];
	e=q->data[++q->front];
}
*/
int deQueue(SqQueue *q,char &e)//����
{
	if(q->rear ==q->front )//����
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
	cout<<"���г�����:"<<QueueLength(q)<<endl;
	while(!QueueEmpty(q))
	{
		deQueue(q,e);
		cout<<e<<" ";
	}
	cout<<endl;
	ClearQueue(q);
	return 0;
}
