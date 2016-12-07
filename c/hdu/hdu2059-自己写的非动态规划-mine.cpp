#include<iostream>
using namespace std;
/*
	获得兔子所花时间 
*/
double getRabbitTime(int vr, double l) {
	return l / vr;
}
/*
	获得乌龟所花最少时间
*/
double getTortoiseTime(double l, int n, int c, int t, int vt1, int vt2, int *dis) {
	double sum = 0.0;
	// 如果乌龟脚蹬速度大于乌龟开电动车，则不需要充电 
	if(vt1 <= vt2) {
		return l / vt2;
	}

	// 剩余可以走的距离 
	double lastC = c;
	int i;
	// 循环变量n个加电站 
	for(i = 0; i < n; i++) {
		// 到达下一个加店站的距离 
		double s = dis[i + 1] - dis[i];
		
		double t1, t2;
		double tMin;
		// 如果电足够
		if(s <= lastC) {
			//没有到达终点 
			if(i != n - 1) {
				// 不充电
				t1 = s / vt2;
				
				//充电
				t2 = s / vt1 + t;
				
				// To get the min
				if(t1 > t2) {//充电后 
					tMin = t2;
					// 修改剩下可以走的距离
					lastC = c - s;
				} else {
					tMin = t1;
					// 修改剩下可以走的距离
					lastC = lastC - s;
				}	
			} else { //到达终点 
				tMin = s / vt1;
			}
			
			//tMin = t1 > t2 ? t2 : t1;
		} else if(s < c) { // 充电后足够 
			// 不充电，电用完后脚蹬
			t1 = lastC / vt1 + (s - lastC) / vt2;
			
		 	//先充电
			t2 = s / vt1 + t;
			if(t1 > t2) {
				tMin = t2;
				// 修改剩下可以走的距离
				lastC = c - s;
			} else {
				tMin = t1;
				// 没电了
				lastC = 0.0;
			}
			
		} else { //即使充电，也会没电 
			t1 = lastC / vt1 + (s - lastC) / vt2;
			
			//先充电
			t2 = c / vt1 + t + (s - c) / vt2;
			if(t1 > t2) {
				tMin = t2;
			} else {
				tMin = t1;
			}
			// 没电了
			lastC = 0.0;
		}
		sum += tMin;
	}
	return sum;
}
void test() {
	
	double  l;// The length of the road
	
	int n,		//充电站的个数 
		c,		//充电后能行驶的距离 
		t,		//充电耗费时间
		vr,		//兔子跑步的速度
		vt1,	//乌龟开电动车 
		vt2; 	//乌龟脚蹬 
	while(scanf("%lf", &l) != EOF) {
		int *dis = new int[n + 1];
		
		cin >> n >> c >> t;
		cin >> vr >> vt1 >> vt2;
		
		for(int i = 0; i < n; i++) {
			cin >> dis[i];
		}
		dis[n] = l;
		double tRabbit = getRabbitTime(vr, l);
		
		double tTortoise = getTortoiseTime(l, n, c, t, vt1, vt2, dis);
		
		cout << "tRabbit = " << tRabbit << endl;
		cout << "tTortoise = " << tTortoise << endl;
		
		// 如果兔子花的时间大于等于乌龟花的时间，则乌龟赢 
		if(tRabbit > tTortoise) {
			cout << "What a pity rabbit!" << endl;
		} else {
			cout << "Good job,rabbit!" << endl;
		}
		delete dis;
	}
	
}
int main() {
	test();
	return 0;
}
/**
Sample Input

100
3 20 5
5 8 2
10 40 60
100
3 60 5
5 8 2
10 40 60


Sample Output
Good job,rabbit!
What a pity rabbit!

*/