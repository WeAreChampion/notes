#include<iostream>
using namespace std;
/*
1/1 1/2 1/3
1/2 1/1 1/2
1/3 1/2 1/1
矩阵对角线上的元素始终是1/1，对角线两边分数的分母逐个递增。
请求出这个矩阵的总和。
*/ 
int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n) {
        int i;
        double sum = 0.0;
        for(i = 1; i <= n; i++) {
            if(i == n) { 
                sum += n;
            } 
            else {
                sum += 2.0 * i / (n - i + 1);
            }    
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}
/*
Sample Input
1
2
3
4
0
Sample Output
1.00
3.00
5.67
8.83

*/