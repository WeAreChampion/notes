#include<iostream>
using namespace std;
int a[10][5]={{0},{0,1,1,1,1},{0,2,4,8,6},{0,3,9,7,1},{0,4,6,4,6},{0,5,5,5,5},{0,6,6,6,6},{0,7,9,3,1},{0,8,4,2,6},{0,9,1,9,1}};
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		__int64 n,i;
		scanf("%I64d",&n);
		int m=n%10;
		int mm=n%4;
		if(mm==0)
			cout<<a[m][4]<<endl;
		else
			cout<<a[m][mm]<<endl;
	}
	return 0;
}