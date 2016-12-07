/* 
     有如下方程：Ai = (Ai-1 + Ai+1)/2 - Ci (i = 1, 2, 3, .... n).
     若给出A0, An+1, 和 C1, C2, .....Cn.
     请编程计算A1 = ?
     因为：Ai=(Ai-1+Ai+1)/2 - Ci,

          A1=(A0  +  A2)/2 - C1; 
          A2=(A1  +  A3)/2 - C2 , ... 
    =>    A1+A2 = (A0+A2+A1+A3)/2 - (C1+C2)

          2[(A1+A2)+(C1+C2)] = A0+A2+A1+A3; 
          A1+A2 = A0+A3 - 2(C1+C2); 
    =>    A1+A2 =  A0+A3 - 2(C1+C2)  
    同理可得： 
          A1+A1 =  A0+A2 - 2(C1)  
          A1+A2 =  A0+A3 - 2(C1+C2) 
          A1+A3 =  A0+A4 - 2(C1+C2+C3) 
          A1+A4 =  A0+A5 - 2(C1+C2+C3+C4) 
          ... 
          A1+An = A0+An+1 - 2(C1+C2+...+Cn) 
    ----------------------------------------------------- 左右求和 
         (n+1)A1+(A2+A3+...+An) = nA0 +(A2+A3+...+An) + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn) 
      
    =>   (n+1)A1 = nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn) 
      
    =>   A1 = [nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)]/(n+1) 
*/
#include<iostream>
#include<cstdio>
using namespace std;   
const int maxn = 3003;  
double a[maxn], c[maxn];  
int main() {
	int n, i, j;
	while (scanf("%d", &n) == 1) {
		scanf("%lf%lf", &a[0], &a[n + 1]);
     	for (i = 1; i <= n; i++) {
        	scanf("%lf", &c[i]);
     	}  
  		a[1] = n * a[0] + a[n + 1];
		double sum = 0;
  		for (i = n, j = 1; i >= 1 && j <= n; j++, i--) {
         	sum += i * c[j];
       	}
      	a[1] = (a[1] - 2 * sum) / (n + 1);
     	printf("%.2lf\n", a[1]);
	}
	return 0;
}
/**

Sample Input
1
50.00
25.00
10.00
2
50.00
25.00
10.00
20.00

 
Sample Output
27.50
15.00
*/