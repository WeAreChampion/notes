#include<iostream>
using namespace std;
int a[39],b[21],c[21];
int n;
void dfs(int j)
{
     int i;
     if(j==n&&a[1+c[n]])
      { 
            for(i=1;i<n;i++)
            	printf("%d ",c[i]);
            printf("%d",c[n]);
            printf("\n");
      }
       for(i=2;i<=n;i++)
           if(b[i]!=0&&a[c[j]+i]==1)
           {
                  c[j+1]=i;
                  b[i]=0;
                  dfs(j+1);
                  b[i]=i;
           }    
}
int main()
{
    int k;//40 以内的质数 
    a[2]=a[3]=a[5]=a[7]=a[11]=a[13]=a[17]=a[17]=a[19]=a[23]=a[29]=a[31]=a[33]=a[37]=a[39]=1;
    c[1]=1;
    for(k=1;k<=20;k++)
        b[k]=k;
    k=1;
    while(scanf("%d",&n)!=EOF)
    {
         printf("Case %d:\n",k++);  
         dfs(1);
         printf("\n");                                           
    }
    return 0;
}
/*
Input:(0<n<20)
6
8
Output: 
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/