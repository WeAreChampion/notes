#include<iostream>
using namespace std;
#define MaxSize 100
#define N 4
int a[N][N]={
	{1,3,7,8},
	{3,2,5,10},
	{7,5,6,9},
	{8,10,9,4}};
 int b[N+1][N+1]={
	{1,3,0,0,0},
	{4,2,10,0,0},
	{0,5,6,8,0},
	{0,0,7,9,11},
	{0,0,0,12,13}};
typedef struct
{
	int i;
	int j;
	int e;
}Triple;//Sa[MaxSize],
typedef struct
{
	Triple data[MaxSize];
	int mu,nu,tu;//分别表示矩阵行，列即非零元素个数 
}Matrix;
void symmetric_matrix(Matrix &array)//对称矩阵压缩存储
{
	array.mu=N;array.nu=N;array.tu=(N+1)*N/2;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i>=j)
			{
				array.data[i*(i+1)/2+j].i=i;
				array.data[i*(i+1)/2+j].j=j;
				array.data[i*(i+1)/2+j].e=a[i][j];
			}
		}
	}
}
void diagonal_matrix(Matrix &array)//对角矩阵压缩存储
{
	int k,n=N+1;
	array.mu=N+1;array.nu=N+1;array.tu=3*n-2;
	array.data[0].i=0;array.data[0].j=0;array.data[0].e=b[0][0];
	array.data[1].i=0;array.data[1].j=1;array.data[1].e=b[0][1];
	for(int i=1;i<N+1;i++)
	{
		for(int j=0;j<N+1;j++)
		{
			if(b[i][j]!=0)
			{
				if(i>j)        k=0;
				else if(i==j)  k=1;
				else	       k=2;	
				array.data[3*i+k-1].i=i;//下标从0开始，所以要减1 
				array.data[3*i+k-1].j=j; 
				array.data[3*i+k-1].e=b[i][j];
			}
		}
	}
}
int getElem(Matrix array,int i,int j)//get elem (i,j)
{
	for(int k=0;k<array.tu;k++)
	{
		if(array.data[k].i==i&&array.data[k].j==j)
		{
			return array.data[k].e;
		}
	}
	return 0;
}
void Disp(Matrix array)//输出压缩矩阵元素值 
{
	for(int i=0;i<array.tu;i++)
	{
		cout<<array.data[i].e<<" ";
	}
	cout<<endl;
}
void DispArray(Matrix array)//output the matrix
{
	int arr[2*N][2*N]={0},i,j;
	for(i=0;i<array.tu;i++)
	{
		arr[array.data[i].i][array.data[i].j]=array.data[i].e;
	}
	for(i=0;i<array.mu;i++)
	{
		for(j=0;j<array.nu;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void DispArray_a()//output the matrix a
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void DispArray_b()//output the matrix b
{
	for(int i=0;i<N+1;i++)
	{
		for(int j=0;j<N+1;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
}
void CreateMatrix(Matrix &array)//create the matrix 
{
	int i,j,t,value,k,nn=0,pos,m,n;
	char ch;
	do
	{
		cout<<"请输入矩阵的行和列：";
		cin>>n>>m;
	}while(n<=0||m<=0);
	array.mu=n;
	array.nu=m;
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
		do
		{
			cout<<"请输入是否要输入新值 Y/N："; 
			cin>>ch;
		}
		while(ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n');
		if(ch=='Y'||ch=='y')
		{
			cout<<"请输入元素的值：";
			cin>>value;
			array.data[nn++].e=value;
		}
		else
		{
			for(k=0;k<nn;k++)
			{
				cout<<array.data[k].e<<" ";
			}
			if(nn>0)
			{
				cout<<endl;
			}
			cout<<"请输入重复元素在压缩存储数组中的下标：";
			cin>>pos;
			array.data[nn].e=array.data[pos].e;
		}
	}
}
int main()
{
	Matrix array,array1,array2; 
	cout<<"对称矩阵是:"<<endl;
	DispArray_a();
	cout<<"压缩后的对称矩阵是:"<<endl;
	symmetric_matrix(array1);
	Disp(array1);
	cout<<"对角矩阵是:"<<endl;
	DispArray_b();
	cout<<"压缩后的对角矩阵是:"<<endl;
	diagonal_matrix(array2);
	Disp(array2);
	CreateMatrix(array);
	DispArray(array);
	cout<<"array数组第3行第3列的元素是: "<<getElem(array,3,3)<<endl; 
	return 0;
} 
/*
4 4
4
0 0
y 
1
1 1
y
2
3 3
y
3
2 2
n
2
*/