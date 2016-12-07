#include<iostream>
using namespace std;
/*
	判断一个数是否为2的n次方（一个数为2的n次方，则最高位为1，其余位为0）
*/
bool is2Power(int num)
{
	bool flag = true;

	num = num & (num - 1); //计算num和num - 1的与的结果
	// 如果结果为0，则不是2的n次方
	if(num) {
		flag = false;
	}
	return flag;
}
void test() {
	cout << is2Power(2) << endl;
	cout << is2Power(3) << endl;
	cout << is2Power(8) << endl;
	cout << is2Power(1) << endl;
	cout << is2Power(6) << endl;
}
int main() {
	test();
	return 0;
}