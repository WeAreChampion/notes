#include<iostream>
using namespace std;
int count=0;
void move(int start,int n,int end)
{
	count++;
}
/*
void hanoi(int n,int start,int help1,int help2,int end)
{
	if(n==1)
		move(1,1,3);
	else if(n%3==0)
	{
		move(1,1,2);
		move(1,2,3);
		move(2,1,3);
	}
	else if(n%3==1)
	{
		move(1,1,2);
		move(1,2,4);
		move(1,3,3);
		move(4,2,3);
		move(2,1,3);
	}
	else
	{
		hanoi(n-2,1,3,4,2);
		move(1,n-1,4);
		move(1,n,3);
		move(4,n-1,3);
		hanoi(n-2,2,1,4,3);
	}
}
*/
/*
void hanoi(int n,int start,int help1,int end)
{
	if(n==1)
		move(1,1,3);
	if(n==2)
	{
		move(1,1,2);
		move(1,2,3);
		move(2,1,3);
	}
	if(n>=3)
	{
		hanoi(n-2,1,4,2);
		move(1,n-1,4);
		move(1,n,3);
		move(4,n-1,3);
		hanoi(n-2,2,4,3);
	}
}
*/
int main()
{
	int n,a[1000];
	while(cin>>n)
	{
		///*
		count=0;
		hanoi(n,1,2,4,3);
		cout<<count<<endl;
	//	*/
		/*
		a[1]=1;
		a[2]=3;
		a[3]=5;
		for(int i=4;i<=n;i++)
			a[i]=a[i-2]+3;
		cout<<a[n]<<endl;
		*/
	}
	return 0;
}