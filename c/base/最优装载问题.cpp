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
	int n,c;
	int ca=1;
	while(cin>>n)
	{
		int *w=new int[n+1];
		int *bestx=new int[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
			bestx[i]=0;
		}
		cin>>c;
		Loading<int> l;
	 	int max=l.MaxLoading(w,c,n,bestx);
	 	cout<<"Case: "<<ca<<endl;
		cout<<max<<"��";
		for(int i=1;i<=n;i++)
			cout<<bestx[i];
		cout<<endl;
		ca++;
		delete w;
		delete bestx;
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