#include<iostream>
using namespace std;
/*
	To calculate N! and return the value.
	e = 1/1! + 1/2! + 1/3! + ... + 1/N!(N->+¡Þ)
*/ 
int caculateN(int n)
{
	int i, p = 1;
	if(n == 0 || n == 1)
		return 1;
	for(i = 2; i <= n; i++)
		p = p * i;
	return p;
}
int main()
{
	double e;
	int i;
	cout<<"n e"<<endl<<"- -----------"<<endl;
	e = 0;
	for(i = 0;i <= 9; i++)
	{
		e += 1.0 / caculateN(i);
		cout<<i<<" ";
	if(i <= 2)
		cout<<e<<endl;
	else
		printf("%.9lf\n", e);
	}
	return 0;
}
/*
output:
n e
- -----------
0 1
1 2
2 2.5
3 2.666666667
4 2.708333333
*/