/*
每隔一个人杀一个人，求最后留下的人的位置
第一轮杀掉所有序号为偶数的人，杀了[n/2] 个人 
若N是奇数，则第二轮会杀掉1,5,9,13..如果N
是偶数则3,7,11...会被杀掉, 杀了[n/4]个人
如此反复，直到还剩下一个人。
技巧：
利用位运算可以快速求出答案。
2^N个人最后剩下的一定是位置为1的人，2^N+1(2^N>1)
个人最后剩下的一定是位置为3的人， 2^N+m(2^N>m)个
人剩下的是2*m+1的那个人 
input :
1
2
3
4
2008
output:
1
1
3
1
1969
*/ 
#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;
unsigned f(unsigned x)
{
	unsigned y;
	do{
		y=x;
		x&=x-1;
	}
	while(x);
	return y;
}
int main()
{
	int n;
	long begin =clock();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",((n-f(n))<<1)|1);
	}
	long end=clock();
	printf("%ld\n",end-begin);
	return 0;
}