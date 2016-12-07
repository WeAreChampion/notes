#include<iostream>
using namespace std;
int main()
{
	__int64 i;
	for(i=1;i<=9;i=i+2)
	{
		printf("%I64d\n",i);
	}
	i=i+11;
	///*
	while(i<=1000000)
	{
		printf("%I64d\n",i);
		i=i+11;
	}
	//*/
	return 0;
}