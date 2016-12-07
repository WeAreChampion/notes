//ｈ( n ) = ( ( 4*n-2 )/( n+1 )*h( n-1 ) );


#include<stdio.h>

//*******************************
//打表卡特兰数
//第 n个 卡特兰数存在a[n]中，a[n][0]表示长度；
//注意数是倒着存的，个位是 a[n][1] 输出时注意倒过来。 
//*********************************
int a[105][100];
void ktl()
{
    int i,j,yu,len;
    a[2][0]=1;
    a[2][1]=2;
    a[1][0]=1;
    a[1][1]=1;
    len=1;
    for(i=3;i<101;i++)
    {
        yu=0;
        for(j=1;j<=len;j++)
        {
            int t=(a[i-1][j])*(4*i-2)+yu;//采用大数数组存储方式，yu表示进位 
            yu=t/10;
            a[i][j]=t%10;
        }    
        while(yu)//处理进位 
        {
            a[i][++len]=yu%10; 
            yu/=10;
        }
        for(j=len;j>=1;j--)//从 
        {
            int t=a[i][j]+yu*10;
            a[i][j]=t/(i+1);
            yu = t%(i+1);//作除法，同时处理余数 
        }        
        while(!a[i][len])
        {
            len--;
        }    
        a[i][0]=len;//存储长度 
    }    
}    
int main()
{
    ktl();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=a[n][0];i>0;i--)
        {
            printf("%d",a[n][i]);
        }    
        puts("");
    }    
    return 0;
}