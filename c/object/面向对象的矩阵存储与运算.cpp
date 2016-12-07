#include<iostream>
using namespace std;
#define MaxSize 100
class Matrix
{
	private:
	int a[MaxSize][MaxSize];
	int row;//������ 
	int column;//������ 
	public:
	void setRow(Matrix &M);
	int getRow(Matrix M);
	void setColumn(Matrix &M);
	int getColumn(Matrix M);
	void CreatMatrix(Matrix &M);
	void DispMatrix(Matrix M);
	int AddMatrix(Matrix M,Matrix N,Matrix &Q);
	int SubtractMatrix(Matrix M,Matrix N,Matrix &Q);
	int MultiplyMatrix(Matrix M,Matrix N,Matrix &Q);
};
void Matrix::setRow(Matrix &M)
{
	cout<<"�����������У�";
	cin>>M.row;
}
void Matrix::setColumn(Matrix &M)
{
	cout<<"�����������У�";
	cin>>M.column;
}
int Matrix::getRow(Matrix M)
{
	return M.row;
}
int Matrix::getColumn(Matrix M)
{
	return M.column;
}
void Matrix::CreatMatrix(Matrix &M)
{
	cout<<"��������Ӧ�ľ���:\n";
	for(int i=0;i<M.row;i++)
	{
		for(int j=0;j<M.column;j++)
		{
			cin>>M.a[i][j];
		}
	}
}
int Matrix::AddMatrix(Matrix M,Matrix N,Matrix &Q)
{
	if(N.row!=M.row||N.column!=M.column)
		return 0;
	Q.row=N.row;Q.column=N.column;
	for(int i=0;i<M.row;i++)
	{
		for(int j=0;j<M.column;j++)
		{
			Q.a[i][j]=M.a[i][j]+N.a[i][j];
		}
	}
	return 1;
}
int Matrix::SubtractMatrix(Matrix M,Matrix N,Matrix &Q)
{
	if(N.row!=M.row||N.column!=M.column)
		return 0;
	Q.row=N.row;Q.column=N.column;
	for(int i=0;i<M.row;i++)
	{
		for(int j=0;j<M.column;j++)
		{
			Q.a[i][j]=M.a[i][j]-N.a[i][j];
		}
	}
	return 1;
}
int Matrix::MultiplyMatrix(Matrix M,Matrix N,Matrix &Q)
{
	if(M.column!=N.row)
		return 0;
	Q.row=M.row;Q.column=N.column;
	for(int i=0;i<M.row;i++)
	{
		for(int j=0;j<N.column;j++)
		{
			Q.a[i][j]=0;
			for(int k=0;k<M.column;k++)
				Q.a[i][j]+=M.a[i][k]*N.a[k][j];
		}
	}
	return 1;
}
void Matrix::DispMatrix(Matrix M)
{
	cout<<"��������ǣ�"<<M.row<<endl;
	cout<<"��������ǣ�"<<M.column<<endl;
	cout<<"����Ϊ��\n";
	for(int i=0;i<M.row;i++)
	{
		for(int j=0;j<M.column;j++)
		{
			cout<<M.a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	Matrix M;
	M.setRow(M);
	cout<<"��������ǣ� "<<M.getRow(M)<<endl;
	M.setColumn(M);
	cout<<"��������ǣ� "<<M.getColumn(M)<<endl;
	M.CreatMatrix(M);
	M.DispMatrix(M);
	Matrix N;
	N.setRow(N);
	cout<<"��������ǣ� "<<N.getRow(N)<<endl;
	N.setColumn(N);
	cout<<"��������ǣ� "<<N.getColumn(N)<<endl;
	N.CreatMatrix(N);
	N.DispMatrix(N);
	Matrix Q;
	Q.AddMatrix(M,N,Q);
	cout<<"��Ӿ���Q��\n";
	Q.DispMatrix(Q);
	Matrix Q1;
	Q1.SubtractMatrix(M,N,Q1);
	cout<<"�������Q1��\n";
	Q1.DispMatrix(Q1);
	Matrix Q2;
	Q2.AddMatrix(M,N,Q2);
	cout<<"��˾���Q2��\n";
	Q2.DispMatrix(Q2);
	return 0;
}
/*
4
4
0 -2 1 3
3 -3 2 5
0 0 4 -2
-1 9 7 4
4
4
0 2 0 5
7 -6 1 11
-8 8 3 5
-6 7 2 0
*/