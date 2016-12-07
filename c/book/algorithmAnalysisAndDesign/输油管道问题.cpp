#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Point
{
	double x;
	double y;
};
bool comp(const Point x, const Point y)
{
	if(x.y != y.y) {
		return x.y < y.y;
	}
	return x.y < y.y;
}
vector<Point> v;
int main()
{
	int n, i;
	cin>>n;
	Point p;
	for(i = 0; i < n; i++) {
		cin>>p.x>>p.y;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), comp);
	for(i = 0; i < n; i++) {
		cout<<v[i].x<<" "<<v[i].y<<endl;
	}
	int sum = 0;
	for(i = 0; i < n / 2; i++) {
		sum += (int)(v[n - i - 1].y - v[i].y);
	}
	cout<<sum<<endl;
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
6
*/