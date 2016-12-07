#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int Operate(int a,char op,int b)
{
	int sum;
	switch(op)
	{
		case '+':sum=a + b; break;
		case '-':sum=a - b; break;
		case '*':sum=a * b; break;
		case '/':sum=a / b; break;
	} 
	return sum;
}
int power(int x,int expn)
{
	int s=x;
	for(int i=1;i<expn;i++)
		s=s*x;
	return s;
}
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		string s="";
		int x;
		char op;
		cin>>x>>s;
		int i,c,a,b,expn,t=0,flag=0;
		int j=2;
		if(s[j]=='-')
		{
			flag=1;
			j++;
		}
		for(i=j;i<s.length();i++)
		{
			
			if(s[i]=='+'||s[i]=='-')
			{
				if(t==1)
					op=s[i];
			}
			else if(s[i]>='0'&&s[i]<='9')
			{
				c=s[i]-'0';
				if(s[i+1]=='x')
				{
					if(s[i+2]=='^')
					{
						expn=s[i+3]-'0';
						c=c*power(x,expn);
						i=i+3;
					}
					else
					{
						c=c*x;
						i++;
					}
				}
				if(t==0)
					a=c;
				else
					b=c;
				t++;
			}
			else if(s[i]=='x')
			{
				if(s[i+1]=='^')
				{
					expn=s[i+2]-'0';
					c=power(x,expn);
					i=i+2;
				}
				else
				{
					c=x;
				}
				if(t==0)
					a=c;
				else
					b=c;
				t++;
			}
			if(t==2)
			{
				if(flag)
					a=-a;
				a=Operate(a,op,b);
				t=1;
				flag=0;
			}
		}
		cout<<a<<endl;
	}
	return 0;
} 
/*
10
5
y=-x-1
6
y=x^2-2x+1 
*/ 