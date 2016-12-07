#include<iostream>
using namespace std;
template<class T>
class TBase
{
public:
	T data;
	void setData(T d);
	T getData();
};
template<class T>
void TBase<T>::setData(T d)
{
	data = d;
}
template<class T>
T TBase<T>::getData()
{
	return data;
}
//已整数形式继承TBase
//即子类函数中data成员形式是整型 
class Derived : public TBase<int> 
{
public:
	Derived();
	Derived(int d);
};
Derived::Derived()
{
	data = 0;
}
Derived::Derived(int d)
{
	data = d;
}
int main()
{
	TBase<double> t;
	t.setData(1.01);
	cout<<t.getData()<<endl;
	Derived d;
	d.setData(2);
	cout<<d.getData()<<endl;
	Derived dd;
	cout<<dd.getData()<<endl;
	dd.setData(3);
	cout<<dd.getData()<<endl;
	return 0;
}