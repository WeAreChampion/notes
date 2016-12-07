#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point {
    int x ;
    int y ;
}po[555555];
/*
	get the value from there Point
*/
int cross(Point a , Point b ,Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
/*
	判断是凸多边形还是凹多边形
	如果地块的形状为凸多边形，返回true,否则返回false
*/
bool convex(int n) {
	/*
		For each all points and calculate the across value
	*/
    for(int i = 0 ; i < n ; i ++) {
		//is a circle
        if(cross(po[i], po[(i + 1) % n], po[(i + 2) % n]) < 0) {
            return false;
		}
	}
    return true;
}
int main() {
    int n ;
    while (cin >> n , n) {
        for (int i=0;i < n ; i ++ )
            cin >> po[i].x >> po[i].y;
        if (convex(n))
            cout<<"convex"<<endl;
        else
            cout<<"concave"<<endl;
    }
    return 0;
}
/*
Sample Input
4
0 0 1 0 1 1 0 1
0

Sample Output
convex
*/