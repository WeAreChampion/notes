/*
ÿ��һ����ɱһ���ˣ���������µ��˵�λ��
��һ��ɱ���������Ϊż�����ˣ�ɱ��[n/2] ���� 
��N����������ڶ��ֻ�ɱ��1,5,9,13..���N
��ż����3,7,11...�ᱻɱ��, ɱ��[n/4]����
��˷�����ֱ����ʣ��һ���ˡ�
���ɣ�
����λ������Կ�������𰸡�
2^N�������ʣ�µ�һ����λ��Ϊ1���ˣ�2^N+1(2^N>1)
�������ʣ�µ�һ����λ��Ϊ3���ˣ� 2^N+m(2^N>m)��
��ʣ�µ���2*m+1���Ǹ��� 
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