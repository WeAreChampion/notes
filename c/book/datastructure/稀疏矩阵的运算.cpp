#include<iostream>
using namespace std;
#define MaxSize 100
#define Size 100
typedef struct
{
	int i;int j;int e;
}Triple;
typedef struct
{
	Triple data[MaxSize];
	int rpos[MaxSize];//各行第一个非零元的位置表 
	int mu,nu,tu;//分别表示矩阵行，列即非零元素个数 
}Matrix;
int getElem(Matrix array,int i,int j)//get elem (i,j)
{
	for(int k=0;k<array.tu;k++)
		if(array.data[k].i==i&&array.data[k].j==j)
			return array.data[k].e;
	return 0;
}
void Disp(Matrix array)//输出压缩矩阵元素值 
{
	cout<<"压缩矩阵存储的元素值是:\n";
	for(int i=0;i<array.tu;i++)
		cout<<array.data[i].e<<" ";
	cout<<endl;
}
void DispArray(Matrix array)//output the matrix
{
	int arr[Size][Size]={0},i,j;
	for(i=0;i<array.tu;i++)
		arr[array.data[i].i][array.data[i].j]=array.data[i].e;
	for(i=0;i<array.mu;i++)
	{
		for(j=0;j<array.nu;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
void CreateMatrix(Matrix &array)//create the matrix 
{
	int i,j,t,value,k,nn=0,pos,m,n;char ch;
	do
	{
		cout<<"请输入矩阵的行和列：";
		cin>>n>>m;
	}while(n<=0||m<=0);
	array.mu=n;array.nu=m;
	cout<<"请输入矩阵非零元素个数:  ";
	cin>>t; 
	array.tu=t;
	while(t--)
	{
		do
		{
			cout<<"请输入该元素在矩阵中的行列下标: ";
			cin>>i>>j;
		}while(i>n||i<0||j>m||j<0);
		array.data[nn].i=i;//存储行标 
		array.data[nn].j=j;//存储列标
		cout<<"请输入元素的值：";
		cin>>value;
		array.data[nn].e=value;
		nn++;
	}
}
int AddMatrix(Matrix M,Matrix N,Matrix &Q)
{
	if((M.mu!=N.mu)||(M.nu!=N.nu))
		return 0;
	Q.mu=M.mu;Q.nu=M.nu;
	int count=0;//元素个数 
	int i=0,j=0;//指向三元组的下标 
	while(i<M.tu||j<N.tu)
	{
		if(M.data[i].i<N.data[j].i)//M的当前行数大于N的行数 
		{//将三元组M的信息保存到三元组Q中 
			Q.data[count].i=M.data[i].i;
			Q.data[count].j=M.data[i].j;
			Q.data[count].e=M.data[i].e; 
			count++;//元素个数加1 
			i++;//指向M的数组下标下移  
		} 
		else if(M.data[i].i==N.data[j].i)
		{
			if(M.data[i].j<N.data[j].j)
			{//M的当前列数大于N的列数 
				Q.data[count].i=M.data[i].i;
				Q.data[count].j=M.data[i].j;
				Q.data[count].e=M.data[i].e;
				count++;//元素个数加1 
				i++;//指向M的数组下标下移  
			}
			else if(M.data[i].j==N.data[j].j)
			{
				if(M.data[i].e+N.data[j].e!=0)//相加之和不为0 
				{//将三元组M的信息保存到三元组Q中 
					Q.data[count].i=M.data[i].i;
					Q.data[count].j=M.data[i].j;
					Q.data[count].e=M.data[i].e+N.data[j].e;
					count++;//元素个数加1 	
				}
				i++;//指向M的数组下标下移 
				j++;//指向N的数组下标下移 
			}
			else
			{//将三元组N的信息保存到三元组Q中 
				Q.data[count].i=N.data[j].i;
				Q.data[count].j=N.data[j].j;
				Q.data[count].e=N.data[j].e;
				count++;//元素个数加1 
				j++;//指向N的数组下标下移 
			}
		}
		else
		{//将三元组N的信息保存到三元组Q中 
			Q.data[count].i=N.data[j].i;
			Q.data[count].j=N.data[j].j;
			Q.data[count].e=N.data[j].e;
			count++;//元素个数加1 
			j++;//指向N的数组下标下移 
		}
	}
	Q.tu=count;
	return 1;
}
int SubtractMatrix(Matrix M,Matrix N,Matrix &Q)
{
	if((M.mu!=N.mu)||(M.nu!=N.nu))
		return 0;
	Q.mu=M.mu;Q.nu=M.nu;
	int count=0;
	int i=0,j=0;
	while(i<M.tu||j<N.tu)
	{
		if(M.data[i].i<N.data[j].i)
		{
			Q.data[count].i=M.data[i].i;
			Q.data[count].j=M.data[i].j;
			Q.data[count].e=M.data[i].e;
			count++;//元素个数加1 
			i++;//指向M的数组下标下移  
		} 
		else if(M.data[i].i==N.data[j].i)
		{
			if(M.data[i].j<N.data[j].j)
			{
				Q.data[count].i=M.data[i].i;
				Q.data[count].j=M.data[i].j;
				Q.data[count].e=M.data[i].e;
				count++;
				i++;//指向M的数组下标下移  
			}
			else if(M.data[i].j==N.data[j].j)
			{
				if(M.data[i].e-N.data[j].e!=0)
				{
					Q.data[count].i=M.data[i].i;
					Q.data[count].j=M.data[i].j;
					Q.data[count].e=M.data[i].e-N.data[j].e;
					count++;//元素个数加1 	
				}
				i++;//指向M的数组下标下移  
				j++;//指向N的数组下标下移  
			}
			else
			{
				Q.data[count].i=N.data[j].i;
				Q.data[count].j=N.data[j].j;
				Q.data[count].e=-N.data[j].e;
				count++;//元素个数加1 
				j++;//指向N的数组下标下移  
			}
		}
		else
		{
			Q.data[count].i=N.data[j].i;
			Q.data[count].j=N.data[j].j;
			Q.data[count].e=-N.data[j].e;
			count++;//元素个数加1 
			j++;//指向N的数组下标下移  
		}
	}
	Q.tu=count;
	return 1;
}
int MultiplyMatrix(Matrix M,Matrix N,Matrix &Q)
{
	if(M.nu!=N.mu)
		return 0;
	Q.mu=M.mu;Q.nu=N.nu;Q.tu=0;//init Q
	int ctemp[Size]={0},tp;
	int brow,t,ccol;
	if(M.tu*N.tu!=0)
	{
		for(int arow=0;arow<M.nu;arow++)
		{
			Q.rpos[arow]=Q.tu;
			if(arow<M.tu-1) 
				tp=M.rpos[arow+1];
			else
				tp=M.tu;
			for(int p=M.rpos[arow];p<tp;p++)
			{
				brow=M.data[p].j;
				if(brow<N.nu-1)
					t=N.rpos[brow+1];
				else
					t=N.tu;
				for(int q=N.rpos[brow];q<t;q++)
				{
					ccol=N.data[q].j;
					ctemp[ccol]+=M.data[p].e*N.data[q].e;
				}
			}
			for(ccol=0;ccol<Q.nu;ccol++)
			{
				if(ctemp[ccol])
				{
					if(++Q.tu>MaxSize)
						return 0;
					Q.data[Q.tu].i=arow;
					Q.data[Q.tu].j=ccol;
					Q.data[Q.tu].i=ctemp[ccol];
				}
			}
		}
	}
}
void TransposeMatrix(Matrix M,Matrix &array)//转置 
{
	array.mu=M.nu;array.nu=M.mu;array.tu=M.tu;
	int col,t,num[Size],cpot[Size],p,q;
	if(array.tu)
	{
		for(col=0;col<M.nu;col++)	num[col]=0;
		for(t=0;t<M.tu;t++)	++num[M.data[t].j];//求M中每一列含非零元素个数
	 	cpot[1]=0;
	 	for(col=1;col<M.nu;col++)	cpot[col]=cpot[col-1]+num[col-1];
	 	for(p=0;p<M.tu;p++)
	 	{
	 		col=M.data[t].j;q=cpot[col];
	 		array.data[q].i=M.data[p].j;
	 		array.data[q].j=M.data[p].i;
	 		array.data[q].e=M.data[p].e;
	 		++cpot[col];
	 	}
	}
}
int main()
{
	Matrix M,N;
	cout<<"构造三元矩阵M\n";
	CreateMatrix(M);
	cout<<"矩阵M是:\n";
	DispArray(M);
	cout<<"构造三元矩阵N\n";
///	Disp(M);
	CreateMatrix(N);
	cout<<"矩阵N是:\n";
	DispArray(N);
//	Disp(N);
	Matrix Q1;
	AddMatrix(M,N,Q1);
	cout<<"求和矩阵Q1是:\n";
	DispArray(Q1);
	Matrix Q2;
	SubtractMatrix(M,N,Q2);
	cout<<"求差矩阵Q2是:\n";
	DispArray(Q2);
	Matrix Q3;
	MultiplyMatrix(M,N,Q3);
	cout<<"求积矩阵Q3是:\n";
	DispArray(Q3);
	return 0;
}
/*
4 4
3
0 3
2
1 2
3
2 1
-1
4 4
4
0 2
1
1 1
2
1 2
-3
3 3
1
*/