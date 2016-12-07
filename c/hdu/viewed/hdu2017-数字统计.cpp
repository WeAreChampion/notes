#include<stdio.h>
#include<string.h>
int main()
{
    int n, j, i;
    scanf("%d\n", &n);
    while(n--) {
        char a[100];
        j=0;
        gets(a);
        for(i = 0; i < strlen(a); i++)
            if(a[i] >= '0' && a[i] <= '9')
                j++;
            printf("%d\n", j);
    }
}