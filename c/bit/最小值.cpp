#include<iostream>
using namespace std;
/*
	求最小int -2^31
	得到结果：-2147483648
*/
int getMinInt()
{
	return 1 << 31;
}

/*
	同样在g++下编译，出现warning: left shift count is negative
	
	结果为0，不提倡
*/
int getMinInt_2()
{
	return 1 << -1;
}
void test() {
	cout << getMinInt() << endl;
	cout << getMinInt_2() << endl;
}
int main() {
	test();
	return 0;
}