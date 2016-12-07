/*
问题描述：在经典汉诺塔的基础上加一个条件，即，如果再加一根柱子
（即现在有四根柱子a,b,c,d)，计算将n个盘从第一根柱子
(a)全部移到最后一根柱子(d)上所需的最少步数，当然，
也不能够出现大的盘子放在小的盘子上面。注：1<=n<=64;
分析：设F[n]为所求的最小步数，显然，当n=1时，F[n]=1;
当n=2时，F[n]=3;如同经典汉诺塔一样，我们将移完盘子的任务分为三步：
（1）将x(1<=x<=n)个盘从a柱依靠b,d柱移到c柱，这个过程需要的步数为F[x];
（2）将a柱上剩下的n-x个盘依靠b柱移到d柱（注：此时不能够依靠c柱，
因为c柱上的所有盘都比a柱上的盘小）些时移动方式相当于是一个经典汉诺塔，
即这个过程需要的步数为2^(n-x)-1（证明见再议汉诺塔一）；
（3）将c柱上的x个盘依靠a,b柱移到d柱上，这个过程需要的步数为F[x];
第（3）步结束后任务完成。
故完成任务所需要的总的步数F[n]=F[x]+2^(n-x)-1+F[x]=2*F[x]+2^(n-x)-1;
但这还没有达到要求，题目中要求的是求最少的步数，
易知上式，随着x的不同取值，对于同一个n，
也会得出不同的F[n]。即实际该问题的答案应该min{2*F[x]+2^(n-x)-1},
其中1<=x<=n;在用高级语言实现该算法的过程中，我们可以用循环的方式，
遍历x的各个取值，并用一个标记变量min记录x的各个取值中F[n]的最小值。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int INF = 99999999;
int f[65];
void Init(){
    f[1] = 1; f[2] = 3;
	for(int i = 3; i < 65; i++){
		int minx = INF;
        for(int x = 1; x < i; x++)
            if(2 * f[x] + pow(2.0, i - x) - 1 < minx)
                minx = 2 * f[x] + pow(2.0, i - x) - 1;

        /*写成下面这样就错了,估计是tmp溢出了
        for(int x=1;x<i;x++){
            int tmp=2*f[x]+pow(2.0,i-x)-1;
            if(tmp<minx)
                minx=tmp;
        }
        */
        f[i] = minx;
    }
}
int main(){

    int n;
    Init();
    while(~scanf("%d", &n)){
        printf("%d\n", f[n]);
    }
    return 0;
}
/*
Sample Input
1
3
12

Sample Output
1
5
81
*/