#include<iostream>
using namespace std;
typedef char Type;
typedef struct Node
{
	struct Node *next;
	Type data;
}Node;
typedef struct Queue
{
	Node *front;
	Node *rear;
}Queue;
//delete the queue's front and change the front
void DeQueue(Queue *&queue,Type &data)
{
	Node *p=queue->front;
	data=queue->front->data;
	queue->front=p->next;
	delete p;
}
//delete the queue's front, change the front and return data
Type DeQueue(Queue *&queue)
{
	Type data1;
	Node *p=queue->front;
	data1=queue->front->data;
	queue->front=p->next;
	delete p;
	return data1;
}
//destroy the Queue and release the room
void Destroy(Queue *&queue)
{
	Node *p;
	while(queue->front!=queue->rear)
	{
		p=queue->front;
		queue->front=p->next;
		delete p;
	}
	delete queue;
}
//dispplay the Queue's elem 
void DispQueue(Queue *&queue)
{
	cout<<"The Elem is: "<<endl;
	Node *p=queue->front;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;//point get the next
	}
	cout<<endl;
}
//Init the Queue
void InitQueue(Queue *&queue)
{
	queue=new Queue();
	queue->front=queue->rear=NULL;
}
//insert the node as queue's rear
void InQueue(Queue *&queue,Type data)
{
	Node *q=new Node();
	q->data=data;
	q->next=NULL;
	if(queue->front==NULL)//is the first Node
	{
		queue->front=q;
		queue->rear=q;
	}
	else
	{
		queue->rear->next=q;
		queue->rear=q;//change the rear
	}
}
bool IsEmpty(Queue *queue)
{
	return queue->front==NULL;
}
int GetLength(Queue *queue)
{
	Node *p=queue->front;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
Type GetFront(Queue *queue)
{
	if(!IsEmpty(queue))
		return queue->front->data;
}
Type GetRear(Queue *queue)
{
	if(IsEmpty(queue))
		return queue->rear->data;
}
//Link queue2 to the queue1's rear and return the former queue's rear
Node* LinkQueue(Queue *&queue1,Queue *queue2)
{
	//save the rear to return
	Node *p=queue1->rear;
	queue1->rear->next=queue2->front;//link the Queue
	queue1->rear=queue2->rear;//change the Queue's rear
	return p;
}
//Divide the queue to queue1 and queue2
void DivideQueue(Queue *&queue1,Queue *&queue2,Node *p)
{
	queue2->front=p->next;
	queue2->rear=queue1->rear;
	queue1->rear=p;//change the queue1's rear
	queue1->rear->next=NULL;
}
void Test()
{
	Queue *queue;

	//Test InitQueue(queue)
	InitQueue(queue);

	//Test IsEmpty(queue)
	cout<<"链队列"<<(IsEmpty(queue)?"为空":"不为空")<<endl;

	//Test InQueue(queue,data)
	InQueue(queue,'a');
	InQueue(queue,'b');
	InQueue(queue,'c');

	//Test DispQueue(queue)
	DispQueue(queue);

	//Test DeQueue(queue)
	cout<<"出队元素是："<<DeQueue(queue)<<endl;

	DispQueue(queue);
	//add 'd' into the Queue
	InQueue(queue,'d');

	DispQueue(queue);

	//Test GetLength(queue)
	cout<<"链队列的长度是："<<GetLength(queue)<<endl;
	
	DispQueue(queue);

	//Test Destroy(queue)
	Destroy(queue);

	system("pause");
} 
void TestLinkAndDivide()
{
	Queue *queue1,*queue2;
	
	//about the queue1
	InitQueue(queue1);
	InQueue(queue1,'a');
	InQueue(queue1,'b');
	InQueue(queue1,'c');
	DispQueue(queue1);
	
	//about the queue2
	InitQueue(queue2);
	InQueue(queue2,'d');
	InQueue(queue2,'e');
	InQueue(queue2,'f');
	DispQueue(queue2);
	
	//Test LinkQueue(queue1,queue2);
	Node *p=LinkQueue(queue1,queue2);
	DispQueue(queue1);
	
	//Test DivideQueue(queue1,queue2,p)
	DivideQueue(queue1,queue2,p);
	
	//display the Information
	DispQueue(queue1);
	DispQueue(queue2);
	
	//destroy the Queue
	Destroy(queue1);
	Destroy(queue2);
}
int main()
{
	TestLinkAndDivide();
	return 0;
}