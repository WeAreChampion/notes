#include<iostream>
using namespace std;
#define N 11

/**
	To save the counts about number 0-9
	d[i] 即a与b之间i的个数(i 在0-9之间)
*/
int d[N];

/**
	To record the weight change
	权值，若为1，则进行加法；为-1，进行减法
*/
int value;

/**
	To counts one from 1 to n
*/
void countsOne(int n)
{
	//递归出口
	if( n <= 0) {
		return;
	}
	// To save the 个位(number % 10) and 高位(number / 10);
	int one, ten;

	one = n % 10;

	//高位(number / 10)
	n = n / 10;

	ten = n;

	// 个位数出现进行统计
	for(int i = 0; i <= one; i++) {
		d[i] += value;
	}

	//处理高位
	while(ten) {
		/**
			新的低位即个位进行统计，如为6，则有0-6个数，这里有one+1个数
		*/
		d[ten % 10] += (one + 1) * value;
		
		//每次除以10进行统计
		ten /= 10;
	}
	
	/**
		n = 197->n = 19, one = 7;
		个位为1的个数0-197，个位为1的共有1-19共19个
	*/
	for(int i = 0; i < 10; i++) {
		d[i] +=value * n;
	}

	//第一位是0的情况排除
	d[0] -= value;

	//权值变为原来的10倍
	value *= 10;

	countsOne(n - 1);
}
void testCountsOne()
{
	int m, n;
	while(cin >> m >> n) {
		int small = m;
		int big = m;

		//To change the small and big value
		if(m > n) {
			small = n;
		} else {
			big = n;
		}

		// To init array d
		for(int i = 0; i < 10; i++) {
			d[i] = 0;
		}

		value = 1;
		countsOne(big);


		value = -1;
		countsOne(small - 1);

		//输出d[1]即1的个数
		cout << "counts 1 : " << d[1] << endl;
		
		//输出d[2]即2的个数
		cout << "counts 1 : " << d[2] << endl;
	}
}
int main()
{
	testCountsOne();
	return 0;
}
/*
Input:
1 10
44 497

Output:
2
185

*/