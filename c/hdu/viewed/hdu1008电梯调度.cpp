#include<stdio.h>
#define UP 6
#define DOWN 4
#define STOP 5
/*
	电梯算法是先上到最顶端，而后再下到最顶端，依次循环.
	输入参数: n
			  n1    --- floor
		   	  n2    --- floor
		   	  ...
		   	  nn    --- floor
 	Elevator Up   ---6 seconds
 	Elevator DOWN ---4 seconds
 	Elevator STOP ---5 seconds
*/
int sum = 0;
int temp = 0;
void getTime(int floor)
{
	if(floor > temp)
	{
		sum += (floor - temp) * UP + STOP;
	}
	else
	{
		sum += (temp - floor) * DOWN + STOP;
	}
	temp = floor;
}
int main()
{
	int n, floor;
	while(scanf("%d", &n), n)
	{
		//init the value is 0
		temp = sum=0;
		while(n--)
		{
			scanf("%d", &floor);
			getTime(floor);
		}
		printf("%d\n", sum);
	}
	return 0;
}
/*
Sample Input
1 2
3 2 3 1
0
Sample Output
17
41
*/