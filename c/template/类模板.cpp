#include<iostream>
#include<cstdlib>
using namespace std;
class MyType
{
public :
	int value;
	MyType(int i);
	int compare(MyType y);
};
MyType::MyType(int i)//¹¹Ôìº¯Êý
{
	this->value = i ;
}
int MyType::compare(MyType y)
{
	if(value > y.value)
		return 1;
	else
		return -1;
}
MyType max(MyType x, MyType y)
{
	if(x.compare(y) > 0)
		return x;
	else
		return y;
}
template<class Type>
Type max(Type x, Type y)
{
	return (x > y ? x : y);
}
void Swap(MyType &x, MyType &y)
{
	MyType temp = x;
	x = y;
	y = temp;
}
void sort(MyType *MyArray, int size)
{
	for(int i = 0; i < size; i++){ 
		for(int j = 0; j < size- i -1; j++){ 
			if(max(MyArray[j], MyArray[j + 1]).value == MyArray[j].value){ 
				Swap(MyArray[j], MyArray[j + 1]);
			}
		}
	} 
}
void Disp(MyType *MyArray, int size)
{
	for(int i = 0;i < size; i++)
		cout<<MyArray[i].value<<" ";
	cout<<endl;
}
int main()
{
	int a, b;
	a= rand();
	b= rand();
	MyType A(a), B(b);
	cout<<"a= "<<a<<endl;
	cout<<"b= "<<b<<endl;
	MyType myarray[] = {MyType(82), MyType(34), MyType(26), MyType(77), MyType(68)};
	sort(myarray, 5);
	Disp(myarray, 5);
	return 0;
}