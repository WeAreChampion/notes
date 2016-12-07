#include<iostream>
using namespace std;
template<class Type>
class Stack
{
private:
	Type *elem;
	int top,size;
public:
	void Push(Type e);
	Type getPop();
	Type Pop();
	void InitStack(int size,int top);
	Stack(int size);
	void setSize(int size);
	void getLength();
	int isEmpty();
	~Stack();
};
template<class Type>
Stack<Type>::Stack(int size)
{
	elem=new Type[size];
	top=0;
}
template<class Type>
void Stack<Type>::Push(Type e)
{
	switch(top<=size)
	{
		case 0:	size=size+10;break;
	}
	elem[top++]=e;
}
template<class Type>
Type Stack<Type>::getPop()
{
	return elem[--top];
}
template<class Type>
Type Stack<Type>::Pop()
{
	switch(top==0)
	{
		case 0:	return elem[--top];break;
	}
}
template<class Type>
void Stack<Type>::InitStack(int size,int top)
{
	this->size=size;
	this->top=top;
}
template<class Type>
void Stack<Type>::setSize(int size)
{
	this->size=size;
}
template<class Type>
void Stack<Type>::getLength()
{
	return top;
}
template<class Type>
Stack<Type>::~Stack()
{
	delete []elem;
	cout<<"存储空间已经释放！\n";
}
template<class Type>
int Stack<Type>::isEmpty()
{
	return top==0;
}
int main()
{
	Stack<int> a(10);
	a.Push(1);
	a.Push(2);
	a.Push(3);
	a.Push(4);
	while(!a.isEmpty())
	{
		cout<<a.Pop()<<" ";
	}
	cout<<endl;
	return 0;
}