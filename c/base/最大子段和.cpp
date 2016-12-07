#include<iostream>
using namespace std;
/*
	To get max Sum.
*/
//To save the current start pos and end pos
int bStart;
int bEnd;
//To save the start pos and end pos
int start;
int end;
int maxsum(int a[], int n)//一维最大子串和 
{
	int sum = -10000000, b = 0;
	int i;
	for(i = 0; i < n; i++) {
		//若当前值大于0，则累加 
		if(b > 0) {
			b += a[i];
			//记忆相应的最后位置i 
			bEnd = i;
		} else {
			//若当前值小于等于0，则将当前值a[i]保存到当前最优值中. 
			b = a[i];
			bStart = i;
			bEnd = i;
		}
		if(b > sum) {//若当前最优值大于保存的最优值，则保存当前值为最优值 
			sum = b;
			//To save the start pos and end pos
			start = bStart;
			end = bEnd;
		}
	}
	return sum;
}
void test() {
	int array[] = {
		-1, 2, -1, 6, 8, -7, 8, -2
	};
	cout << maxsum(array, 8) << endl;
	cout << "start = " << start <<" , end = " << end << endl;
}
int main()
{
	test();
	return 0;
}