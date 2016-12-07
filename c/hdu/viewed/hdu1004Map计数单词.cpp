#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
	����map�ļ�ֵ�Խ���ƥ�䣬�������+1��û������ӡ�
*/
int main()
{
	map<string, int> Ballon;
	string color, MaxColor;
	int n, max;
	while(cin>>n && n) {
		Ballon.clear();

		//read the string color
		while(n--) {
			cin >> color;
			Ballon[color]++;
		}

		//To get the max counts between counts
		map<string, int>::iterator it;
		max = 0;
		//Tn = O(N)
		for(it = Ballon.begin(); it != Ballon.end(); it++) {
			if(it->second > max) {
				max = it->second;
				MaxColor = it->first;
			}
		}
		cout<<MaxColor<<endl;
	}
	return 0;
}
/*
Sample Input
5
green
red
blue
red
red
3
pink
orange
pink
0

Sample Output
red
pink
*/