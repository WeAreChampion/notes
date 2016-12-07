#include<iostream>
#include<malloc.h>
#include<stdlib.h>
# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10
using namespace std;
typedef struct 
{
	char  *base;
	char  *top;
	//char data[STACK_INIT_SIZE];
	int stacksize;
}SqStack; 
void InitStack(SqStack &s)
{
	//s.base=(char *)new (SqStack);
	s.base=(char *) malloc(STACK_INIT_SIZE * sizeof(char));
	if(!s.base)   exit (0);
	s.top=s.base;
	s.stacksize =STACK_INIT_SIZE;
}
void DestroyStack(SqStack &s)
{
	delete(s.base);
}
void ClearStack(SqStack &s)
{
	while(s.top!=s.base)
	{
		delete(s.top);
		s.top--;
	}
}
int StackEmpty(SqStack s)
{
	return(s.top==s.base);
}
int StackLength(SqStack &s)
{
	int i=0;
	while(s.top!=s.base)
	{
		i++;
		s.top--;
	}
	return i;
}
int GetTop(SqStack s,char &e)
{
	if(s.top==s.base)
		return 0;
	e=*(s.top-1);
	return 1;
}
void Push(SqStack &s,char e)
{
	if(s.top-s.base>=s.stacksize)
	{
		//s.base=(char *)new(SqStack);
		s.base=(char *)realloc(s.base,(s.stacksize+STACKINCREMENT) * sizeof(char));
		if(!s.base)  exit(0);
		s.top=s.base+s.stacksize;
		s.stacksize +=STACKINCREMENT;
	}
	*s.top=e;
	s.top++;
}
int Pop(SqStack &s,char &e)
{
	if(s.top==s.base)
		return 0;
	s.top--;
	e=*s.top;
	return 1;
}
void DispStack(SqStack s)
{
	/*char *p=s.base;
	while(s.top!=p )
	{
		printf("%c",*p);
		p++;
		//s.top--;
	}*/
	while(s.top!=s.base)
	{
		s.top--;
		cout<<*s.top;	
	}
	cout<<*s.top<<endl;
}
int main()
{
	SqStack s;
	char e;
	InitStack(s);
	cout<<"栈为"<<(StackEmpty(s)?"空":"非空")<<endl;
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	cout<<"栈为"<<(StackEmpty(s)?"空":"非空")<<endl;
	cout<<"栈长度:"<<StackLength(s)<<endl;
	GetTop(s,e);
	cout<<"栈顶元素是:"<<e<<endl;
	cout<<"从栈顶到栈底的元素是:";
	DispStack(s);
	cout<<"出栈序列:";
	while(!StackEmpty(s))
	{
		Pop(s,e);
		cout<<e;
	}
	cout<<endl<<"栈为"<<(StackEmpty(s)?"空":"非空")<<endl;
	ClearStack(s);
	return 0;
}

