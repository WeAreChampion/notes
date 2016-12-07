#include<iostream>
using namespace std;
template <class Type>
Type Max(Type a,Type b)
{
	return (a>b?a:b);
}
template <class Type>
Type Min(Type a,Type b)
{
	return (a<b?a:b);
}
int main()
{
	int a,b;
	cout<<"please input a and b: ";
	while(cin>>a>>b)
	{
		cout<<"the max is: "<<Max(a,b)<<endl;
		cout<<"the min is: "<<Min(a,b)<<endl;
		double c,d;
		cout<<"please input c and d: ";
		cin>>c>>d;
		cout<<"the max is: "<<Max(c,d)<<endl;
		cout<<"the min is: "<<Min(c,d)<<endl;
		cout<<"please input a and b: ";
	}
	return 0;
}