#include<iostream>
using namespace std;
/*
1.��˷��������������
�﷨��result=polygonarea(Point *polygon,int N);
������
*polygon������ζ�������
N������ζ�����Ŀ
����ֵ����������
ע�⣺
֧���������Σ�����͹�Կ�
����ζ�������ʱ��˳ʱ��˳������
Դ����
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