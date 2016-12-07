#include<iostream>
#include<cmath>
using namespace std;
int n;//�ʺ���� 
int *x;//��ǰ��
int sum=0;//�ۼƿ��з���
bool Place(int k)//�жϵ�k�е�x[k]λ���Ƿ�Ϸ� 
{
	for(int j=1;j<k;j++)
	{
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	} 
	return true;
} 
void Backtrack()
{
	x[1]=0;
	int k=1;
	while(k>0)
	{
		x[k]+=1;//
		while((x[k]<=n)&&!Place(k))
			x[k]+=1;//
		if(x[k]<=n)
		{
			if(k==n)
			{
				sum++;
				cout<<"��"<<sum<<"�ֿ��з���:"<<endl;
				for(int i=1;i<=n;i++)//output the result
					cout<<x[i]<<" ";
				cout<<endl;
			}	
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
			k--;
	}
} 
int main()
{
	cout<<"Please input n= ";
	while(cin>>n)
	{
		x=new int [n+1];
		Backtrack();
		cout<<"the sum is :"<<sum<<endl;
		sum=0;
		delete x;
		cout<<"Please input n= ";
	}
	return 0;
} 