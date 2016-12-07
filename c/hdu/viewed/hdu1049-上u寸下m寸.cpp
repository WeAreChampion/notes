#include <iostream>
using namespace std;
/*
	长度为20寸，上u寸/s，下落d寸/s， 求时间
*/
int n,u,d;
int height;
int _time;
int main() {
	while(cin >> n >> u >> d) {
		if((n && u && d) == 0) {
			break;
		}
		height = 0;
		_time = 0;
		while(height < n) {
			height += u;
			_time++;
			if(height >= n) {
				cout << _time << endl;
				break;
			}
			
			//下落
			height -= d;
			_time++;
		}
	}
	return 0;
}
/*
Sample Input
10 2 1
20 3 1
0 0 0
 

Sample Output
17
19

*/