#include<iostream>
using namespace std;
template <class Type>
Type max(Type x, Type y)
{
	return (x > y ? x : y);
}
template <class Type>
Type min(Type x, Type y)
{
	return (x < y ? x : y);
}
template <class Type>
void Swap(Type &x, Type &y)
{
	Type a;
	a = x;
	x = y;
	y = a;
}
template <class Type>
void swap(Type *x, Type *y)
{
	Type a;
	a = *x;
	*x = *y;
	*y = a;
}
int main()
{
	int a = 10, b = 8;
	cout<<"a= "<<a<<" b= "<<b<<endl;
	cout<<"max(a,b) is "<<max(a,b)<<endl;
	cout<<"min(a,b) is "<<min(a,b)<<endl;
	Swap(a, b);
	cout<<"a= "<<a<<" b= "<<b<<endl;
	double aa = 0.09, bb = -1;
	cout<<"aa= "<<aa<<" bb= "<<bb<<endl;
	cout<<"max(aa,bb) is "<<max(aa,bb)<<endl;
	cout<<"min(aa,bb) is "<<min(aa,bb)<<endl;
	swap(&aa, &bb);
	cout<<"aa= "<<aa<<" bb= "<<bb<<endl;
	return 0;
}