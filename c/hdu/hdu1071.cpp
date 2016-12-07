#include<iostream>
using namespace std;
double x1,y1,x2,y2,x3,y3;
double f(double x,double a,double a1,double b)
{
	double s;
	s=a*x*x*x/3 - (2*a*x1+a1)*0.5*x*x + (a*x1*x1+y1-b)*x;
	return s;
}
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		double a=(y2-y1)/(x2-x1)/(x2-x1);
		double a1=(y3-y2)/(x3-x2);
		double b=y2-a1*x2;
		
		printf("%.2lf\n",f(x3,a,a1,b)-f(x2,a,a1,b));
	}
	return 0;
}