#include<iostream>
using namespace std;
#define Max 100
int n,		//��װ����
	x[Max],		//��ǰ�� 
	bestx[Max];	//��ǰ���Ž�	 
int w[Max],	//��װ���������� 
	c,		//��һ���ִ��������� 
	cw,		//��ǰ������	 
	bestw,	//��ǰ���������� 
	r;		//ʣ�༯װ������ 
void Backtrack(int i)//������i���� 
{
	if(i>n)//����Ҷ�ӽ�� 
	{
		if(cw>bestw)//�洢��ǰ����ֵ 
		{
			bestw=cw;
			for(int j=1;j<=n;j++)
				bestx[j]=x[j];
		}
		return ;
	}
	//�������� 
	r-=w[i];
	if(cw+w[i]<=c)//���������� 
	{
		x[i]=1;
		cw+=w[i];//�ı䵱ǰ������ 
		Backtrack(i+1);
		cw-=w[i]; //��ԭ������ 
	}
	if(cw+r>bestw)
	{
		x[i]=0;
		Backtrack(i+1);//����������
	}
	r+=w[i];
}
int MaxLoading(int _w[],int _c,int _n,int _bestx[])
{
	c=_c;
	n=_n;
	for(int i=1;i<=n;i++)
	{
		w[i]=_w[i];
		bestx[i]=_bestx[i];
	}
	bestw=0;
	cw=0;
	//init
	r=0;
	for(int i=1;i<=n;i++)
		r+=w[i];
	Backtrack(1);
	return bestw;
}
int main()
{
	int n,c;
	int ca=1;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
			bestx[i]=0;
		}
		cin>>c;
	 	int max=MaxLoading(w,c,n,bestx);
	 	cout<<"Case: "<<ca<<endl;
		cout<<max<<"��";
		for(int i=1;i<=n;i++)
			cout<<bestx[i];
		cout<<endl;
		ca++;
	}
	return 0;
}
/*
Input:
3
10 40 40
50
Output:
Case 1:
50 110
*/