#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct Mouse
{
	int j;
	int f;
	double a;//�洢��ֵ 
};
bool comp(const Mouse d1, const Mouse d2)
{
	if(d1.a != d2.a) {
		return d1.a > d2.a;//��a�Ӵ�С���� 
	}
	return d1.f < d2.f;//��f��С�������� 
}
int main()
{
	vector<Mouse> v;
	Mouse mouse;
	int m, n, i;
	cout.precision(3);//������� 
	double sum;
	while(cin>>m>>n) {
		if(m == -1 && n == -1) { 
			break;
		} 
		v.clear();
		sum = 0.0;
		for(i = 0; i < n; i++) {
			cin>>mouse.j>>mouse.f;
			mouse.a = mouse.j * 1.0 / mouse.f;
			v.push_back(mouse);//��ӽ������� 
		} 
		sort(v.begin(), v.end(), comp);
		for(i = 0; i < v.size(); i++) {
			if(m >= v[i].f) {//m�㹻 
				sum += v[i].j;//ֱ�ӽ��� 
				m -= v[i].f;
			} else {
				sum += m * v[i].a;//m is over,break
				break;
			}
		}
		cout<<fixed<<sum<<endl;
	} 
	return 0;
}
/*
In:
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
out:
13.333
31.500
*/ 