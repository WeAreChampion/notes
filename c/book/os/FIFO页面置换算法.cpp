#include<iostream>
using namespace std;
typedef int ElemType;
#define Max_Queue_Size 100
typedef struct Queue
{
	int point;
	int arraySize;
	int length;
	ElemType data[Max_Queue_Size];
}Queue;
void InitQueue(Queue *&queue,int size)
{
	queue=new Queue();
	queue->point=0;
	queue->arraySize=size;
	queue->length=0;
	for(int i=0;i<queue->arraySize;i++)
	{
		queue->data[i]=-1;
	}
}
int FindPageId(Queue *queue,int pageId)
{
	int pos=-1;
	for(int i=0;i<queue->length;i++)
	{
		if(queue->data[i]==pageId)
		{
			pos=i;
			break;
		}
	}
	return pos;
}
void DispQueue(Queue *queue)
{
	cout<<"Queue 's elem is :";
	for(int i=0;i<queue->length;i++)
	{
		if(queue->data[i]!=-1)
		{
			cout<<queue->data[i]<<" ";
		}
	}
	cout<<endl;
}
int InQueue(Queue *&queue,ElemType elem[],int elemSize)
{
	int count=0;
	for(int i=0;i<elemSize;i++)
	{
		if(queue->length!=queue->arraySize)//Not Full,In Queue 
		{
			if(FindPageId(queue,elem[i])==-1)//Not Find and InQueue
			{
				queue->data[queue->length]=elem[i];
				queue->length++;
				DispQueue(queue);
				count++;
			}
			continue;
		}
		//is Full,Swap the page
		if(FindPageId(queue,elem[i])==-1)//Need to Swap the Page
		{
			queue->data[queue->point]=elem[i];
			queue->point=(queue->point+1)%queue->arraySize;
			count++;
			DispQueue(queue); 	
		}
	}
	return count;
}
void TestFIFO()
{
	int a[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}; 
	int length=20;
	Queue *queue;
	InitQueue(queue,3);
	int count=InQueue(queue,a,length);
	cout<<"缺页次数是："<<count<<endl;
	cout<<"缺页率是："<<(count*1.0/length)<<endl;
	delete queue;
}
int main()
{
	TestFIFO();	
}