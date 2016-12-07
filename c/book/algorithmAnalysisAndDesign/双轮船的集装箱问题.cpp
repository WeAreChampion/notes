#include<iostream>
using namespace std;
template<class Type>
class Loading
{
public:
	Type MaxLoading(Type w[],Type c,int n,int bestx[]);
	void Backtrack(int i);
	int n,		//��װ����
		*x,		//��ǰ�� 
		*bestx;	//��ǰ���Ž�	 
	Type *w,	//��װ���������� 
		c,		//��һ���ִ��������� 
		cw,		//��ǰ������	 
		bestw,	//��ǰ���������� 
		r;		//ʣ�༯װ������ 
};
template<class Type>
void Loading<Type>::Backtrack(int i)//������i���� 
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
		x[i]=1;		//������ѡ 
		cw+=w[i];//�ı䵱ǰ������ 
		Backtrack(i+1);
		cw-=w[i]; //��ԭ������ 
	}
	if(cw+r>bestw)
	{
		x[i]=0;	//����δѡ 
		Backtrack(i+1);//����������
	}
	r+=w[i];//��ԭ 
}
template<class Type>
Type Loading<Type>::MaxLoading(Type *w,Type c,int n,int *bestx)
{
	Loading<Type> X;
	X.x=new int [n+1];//��������飬������ֵ 
	X.w=w;
	X.c=c;
	X.n=n;
	X.bestx=bestx;
	X.bestw=0;
	X.cw=0;
	//init
	X.r=0;
	for(int i=1;i<=n;i++)//ʣ������ 
		X.r+=w[i];
	X.Backtrack(1);
	return X.bestw;
}
int main()
{
	int n,c1,c2,i;
	int ca=1;
	while(cin>>n)
	{
		int *w=new int[n+1];
		int *bestx=new int[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>w[i];
			bestx[i]=0;
		}
		cin>>c1>>c2;
		if(c2>c1)//Swap(c1,c2)
		{
			int temp=c1;
			c1=c2;
			c2=temp;
		}
		Loading<int> l;
	 	int max1=l.MaxLoading(w,c1,n,bestx);
	 	cout<<"Case: "<<ca<<endl;
		int count=0,sum1=0,sum2=0;
		int *bestw=new int [n+1];
		int *besty=new int [n+1];
		for(i=1;i<=n;i++)
		{
			if(bestx[i]==0)
				count++;
			bestw[count]=w[i];//save the δװ�Ļ������� 
		}
		l.MaxLoading(bestw,c2,count,besty);//��c2����װʣ�༯װ�� 
		int count1=0;
		for(i=1;i<=count;i++)//�ۼ�δװ��c1�м�װ��װ��c2�еĸ��� 
			if(besty[i])
				count1++;
		if(count1!=count)//����ȣ�����δȫ��װ�꣬���No 
		{
			cout<<"No";
		}
		else
		{
			cout<<max1<<" ";
			for(i=1;i<=n;i++) 
				cout<<bestx[i];
		}
		cout<<endl;
		ca++;
		delete w;
		delete bestx;
		delete besty;
		delete bestw;
	}
	return 0;
}
/*
Input:
3
10 40 40
50 50
3
20 40 40
50 50
Output:
Case 1:
50 110
Case 2: 
No
*/