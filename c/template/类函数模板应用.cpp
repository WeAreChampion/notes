#include<iostream>
using namespace std;
#define MaxSize 100
template <class Type>
class Stack
{
private:
	Type items[MaxSize];
	int top;
public:
	Stack(int);
	void Push(const Type& c);
	Type Pop();
	bool isEmpty() const;
	~Stack(); 
};
template <class Type>
void Stack<Type>::Push(const Type& c) {
	items[top++] = c;
}
template <class Type>
Type Stack<Type>::Pop() {
	return items[--top];
}
template <class Type>
Stack<Type>::~Stack() {
	cout<<"空间已经释放！\n";
}
template <class Type>
Stack<Type>::Stack(int t) {
	top = t;
}
template <class Type>
bool Stack<Type>::isEmpty() const {
	if(top == 0) {
		return true;
	}
	return false;
}
int main() {
	Stack<int> s(0);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	while(!s.isEmpty()) {
		cout<<s.Pop()<<" ";
	} 
	cout<<endl;
	return 0;
}