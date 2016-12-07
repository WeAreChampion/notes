#include<iostream>
using namespace std;
template<class Type>
Type Max(Type a,Type b)
{
	return (a>b?a:b);
}
template<class Type>
Type Min(Type a,Type b)
{
	return (a<b?a:b);
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<"the max is:"<<Max(a,b)<<endl;
		cout<<"the min is:"<<Min(a,b)<<endl;
	}
	return 0;
}