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
}po[100];
/*
	To get cross value between two point
*/
int cross (Point a , Point b) {
    return a.x * b.y - a.y * b.x;
}
int main() {
    int n ;
    while ( scanf("%d",&n) , n) {
        int i ;
		
		// To scanf counts n points
        for ( i = 0 ; i < n ; i ++ ) {
            scanf("%d%d",&po[i].x,&po[i].y);
        }
        double sum = 0 ;
        for ( i = 0 ; i < n ; i ++ )
            sum += cross(po[i], po[(i + 1) % n])/2.0;
        printf("%.1lf\n", sum);
    }
    return 0;
}