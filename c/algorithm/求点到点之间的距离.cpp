#include<iostream>
#include<cmath>
using namespace std;
float distance_2d(float x1,float y1,float x2,float y2)
{
	return(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
float distance_3d(float x1,float y1,float x2,float y2,float z1,float z2)
{
	return(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)));
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		float x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2;
		cout<<distance_2d(x1,y1,x2,y2)<<endl;
		cin>>x1>>y1>>x2>>y2>>x3>>y3; 
		cout<<distance_3d(x1,y1,x2,y2,x3,y3)<<endl;
	}
	return 0;
}