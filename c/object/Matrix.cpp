#include<iostream>
using namespace std;
template<class Type>
class Matrix
{
private:
	Type **array;
	int row;
	int column;
public:
	void InitMatrix();
	void setRow(int row);
	int getRow();
	void setColumn(int column);
	int getColumn();
	Matrix<Type> operator + (Matrix<Type> a);
	Matrix<Type> operator * (Matrix<Type> a);
	void DestroyMatrix();
	void Display();
	void InputMatrix();
	void InputRow();
	void InputColumn();
	bool Compare(Matrix<Type> a); 
};
template<class Type>
bool Matrix<Type>::Compare(Matrix<Type> a)
{
	if(column!=a.row)
		return false;
	return true;
}
template<class Type>
void Matrix<Type>::InitMatrix()
{
	array=new int *[row];
	for(int i=0;i<row;i++)
	{
		array[i]=new int[column];
	}
}
template<class Type>
void Matrix<Type>::InputMatrix()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cin>>array[i][j];
		}
	}
}
template<class Type>
void Matrix<Type>::setRow(int row)
{
	this->row=row;
}
template<class Type>
int Matrix<Type>::getRow()
{
	return row;
}
template<class Type>
void Matrix<Type>::setColumn(int column)
{
	this->column=column;
}
template<class Type>
int Matrix<Type>::getColumn()
{
	return column;
}
template<class Type>
Matrix<Type> Matrix<Type>::operator + (Matrix<Type> a)
{
	Matrix<Type> c;
	c.setRow(a.getRow());
	c.setColumn(a.getColumn());
	c.InitMatrix();
	for(int i=0;i<a.row;i++)
	{
		for(int j=0;j<a.column;j++)
		{
			c.array[i][j]=a.array[i][j]+array[i][j];
		}
	}
	return c;
}
template<class Type>
Matrix<Type> Matrix<Type>::operator * (Matrix<Type> a)
{
	Matrix<Type> c;
	c.setRow(a.getRow());
	c.setColumn(column);
	c.InitMatrix();
	for(int i=0;i<a.row;i++)
	{
		for(int j=0;j<column;j++)
		{
			c.array[i][j]=0;
			for(int k=0;k<a.column;k++)
			{
				c.array[i][j]+=a.array[i][k]*array[k][j];
			}
		}
	}
	return c;
}
template<class Type>
void Matrix<Type>::DestroyMatrix()
{
	for(int i=0;i<row;i++)
	{
		delete []array[i];
	}
	delete []array;
}
template<class Type>
void Matrix<Type>::Display()
{
	cout<<"Matrix is:\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}
template<class Type>
void Matrix<Type>::InputRow()
{
	cout<<"Matrix'row is: ";
	cin>>row;
}
template<class Type>
void Matrix<Type>::InputColumn()
{
	cout<<"Matrix'column is: ";
	cin>>column;
}
int main()
{
	Matrix<int> a;
	a.InputRow();
	a.InputColumn();
	a.InitMatrix();
	a.InputMatrix();
	a.Display();
	Matrix<int> b;
	b.InputRow();
	b.InputColumn();
	b.InitMatrix();
	b.InputMatrix();
	b.Display();
	Matrix<int> c;
//	cout<<c.getRow()<<" ";
//	cout<<c.getColumn()<<endl;
	c=a+b;
	c.Display();
	a.DestroyMatrix();
	b.DestroyMatrix();
	c.DestroyMatrix();
	return 0;
} 
/*
3 
3
1 2 3
4 5 6
7 8 9
3 
3
1 2 7
3 4 8
5 6 9
*/