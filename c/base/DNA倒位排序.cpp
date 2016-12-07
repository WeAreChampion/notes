#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
就是字符串中每个字符与它右边的字符相比，
逆序的次数，即倒位序排序 
*/
bool comp(const string s1, const string s2)
{
	int i, j, k, n, m;
	int c1 = 0, c2 = 0;
	for(i = 0; i < s1.size(); i++) {
		for(j = i + 1; j < s1.size(); j++) {
			if(s1[i] > s1[j]) {//count s1 的倒位数
				c1++;
			}
		}
	}
	for(i = 0; i < s2.size(); i++) {
		for(j = i + 1; j < s2.size(); j++) {
			if(s2[i] > s2[j]) {//count s2 的倒位数
				c2++;
			}
		}
	}
	if(c1 != c2) { 
		return c1 < c2;
	} 
	return c1 < c2; //按从小到大排序 
}
int main()
{
	string s;
	vector<string> v;
	int n, a, b, i, j, k, p = 0;
	cin>>n;
	for(i = 0; i < n; i++) {//case
		cin>>a>>b;
		v.clear();
		p++;
		for(j = 0; j < b; j++) {
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(), comp);//sort 
		if(p != 1) {
			cout<<endl;
		}
		for(k = 0; k < v.size(); k++) {
			cout<<v[k]<<endl;
		}
	}
	return 0;
}
/*
input:
1
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
output: 
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA
*/