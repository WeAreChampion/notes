/*
#include<iostream>
using namespace std;
int a[20];
int f(int i)
{
	int flag=1,k=0;
	while(i)
	{
		a[k++]=i%10;
		i=i/10;
	}
	for( i=0;i<k;i++)
		if(a[i]==4||(a[i]==2&&a[i+1]==6))
			return 0;
	return 1;
}
int main()
{
	int n,m,count;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		if(n>m)
			continue;
		count=m-n+1;
		for(int i=n;i<=m;i++)
		{
			if(f(i)==0)
				count--;
		}
		printf("%d\n",count);
	}
	return 0;
}
/*
int main()
{
	int n,m,count,k,a[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		if(n>m)
			continue;
		count=m-n+1;
		for(int i=n;i<=m;i++)
		{
			k=0;
			int flag=1;
			int ii=i;
			while(ii)
			{
				a[k]=ii%10;
				ii=ii/10;
				k++;
			}
			for(int tt=0; tt<k&&flag!=0 ;tt++)
				if((a[tt]==4)||(a[tt]==2&&a[tt+1]==6))
				{
					flag=0;
					break;
				}
			if(flag==0)
				count--;
		}
		//cout<<count<<endl;
		printf("%d\n",count);
	}
	return 0;
}
*/
//*/
///*
#include<cstdio>
#include<cstring>
#include<cstdlib>
char ch[20];
int jilishu[1000010];
void set()
{
    int i;
    jilishu[0]=0;
    for(i=1;i<=1000010;i++)
        {   jilishu[i]=jilishu[i-1];
            itoa(i,ch,10);//进制转换int value 被转换的整数，char *string
			// 转换后储存的字符数组，int radix 转换进制数，如2,8,10,16进
			// 制等函数原型char *itoa(int value, char *string, int radix); 
            if((strstr(ch,"62")!=NULL)||(strstr(ch,"4")!=NULL))
				//在ch数组中查找第一次出现字符位置
				continue;
            else 
				jilishu[i]++;
        }
}
int main()
{
    int a,b;
    set();
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int i,k=0;
        if(a==0&&b==0) break;
        printf("%d\n",jilishu[b]-jilishu[a-1]);
    }
    return 0;
}
//*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
char ch[20];
int jilishu[1000010];
void set()
{
    int i;
    jilishu[0]=0;
    for(i=1;i<=1000010;i++)
        {   jilishu[i]=jilishu[i-1];
            itoa(i,ch,10);
            if((strstr(ch,"62")!=NULL)||(strstr(ch,"4")!=NULL))
				continue;
            else 
				jilishu[i]++;
        }
}
int main()
{
    int a,b;
    set();
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int i,k=0;
        if(a==0&&b==0) break;
        printf("%d\n",jilishu[b]-jilishu[a-1]);
    }
    return 0;
}