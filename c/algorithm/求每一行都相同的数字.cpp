/*
����ÿһ�У�һ�����У������ֵ�����
��ÿһ�г��ֵ����ֲ�ͬ 
input:
5
2 3 1 8 6
3 8 1 9 5
1 3 5 9 6
0
output: 
1 3
*/
#include<iostream>
using namespace std;
int main()
{
	int n,a,i;
	int sign[300];
	while(cin>>n&&n)
	{
		memset(sign,0,sizeof(sign));//�����������ֵ�ֵΪ0
		for(i=1;i<=3*n;i++)
		{
			cin>>a;
			sign[a]++;
		} 
		int flag=0;
		for(i=1;i<=300;i++)
		{
			if(sign[i]==3)
			{
				if(flag)
				{
					cout<<" ";	
				}
				flag=1;
				cout<<i;
			}
		}
		cout<<endl;
	}
	return 0;
}