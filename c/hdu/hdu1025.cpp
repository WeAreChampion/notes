/*
���⽲����Դ�ѷ������븻ԣ����֮�佨�첻�ཻ�ĵ�·��������Ǹ�DP�⣬�õ���
LIS��Longest Increasing Subsequence������������½��������У����������㷨
���Ӷ�ΪO(n*logn)��O(n^2)��ǰ��ʹ�ö��ֲ��ң��������ز��ҡ������㷨����˼·��
��������a,b���飬a����洢���ݣ�b����洢����������С����㷨�ؼ��������
���ֲ���
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