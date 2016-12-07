#include<iostream>
using namespace std;
const int time_slice =2;	//ʱ��Ƭ 
#define Max_Process 200		//�������� 
#define Max_Priority 20		//����������ȼ� 
int Need_Time=0;	//��¼���н����������ʱ��	
int Current_Time=0;	//��¼ϵͳʱ�� 
typedef struct PCB	//���̿��ƿ�PCB
{
	int Id;			//���̱�ʶId 
	int priority;	//���ȼ� 
	int arriveTime;	//����ʱ�� 
	int needTime;	//��Ҫ����ʱ�� 
	int runTime;	//����CPUʱ�� 
	char state;		//����״̬(W����Wait��R����Run,B��������Block��F���Finish) 
	int startBlock;	//��������ʱ�䣬ʱ�� 
	int blockTime;	//���̱�������ʱ�䣬ʱ����
	int finishTime;	//�������ʱ��ʱ�� 
}PCB;
typedef struct Node
{
	struct Node *next;		//�ڵ�ָ��
	PCB pcb;				//������Ϣ�ڵ�
}Queue;
PCB array[Max_Process];	//������ֵ 
PCB RunningPCB;			//the process is running
Queue *BlockQueue;		//�������̶���
Queue *FinishQueue;		//��ɽ��̶���
Queue *WaitQueue;		//�������� 
Queue *InputQueue;		//���뻺����� 
/*����������ʾ����,������ʾ��ǰ������Ϣ*/ 
void InitDisp()
{
	cout<<"Id\t���ȼ�\t����\tʱ��\t����ʱ��\t״̬\t����ʱ��\t����ʱ��"<<endl;
}
void DispPCB(PCB pcb)
{
	cout<<pcb.Id<<"\t";
	cout<<pcb.priority<<"\t";
	cout<<pcb.arriveTime<<"\t";
	cout<<pcb.needTime<<"\t";
	cout<<pcb.runTime<<"\t\t";
	cout<<pcb.state<<"\t";
	cout<<pcb.startBlock<<"\t\t";
	cout<<pcb.blockTime<<endl;
	cout<<endl;
}
/*Init the Queue*/ 
void InitQueue(Queue* &queue)
{
	queue=new Queue();
	queue->next=NULL;
}
/*
ArriveQueue���̽��Ӳ���������β�巨�������Ľ��̿϶���ǰ�� 
FinishQueue���̽��Ӳ���������β�巨������ɵĽ��̿϶���ǰ��
*/
void InQueue(Queue* &queue,PCB pcb)//insert the Queue by arrvite
{
	Queue *q=new Queue();
	q->pcb=pcb;
	Queue *p=queue;
	while(p->next!=NULL)//p ->the queue's rear
	{
		p=p->next;
	}
	//insert the node as rear
	q->next=p->next;//or NULL
	p->next=q;
}
/*���̽��Ӳ����������ȼ�����*/
void InQueueByPriority(Queue* &queue,PCB pcb)
{
	Queue *p=queue;
	Queue *q;
	q=new Queue();
	q->pcb=pcb;
	if(p->next==NULL)//is first node
	{
		q->next=queue->next;
		queue->next=q;
		return ;
	}
	//big to small
	while(p->next!=NULL&&p->next->pcb.priority>=pcb.priority)
	{
		p=p->next;
	}
	//insert node behind p
	q->next=p->next;
	p->next=q;
}
/*���̽��Ӳ�����������ʱ������*/
void InQueueByArriveTime(Queue* &queue,PCB pcb)//insert the Queue by arrvite
{
	Queue *p=queue;
	Queue *q;
	q=new Queue();
	q->pcb=pcb;
	if(p->next==NULL)//is first node
	{
		q->next=queue->next;//or is NULL
		queue->next=q;
		return ;
	}
	//small to big
	while(p->next!=NULL&&p->next->pcb.arriveTime<=pcb.arriveTime)
	{
		p=p->next;
	}
	//insert node behind p
	q->next=p->next;
	p->next=q;
}
/*As the BlockQueue,InQueue by the time when the process finish Block*/
void InQueueByBlockTime(Queue* &queue,PCB pcb)
{
	Queue *p=queue;
	Queue *q;
	q=new Queue();
	q->pcb=pcb;
	if(p->next==NULL)//is first node
	{
		q->next=NULL;
		queue->next=q;
		return ;
	}
	//small to big
	while(p->next!=NULL&&(p->next->pcb.blockTime+p->next->pcb.startBlock)<=(pcb.blockTime+pcb.startBlock))
	{
		p=p->next;
	}
	//insert node q between pp and p
	q->next=p->next;
	p->next=q;
}
/*���̳��Ӳ��������س��ӵĽ�����Ϣ����ɾ���ڵ㣬�ͷ���Ӧ�ռ�*/
PCB DeQueue(Queue* &queue)
{
	PCB pcb;
	Queue *p=queue->next;	//p-->the first Node
	queue->next=p->next;
	pcb=p->pcb;
	delete p;				//delete the node
	return pcb;
}
/*���̳��Ӳ���*/
void DeQueue(Queue* &queue,PCB &pcb)
{
	Queue *p=queue->next;
	queue->next=p->next;
	pcb=p->pcb;
	delete p;		//delete the node
}
void Destroy(Queue* &queue)
{
	Queue *p=queue->next;
	while(p!=NULL)
	{
		queue->next=p->next;
		delete p;		//delete the node
		p=queue->next;
	}
	delete queue;
}
/*�����ڶ����н��̵���Ϣ*/
void DispQueue(Queue *queue)
{
	Queue *p=queue->next;
	while(p!=NULL)
	{
		DispPCB(p->pcb);
		p=p->next;
	}
}
/*Return the front PCB information*/
PCB GetFront(Queue* queue)
{
	if(queue->next!=NULL)
		return queue->next->pcb;
}
bool IsEmpty(Queue* queue)
{
	return queue->next==NULL;
} 
int GetLength(Queue* queue)
{
	Queue*p=queue;
	int i=0;
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
void ChangeQueue(Queue *&queue)//change the BlockQueue
{
	Queue *p=queue->next;
	while(p!=NULL)			//not NULL
	{
		p->pcb.priority++;	//change the process's priority
		p=p->next;
	}
}
/*�������̿��ƿ麯������ʼ������*/
void Input(int n)
{
	for(int i=0;i<n;i++)
	{
		//input the data
		array[i].Id=i+1;
		cout<<"����Id�ǣ�"<<array[i].Id<<endl;
		cout<<"���������IdΪ"<<array[i].Id<<"����Ϣ��"<<endl;
		cout<<"������������ȼ���";
		cin>>array[i].priority;
		cout<<"��������̵���ʱ�䣺";
		cin>>array[i].arriveTime;
		cout<<"�����������Ҫʱ�䣺";
		cin>>array[i].needTime;
		//count all the process's time
		Need_Time+=array[i].needTime;
		//init the pcb
		array[i].runTime=0;
		array[i].state='W';
		array[i].startBlock=0;
		array[i].blockTime=0; 
		InQueue(InputQueue,array[i]);	//InQueue into the InputQueue
		cout<<endl; 
	}
}
void RunningNotBlock(int n)
{
	PCB pcb;
	bool flag;
	int i;
	Current_Time=0;
	while(GetLength(FinishQueue)!=n)
	{
		flag=true;
		while(!IsEmpty(InputQueue)&&GetFront(InputQueue).arriveTime<=Current_Time)
		{
			InQueueByPriority(WaitQueue,DeQueue(InputQueue));//insert the WaitQueue 
			flag=false;
		}
		if(!IsEmpty(WaitQueue))//DeQueue and get the front node as the RunningPCB
		{
			RunningPCB=DeQueue(WaitQueue);
			RunningPCB.state='R'; 
			flag=false;
			for(i=1;i<=time_slice;i++)//run one time slice
			{
				Current_Time++;//ϵͳʱ������
				//process the InputQueue
				while(!IsEmpty(InputQueue)&&GetFront(InputQueue).arriveTime<=Current_Time)
				{
					InQueueByPriority(WaitQueue,DeQueue(InputQueue));//insert the WaitQueue from InputQueue
				} 
			}
			if(i==time_slice+1)
			{
				ChangeQueue(WaitQueue);
				RunningPCB.runTime+=time_slice;
				RunningPCB.priority--;
				DispPCB(RunningPCB);
				if(RunningPCB.runTime==RunningPCB.needTime)//has finished
				{
					RunningPCB.state='F';
					InQueue(FinishQueue,RunningPCB);
				}
				else
				{
					RunningPCB.state='W';
					InQueueByPriority(WaitQueue,RunningPCB);
				}
				flag=false;
			}
		}
		if(flag)
		{
			Current_Time++;
		}
	}
	delete InputQueue;
	delete WaitQueue;
}
/*��������ִ�к���(��������ʱ�䵽,�þ���״̬�������������*/
void Running(int n)
{
	PCB pcb;
	bool flag;//as the mark 
	int i;
	Current_Time=0;
	while(GetLength(FinishQueue)!=n)
	{
		flag=true;
		while(!IsEmpty(InputQueue)&&GetFront(InputQueue).arriveTime<=Current_Time)
		{
			//insert the WaitQueue
			InQueueByPriority(WaitQueue,DeQueue(InputQueue)); 
			//change the mark
			flag=false;
		}
		
		//finish the block Time and delete from the BlockQueue and InQueue into WaitQueue
		if(!IsEmpty(BlockQueue)&&(Current_Time>=GetFront(BlockQueue).startBlock+GetFront(BlockQueue).blockTime))
		{
			pcb=DeQueue(BlockQueue);
			pcb.state='W';
			InQueueByPriority(WaitQueue,pcb);
			flag=false;
		}
			
		//DeQueue and get the front process as the RunningPCB
		if(!IsEmpty(WaitQueue))
		{
			RunningPCB=DeQueue(WaitQueue);
			RunningPCB.state='R';
			//run one time_slice
			for(i=1;i<=time_slice;i++)
			{
				//����ʱ���µĽ��̽��룬����������� 
				while(!IsEmpty(InputQueue)&&GetFront(InputQueue).arriveTime<=Current_Time)
				{
					//insert the WaitQueue
					InQueueByPriority(WaitQueue,DeQueue(InputQueue)); 
					//change the mark
				}
				//��������ʱ��
				if(RunningPCB.startBlock==Current_Time)
				{
					RunningPCB.state='B'; 
					RunningPCB.runTime+=i-1;
					//insert into the BlockQueue
					InQueueByBlockTime(BlockQueue,RunningPCB);
					break;
				}
				if(RunningPCB.needTime==RunningPCB.runTime)//has finished
				{
					RunningPCB.state='F';
					InQueue(FinishQueue,RunningPCB);
					break;
				}
				Current_Time++;
			}
			//finish one time_slice
			if(i==time_slice+1)
			{
				//change some information
				ChangeQueue(WaitQueue);
				RunningPCB.runTime+=time_slice;
				RunningPCB.priority--;
				
				//display the PCB's information
				DispPCB(RunningPCB);
				
				//the process has finished
				if(RunningPCB.runTime>=RunningPCB.needTime)
				{
					RunningPCB.state='F';
					RunningPCB.finishTime=Current_Time;
					InQueue(FinishQueue,RunningPCB);
				}
				else//not Finished then insert into WaitQueue
				{
					RunningPCB.state='W';
					InQueueByPriority(WaitQueue,RunningPCB);
				}
				flag=false;
			}
			else//not finish one time_slice
			{
				DispPCB(RunningPCB);
				flag=false;
			}
		}
		if(flag)
		{
			Current_Time++;
		}
	}
	delete InputQueue;
	delete WaitQueue;
	delete BlockQueue;
}
//Test The code is right or wrong
//Test InQueueByPriority(queue,data);
void TestPriority()//is right
{
 	PCB p1={1,3,0,2,0,0,0,0,0},
		p2={2,3,1,4,0,0,0,0,0},
		p3={3,4,1,5,0,0,0,0,0};
	Queue *queue;
	InitQueue(queue);
	InQueueByPriority(queue,p1);
	InQueueByPriority(queue,p2);
	InQueueByPriority(queue,p3);
	InitDisp();
	DispQueue(queue);
	Destroy(queue);
	system("pause");
}
//Test InQueueByArriveTime(queue,data);
void TestArriveTime()//is right
{
 	PCB p1={1,3,0,2,0,0,0,0,0},
		p2={2,3,2,4,0,0,0,0,0},
		p3={3,4,1,5,0,0,0,0,0};
	Queue *queue;
	InitQueue(queue);
	InQueueByArriveTime(queue,p1);
	InQueueByArriveTime(queue,p2);
	InQueueByArriveTime(queue,p3);
	InitDisp();
	DispQueue(queue);
	Destroy(queue);
	system("pause");
}
//Test InQueueByBlockTime(queue,data);
void TestBlockTime()//is right
{
 	PCB p1={1,3,0,2,0,0,1,3,0},
		p2={2,3,2,5,0,0,1,2,0},
		p3={3,4,1,4,0,0,2,2,0};
	Queue *queue;
	InitQueue(queue);
	InQueueByBlockTime(queue,p1);
	InQueueByBlockTime(queue,p2);
	InQueueByBlockTime(queue,p3);
	InitDisp();
	DispQueue(queue);
	Destroy(queue);
	system("pause");
}
//Test GetLength(queue),IsEmpty(queue) 
void TestLength()//is right
{
	PCB p1={1,3,0,2,0,0,1,3,0},
		p2={2,3,2,5,0,0,1,2,0},
		p3={3,4,1,4,0,0,2,2,0};
	Queue *queue;
	InitQueue(queue);
	
	//Test IsEmpty(queue)
	cout<<"����"<<(IsEmpty(queue)?"Ϊ��":"����")<<endl;
	InQueueByBlockTime(queue,p1);
	InQueueByBlockTime(queue,p2);
	InQueueByBlockTime(queue,p3);
	InitDisp();
	DispQueue(queue);
	
	//Test IsEmpty(queue)
	cout<<"����"<<(IsEmpty(queue)?"Ϊ��":"����")<<endl;
	
	//Test GetLength(queue)
	cout<<"The Length is :"<<GetLength(queue)<<endl;
	Destroy(queue);
	system("pause");
}
//Not to block
void TestMainNotBlock()//is right
{
	int n;
	cout<<"�������������";
	while(cin>>n)
	{
		InitQueue(WaitQueue);
		InitQueue(FinishQueue);
		InitQueue(InputQueue);
		Input(n);//input the process data
		//display the InputQueue
		InitDisp();
		DispQueue(InputQueue);
		
		
		//start to run the process
		InitDisp();
		RunningNotBlock(n);
		cout<<Current_Time<<endl;
		//display FinishQueue's Information
		InitDisp();
		DispQueue(FinishQueue);
		
		//test Destroy(queue)
		Destroy(FinishQueue); 
		
		system("pause");
		system("cls");
		cout<<"�������������";
	}
} 
void TestMain()//has block time
{
	InitQueue(BlockQueue);
	InitQueue(WaitQueue);
	InitQueue(FinishQueue);
	InitQueue(InputQueue);
	
	//Test data
	PCB p1={1,2,0,2,0,0,0,2,0},
		p2={2,4,2,4,0,0,2,2,0},
		p3={3,4,4,4,0,0,4,2,0};
	InQueueByArriveTime(InputQueue,p1);
	InQueueByArriveTime(InputQueue,p2);
	InQueueByArriveTime(InputQueue,p3);
	
	//display the InputQueue
	InitDisp();
	DispQueue(InputQueue);
		
	//start to run the process
	InitDisp();
	Running(3);
	cout<<"Current_Time is : "<<Current_Time<<endl;
	//display FinishQueue's Information
	InitDisp();
	DispQueue(FinishQueue);
		
	//test Destroy(queue)
	Destroy(FinishQueue); 
} 
int main()
{
	TestMain();
	return 0;
}
/*
Priority ArriveTime NeedTime
4
4 
0 
4
5
1 
2
4 
2 
4
3 
3 
6
*/
