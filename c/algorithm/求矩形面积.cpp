#include<iostream>
#include<cmath>
using namespace std;
double gets(double x1,double y1,double x2,double y2)
{
	return fabs((x1-x2)*(y1-y2));
}
int main()
{
	double x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2)
	{
		if(x1==0&&y1==0&&x2==0&&y2==0)
		{
			break;
		}
		printf("%.3lf\n",gets(x1,y1,x2,y2));
	}
	return 0;
} 