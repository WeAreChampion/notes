///求解fac(n)%100000，其中n为大于等于3的正整数
#include<stdio.h>
#include<math.h>
long long fac_tmp[6][4]={   ///存放矩阵次幂
                    ///位置：00 01 10 11
                   {24578,78309,78309,46269},   ///32次幂%100000
                   {1597,987,987,610},  ///16次幂%100000
                   {34,21,21,13},   ///8次幂%100000
                   {5,3,3,2},   ///4次幂%100000
                   {2,1,1,1},   ///2次幂%100000
                   {1,1,1,0},   ///1次幂%100000
                   };
void fac(int);

int main()
{
    int n;
    scanf("%d",&n);
    fac(n);
    return 1;
}
void fac(int k) ///k>=3
{
    int i;
    long long t00=1,t01=1,t10=1,t11=0;  ///表示矩阵的1次幂
    long long a,b,c,d;
    k=k-3;  ///公式中是n-2次幂，(t00,t01,t10,t11)表示1次幂。所以一共减3次
    for(i=k;i>=32;i=i-32)   ///对于大于等于32的k;
    {
		//利用矩阵乘法公式求解a，b，c，d
        a=(t00*fac_tmp[0][0]+t01*fac_tmp[0][2])%100000; 
        b=(t00*fac_tmp[0][1]+t01*fac_tmp[0][3])%100000;
        c=(t10*fac_tmp[0][0]+t11*fac_tmp[0][2])%100000;
        d=(t10*fac_tmp[0][1]+t11*fac_tmp[0][3])%100000;
        t00=a;  t01=b;  t10=c;t11=d;//组成新的矩阵 
    }
    i=4;
    while(i>=0)    ///对于小于32的k(16,8,4,2,1);
    {
        if(k>=(long long)pow(2,i))  ///如果k大于某一个2的次幂
        {
			//(5-i)：矩阵的2的i次幂在数组fac_tmp中的位置为fac_tmp[5-i]
            a=(t00*fac_tmp[5-i][0]+t01*fac_tmp[5-i][2])%100000; 
            b=(t00*fac_tmp[5-i][1]+t01*fac_tmp[5-i][3])%100000;
            c=(t10*fac_tmp[5-i][0]+t11*fac_tmp[5-i][2])%100000;
            d=(t10*fac_tmp[5-i][1]+t11*fac_tmp[5-i][3])%100000;
            t00=a;  t01=b;  t10=c;t11=d;
            k=k-(int)pow(2,i);
        }
        i--;
    }
    a=(t00*2+t01*1)%100000;
    printf("%lld\n",a);
}