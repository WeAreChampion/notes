#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,flag,i;
	char s[51];
	while(scanf("%d\n",&n)!=EOF)
	{
		while(n--)
		{
			flag=1;
			cin.getline(s,51);
			for(i=0;i<strlen(s);i++)
			{
				if(i==0&&!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))&&s[i]!='_')
				{
					flag=0;
					break;
				}
				else if((!(s[i]>='a'&&s[i]<='z')&&!(s[i]>='A'&&s[i]<='Z'))&&s[i]!='_'&&!(s[i]>='0'&&s[i]<='9'))
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}
	return 0;
}