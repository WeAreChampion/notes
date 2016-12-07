#include<iostream>
using namespace std;
/*
1.叉乘法求任意多边形面积
语法：result=polygonarea(Point *polygon,int N);
参数：
*polygon：多变形顶点数组
N：多边形顶点数目
返回值：多边形面积
注意：
支持任意多边形，凹、凸皆可
多边形顶点输入时按顺时针顺序排列
源程序：
*/
typedef struct {
double x,y;
} Point;
double polygonarea(Point *polygon,int N)
{
	int i,j;
	double area = 0;
	for (i=0;i<N;i++) 
	{
		j = (i + 1) % N;
		area += polygon[i].x * polygon[j].y;
		area -= polygon[i].y * polygon[j].x;
	}
	area /= 2;
	return(area < 0 ? -area : area);
}
int main()
{
	int n;
	while(cin>>n)
	{
		int i;
		Point point[100];
		for(i=0;i<n;i++)
		{
			cin>>point[i].x>>point[i].y;
		}
		cout<<polygonarea(point,n)<<endl;
	}
	return 0;
}