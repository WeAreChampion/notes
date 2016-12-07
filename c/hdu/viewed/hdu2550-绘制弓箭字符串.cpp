#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct Info
{
	int ai;
	int bi;
};
bool comp(const Info a, const Info b)
{
	if(a.ai != b.ai) {
		return a.ai < b.ai;
	}
	return a.ai < b.ai;
}
void drawChar(int length)
{
	cout<<">+";
	for(int i = 0; i < length - 2; i++) {
		cout<<"-";
	}
	cout<<"+>"<<endl;
}
void drawLine(int n, int length)
{
	for(int i = 0; i < n; i++) {
		drawChar(length);
	}
}
void test()
{
	int ca;
	while(scanf("%d", &ca) != EOF) {
		while(ca != 0) {
			int n;
			cin>>n;
			vector<Info> v;
			v.clear(); 
			for(int i = 0; i < n; i++) {
				Info info;
				cin>>info.ai>>info.bi;
				v.push_back(info);
			}
			sort(v.begin(), v.end(), comp);
			for(int i = 0; i < n; i++) {
				drawLine(v[i].bi, v[i].ai);
				if(ca != 0) {
					cout<<endl;
				}
			}
			ca--;
		}
		
	}
}
int main()
{
	test();
	return 0;
} 
/*
Sample Input
1
4
3 4
4 5
5 6
6 7
 

Sample Output
>+-+>
>+-+>
>+-+>
>+-+>

>+--+>
>+--+>
>+--+>
>+--+>
>+--+>

>+---+>
>+---+>
>+---+>
>+---+>
>+---+>
>+---+>

>+----+>
>+----+>
>+----+>
>+----+>
>+----+>
>+----+>
>+----+>

*/