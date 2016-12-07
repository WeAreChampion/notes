#include<iostream>
#include<cmath>
using namespace std;
double get(int x1,int y1,int x2,int y2)
{
	double s=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return s;
}
double f(double s)
{
	if(s<0)
	{
		return -s;
	}
	return s;
}
int main()
{
	int a,b,c,x,y;
	while(cin>>a>>b>>c>>x>>y)
	{
		double dis,k,x1,x2,y1,y2,d,a1,b1;
		if(a==b)//is circle 
		{
			double r=sqrt((double(c*1.0/a)));	
			dis=get(x,y,0,0);
			if(dis>=r)
			{
				printf("%.2lf\n",2*r);
				continue;
			}
			else
			{
				printf("%.2lf\n",2*dis);
				continue;
			}
		} 
		else if(a>b)//椭圆焦点在y轴上 
		{
			a1=sqrt(c*1.0/b);
			b1=sqrt(c*1.0/a);
			if(x==0)
			{
				dis=get(x,y,0,0);
				if(dis<a1)
				{
					printf("%.2lf\n",2*dis);
					continue;
				}
				else
				{
					printf("%.2lf\n",2*a1);
					continue;
				}
			}
			else
			{
				k=y*1.0/x;
				d=sqrt((double)(c/(a+k*k)));
				x1=d;
				x2=-d;
				y1=k*x1;
				y2=k*x2;
				printf("%.2lf\n",fabs(get(x1,y1,x2,y2)));
			}
		}
		else//焦点在x轴上 
		{
			b1=sqrt((double)c*1.0/b);
			a1=sqrt(c*1.0/a);
			if(x==0)
			{
				dis=get(x,y,0,0);
				if(dis<a1)
				{
					printf("%.2lf\n",2*dis);
					continue;
				}
				else
				{
					printf("%.2lf\n",2*b1);
					continue;
				}
			}
			else
			{
				k=y*1.0/x;
				d=sqrt((double)(c/(a+k*k)));
				x1=d;
				x2=-d;
				y1=k*x1;
				y2=k*x2;
				printf("%.2lf\n",fabs(get(x,y,x2,y2)-get(x,y,x1,y1)));
			}
		}
	}
	return 0;
}
/*
			if(x==0)//p in y轴上 
			{
				if(y<r)
				{
					printf("%.2lf",(double)2*y);
					continue;
				}
				else
				{
					printf("%.2lf",2*r);
					continue;
				}	
			}
			*/