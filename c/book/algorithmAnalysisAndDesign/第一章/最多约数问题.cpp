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
	ͳ��Լ������
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
		cout << "Լ�����ĸ����ǣ�" << getMax(CountDiv(a), CountDiv(b)) << endl;
	}
	return 0;
}
/*
In:
1 36


out:
9
*/