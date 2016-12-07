#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	To get 1 + 2+ ... + n.
	利用&&的短路特性累加求和。
*/
int add_fun(int n, int &sum)
{
    n && add_fun(n - 1, sum);
    return (sum += n);
}
int main()
{
    int sum = 0;
    int n = 100;  
    printf("1+2+3+...+n = %d\n", add_fun(n, sum));  
    return 0;  
}  