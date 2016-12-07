#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
	Tn = O(N),输入数据时计算权值并比较保存最小的
*/
typedef struct milk {
	string name;
	int pay;
	int vol;
	double wei;
} ML;
ML M;
int main ()
{
	int T;
	cin >> T;
	while ( T -- ) {
		int N;
		vector <ML> vec;
		cin >> N;
		
		// To save the minName
		string minName = "";
		int minVol = 0.0;
		double minWei = 99999;
		for ( int i = 0; i < N; ++ i ) {
			cin >> M.name >> M.pay >> M.vol;
			int d = 0;
	
			//保存体积，用于计算能喝多少天
			int t = M.vol;

			//每天喝200毫升，最多喝5天，即体积最多1000
			while ( t >= 200 && d <= 4 ) {
				d ++;
				t -= 200;
			}
			if(d) {
				//权值，花最少的钱，最实惠
				M.wei = M.pay * 1.0 / d;
				if(minWei > M.wei || (minWei == M.wei && minVol < M.vol)) {
					minWei = M.wei;
					minName = M.name;
					minVol = M.vol;
				}
			}
		}

		cout << minName << endl;
	}
	return 0;
}
/*
2
2
Yili 10 500
Mengniu 20 1000
4
Yili 10 500
Mengniu 20 1000
Guangming 1 199
Yanpai 40 10000
 

Sample Output
Mengniu
Mengniu
*/