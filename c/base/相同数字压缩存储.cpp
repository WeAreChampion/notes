#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(int a, int b)
{
	return a < b;
}
int main()
{
	int ca;
	cin>>ca;
	while(ca--) {
		vector<int> v;
		int n, a, i;
		cin>>n;
		v.clear();
		for(i = 0; i < n; i++) {
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(), v.end(), comp);
		/*
		for(i=0;i<n;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
		*/
		int count = 1,m = v[0], num=1;
		for(i = 1; i < n; i++) {
			if(v[i] == m) {
				count++;
			} else {
				if(num!=1){ 
					cout<<" "<<count<<" "<<m;
				} else { 
					cout<<count<<" "<<m;
				} 
				m = v[i];
				count = 1;
				num++;
			}
		}
		cout<<" "<<count<<" "<<m<<endl;
	}
	return 0;
}
/*
2
6
1 1 4 2 4 2
5
1 2 3 2 1
*/