#include<iostream>
#include<string>
#include<vector>
#define MaxSize 10000
using namespace std;
bool visit[10000];
vector<string> va,vb;
int f(int it,string end,int length[],int ca)
{
	int sum=0,top=-1,i;
	struct stack 
	{
		string s;
		string e;
	}Stack[MaxSize];
	
	for(i=0;i<ca;i++)
	{
		if(!visit[i]&&va[it]==start)
		{
			top++;
			Stack[top].s=va[it];
			Stack[top].e=vb[it];
			visit[i]=true;
			start=Stack[top].e;
			sum+=length[i];
			if(start==end)
				return sum;
			else
				i=0;
		}
	}
	return 0;
}
int main()
{
	int ca;
	while(scanf("%d",&ca)!=-1)
	{
		string start="",end="",s1="",s2="";
		int i,length[10000];
		va.clear();
		vb.clear();
		//scanf("%s%s",&start,&end);
		cin>>start>>end;
		for(i=0;i<ca;i++)
		{
			//scanf("%s%s%d",&s1,&s2,&length[i]);
			cin>>s1>>s2>>length[i];
			va.push_back(s1);
			vb.push_back(s2);
		}
		int min=32678;
		for(i=0;i<ca;i++)
		{
			if(va[i]==start)
			{
				int t=f(i,end,length,ca);
				if(t)
				{
					if(min>t)
						min=t;
				}
			}
		}
		cout<<min<<endl;
	}
	return 0;
}