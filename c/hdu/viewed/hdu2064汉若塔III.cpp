#include<stdio.h>
int main()
{
    int n, i;
    __int64 a[36];
    a[1] = 2;
    for(i = 2; i <= 35; i++) { 
        a[i] = a[i - 1] * 3 + 2;//�������һ�����ƹ�ϵ
    } 
    while(scanf("%d", &n) != EOF) { 
        printf("%I64d\n", a[n]);
    } 
    return 0;
}