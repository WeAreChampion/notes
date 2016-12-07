#include<iostream>
#include<cmath>
using namespace std;
float area3(float x1,float y1,float x2,float y2,float x3,float y3)
{
	float a,b,c,p,s;
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	return s;
}
int main()
{
	float x1,y1,x2,y2,x3,y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		cout<<area3(x1,y1,x2,y2,x3,y3)<<endl;
	}
	return 0;
} 