#include<iostream>
using namespace std;
/*
	��������0����ĩβ����һ������1��λ�� 
	x = x & (x - 1)
	���ʽ����˼���ǰ�x�Ķ����Ʊ�ʾ�����λ
ֱ��������һ��1�ı�����0

	��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұ�һ��1���0 .��ôһ�������Ķ����Ʊ�ʾ���ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ���
*/
int countOne(int n)
{
	int counts = 0;
	while(n) {
		n = n & (n - 1);
		counts++;
	}
	return counts;
}
void testCountOne()
{
	cout << countOne(1) << endl;
	cout << countOne(2) << endl;
	cout << countOne(3) << endl;
	cout << countOne(999) << endl;
	cout << countOne(19988) << endl;
}
/*
	�ж��Ƿ���2�Ĵη� 
*/
bool is2Pow(int n)
{
	if((n & (n - 1)) == 0) {
		return true;
	}
	return false;
}
void testIs2Pow()
{
	cout << is2Pow(1) << endl;
	cout << is2Pow(2) << endl;
	cout << is2Pow(3) << endl;
	cout << is2Pow(8) << endl;
	cout << is2Pow(12) << endl;
}
int main()
{
//	testCountOne();
	testIs2Pow();
	return 0;
}