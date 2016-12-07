#include<iostream>
using namespace std;
class Base
{
public:	
	int da;
	Base(int d);
	int getDa();
	void setDa(int d);
};
Base::Base(int d){
	da = d;
}
int Base::getDa(){
	return da;
}
void Base::setDa(int d) {
	da = d;
}
template<class T>
class TBase : public Base
{
private:
	T data;
public:
	TBase(int dd, T d) : Base(dd), data(d){}
	void setData(T d);
	T getData();
};
template<class T>
void TBase<T>::setData(T d) {
	data = d;
}
template<class T>
T TBase<T>::getData() {
	return data;
}
int main() {
	Base b(2);
	cout<<b.getDa()<<endl;
	b.setDa(12);
	cout<<b.getDa()<<endl;
	TBase<double> t(2,1.33);
	cout<<t.getData()<<endl;
	return 0;
} 