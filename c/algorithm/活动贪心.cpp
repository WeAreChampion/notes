#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct Activity//活动结构体 
{
	int start;
	int end;
}activity;
//按照活动的结束时间从小到大排序，结束时间相同，按开始时间从小到大排序 
bool Comp(Activity a,Activity b)
{
	if(a.end!=b.end)
		return a.end<b.end;
	return a.start<b.start;
}
int GreedySelector(vector<Activity> v)
{
	int count=1;//v[0] is the first
	activity=v[0];//存储上一次活动信息 
	for(int i=1;i<v.size();i++)
	{
		if(v[i].start>=activity.end)//活动开始时间>=上一活动结束时间 
		{
			activity=v[i];//change the activity
			count++;
		}
	}
	return count;//返回选择的活动数量 
}
int main()
{
	int n;
	while(cin>>n)
	{
		vector<Activity> v;//定义结构体向量v 
		v.clear();
		for(int i=0;i<n;i++)
		{
			cin>>activity.start>>activity.end;
			v.push_back(activity);//添加结构体向量 
		}
		sort(v.begin(),v.end(),Comp);//按Comp排序方法排序 
		cout<<"the max amount of avtivity is: "<<GreedySelector(v)<<endl;
	}
	return 0;
}
/*
11
2 13
3 8
6 10
5 9
8 11
12 14
0 6
1 4
8 12
3 5
5 7
*/