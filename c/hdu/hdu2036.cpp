//area=sqrt(s*(s-a)*(s-b)*(s-c))
//���⣺֪������ι�ʽ�Ϳ���AC�ˡ�
//����ι�ʽ��0.5*|x1*y2-y1*x2+x2*y3-y2*x3+����+xn*y1-yn*x1|
//����ֵ������int�ͣ�abs��int x����float�� fabs��float x��

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,x[3],y[3];
	double sum;
	while(cin>>n&&n)
	{
		if(n>=3&&n<=100)
		{
			sum=0;
			cin>>x[0]>>y[0];
			x[2]=x[0];
			y[2]=y[0];
			while(--n)
			{
				cin>>x[1]>>y[1];
				sum+=x[0]*y[1]-x[1]*y[0];
				x[0]=x[1];
				y[0]=y[1];
			}
			sum+=x[0]*y[2]-x[2]*y[0];
			//sum+=x[1]*y[2]-x[2]*y[1];
			//sum=abs(sum);
			printf("%.1lf\n",sum/2);
		}
	}
	return 0;
}