#include<iostream>
#include<cstdlib>
using namespace std;
template<class Type>
class MyType
{
private:
	Type value;
public :
	MyType(Type i);
	Type Max(MyType y);
	Type Add(MyType y);
	~MyType();
};
template<class Type>
MyType<Type>::MyType(Type i)//构造函数
{
	this->value = i ;
}
template<class Type>
MyType<Type>::~MyType ()
{
	cout<<this->value<<"存储空间已释放！\n";
}
template<class Type>
Type MyType<Type>::Max(MyType y)
{
	if((this->value)>y.value )
		return this->value;
	else
		return y.value;
}
template<class Type>
Type MyType<Type>::Add(MyType y)
{
	return this->value+y.value;
}
int main()
{
	int a,b;
	a= rand();
	b= rand();
	MyType<int> A(a),B(b);
	cout<<"a= "<<a<<endl;
	cout<<"b= "<<b<<endl;
	cout<<"max(A,B)="<<A.Max(B)<<endl;
	cout<<"add(A,B)="<<A.Add(B)<<endl;
	MyType<char> C('c'),D('D');
	cout<<"max(C,D)="<<C.Max(D)<<endl;
	return 0;
}