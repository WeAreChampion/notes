/*���ڸ�����m���ַ�����Ҫ������ظ�n�ε��ַ����м���
���������������һ������ʾ�ظ��Ĵ������ڶ�����ʾ�ڴ�
�ظ������м��ֲ�ͬ���ַ���
In��
5
BBA
BBA
BEA
DEC
CCF

Out:
Case 1:
1 3
2 1
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool myComp(const string &a, const string &b)
{
	if(a != b) {
		return a > b;
	} else { 
		return a > b;
	} 
}
int main()
{
	vector<string> s;
	string ss;
	int n, k = 0, i, count[200010];
	while(cin>>n) {
		int num = 1;
		for(i = 0; i < n; i++) {
			cin>>ss;
			s.push_back(ss);
			count[i] = 0;
		}
		sort(s.begin(), s.end(), myComp);
		for(i = 0; i < s.size() - 1; i++) {
			if(s[i] == s[i+1]) {
				num++;
				continue;
			}
			count[num]++;
			num = 1;
		}
		count[num]++;
		cout<<"  Case:"<<++k<<endl;
		for(i = 1; i <= n; i++) {
			if(count[i] > 0) { 
				cout<<i<<" "<<count[i]<<endl;
			} 
		}
	}
	return 0;
}