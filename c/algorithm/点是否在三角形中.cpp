#include<iostream>
#include<cmath>
using namespace std;
#define E 1e-6
struct Point {
	float x;
	float y;
}point;

struct Triangle {
	Point p1;
	Point p2;
	Point p3;
}triangle;
/**
	To get the triangle's area
*/
float getArea(Point p1, Point p2, Point p3) {
	float result = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y) / 2;
	return result > 0 ? result : -result;
}
void testGetArea() {
	Point p1 = {0l, 0l};
	Point p2 = {0l, 1l};
	Point p3 = {3l, 2l};
	cout << getArea(p1, p2, p3) << endl;
}
/**
	To judge Point p is in triangle
*/
bool isInTriangle(Triangle t, Point p) {
	float sum = 0.0l;
	sum += getArea(t.p1, t.p2, p);
	sum += getArea(t.p1, t.p3, p);
	sum += getArea(t.p2, t.p3, p);
	
	if(fabs(sum - getArea(t.p1, t.p2, t.p3)) <= E) {
		return true;
	}
	return false;
}
void testIsInTriangle() {
	Point p1 = {0l, 0l};
	Point p2 = {0l, 1l};
	Point p3 = {3l, 2l};
	Triangle t;
	t.p1 = p1;
	t.p2 = p2;
	t.p3 = p3;
	Point p = {0l, 0l};
	cout << isInTriangle(t, p) << endl;
	
	p = {0l, 1l};
	cout << isInTriangle(t, p) << endl;
	
	p = {3l, 2l};
	cout << isInTriangle(t, p) << endl;
	
	p = {2l, 2l};
	cout << isInTriangle(t, p) << endl;
	
	p = {3l, 3l};
	cout << isInTriangle(t, p) << endl;
}
int main() {
	testGetArea();
	testIsInTriangle();
	return 0;
}