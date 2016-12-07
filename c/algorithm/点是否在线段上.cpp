#include<iostream>
using namespace std;
struct Point {
	float x;
	float y;
};
bool isOnLine(Point p1, Point p2, Point p)
{
	// 差积是否为0，判断是否在同一直线上
	if ((p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x)*(p1.y - p.y) != 0) {
		return false;
	}
	// 判断是否在线段上, x范围
	if ((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x)) {
		return false;
	}
	// 判断是否在线段上, y范围
	if ((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y)) {
		return false;
	}
	return true;
}
void testIsOnLine() {
	Point p1 = {1L, 2L};
	Point p2 = {2L, 3L};
	Point p = {1.5L, 2.5L};
	cout << isOnLine(p1, p2, p) << endl;
	p = {2.5L, 3.5L};
	cout << isOnLine(p1, p2, p) << endl;
}
int main()
{
	testIsOnLine();
	return 0;
}