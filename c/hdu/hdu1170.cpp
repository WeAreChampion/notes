#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		char str,s;
		int a,b;
		cin>>str>>a>>b;
		s=getchar();
		if(str=='+')
			cout<<a+b<<endl;
		if(str=='-')
			cout<<a-b<<endl;
		if(str=='*')
			cout<<a*b<<endl;
		if(str=='/')
		{
			if(a%b==0)
				cout<<a/b<<endl;
			else
				printf("%.2lf\n",a*1.0/b);
		}
	}
	return 0;
}