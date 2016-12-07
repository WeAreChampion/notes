#include<iostream>
using namespace std;
/*
	获取最大的int即2^31 - 1
	得到结果：2147483647
*/
int getMaxInt()
{
	return (1 << 31) - 1;
}

/*
	使用g++编译，出现warning: left shift count is negative
	结果为-1
*/
int getMaxInt_2()
{
	return (1 << -1) - 1;
}

int getMaxInt_3()
{
	return ~(1 << 31);
}
/*
	在不了解int的长度情况下使用
*/
int getMaxInt_4()
{
	return ((unsigned int) -1) >> 1;
}
void test()
{
	cout << getMaxInt() << endl;
	cout << getMaxInt_2() << endl;
	cout << getMaxInt_3() << endl;
	cout << getMaxInt_4() << endl;
}
int main() {
	test();
	return 0;
}