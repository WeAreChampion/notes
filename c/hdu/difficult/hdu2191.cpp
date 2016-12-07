//应为多重背包
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Info
{
	int p;
	int h;
	int c;
	double v;
};
bool Comp(const Info a,const Info b)
{
	return a.v >b.v ;//按v从大到小排序
}
int main()
{
	int sum;
	int ca,n,m,i,k;
	vector<Info> v;
	Info info;
	cin>>ca;
	while(ca--)
	{
		sum=0;
		cin>>n>>m;
		for(i=0;i<m;i++)
		{
			cin>>info.p>>info.h>>info.c;
			info.v=info.h/info.p;
			v.push_back(info);
		}
		sort(v.begin(),v.end(),Comp);
		for(i=0;i<m;i++)
		{
			if(n>=v[i].p*v[i].c )
			{
				sum+=v[i].h*v[i].c;
				n=n-v[i].p*v[i].c;
			//	if(n==0)
					//break;
			}
			else
			{
				k=n/v[i].p;
				sum+=v[i].h*k;
				break;
			}
		}
		cout<<sum<<endl;
		//for(i=0;i<m;i++)
		//	cout<<v[i].p <<" "<<v[i].h <<endl;
	}
	return 0;
}
*/
# include<iostream>
using namespace std;
# include<cmath>
# include<cstring>
int f[105], V;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void ZeroOnePack(int cost, int weight)   //01背包
{
   	int v;
   	for(v = V; v >= cost; v--){ 
		f[v] = max(f[v - cost] + weight, f[v]);
   	} 
}

void CompletePack(int cost, int weight)   //完全背包
{
	int v;
	for(v = cost; v <= V; v++){ 
		f[v] = max(f[v - cost] + weight, f[v]);
	} 
}

void MultipelePack(int cost, int weight, int amount)  //多重背包
{
  	int k, num;
  	if(cost * amount >= V) {
     	CompletePack(cost, weight);
     	return;
  	}
  	for(k = 1; k < amount; k *= 2) {
     	ZeroOnePack(k * cost, k * weight);
     	amount = amount - k;
  	}
  	ZeroOnePack(amount * cost, amount * weight);
}

int main()
{
   	int t, i, n, cost, weight, amount;
   	cin>>t;
   	while(t--) {
      memset(f, 0, sizeof(f));
      //scanf("%d%d",&V,&n);
	  cin>>V>>n;
      for(i = 1; i <= n; i++) {
         //scanf("%d%d%d",&cost,&weight,&amount);
		 cin>>cost>>weight>>amount;
         MultipelePack(cost, weight, amount);
      }
      //printf("%d\n",f[V]);
	  cout<<f[V]<<endl;
   }
   return 0;
}
