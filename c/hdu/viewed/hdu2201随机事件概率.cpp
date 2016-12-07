/*
	n表示共有n个乘客(包括阿波)，m表示第m个乘客
	请输出第m个乘客(除去熊猫阿波外)坐到原机票位置的概率是多少
	随机事件，每个乘客做到自己位置概率都为1/n
*/
#include<stdio.h>
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		printf("%.2lf\n", 1.0 / n);
	}
	return 0;
}
/*
Sample Input
2 1
11 3
 

Sample Output
0.50
0.09
*/