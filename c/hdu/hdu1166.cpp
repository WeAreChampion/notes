/*//the time limited
#include<stdio.h>
#include<string.h>
int n,j,m,a[50001],tt=1;
int main()
{
	
	scanf("%d",&n);
	while(n--)
	{
		char s[10];
		scanf("%d",&m);
		for(j=1;j<=m;j++)
			scanf("%d",&a[j]);
		scanf("%s",&s);
		printf("Case %d:\n",tt++);
		while(strcmp(s,"End")!=0)
		{
			int aa,bb,sum=0,k;
			scanf("%d%d",&aa,&bb);
			if(strcmp(s,"Query")==0)
			{	
				for(k=aa;k<=bb;k++)
					sum+=a[k];
				printf("%d\n",sum);
			}
			else if(strcmp(s,"Add")==0)
			{
				a[aa]=a[aa]+bb;
			}
			else if(strcmp(s,"Sub")==0)
			{
				a[aa]=a[aa]-bb;
			}
			scanf("%s",&s);
		}
	}
	return 0;
}
*/
/*
��void *memset(void *s,int ch,size_t n);
 �������ͣ���s��ǰn���ֽ���ch�滻������s�� ����
 memset����������һ���ڴ�������ĳ��������ֵ��
 ���ǶԽϴ�Ľṹ�������������������һ����
 �췽��[1]��
���Ҫ��һ��char a[20]���㣬һ����memset(a,0,20�� 
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
int a[50005];
int n;
int lowbit(int t)//λ����
{
	return t&(-t);
}
void insert(int t,int d)//insert,�����޸�
{
	while(t<=n)
	{
		a[t]+=d;
		t+=lowbit(t);
	}
}
long getsum(int t)//�������
{
	long  sum=0;
	while(t>0)
	{
		sum+=a[t];
		t-=lowbit(t);
	}
	return sum;
}
int main()
{
	int T,i,j,k,t;
	scanf("%d",&T);
	t=0;
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			insert(i,k);
		}
		char str[10];
		scanf("%s",str);
		printf("Case %d:\n",++t);
		while(strcmp(str,"End")!=0)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(strcmp(str,"Query")==0)
				printf("%lld\n",getsum(y)-getsum(x-1));
			else if(strcmp(str,"Add")==0)
				insert(x,y);
			else if(strcmp(str,"Sub")==0)
				insert(x,(-1)*y);
			scanf("%s",str);
		}
	}
	return 0;
}
