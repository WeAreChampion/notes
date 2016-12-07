#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
using namespace std;
/*
Problem Description
����N������,x1,x2...xn����ȡ����������ϵõ�|xi-xj|,(0<i,j<=N,i!=j)��
������������K�����������ĸ���һ�������Ϊ��K����ָ��K-1����ͬ�������С��������

Input
�����������Ȱ���һ��������C����ʾ����C���������.
ÿ��������ݵĵ�һ�а�����������N��K��(1<N<=1000,0<K<=2000)
����ȥһ�а���N������������x1,x2..xn��(0<=xi<=2000)
*/
//sort
int cmp(const void *x,const void *y)
{
    return (*(int *)x - *(int *)y);
}
int main()
{
    int t, a[1005], hash[2005];
    cin >> t;
    while(t--) {
        memset(a, 0, sizeof(a));
        memset(hash, 0, sizeof(hash));
        int n, k, i, j, m = 0;
        cin >> n >> k;
        //input array value
        for(i = 1; i <= n; i++) { 
        	cin >> a[i];
       	} 
        int num = 0, flag = 1;
        //sort x1,x2...xn from small to big
        qsort(a + 1, n, sizeof(int), cmp);
        for(i = 1; i < n; i++) {
            for(j =  1; i + j <= n; j++) {
            	//��ֵͬ���1 
               hash[a[i + j] - a[j]]++;//a[i + j] - a[j]������Ŀ�е�|xi-xj|
            }
        }
        int z = 0;
        //K is between [0 - 2000]
        for(int x = 0; x <= 2000; x++) {
        	//has value 
            if(hash[x]) {
                z++;//ͳ��λ��
                if(z == k) {
                    cout << x << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
/*
Sample Input
3
3 2
4 0 7
4 2
1 2 3 4
2 1
2 9
 

Sample Output
4
2
7

*/