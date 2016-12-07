#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*
	两个数通过+,-,*,/,%操作能否得出第三个数
*/
__int64 a, b, c;
int gao() {
	//除数为0re一次，用除法wa一次，加减互逆，乘除互逆，二者有一即可，这道题用除法会出问题
    if(a * b == c || a * c == b || b * c == a || a + b == c || a + c == b || b + c == a)
		return 1;
    if(a != 0)
        if(b % a == c || c % a == b)
            return 1;
    if(b != 0)
        if(a % b == c || c % b == a)
            return 1;
    if(c != 0)
        if(a % c == b || b % c == a)
            return 1;
    return 0;
}
int main()
{
    while(~scanf("%I64d%I64d%I64d", &a, &b, &c)) {
        if(gao())
            puts("oh,lucky!");
        else
            puts("what a pity!");    
    }
    return 0;
}
/*
Sample Input
1 2 3

Sample Output
oh,lucky!
*/