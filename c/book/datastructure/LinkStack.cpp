#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct Stack
{
	struct Stack *next;
	ElemType data;
}Stack;
void Destroy(Stack *&stack)
{
	Stack *p=stack->next ;
	while(p!=NULL)
	{
		stack->next=p->next ;
		delete p;
		p=stack->next;
	}
	delete stack;
}
void DispStack(Stack *stack)
{
	cout<<"��ջ����ջ�׵�Ԫ���ǣ�";
	Stack *p=stack->next ;
	while(p!=NULL)
	{
		cout<<p->data <<" ";
		p=p->next ;
	}
	cout<<endl;
}
bool IsEmpty(Stack *stack)
{
	return stack->next ==NULL;
}
void InitStack(Stack *&stack)
{
	stack=new Stack();
	stack->next =NULL;
}
int GetLength(Stack *stack)
{
	Stack *p=stack->next;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
void Pop(Stack *&stack,ElemType &data)
{
	Stack *p=stack->next ;
	data=p->data ;
	stack->next =p->next ;
	delete p;
}
ElemType Pop(Stack *&stack)
{
	ElemType data;
	Stack *p=stack->next ;
	data=p->data ;
	stack->next =p->next ;
	delete p;
	return data;
}
void Push(Stack *&stack,ElemType data)//push the data into the Stack
{
	Stack *p=new Stack();
	p->data=data;
	p->next =stack->next ;
	stack->next =p;
}
void TestStack()
{
	Stack *stack;
	InitStack(stack);
	//Test InitQueue(queue)
	InitStack(stack);

	//Test IsEmpty(queue)
	cout<<"��ջ"<<(IsEmpty(stack)?"Ϊ��":"��Ϊ��")<<endl;

	//Test InQueue(queue,data)
	Push(stack,'a');
	Push(stack,'b');
	Push(stack,'c');

	//Test DispQueue(queue)
	DispStack(stack);

	//Test DeQueue(queue)
	cout<<"��ջԪ���ǣ�"<<Pop(stack)<<endl;

	DispStack(stack);
	//add 'd' into the Queue
	Push(stack,'d');

	DispStack(stack);

	//Test GetLength(queue)
	cout<<"��ջ�ĳ����ǣ�"<<GetLength(stack)<<endl;

	//Test Destroy(queue)
	Destroy(stack);

	system("pause");
}
int main()
{
	TestStack();
	return 0;
}