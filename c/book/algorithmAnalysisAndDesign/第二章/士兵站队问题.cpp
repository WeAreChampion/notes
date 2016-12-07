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
		
		//����ת�������洢
		vector<int> myvectorX(x, x + n);
		vector<int> myvectorY(y, y + n);
		
		// ���䰴x��������
		sort(myvectorX.begin(), myvectorX.end());
		
		// ���䰴y��������
		sort(myvectorY.begin(), myvectorY.end());
		
		// ����
		for(i = 0; i < n; i++)
			myvectorX[i] -= i;
		
		// ���䰴x��������
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