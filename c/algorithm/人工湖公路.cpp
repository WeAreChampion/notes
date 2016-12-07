/*
������ 
����״������һ����ѯ���޸ĸ��Ӷȶ�Ϊlog(n)�����ݽṹ����������a[1..n]��
 ��ô��ѯa[1]+...+a[n]��ʱ����log(n)���� ��������һ�����ߵ����ݽṹ��֧
 ����ʱ�޸�ĳ��Ԫ�ص�ֵ�����Ӷ�ҲΪlog(n)����


��һ������������Χ���ǳ��У���������ˮ·��������Գ��м�Ľ�ͨ
 ����½�ء�ÿһ�����ж���ֻ�������ڵĳ��н��й�·��������n�����У�
 ���������1~n����ô���i�ĳ���ֻ��i%n+1��(i-2+n)%n+1����������·
 ��������·��˫��ģ��ж๫·�ỵ�����еĻᱻ�޺á���������ѯ�ʣ�
 ĳ���������Ƿ�����໥���
 ���룺
 ��һ����������n��m���ֱ���������Ŀ��ѯ�ʴ�����������m�У�ÿһ
 ����һ����־��f���������б��x��y��
 f=0������x��y֮��Ĺ�·�õģ���x��y֮��Ĺ�·�ỵ�������x��y
 ֮��Ĺ�·�ǻ��ģ���x��y֮��Ĺ�·�ᱻ�޺á�
 f=1����ô�ʹ���ѯ��x��y֮����Ƿ��໥�ɵ�� 
input:
5 10
1 2 5
0 4 5
1 4 5
0 2 3
1 3 4
1 1 3
0 1 2
0 2 3
1 2 4
1 2 5
output:
YES
YES
YES
NO
YES
NO
*/
#include<iostream>
#include<cstring>
using namespace std;
int c[100001],ma[100001];
int lowbit(int t)//λ���� 
{
	return t&(-t);
}
void insert(int k,int d,int max)//�����޸� 
{
	while(k<=max)
	{
		c[k]+=d;
		k=k+lowbit(k);
	}
}
int getsum(int k)//������� 
{
	int t=0;
	while(k>0)
	{
		t+=c[k];
		k-=lowbit(k);
	}
	return t;
}
int main()
{
	int i,j,k,t,n;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(c,0,sizeof(c));//��ʼ������c 
		for(i=1;i<=n;i++)//��ʼ����乫·��� 
		{
			insert(i,1,n);
			ma[i]=1;//ma�����¼��ǰ��������Ƿ����һ���������� 
		}
		while(k--)
		{
			int a,b,f;
			cin>>f>>a>>b;
			if(f==0)//�����ٻ���·�������޺� 
			{
				if(a>b)
				{
					t=a;
					a=b;
					b=t;
				}
				if(b==n&&a==1)
				{
					if(ma[b]==1)
					{
						insert(b,-1,n);
						ma[b]=0;
					}
					else
					{
						insert(b,1,n);
						ma[b]=1;
					}
				}
				else
				{
					if(ma[a]==1)
					{
						insert(a,-1,n);
						ma[a]==0;
					}
					else
					{
						insert(a,1,n);
						ma[a]=1;
					}
				}
			}
			if(f==1)//ѯ���Ƿ���Ե��� 
			{
				if(a>b)
				{
					t=a;
					a=b;
					b=t;
				}
				int t1,t2,t3,t4;
				t1=getsum(a-1);
				t2=getsum(b-1);
				int flag=0;
				if(t2-t1==b-a)//�ж�˳ʱ���Ƿ���Ե��� 
				{
					flag=1;
					printf("YES\n");
				}
				if(!flag)//�ж���ʱ���Ƿ���Ե��� 
				{
					t3=getsum(n)-t2;
					if(t3+t1==n-b+a)
					{
						printf("YES\n");
						flag=1;
					}
				}
				if(!flag)
					printf("NO\n");
			}
		}	
	}
	return 0;
}