#include<iostream>
#include<cmath>
using namespace std;
/*
3.两矢量间角度
语法：result=angle(double x1, double y1, double x2, double y2);
参数：
x/y1～2：两矢量的坐标
返回值：两的角度矢量
注意：
返回角度为弧度制，并且以逆时针方向为正方向
需要math.h
源程序：
*/
#define PI 3.1415926
double angle(double x1, double y1, double x2, double y2)
{
	double dtheta,theta1,theta2;
	theta1 = atan2(y1,x1);
	theta2 = atan2(y2,x2);
	dtheta = theta2 - theta1;
	while (dtheta > PI)
		dtheta -= PI*2;
	while (dtheta < -PI)
		dtheta += PI*2;
	return(dtheta);
}
int main()
{
	double x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2)
	{
		cout<<angle(x1,y1,x2,y2)<<endl;
	}
	return 0;
} 