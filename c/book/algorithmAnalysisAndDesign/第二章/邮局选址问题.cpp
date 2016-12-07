#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Point {
	double x;
	double y;
};
bool comp1(const Point x, const Point y)
{
	if(x.x != y.x) {
		return x.x < y.x;
	}
}
bool comp2(const Point x, const Point y)
{
	if(x.y != y.y) {
		return x.y < y.y;
	}
}
vector<Point> v;
int main()
{
	int n,i;
	cin >> n;
	Point p;
	for(i = 0; i < n; i++) {
		cin >> p.x >> p.y;
		v.push_back(p);//push Point p
	}
	int sum = 0;
	
	// x 坐标排序
	sort(v.begin(), v.end(), comp1);
	cout << "按x坐标排序如下：" << endl;
	for(i = 0; i < n; i++) {
		cout << v[i].x << " " << v[i].y << endl;
	}
	
	// x方向上的中位数
	p = v[n / 2];
	for(i = 0; i < n; i++) {
		sum += abs((int)(v[i].x - p.x));
	}
	
	// y 坐标排序
	sort(v.begin(), v.end(), comp2);
	cout << "按y坐标排序如下：" << endl;
	for(i = 0; i < n; i++) {
		cout << v[i].x << " " << v[i].y << endl;
	}

	// y方向上的中位数
	p = v[n / 2];
	for(i = 0; i < n; i++) {
		sum += abs((int)(v[i].y - p.y));
	}
	cout << sum << endl;
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

output:
10

*/