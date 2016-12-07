#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	��̰���㷨֮��Ʒ��������������ֵ����
	Ϊ�ˣ��Լ�ֵ���ؽ��дӸߵ����������ν�
	��ѡ��ֱ��û�пɽ�������ƷΪֹ�� 
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
	cout.precision(3);//���������Ҫ
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
		cout<<fixed<<sum<<endl;//�������
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