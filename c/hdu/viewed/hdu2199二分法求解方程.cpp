#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
/*
Now,given the equation 8*x^4 + 7*x^3 + 2*x^2 + 3*x + 6 == Y,
can you find its solution between 0 and 100;
二分法求解方程，通过相应的精度进行控制，判断在指定范围内是否有解
*/
double deal(double x)
{
    return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * x * x + 3 * x+6;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        double x, sum, l = 0,r = 100;
        scanf("%lf", &sum);
		//no solutions condition
        if(sum < deal(0) || sum > deal(100.0)) {
            printf("No solution!\n");
            continue;
        }
        else
        {
            double mid;
            int flg = 0;
			//精度要求.The fixed
            while(r - l > 1e-6) {
                 mid = (l + r) / 2;
                if(deal(mid) > sum)
                    r = mid;
                else
                    l = mid;
            }
            printf("%.4lf\n", r);
        }
    }
    return 0;
}
/*
Sample Input
2
100
-4
 

Sample Output
1.6152
No solution!
*/