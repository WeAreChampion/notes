#include<iostream>
#include<string>
#include<vector>
using namespace std; 
#define Max_Page_Table_Size 32
#define Max_Quick_Table_Size 16
#define Page_Size 1024
typedef struct PTE//页表项 
{
	int pageId;			//页号 
	int blockId;		//块号
	int P;				//P状态位 
	int visited;		//访问位
	int change;			//修改位 
	int externalAdress;	//外存地址
}PTE;
void DispPTE(PTE pte)//输出页表项信息
{
	cout<<"页表项信息如下："<<endl;
	cout<<"页号："<<pte.pageId<<endl;
	cout<<"块号："<<pte.blockId<<endl;
	cout<<"状态位："<<pte.P<<endl;
	cout<<"访问位："<<pte.visited<<endl;
	cout<<"修改位："<<pte.change<<endl;
	cout<<"外存地址："<<pte.externalAdress<<endl;
	cout<<endl;
}
typedef PTE ElemType;
//Quick Table's data structure
typedef struct QuickTable
{
	ElemType data[Max_Quick_Table_Size];
	int length;		//快表存储长度
	int Quick_Table_Size;//快表大小
}QuickTable;
void InitQucikTable(QuickTable &qtable)
{
	qtable.length=0;
	qtable.Quick_Table_Size=4;
}
bool IsFull(QuickTable qtable)
{
	return qtable.length==qtable.Quick_Table_Size;
}
void AddPTE(QuickTable &qtable,PTE pte)
{
	if(!IsFull(qtable))
		qtable.data[qtable.length++]=pte;
}
int FindPage(QuickTable pt,int pageId)
{
	int position=-1;
	for(int i=0;i<pt.length;i++)
	{
		if(pt.data[i].pageId==pageId)
		{
			position=i;
		}
	}
	return position;
}
void TestQuickTable(QuickTable &qtable)
{
	PTE pte[4]={
		//pageId,blockId,P,visited,change,externalAdress
		3,1,1,0,0,19,
		5,7,1,1,0,17
				};
	for(int i=0;i<4;i++)
		AddPTE(qtable,pte[i]);
}
typedef struct PageTable//页表
{
	ElemType data[Max_Page_Table_Size];//页表寄存器
	int length;		//页表存储长度
	int Page_Table_Size;//页表大小
}PageTable;
void InitPageTable(PageTable &pt)//Init the Page Table
{
	pt.length=0;
	pt.Page_Table_Size=16;
}
bool IsFull(PageTable pt)
{
	return pt.length==pt.Page_Table_Size;
}
void AddPTE(PageTable &pt,PTE pte)//页表未满时，添加页表项进入页表
{
	if(IsFull(pt))
		return ;
	pt.data[pt.length++]=pte;
}
//add some PTE into the PageTable
void TestPageTable(PageTable &pt)
{
	PTE pte[8]={
//pageId,blockId,P,visited,change,externalAdress
		0,2,0,1,0,12,
		1,5,0,0,0,18,
		2,3,0,0,0,25,
		3,1,0,0,0,19,
		4,4,0,1,1,13,
		5,7,0,1,0,17,
		6,10,0,1,0,30,
		7,13,0,0,0,31
				};
	for(int i=0;i<8;i++)
		AddPTE(pt,pte[i]);
}
//the algotithm about LRU to displace
#define Max_Block_Size 8	//运行时最大物理块号
#define Block_Size 5	//运行进程使用的物理块号
typedef int DataType;
typedef struct Node
{
	struct Node *next;
	DataType pageId;
}Stack;
//Init Stack
void InitStack(Stack *&stack)
{
	stack=new Stack();
	stack->next =NULL;
}
//入栈，采用头插法
void Push(Stack *&stack,DataType pageId)
{
	Stack *q=new Stack();
	q->pageId=pageId;
	q->next =stack->next ;
	stack->next =q;
}
int Length(Stack *stack)
{
	Stack *p=stack;
	int i=0;
	while(p->next!=NULL)
	{
		i++;
		p=p->next ;
	}
	return i;
}
//find pageId from Stack return bool and save the point
bool FindPageId(Stack *stack,DataType pageId,Stack *&q)
{
	Stack *p=stack;
	while(p->next!=NULL&&p->next->pageId!=pageId)
	{
		p=p->next;
	}
	if(p->next ==NULL)//has found the pageId
		return false;
	q=p;			//save the Node point
	return true;
}
Stack* GetRearFormNode(Stack *stack)
{
	Stack *q=stack;
	Stack *p=q->next;
	while(q->next!=NULL&&p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	return q;
}
void DispStack(Stack *stack)
{
	cout<<"内存块数据如下："<<endl;
	Stack *p=stack->next ;
	while(p!=NULL)
	{
		cout<<p->pageId<<" ";
		p=p->next ;
	}
	cout<<endl;
}
//LRU 算法
void LRUPush(Stack *&stack,PageTable &ptable,DataType pageId)
{
	Stack *q;//存储在内存快找到pageId的前驱节点指针
	Stack *p;
	bool flag=FindPageId(stack,pageId,q);//find pageId from stack
	if(flag)//has found the pageId and change the stack's top
	{
		//like delete the node
		p=q->next;		//p->q->next
		q->next=p->next;
		//change the node as the first node
		p->next=stack->next;
		stack->next=p;
	}
	else//not Find in the stack
	{
		if(Length(stack)==Block_Size)//内存快已满，选择一个页表项置换出来
		{
			//p指向倒数第二个节点
			q=GetRearFormNode(stack);
			p=q->next;//p->the rear Node should be swap
			ptable.data[p->pageId].P=0;//换出
			q->next=NULL;
			delete p;
			p=new Stack();
			p->pageId=pageId;
			//as the first Node
			p->next=stack->next;
			stack->next=p;			
		}
		else
		{
			Push(stack,pageId);//添加进入内存块
		}
	}
	//change the PageTable
	ptable.data[pageId].P=1;//修改状态位
	DispStack(stack);
	//DispPTE(pte);//输出页表项信息
}
void TestStack()//is right
{
	int a[]={4,7,0,7,1,0,1,2,1,2,6};
	int length=11;
	PageTable ptable;
	InitPageTable(ptable);
	Stack *stack;
	InitStack(stack);
	for(int i=0;i<length;i++)
	{
		LRUPush(stack,ptable,a[i]);//,ptable,pte,
	}
	delete stack;
	system("pause");
}
//the Logical Adress's data structure
typedef struct LogicalAdress	//逻辑地址
{
	int pageId;//页号 
	int pageAdress;//业内地址
}LogicalAdress;
void DispLogicalAdress(LogicalAdress ladress)
{
	cout<<"逻辑地址信息(10进制)："<<endl;
	cout<<"页号："<<ladress.pageId<<endl;
	cout<<"业内地址："<<ladress.pageAdress<<endl;
}
int StringToInt(string s)//0,1串change to 10进制数值
{
	int sum=0;
	int k=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		sum+=(s[i]-'0')*k;
		k=k*2;
	}
	return sum;
}
bool IsLogicalAdress(string s)
{
	if(s.size()!=14)
		return false;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='0'&&s[i]!='1')
			return false;
	}
	return true;
}
//input the adress string and get the Logical Adress 
void getLogicalAdress(LogicalAdress &ladress,string s)
{
	string str="";
	for(int i=0;i<3;i++)
		str+=s[i];
	ladress.pageId=StringToInt(str);
	str="";
	for(int i=3;i<s.size();i++)
		str+=s[i];
	ladress.pageAdress=StringToInt(str);
}
typedef struct RealAdress		//实际地址
{
	int blockId;//块号
	int pageAdress;//业内地址
}RealAdress;
void DispRealAdress(RealAdress radress)
{
	cout<<"逻辑地址信息(10进制)："<<endl;
	cout<<"块号："<<radress.blockId<<endl;
	cout<<"业内地址："<<radress.pageAdress<<endl;
}
//set BlockId
void setBlockId(RealAdress radress,int blockId)
{
	radress.blockId=blockId;
}
//set Page Adress
void setPageAdress(RealAdress radress,int pageAdress)
{
	radress.pageAdress=pageAdress;
}
//get Real Adress from the struct of RealAdress
int getRealAdress(RealAdress radress)
{
	return radress.blockId*Page_Size+radress.pageAdress;
}
//get Real Adress from the blockId and pageAdress
int getRealAdress(int blockId,int pageAdress)
{
	return blockId*Page_Size+pageAdress;
}
//运行代码
void Run(Stack *stack,LogicalAdress ladress,QuickTable qtable,PageTable ptable,RealAdress &radress)
{
	if(ladress.pageId>=ptable.length)
	{
		cout<<"页号越界，中断！"<<endl;
		return;
	}
	//find in Quick Table
	int pos=FindPage(qtable,ladress.pageId);
	if(pos!=-1) //has found the pageId in Quick table
	{
		qtable.data[pos].visited=1;
		DispPTE(qtable.data[pos]);//输出快表中页表项信息 
		setBlockId(radress,qtable.data[pos].blockId);//查表得到块号
		setPageAdress(radress,ladress.pageAdress);//设置业内地址
		DispRealAdress(radress);//输出实地址
		return ;
	}
	//else find in PageTable
	;//get the pageId
	if(ptable.data[ladress.pageId].P)//在内存
	{
		DispPTE(ptable.data[pos]);//输出页面项信息
		setBlockId(radress,ptable.data[pos].blockId);//查表得到块号
		setPageAdress(radress,ladress.pageAdress);//设置业内地址
		DispRealAdress(radress);//输出实地址
		return;
	}
	//Not ine the Memory
	LRUPush(stack,ptable,ladress.pageId);//添加到执行块中，进行LRU页面置换算法
	DispPTE(ptable.data[pos]);//输出页面项信息
	//修改快表
	//Not in the Memory
	setBlockId(radress,ptable.data[pos].blockId);//查表得到块号
	//得到实地址信息 
	setPageAdress(radress,ladress.pageAdress);//设置业内地址
	DispRealAdress(radress);//输出实地址 	
}
void Test()
{
	LogicalAdress ladress;
	RealAdress radress;
	//int a[]={4,7,0,7,1,0,1,2,1,2,6};//输入页面的序列
	int length=11;
	string s1="1000000110010";//4 
	string s2="1110010101010";//7
	string s3="0000100010010";//0
	string s4="1110010101010";//7
	string s5="0010110110010";//1
	string s6="0000100010010";//0
	string s7="0010110110010";//1
	string s8="0100110111101";//2
	string s9="0010110110010";//1
	string s10="0100110111101";//2
	string s11="1101010110011";//6
	vector<string> v;
	v.clear();
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	v.push_back(s6);
	v.push_back(s7);
	v.push_back(s8);
	v.push_back(s9);
	v.push_back(s10);
	v.push_back(s11);
	QuickTable qtable;
	InitQucikTable(qtable);
	TestQuickTable(qtable);
	PageTable ptable;
	InitPageTable(ptable);
	TestPageTable(ptable);
	Stack *stack;
	InitStack(stack);
	int pageId;
	for(int i=0;i<length;i++)
	{
		getLogicalAdress(ladress,v[i]);
		DispLogicalAdress(ladress);
		Run(stack,ladress,qtable,ptable,radress); 
		DispRealAdress(radress); 
	}
	delete stack;
	system("pause");
}
int main()
{
	Test();
	return 0;
}
/*
*/