#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int TheValue(char sa) {
	int a;
	if(sa == '0')
		a = 0;
	else if(sa == '1')
		a = 1;
	else if(sa == '2')
		a = 2;
	else if(sa == '3')
		a = 3;
	else if(sa == '4')
		a = 4;
	else if(sa == '5')
		a = 5;
	else if(sa == '6')
		a = 6;
	else if(sa=='7')
		a=7;
	else if(sa=='8')
		a=8;
	else if(sa=='9')
		a=9;
	else if(sa=='a')
		a=10;
	else if(sa=='b')
		a=11;
	else if(sa=='c')
		a=12;
	else if(sa=='d')
		a=13;
	else if(sa=='e')
		a=14;
	else if(sa=='f')
		a=15;
	else if(sa=='g')
		a=16;
	else if(sa=='h')
		a=17;
	else if(sa=='i')
		a=18;
	else if(sa=='j')
		a=19;	
	return a;
}
char CharValue(int i)
{
	char op; 
	if(i==10)
		op='a';
	else if(i==11)
		op='b';
	else if(i==12)
		op='c';
	else if(i==13)
		op='d';
	else if(i==14)
		op='e';
	else if(i==15)
		op='f';
	else if(i==16)
		op='g';
	else if(i==17)
		op='h';
	else if(i==18)
		op='i';
	else if(i==19)
		op='j';
	return op;
} 
int main()
{
	string sa,sb,t;
	vector<int> v;
	int i,a,b,sum,flag;
	while(cin>>sa>>sb)
	{
		cout<<"sa="<<sa<<endl<<"sb="<<sb<<endl;
		flag=0;//进位标志 
		v.clear();
		sum=0;
		reverse(sa.begin(),sa.end());
		reverse(sb.begin(),sb.end());
		if(sa.size()<sb.size())//swap
		{
			t=sa;
			sa=sb;
			sb=t;
		}
		for(i=0;i<sa.size();i++)
		{
			a=TheValue(sa[i]);
			if(i>=sb.size())
				b=0;
			else
			{
				b=TheValue(sb[i]);
			}
			sum=a+b+flag;
			if(sum>19)
			{
				flag=1;
				sum=sum-20;
			}
			else
				flag=0;
			v.push_back(sum);
		}
		if(flag)
		{
			v.push_back(1);
		}
		for(i=v.size()-1;i>=0;i--)
		{
			if(v[i]<10)
				cout<<v[i];
			else
			{
				cout<<CharValue(v[i]);
			}
		}
		cout<<endl;
	}
	return 0;
} 
/*
Input:
1234567890
abcdefghij
99999jjjjj
9999900001
*/