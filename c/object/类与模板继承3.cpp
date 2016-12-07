#include<iostream>
using namespace std;
template<class Type>
class Base
{
public:	
	Type da;
	Base(Type d);
	int getDa();
	void setDa(Type d);
};
template<class Type>
Base<Type>::Base(Type d)
{
	da=d;
}
template<class Type>
int Base<Type>::getDa()
{
	return da;
}
template<class Type>
void Base<Type>::setDa(Type d)
{
	da=d;
}
template<class Type,class T>
class TBase:public Base<Type>
{
public:
	T data;
	TBase(Type dd,T d):Base<Type>(dd),data(d){}
	void setData(T d);
	T getData();
};
//template<class T>
template<class Type,class T>
void TBase<Type,T>::setData(T d)
{
	data=d;
}
//template<class T>
template<class Type,class T>
T TBase<Type,T>::getData()
{
	return data;
}
int main()
{
	TBase<int,double> t(2,1.33);
	cout<<t.getDa()<<endl<<t.getData()<<endl;
	return 0;
} 