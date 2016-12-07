#include<iostream>
using namespace std;
template<class Type> class Array;
template<class Type>
class ArrayBody
{
	friend class Array<Type>;//友元类 
	Type *tpBody;
	int iRows, iColumns, iCurrentRow;
	ArrayBody(int iRsz, int iCsz)//构造函数 
	{
		tpBody = new Type[iRsz * iCsz];//开辟数组空间 
		iRows = iRsz;//赋值 
		iColumns = iCsz;
		iCurrentRow = -1;//当前行=-1 
	}
public:
	Type &operator[](int j)//重载操作符[] 
	{
		bool row_error, column_error;
		row_error = column_error = false;//初始化标记 
		try
		{
			if(iCurrentRow < 0 || iCurrentRow >= iRows)
				row_error = true;
			if(j < 0 || j >= iColumns) { 
				column_error = true;
			} 
			if(row_error || column_error) {
				throw 'e';
			}
		}catch(char) {
			if(row_error) { 
				cerr<<"行下标越界["<<iCurrentRow<<"]";
			} 
			if(column_error) {
				cerr << "列下标越界[" << j << "]";
			}
			cout << endl;
		}
		return tpBody[iCurrentRow * iColumns + j];
	}
	~ArrayBody(){
		delete[]tpBody;
	}//析构函数，释放空间 
};
template<class Type> class Array
{
	ArrayBody<Type> tBody;
	public:
	ArrayBody<Type> &operator[](int i)
	{
		tBody.iCurrentRow = i;
		return tBody;
	}
	Array(int iRsz, int iCsz):tBody(iRsz, iCsz){}
};
int main()
{
	Array<int> a1(10,20);
	Array<double> a2(3, 5);
	int b1;
	double b2;
	b1 = a1[-5][10];
	b1 = a1[10][15];
	b1 = a1[1][4];
	b2 = a2[2][6];
	b2 = a2[10][20];
	b2 = a2[1][4];
	return 0;
}