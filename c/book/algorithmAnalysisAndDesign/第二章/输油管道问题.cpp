// TransportOil.cpp
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std ;
struct Point {
	int x ;
	int y ;
};
//�Ľ��Ŀ�������
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

		if(i < j) { //����������н���
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
	cout << "�������;��ĸ���: ";
	cin >> n ;
	m = n ;
	Point *p = new Point[n] ;//������ṹ��
	while(n) {
		cin >> p[i].x >> p[i].y ;
		n-- ;
		i++ ;
	}
	//�Ե�p[]���������������
	Quick_Sort(p, 1, m) ;
	����double sum = 0 ;
	for(i = 1; i <= m / 2; i++)
		sum += fabs(p[m - i + 1].y - p[i].y) ;
	y = p[(m + 1) / 2].y ;
	cout << sum << endl;
	system("pause");
	return 0 ;
}