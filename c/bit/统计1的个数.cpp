#include<iostream>
using namespace std;
/*
	快速设置0：从末尾到第一次遇到1的位置 
	x = x & (x - 1)
	表达式的意思就是把x的二进制表示从最低位
直到遇到第一个1的比特置0

	把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0 .那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作
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
	判断是否是2的次方 
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