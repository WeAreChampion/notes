#include<iostream>
using namespace std; 
/*
	1. n 个数字（ 0,1,…,n-1 ）形成一个圆圈，从数字 0 开始，
	2. 每次从这个圆圈中删除第 m 个数字（第一个为当前数字本身
	，第二个为当前数字的下一个数字）。
*/
int LastRemaining_Solution2(int n, unsigned int m)  
{  
	// invalid input  
	if(n <= 0 || m < 0)  
    	return -1;  
	// if there are only one integer in the circle initially,  
 	// of course the last remaining one is 0  
	int lastinteger = 0;  
	// find the last remaining one in the circle with n integers  
	for (int i = 2; i <= n; i++)   
     	lastinteger = (lastinteger + m) % i;  
	return lastinteger;  
}
void test()
{
	int n = 5, m = 2;
	cout << LastRemaining_Solution2(n, m) << endl;
}
int main()
{
	test();
	return 0;
}