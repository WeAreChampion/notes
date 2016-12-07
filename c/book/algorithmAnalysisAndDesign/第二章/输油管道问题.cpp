// TransportOil.cpp
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std ;
struct Point {
	int x ;
	int y ;
};
//改进的快速排序
void Quick_Sort(Point *p, int left, int right)
{
	int partition ;
	partition = (right - left) / 2;
	int i = left, j = right ;
	while( i < j) {
		do {
			i++ ;
		} while(p[i].y < p[partition].y) ;

		do {
			j-- ;
		} while(p[j].y > p[partition].y) ;

		if(i < j) { //将两个点进行交换
			Point temp ;
			temp = p[i] ;
			p[i] = p[j] ;
			p[j] = temp ;
		}
	}
	Quick_Sort(p, left, j) ;
	Quick_Sort(p, j + 1, right) ;
}
int main()
{
	int n, y, m, i = 1;
	cout << "请输入油井的个数: ";
	cin >> n ;
	m = n ;
	Point *p = new Point[n] ;//创建点结构体
	while(n) {
		cin >> p[i].x >> p[i].y ;
		n-- ;
		i++ ;
	}
	//对点p[]的纵坐标进行排序
	Quick_Sort(p, 1, m) ;
	　　double sum = 0 ;
	for(i = 1; i <= m / 2; i++)
		sum += fabs(p[m - i + 1].y - p[i].y) ;
	y = p[(m + 1) / 2].y ;
	cout << sum << endl;
	system("pause");
	return 0 ;
}