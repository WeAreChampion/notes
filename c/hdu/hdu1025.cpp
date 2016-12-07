/*
此题讲了资源匮乏城市与富裕城市之间建造不相交的道路，这道题是个DP题，用到了
LIS（Longest Increasing Subsequence）最长上升（不下降）子序列，它有两种算法
复杂度为O(n*logn)和O(n^2)。前者使用二分查找，后者朴素查找。它的算法大致思路：
设置两个a,b数组，a数组存储数据，b数组存储最长不降序序列。此算法关键在于设计
二分查找
*/ 
#include<stdio.h>
int dp[50005],a[50005];
int Lis(int n)
{
    int len=1,i,low,high,mid;
    dp[1]=a[1];
    for(i=2;i<=n;i++)
    {
       low=1;
       high=len;
       while(low<=high)//Binary Search
       {
           mid=(low+high)/2;
           if(a[i]>dp[mid])
               low=mid+1;
           else
               high=mid-1;
       }
       dp[low]=a[i];//insert 
       if(low>len)
           len=low;//change the length(use the length of dp[])
    }
    return len;
}
int main()
{
    int n,x,y,i,ans,k=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        ans=Lis(n);
        printf("Case %d:\n",k++);
        if(ans==1)
            printf("My king, at most 1 road can be built.\n");
        else
            printf("My king, at most %d roads can be built.\n",ans);
        printf("\n");
    }
    return 0;
}
/*
2
1 2
2 1
3
1 2
2 3
3 1
*/