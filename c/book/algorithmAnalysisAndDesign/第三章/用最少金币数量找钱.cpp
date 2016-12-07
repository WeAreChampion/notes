#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
	使用最少的金币数量找钱：贪心算法的运用.
*/
struct Info {
	int value;
	int count;
};
bool comp(const Info a, const Info b)//sort way
{
	return a.value > b.value;
}
void Disp(vector<Info> v)//display
{
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].value << " " << v[i].count << endl;
	}
}
int main()
{
	int n, i, k, m;
	while(cin >> n) {
		Info info;
		vector<Info> v;
		v.clear();
		for(i = 0; i < n; i++) {
			cin >> info.value >> info.count;
			v.push_back(info);
		}
		cin >> m;
		sort(v.begin(), v.end(), comp);//sort
		Disp(v);
		int count = 0;
		for(i = 0; i < v.size(); i++) {
			k = m / v[i].value;			//get
			if(k <= v[i].count) {	//compare
				count += k;			//count
				m -= v[i].value * k;	//reduce m
			} else {
				count += v[i].count;	//count
				m -= v[i].value * v[i].count;//reduce m
			}
			if(m <= 0) {
				break;
			}
		}
		cout << count << endl;
	}
	return 0;
}
/*
Input:
3
1 3
2 3
5 3
18

output:
5
*/