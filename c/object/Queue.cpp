#include<iostream>
using namespace std;
template<class Type>
class Queue
{
private:
	int front;
	int rear;
	Type *array;
public:
	void Enqueue(Type elem);
	Type Dequeue();	//out the queue
	void InitQueue();
	void Display();
	int FindElem(Type elem);
	Type getElem(int position);
	bool IsEmpty();
	Queue();
	~Queue();
	void OutQueue();
	Type getRearElem();
	Type getFrontElem();
	int getRear();
	int getFront();
};
template<class Type>
void Queue<Type>::Enqueue(Type elem)
{
	rear++;
	array[rear]=elem;
}
template<class Type>
Type Queue<Type>::Dequeue()	//out the queue
{
	front++;
	int elem=array[front];
	return elem;
}
template<class Type>
void Queue<Type>::InitQueue()
{
	front=rear=0;
} 
template<class Type>
void Queue<Type>::Display()
{
	for(int i=front+1;i<=rear;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
template<class Type>
int Queue<Type>::FindElem(Type elem)
{
	for(int i=front+1;i<=rear;i++)
		if(elem==array[i])
			return i;
}
template<class Type>
Type Queue<Type>::getElem(int position)
{
	return array[position];
}
template<class Type>
bool Queue<Type>::IsEmpty()
{
	return front==rear;
}
template<class Type>
Queue<Type>::Queue()
{
	array=new Type();
}
template<class Type>
Queue<Type>::~Queue()
{
	delete array;
	cout<<"存储空间已经释放！\n";
}
template<class Type>
void Queue<Type>::OutQueue()
{
	while(rear>front)
	{
		cout<<array[front]<<" ";
		front++;
	}
	cout<<endl;
}
template<class Type>
Type Queue<Type>::getRearElem()
{
	return array[rear];
}
template<class Type>
Type Queue<Type>::getFrontElem()
{
	return array[front+1];
}
template<class Type>
int Queue<Type>::getRear()
{
	return rear;
}
template<class Type>
int Queue<Type>::getFront()
{
	return front;
}
int main()
{
	Queue<char> Q;
	Q.InitQueue();
	Q.Enqueue('a');
	Q.Enqueue('b');
	Q.Enqueue('c');
	Q.Enqueue('d');
	Q.Enqueue('e');
	Q.Enqueue('f');
	Q.Display();
	cout<<"the front elem is:"<<Q.getFrontElem()<<endl;
	cout<<"the rear elem is :"<<Q.getRearElem()<<endl;
	cout<<"the c position is:"<<Q.FindElem('c')<<endl;
	cout<<"the 4 position is:"<<Q.getElem(4)<<endl;
	cout<<"out the Queue:";
	while(!Q.IsEmpty())
	{
		cout<<Q.Dequeue()<<" ";
	}
	cout<<endl;
	return 0;
} 