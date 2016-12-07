#include<iostream>
#include<string>
using namespace std;
# define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack* &s)
{
	s = (SqStack*) new(SqStack);
	s->top = -1;
}
int StackLength(SqStack* s)
{
	return (s->top + 1);
}
void ClearStack(SqStack* &s)
{
	delete s;
}
int Push(SqStack * &s, char e)
{
	if(StackLength(s) < MaxSize) {
		s->data[++s->top] = e;
		return 1;
	}
	return 0;
}
int Pop(SqStack* &s, char &e)
{
	if(s->top == -1)//讨论栈是否为空
		return 0;
	e = s->data[s->top--];
	return 1;
}
int StackEmpty(SqStack*s)
{
	return(s->top == -1);
}
void GetTop(SqStack *s, char &e)
{
	if(s->top != -1)//讨论栈是否为空
		e=s->data[s->top];
}
char GetTop(SqStack *s)
{
	return s->data[s->top];
}
void DispStack(SqStack *s)
{
	for(int i=s->top;i>=0;i--)
	{
		cout<<s->data[i];
	}
	cout<<endl;
}
typedef struct 
{
	int data[MaxSize];
	int top;
}Stack;
void Init(Stack *&s)
{
	s=new (Stack);
	s->top=-1;
}
void Push(Stack *&s,int e)
{
	s->data[++s->top]=e;
}
void Pop(Stack *&s,int &e)
{
	e=s->data[s->top--];
}
int GetTop(Stack *s)
{
	if(s->top!=-1)
	{
		return s->data[s->top];
	}
	return -1;
}
int compOperator(char ch,char top)//ch and top
{
	if((ch=='#' && top=='#')||(ch==')' && top=='('))
		return 0;//ch==top
	else if(top=='#'||ch=='('||((ch=='*'||ch=='/')&&(top=='+'||top=='-'||top=='#'))||top=='(')
		return 1;//ch>top
	else 
		return 2;//ch<top
}
int Operate(int a,char theta,int b)
{
	int s;
	switch(theta)
	{
		case '+':s = a + b;break;
	 	case '-':s = a - b;break;
	 	case '*':s = a * b;break;
	 	case '/':s = a / b;break;
	}
	return s;
}
int ConvertToInt(string s)//convert string to int
{
	int sum=0,a=1;
	for(int i=s.length()-1;i>=0;i--)
	{
		sum+=(s[i]-'0')*a;
		a=a*10;
	}
	return sum;
}
int getValue(SqStack *&optr,Stack *&opnd)
{
	Push(optr,'#');//push # into the optr stack
	cout<<"please input the Calculation formula:";
	char ch;
	string str="";
	ch=getchar();
	while(ch!='#' || GetTop(optr)!='#')
	{
		if(ch>='0' && ch<='9')
		{
			str+=ch;
			ch=getchar();
		}
		else
		{
			if(str!="")
				Push(opnd,ConvertToInt(str));
			str="";
			char theta,x;
			int a,b;
			switch(compOperator(ch,GetTop(optr)))
			{
				case 0:Pop(optr,x);ch=getchar();break;
				case 1:Push(optr,ch);ch=getchar();break;
				case 2:Pop(optr,theta);Pop(opnd,b);
				Pop(opnd,a);Push(opnd,Operate(a,theta,b));break;
			}
		}
	}
	return GetTop(opnd);
}
int main()
{
	char e;
	SqStack *s;
	InitStack(s);
	cout<<"栈为:  "<<(StackEmpty(s)?"空":"非空")<<endl;
	cout<<"读入数据a,b,c,d,e"<<endl;
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	cout<<"栈为"<<(StackEmpty(s)?"空":"非空")<<endl;
	cout<<"栈元素个数:"<<StackLength(s)<<endl;
	GetTop(s,e);
	cout<<"栈顶元素是:"<<e<<endl;
	cout<<"栈顶元素是:"<<GetTop(s)<<endl;
	cout<<"从栈顶到栈底元素:";
	DispStack(s);
	cout<<"出栈序列:";
	while(!StackEmpty(s))
	{
		Pop(s,e);
		cout<<e;
	}
	cout<<endl<<"栈为"<<(StackEmpty(s)?"空":"非空")<<endl;
	ClearStack(s);
	Stack *opnd;//operand,操作数 
	Init(opnd);//init the opnd stack
	SqStack *optr;//operator,操作符 
	InitStack(optr);//init the optr stack
	cout<<getValue(optr,opnd)<<endl;
	return 0;
}
/*
3+4#
3+4*5#
3+4*5-10#
4+2*3-10/2#
2+(3+4*2)-8/2*2#
12+(13+4*2)-18/2*3#
/*
//	string str="12345678";
//	cout<<ConvertToV(str)<<endl;
int DispStack(SqStack *s)
{
	if(s->top==-1)
		return 0;
	while(s->top!=-1)
	{
		cout<<s->data[s->top];
		s->top--;
	}
	cout<<endl;
	return 1;
}
*/