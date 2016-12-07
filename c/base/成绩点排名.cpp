#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Info
{
	double score;
	char a[20];
};
bool comp(Info a, Info b)
{
	return a.score > b.score;
}
int f(double count1, int count2)
{
	double count = count1 - count2;
	if(count >= 0.5) { 
		return count2 + 1;
	} else if(count >= 0.4) {
		double cou1 = count * 10;
		int cou2 = (int) cou1;
		if(cou1 - cou2 >= 0.5) { 
			return count2 + 1;
		} else { 
			return count2;
		} 
	}
	return count2;
}
int main()
{
	int n;
	while(cin >> n) {
		vector<Info> v;
		Info info;
		v.clear();
		int i, m;
		for(i = 0; i < n; i++) {
			cin >> info.a >> info.score;
			v.push_back(info);
		}
		sort(v.begin(), v.end(), comp);
		cin >> m;
		char s[20];
		double count = n * 0.35;
		int j, num1 = (int) count, num;
		num = f(count, num1);
		for(j = 0; j < m; j++) {
			cin >> s;
			for(i = 0; i < v.size(); i++) {
				if(strcmp(v[i].a,s) == 0) {
					if(i + 1 > num) {
						cout << "No" << endl;
					} else {
						cout << i + 1 << endl;
					}
				}
			}
		}
	}
	return 0;
} 
/*
10
zhangsan 98.00
lisi 99.00 
wangwu 89.00 
dasan 88.00 
xiaosi 78.00 
liuliu 79.00 
hhah 77.00 
jisd 64.00 
ming 64.01 
da 45.00
5
wangwu
jisd
dasan
liuliu
zhangsan
*/