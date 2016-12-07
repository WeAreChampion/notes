#include<iostream>
using namespace std;
const int time_slice =2;	//时间片 
#define Max_Process 200		//进程数量 
#define Max_Priority 20		//进程最大优先级 
int Need_Time=0;	//记录所有进程完成所需时间	
int Current_Time=0;	//记录系统时刻 
typedef struct PCB	//进程控制块PCB
{
	int Id;			//进程标识Id 
	int priority;	//优先级 
	int arriveTime;	//到达时间 
	int needTime;	//需要运行时间 
	int runTime;	//已用CPU时间 
	char state;		//进程状态(W就绪Wait，R运行Run,B进程阻塞Block，F完成Finish) 
	int startBlock;	//进程阻塞时间，时刻 
	int blockTime;	//进程被阻塞的时间，时间间隔
	int finishTime;	//进程完成时的时刻 
}PCB;
typedef struct Node
{
	struct Node *next;		//节点指针
	PCB pcb;				//进程信息节点
}Queue;
PCB array[Max_Process];	//进程数值 
PCB RunningPCB;			//the process is running
Queue *BlockQueue;		//阻塞进程队列
Queue *FinishQueue;		//完成进程队列
Queue *WaitQueue;		//就绪队列 
Queue *InputQueue;		//输入缓冲队列 
/*建立进程显示函数,用于显示当前进程信息*/ 
void InitDisp()
{
	cout<<"Id\t优先级\t到达\t时长\t运行时间\t状态\t阻塞时刻\t阻塞时间"<<endl;
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
ArriveQueue进程进队操作，采用尾插法，先来的进程肯定在前面 
FinishQueue进程进队操作，采用尾插法，先完成的进程肯定在前面
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
/*进程进队操作，按优先级排序*/
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
/*进程进队操作，按进入时间排序*/
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
/*进程出队操作，返回出队的进程信息，并删除节点，释放相应空间*/
PCB DeQueue(Queue* &queue)
{
	PCB pcb;
	Queue *p=queue->next;	//p-->the first Node
	queue->next=p->next;
	pcb=p->pcb;
	delete p;				//delete the node
	return pcb;
}
/*进程出队操作*/
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
/*访问在队列中进程的信息*/
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
/*建立进程控制块函数，初始化数据*/
void Input(int n)
{
	for(int i=0;i<n;i++)
	{
		//input the data
		array[i].Id=i+1;
		cout<<"进程Id是："<<array[i].Id<<endl;
		cout<<"请输入进程Id为"<<array[i].Id<<"的信息！"<<endl;
		cout<<"请输入进程优先级：";
		cin>>array[i].priority;
		cout<<"请输入进程到达时间：";
		cin>>array[i].arriveTime;
		cout<<"请输入进程需要时间：";
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
				Current_Time++;//系统时间增加
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
/*建立进程执行函数(进程运行时间到,置就绪状态，考虑阻塞情况*/
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
				//运行时有新的进程进入，插入就绪队列 
				while(!IsEmpty(InputQueue)&&GetFront(InputQueue).arriveTime<=Current_Time)
				{
					//insert the WaitQueue
					InQueueByPriority(WaitQueue,DeQueue(InputQueue)); 
					//change the mark
				}
				//到达阻塞时间
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
	cout<<"队列"<<(IsEmpty(queue)?"为空":"不空")<<endl;
	InQueueByBlockTime(queue,p1);
	InQueueByBlockTime(queue,p2);
	InQueueByBlockTime(queue,p3);
	InitDisp();
	DispQueue(queue);
	
	//Test IsEmpty(queue)
	cout<<"队列"<<(IsEmpty(queue)?"为空":"不空")<<endl;
	
	//Test GetLength(queue)
	cout<<"The Length is :"<<GetLength(queue)<<endl;
	Destroy(queue);
	system("pause");
}
//Not to block
void TestMainNotBlock()//is right
{
	int n;
	cout<<"请输入进程数：";
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
		cout<<"请输入进程数：";
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
