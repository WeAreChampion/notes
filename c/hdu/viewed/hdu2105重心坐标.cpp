#include<iostream>
using namespace std;
/*
	输出中心坐标(x, y)
	x = (x1 + x2 + x3) * 1.0 / 3;
	y = (y1 + y2 + y3) * 1.0 / 3;
*/
int main() {
	int n;
	while(cin>>n && n) {
		while(n--) {
			double x1, y1, x2, y2, x3, y3;
			double x, y;
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			x = (x1 + x2 + x3) * 1.0 / 3;
			y = (y1 + y2 + y3) * 1.0 / 3;
			printf("%.1lf %.1lf\n", x, y);
		}
	}
	return 0;
}