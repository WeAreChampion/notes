#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	简单贪心算法之物品交换，求获得最大价值量，
	为此，对价值比重进行从高到低排序，依次进
	行选择，直到没有可交换的物品为止。 
*/
struct Info//the struct about Info
{
	int j;
	int f;
	double a;
};
bool Comp(const Info &aaa,const Info &bbb)//sort
{
	if(aaa.a != bbb.a)
		return aaa.a > bbb.a; 
	else
		return aaa.f < bbb.f;
}
int main()
{
	int m, n, jj, ff, i;
	vector<Info> v;//the vector
	Info info;
	double sum;
	cout.precision(3);//输出精度需要
	while(cin>>m>>n)
	{
		sum = 0;
		v.clear();
		if(m == -1 && n == -1)	break;
		for(i = 0; i < n; i++)
		{
			cin>>jj>>ff;
			info.j = jj;
			info.f = ff;
			info.a = jj * 1.0 / ff;//change to double
			v.push_back(info);
		}
		sort(v.begin(), v.end(), Comp);//quick sort by Comp
		for(i = 0; i < v.size(); i++)
		{
			if(m >= v[i].f)
			{
				sum += v[i].j;
				m -= v[i].f;
			}
			else
			{
				sum += m s* v[i].a;
				break;
			}
		}
		cout<<fixed<<sum<<endl;//输出精度
		//printf("%.3lf\n",sum);
	}
	return 0;
}
/*
Sample Input
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
Sample Output
13.333
31.500

*/