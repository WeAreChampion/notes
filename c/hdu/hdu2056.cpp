//自己的有问题
#include<iostream>
using namespace std;
int main()
{
	float x1,x2,x3,x4,y1,y2,y3,y4,a;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		if((x1!=y1)||(x2!=y2)||(x3!=y3)||(x4!=y4)) continue;
		if(x1>x2)
		{
			float temp=x1;
			x1=x2;
			x2=temp;
		}
		if(x3>x4)
		{
			float temp=x3;
			x3=x4;
			x4=temp;
		}
		if(x3<x1&&x1<x2&&x2<x4)
			a=(x2-x1)*(x2-x1);
		else if(x1<x3&&x3<x2&&x2<x4)
			a=(x2-x3)*(x2-x3);
		else if(x3<x1&&x1<x4&&x4<x2)
			a=(x4-x1)*(x4-x1);
		else if(x1<x3&&x3<x4&&x4<x2)
			a=(x4-x3)*(x4-x3);
		else a=0;
		if(a<0)	a=0;
		printf("%.2f\n",a);
	}
	return 0;
}
/*
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
 double x1,y1,x2,y2,x3,y3,x4,y4;
 double x[4],y[4];
 double s,l,h;
 while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
 {
  x[0]=x1;x[1]=x2;x[2]=x3;x[3]=x4;
  y[0]=y1;y[1]=y2;y[2]=y3;y[3]=y4;
  sort(x,x+4);
  sort(y,y+4);
  l=fabs(x2-x1)+fabs(x4-x3)-(x[3]-x[0]);
  h=fabs(y2-y1)+fabs(y4-y3)-(y[3]-y[0]);
  s=l*h;
  if(l<=0 || h<=0)s=0.00;
  printf("%.2lf\n",s);

}
 return 0;
}
#include<stdio.h>
double max(double a,double b)
{
 if(a>b)
  return a;
 else
  return b;
}
double min(double a,double b)
{
 if(a<b)
  return a;
 else
  return b;
}
int main()
{
   double x1,y1,x2,y2,x3,y3,x4,y4,t;
   while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
   {
   if(x1>x2)
   {t=x1;x1=x2;x2=t;}
   if(y1>y2)
   {t=y1;y1=y2;y2=t;}
   if(x3>x4)
   {t=x3;x3=x4;x4=t;}
   if(y3>y4)
   {t=y3;y3=y4;y4=t;}
   x1=max(x1,x3);
   y1=max(y1,y3);
   x2=min(x2,x4);
   y2=min(y2,y4);
   printf("%.2lf\n",x1>x2||y1>y2?0:(x2-x1)*(y2-y1));
   }
   return 0;
}



*/