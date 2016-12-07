#include<iostream>
#include<cmath>
using namespace std;
/*
3.��ʸ����Ƕ�
�﷨��result=angle(double x1, double y1, double x2, double y2);
������
x/y1��2����ʸ��������
����ֵ�����ĽǶ�ʸ��
ע�⣺
���ؽǶ�Ϊ�����ƣ���������ʱ�뷽��Ϊ������
��Ҫmath.h
Դ����
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