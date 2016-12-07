#include<iostream>
using namespace std;
template<class Type>
Type getMax(Type a, Type b)
{
	return (a > b ? a : b);
}
template<class Type>
Type getMin(Type a, Type b)
{
	return (a < b ? a : b);
}
void TestInt() {
	int n;
	cin>>n;
	int a;
	cin>>a;
	int b, min = a, max = a;
	for(int i = 1; i < n; i++)
	{
		cin>>b;
		min = getMin(b, min);
		max = getMax(b, max);
	}
	cout<<"min = "<<min<<endl;
	cout<<"max = "<<max<<endl;
}
void TestDouble()
{
	int n;
	cin>>n;
	double a;
	cin>>a;
	double b, min = a, max = a;
	for(int i = 1; i < n; i++)
	{
		cin>>b;
		min = getMin(b, min);
		max = getMax(b, max);
	}
	cout<<"min = "<<min<<endl;
	cout<<"max = "<<max<<endl;
}
void TestFloat() {
	int n;
	cin>>n;
	float a;
	cin>>a;
	float b, min = a, max = a;
	for(int i = 1; i < n; i++)
	{
		cin>>b;
		min = getMin(b, min);
		max = getMax(b, max);
	}
	cout<<"min = "<<min<<endl;
	cout<<"max = "<<max<<endl;
}
int main()
{
	//TestInt();
	//TestFloat();
	//TestDouble(); 
	return 0;
}
/*
Int:
5
3 4 1 5 2
Float:
5
1.1 1.2 1.3 1.4 1.5
Double:
1.11,1.12,1.13,1.14,1.3
*/