#include<iostream>
#define Pi 3.1415927
using namespace std;
/*
首先应该知道商为定值的两个量成正比例，积为定值的两个量成反比例。
设一定的距离是s，车轮直径是d，车轮半径是r，转动圈数是n。
根据直径和半径关系有d=2r，即r=d/2。
车轮转一圈所走路程为车轮的周长，就是2πr，也就是πd。
车轮要转动n圈才走s距离，所以nπd=s。
距离一定，所以s是定值，所以nd=s/π也是定值。
因此n和d的积是定值，说明它们是反比例关系。
即车轮的直径和它转动的圈数组成比例，成反比例
*/
int main()
{
	double d, c, t;
	double sum, v;
	int j = 0;
	while(scanf("%lf%lf%lf", &d, &c, &t) != EOF) {
		if(c == 0){
			break;
		}
		sum = (Pi * d * c) / (12 * 5280);
		v = 1.0 * (sum * 60 * 60) / t;
		printf("Trip #%d: %.2lf %.2lf\n",++j, sum, v);
	}
	return 0;

}
/*
Sample Input
26 1000 5
27.25 873234 3000
26 0 1000
 

Sample Output
Trip #1: 1.29 928.20
Trip #2: 1179.86 1415.84

*/