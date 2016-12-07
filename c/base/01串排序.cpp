#include<iostream>
using namespace std;
#include<string>
#include<set>
#include<algorithm>
/*
	��ά���� 
	���Ȱ��������򣬶���1�ĸ����������ASCII����.
*/
struct Comp
{
	//���ز�����������ʹ�ڲ���ʱ�Ͱ���Ӧ������ 
	bool operator()(const string s1, const string s2) {
		if(s1.length() != s2.length()) {
			return s1.length() < s2.length();
		}
		//count 1 in string s1
		int c1 = count(s1.begin(), s1.end(), '1');
		//count 1 in string s2
		int c2 = count(s2.begin(), s2.end(), '1');
		return (c1 != c2 ? c1 < c2 : s1 < s2);
	}
};
int main()
{
	multiset<string, Comp> ms;
	int n;
	while(cin>>n) {
		ms.clear();
		int i;
		string s;
		for(i=0;i<n;i++) {
			cin>>s;
			ms.insert(s);
		}
		for(multiset<string,Comp>::iterator it = ms.begin(); it != ms.end(); it++) {
			cout<<*it<<endl;
		}
	}
	return 0;
}
/*
Input:
6
100111111
00001101
1010101
1
0
1100
Output:
0
1
1100
1010101
00001101
100111111
*/