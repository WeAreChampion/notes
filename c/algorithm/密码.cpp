#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int f(string s)
{
	int sum=0,i,a,k=0;
	for(i=s.length()-1;i>=0;i--)
	{
		a=s[i]-'0';
		int sss=(int)pow(2,(double)k);
		sum+=a*sss;
		k++;
	}
	return sum;
}
int main()
{
	int n;
	while(cin>>n)
	{
		string str="";
		while(n--)
		{
			char ch;
			getchar();
			string s="";
			int flag=1,count=0;
			while((ch=getchar())!='\n')
			{
				if(ch==' ')
				{
					count++;
				}
				else if(count!=0)
				{
					if(count%2==1)
						s+='1';
					else
						s+='0';
					count=0;
				}
			}
			char aaa=f(s);
			str+=aaa;
		}
		cout<<str<<endl;
	}
	return 0;
} 