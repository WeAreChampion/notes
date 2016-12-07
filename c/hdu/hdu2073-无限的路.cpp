#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
// The sqrt(2) const
#define SQURT2 sqrt(2.0)
// The point struct
struct Point {
	int x;
	int y;
}point, pointA, pointB;
/*
	To get the distance from point pA to point pB
*/
double getDistance(Point pA, Point pB) {
	return sqrt((double)((pA.x - pB.x) * (pA.x - pB.x) + (pA.y - pB.y) * (pA.y - pB.y)));
}
/*
	To get the distance from (x1, y1) to (x2, y2);
*/
double getDistance(int x1, int y1, int x2, int y2) {
	return sqrt((double) ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
double getAbs(double value) {
	return value >= 0.0 ? value : -value;
}
/*
	To get the distance from point p to start(0, 0)
*/
double getLinkDistance(Point p) {
	//is point (0, 0)
	if(p.x == 0 && p.y == 0) {
		return 0.0;
	}
	
	//is point (0, 1)
	if(p.x == 0 && p.y == 1) {
		return 1.0;
	}
	
	// To calculate pointA to (0, 0) distance
	double sum = 1.0;
	if(p.x == 0) {// on the (0, p.y)
		// To get the distance from (0,1)->(1,0);..;(0, i)->(i,0);
		for(int i = 1; i <= p.y - 1; i++) {//on y
			sum += SQURT2 * i;
		}
		
		// To get the distance from (0,1)->(1,0);..;(0, i)->(i,0);
		for(int i = 1; i <= p.y - 1; i++) {//on y
			sum += getDistance(i, 0, 0, i + 1);
		}
		
		return sum;
	} else if(p.y == 0) {// on the (p.x, 0)
		// To get the distance from (0,1)->(1,0);..;(0, i)->(i,0);
		for(int i = 1; i <= p.x; i++) {//on y
			sum += SQURT2 * i;
		}
		
		// To get the distance from (0,1)->(1,0);..;(0, i)->(i,0);
		for(int i = 1; i <= p.x - 1; i++) {//on y
			sum += getDistance(i, 0, 0, i + 1);
		}
		
		return sum;
	} else {
		int x = p.x + p.y - 1;//point (x + y - 1, 0)
		
		// To get the distance from (0,1)->(1,0);..;(0, i)->(i,0);
		for(int i = 1; i <= x; i++) {//on y
			sum += SQURT2 * i;
		}
			
		// To get the distance from (0,1)->(1,0);..;(0, i)->(i,0);
		for(int i = 1; i <= x; i++) {//on y
			sum += getDistance(i, 0, 0, i + 1);
		}
		
		//To add the distance between (0, x + y) and (x + y, 0)
		double l = getDistance(0, p.x + p.y, p.x + p.y, 0);
		
		//利用相似三角形来求比例
		sum += (l - 1.0 * l * p.y / (p.x + p.y));
		return sum;
	}
	return sum;
}
void test() {
	int ca;
	cin >> ca;
	while(ca--) {
		cin >> pointA.x >> pointA.y;
		cin >> pointB.x >> pointB.y;
		
		double value = getAbs(getLinkDistance(pointA) - getLinkDistance(pointB));
		
		printf("%.3lf\n", value);
	}
}
int main() {
	test();
	return 0;
}
/*
Sample Input
5
0 0 0 1
0 0 1 0
2 3 3 1
99 99 9 9
5 5 5 5
 

Sample Output
1.000
2.414
10.646
54985.047
0.000

*/