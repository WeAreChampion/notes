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
	
	// x ��������
	sort(v.begin(), v.end(), comp1);
	cout << "��x�����������£�" << endl;
	for(i = 0; i < n; i++) {
		cout << v[i].x << " " << v[i].y << endl;
	}
	
	// x�����ϵ���λ��
	p = v[n / 2];
	for(i = 0; i < n; i++) {
		sum += abs((int)(v[i].x - p.x));
	}
	
	// y ��������
	sort(v.begin(), v.end(), comp2);
	cout << "��y�����������£�" << endl;
	for(i = 0; i < n; i++) {
		cout << v[i].x << " " << v[i].y << endl;
	}

	// y�����ϵ���λ��
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