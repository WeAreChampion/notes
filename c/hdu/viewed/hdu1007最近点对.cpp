/*
	求n个点中距离最近的两个点间的距离,可以当做模板用来做题了,
这个算法<<算法导论>>的第33章第四节--寻找最近点对中有介绍.
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct node {
	double x, y;
} point[100000]; //point
int n;
/*
	To sort by the x, if x is equal then sort by y.
*/
bool cal_less(node p1, node p2)
{
	if(p1.x != p2.x)
		return p1.x < p2.x;
	else
		return p1.y < p2.y;
}
/*
	To get the distance	between one point and the other point
*/
double dist(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
/*
	To get the min distance from two distance
*/
double getmin(double a, double b)
{
	return a < b ? a : b;
}
/*
	To get the result by divide and conquer
*/
double solve(int l, int r)
{
	//If there is one point then return a max_value
	if(l == r)
		return 1000000000;
	
	//If there are two point then calculate the distance and return the distance.
	if(l == r - 1)
		return dist(point[l], point[r]);
	
	//If there are there point then calculate the distance and return the min distance.
	if(l == r - 2)
		return getmin(getmin(dist(point[l], point[l + 1]), dist(point[l + 1], point[l + 2])), dist(point[l], point[l + 2]));
	
	//mid = (l + r) / 2
	int i, j, mid = (l + r) >> 1;
	
	//get min from the [l, mid] and [mid + 1, r];
	double curmin = getmin(solve(l, mid), solve(mid + 1, r));
	for(i = l; i <= r; i++) {
		//最多不超过6个点
		for(j = i + 1; j <= i + 5 && j <= r; j++) {
			curmin = getmin(curmin, dist(point[i], point[j]));
		}
	}
	return curmin;
}
int main()
{
	int i;
	while(scanf("%d", &n) != EOF && n) {
		for(i = 0; i < n; i++)
			scanf("%lf %lf", &point[i].x, &point[i].y);//input the point
		
		sort(point, point + n, cal_less);//quick sort
		
		double ans = solve(0, n - 1);
		printf("%.2lf\n", ans / 2);//output the min distence
	}
	return 0;
}
/*
2
0 0
1 1
2
1 1
1 1
3
-1.5 0
0 0
0 1.5
0
*/