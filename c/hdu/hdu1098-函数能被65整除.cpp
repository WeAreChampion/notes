#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
/*
	f(x)=5*x^13+13*x^5+k*a*x给定一个整数k，看能否被65整除
	f(1) = 18 + ka;
	f(x)能被65整出，这可得出f(x)=n*65;
	即：18+ka=n*65;若该方程有整数解则说明假设成立。
	ax + by = c的方程有解的一个充要条件是：c % gcd(a, b) == 0。
	然后枚举直到(65*n-18 ) % k == 0为止。
	
	求出相应的a的值
*/
/*
	求a, b最大公约数
*/
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
/*
	Swap a and b
*/
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
/*
	判断能否整除
*/
int fun(int m, int n)
{
    if(m < n)
		swap(m, n);
    if(!(18 % gcd(m, n)))
		return 1;
	return 0;
}
int main() {
    int m;
    while(~scanf("%d", &m)) {
		
		// 能否整除
        if(fun(65, m)) {
            for(int i = 1; ; i++) {
				//能够整除
                if((i * 65 - 18) % m == 0) {
                    printf("%d\n", (i * 65 - 18) / m);
                    break;
                }
            }
        } else {
			printf("no\n");
		}
    }
    return 0;
}

/*
Sample Input
11
100
9999
 

Sample Output
22
no
43
*/