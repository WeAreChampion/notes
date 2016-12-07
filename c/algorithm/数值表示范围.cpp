#include<iostream>
#include<limits>
using namespace std;
template<class Type>
void showMaxMin()
{
	cout<<"min: "<<numeric_limits<Type>::min()<<endl;
	cout<<"max: "<<numeric_limits<Type>::max()<<endl;
}
int main()
{
	cout<<"short: "<<endl;
	showMaxMin<short>();
	cout<<"int: "<<endl;
	showMaxMin<int>();
	cout<<"long: "<<endl;
	showMaxMin<long>();
	cout<<"float: "<<endl;
	showMaxMin<float>();
	cout<<"double: "<<endl;
	showMaxMin<double>();
	cout<<"long double: "<<endl;
	showMaxMin<long double>();
	cout<<"unsigned short: "<<endl;
	showMaxMin<unsigned short>();
	cout<<"unsigned int: "<<endl;
	showMaxMin<unsigned int>();
	cout<<"unsigned long: "<<endl;
	showMaxMin<unsigned long>();
	return 0;
}