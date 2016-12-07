/*
设A=a1^x1*a2^x2*... an^xn,则A的欧拉函数为:
phi(A)= a1^（x1-1)*(a1-1)*a2^(x2-1)*(a2-1)*... an^(xn-1)*(an-1)
即 phi(A)= A*(a1-1)*(a2-1)*...*(an-1)/(a1*a2*...*an)
*/ 
#include<iostream>
#include<cmath>
typedef __int64 inta;
using namespace std;
inta phi(inta a)//求a欧拉函数的值 
{
	inta temp=a;
	for(int i=2;i<=(int)sqrt((double)a);i++)//寻找A的质因子 
		if(a%i==0)
		{
			while(!(a%i))
				a=a/i;
			temp=temp/i*(i-1);	
		}
	if(a!=1)
		temp=temp/a*(a-1);
	return temp;
	
}
int main()
{
	inta a;
	while(scanf("%I64d",&a)!=EOF)
	{
		printf("%I64d\n",phi(a));
	}
	return 0;
}