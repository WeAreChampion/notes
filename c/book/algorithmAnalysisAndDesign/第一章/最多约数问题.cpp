#include<iostream>
using namespace std;
/**
	To get the max int value between a and b
*/
int getMax(int a, int b)
{
	return a > b ? a : b;
}

/**
	统计约数数量
*/
int CountDiv(int n)
{
	int count = 2, i;
	for(i = 2; i < n; i++) {
		if(n % i == 0) {
			count++;
		}
	}
	return count;
}
int main()
{
	int a, b;
	while(cin >> a >> b) {
		cout << "约数最多的个数是：" << getMax(CountDiv(a), CountDiv(b)) << endl;
	}
	return 0;
}
/*
In:
1 36


out:
9
*/