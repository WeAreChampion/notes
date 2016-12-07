#include<iostream>
using namespace std;
template<class Type> class Array;
template<class Type>
class ArrayBody
{
	friend class Array<Type>;//��Ԫ�� 
	Type *tpBody;
	int iRows, iColumns, iCurrentRow;
	ArrayBody(int iRsz, int iCsz)//���캯�� 
	{
		tpBody = new Type[iRsz * iCsz];//��������ռ� 
		iRows = iRsz;//��ֵ 
		iColumns = iCsz;
		iCurrentRow = -1;//��ǰ��=-1 
	}
public:
	Type &operator[](int j)//���ز�����[] 
	{
		bool row_error, column_error;
		row_error = column_error = false;//��ʼ����� 
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
				cerr<<"���±�Խ��["<<iCurrentRow<<"]";
			} 
			if(column_error) {
				cerr << "���±�Խ��[" << j << "]";
			}
			cout << endl;
		}
		return tpBody[iCurrentRow * iColumns + j];
	}
	~ArrayBody(){
		delete[]tpBody;
	}//�����������ͷſռ� 
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