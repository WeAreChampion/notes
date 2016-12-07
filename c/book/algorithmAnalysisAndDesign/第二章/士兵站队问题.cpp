#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int n, i, x[1001], y[1001] ;
	int x_sum, y_sum;
	while(cin >> n) {
		for (i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		
		//数组转换容器存储
		vector<int> myvectorX(x, x + n);
		vector<int> myvectorY(y, y + n);
		
		// 对其按x坐标排序
		sort(myvectorX.begin(), myvectorX.end());
		
		// 对其按y坐标排序
		sort(myvectorY.begin(), myvectorY.end());
		
		// 作差
		for(i = 0; i < n; i++)
			myvectorX[i] -= i;
		
		// 对其按x坐标排序
		sort(myvectorX.begin(), myvectorX.end());
		x_sum = 0;
		y_sum = 0;
		for(i = 0; i < n; i++) {
			x_sum += (int)abs(myvectorX[i] - myvectorX[n / 2]);
			y_sum += (int)abs(myvectorY[i] - myvectorY[n / 2]);
		}
		cout << (x_sum + y_sum) << endl;
	}
	return 0;
}
/*
Input:
5
1 2
2 2
1 3
3 -2
3 3

Output:
8

*/