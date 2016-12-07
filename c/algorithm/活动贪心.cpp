#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct Activity//��ṹ�� 
{
	int start;
	int end;
}activity;
//���ջ�Ľ���ʱ���С�������򣬽���ʱ����ͬ������ʼʱ���С�������� 
bool Comp(Activity a,Activity b)
{
	if(a.end!=b.end)
		return a.end<b.end;
	return a.start<b.start;
}
int GreedySelector(vector<Activity> v)
{
	int count=1;//v[0] is the first
	activity=v[0];//�洢��һ�λ��Ϣ 
	for(int i=1;i<v.size();i++)
	{
		if(v[i].start>=activity.end)//���ʼʱ��>=��һ�����ʱ�� 
		{
			activity=v[i];//change the activity
			count++;
		}
	}
	return count;//����ѡ��Ļ���� 
}
int main()
{
	int n;
	while(cin>>n)
	{
		vector<Activity> v;//����ṹ������v 
		v.clear();
		for(int i=0;i<n;i++)
		{
			cin>>activity.start>>activity.end;
			v.push_back(activity);//��ӽṹ������ 
		}
		sort(v.begin(),v.end(),Comp);//��Comp���򷽷����� 
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