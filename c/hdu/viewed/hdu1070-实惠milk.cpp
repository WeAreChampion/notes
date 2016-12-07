#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef struct milk {
	char name[110];
	int pay;
	int vol;
	double wei;
} ML;
ML M;
/*
	排序规则
		1.先按权值大小
		2.再按体积
*/
bool cmp ( const ML &a, const ML &b )
{
	//权值，花最少的钱，喝最多的牛奶
	if ( a.wei != b.wei )
		return a.wei < b.wei;
	//体积
	return a.vol > b.vol;
}
int main ()
{
	int T;
	cin >> T;
	while ( T -- ) {
		int N;
		vector <ML> vec;
		cin >> N;
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
				
				//添加到向量中
				vec.push_back ( M );
			}
		}
		//排序
		sort ( vec.begin(), vec.end(), cmp );
		//输出第一个
		cout << vec[0].name << endl;
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