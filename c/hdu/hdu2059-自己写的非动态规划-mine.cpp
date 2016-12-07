#include<iostream>
using namespace std;
/*
	�����������ʱ�� 
*/
double getRabbitTime(int vr, double l) {
	return l / vr;
}
/*
	����ڹ���������ʱ��
*/
double getTortoiseTime(double l, int n, int c, int t, int vt1, int vt2, int *dis) {
	double sum = 0.0;
	// ����ڹ�ŵ��ٶȴ����ڹ꿪�綯��������Ҫ��� 
	if(vt1 <= vt2) {
		return l / vt2;
	}

	// ʣ������ߵľ��� 
	double lastC = c;
	int i;
	// ѭ������n���ӵ�վ 
	for(i = 0; i < n; i++) {
		// ������һ���ӵ�վ�ľ��� 
		double s = dis[i + 1] - dis[i];
		
		double t1, t2;
		double tMin;
		// ������㹻
		if(s <= lastC) {
			//û�е����յ� 
			if(i != n - 1) {
				// �����
				t1 = s / vt2;
				
				//���
				t2 = s / vt1 + t;
				
				// To get the min
				if(t1 > t2) {//���� 
					tMin = t2;
					// �޸�ʣ�¿����ߵľ���
					lastC = c - s;
				} else {
					tMin = t1;
					// �޸�ʣ�¿����ߵľ���
					lastC = lastC - s;
				}	
			} else { //�����յ� 
				tMin = s / vt1;
			}
			
			//tMin = t1 > t2 ? t2 : t1;
		} else if(s < c) { // �����㹻 
			// ����磬�������ŵ�
			t1 = lastC / vt1 + (s - lastC) / vt2;
			
		 	//�ȳ��
			t2 = s / vt1 + t;
			if(t1 > t2) {
				tMin = t2;
				// �޸�ʣ�¿����ߵľ���
				lastC = c - s;
			} else {
				tMin = t1;
				// û����
				lastC = 0.0;
			}
			
		} else { //��ʹ��磬Ҳ��û�� 
			t1 = lastC / vt1 + (s - lastC) / vt2;
			
			//�ȳ��
			t2 = c / vt1 + t + (s - c) / vt2;
			if(t1 > t2) {
				tMin = t2;
			} else {
				tMin = t1;
			}
			// û����
			lastC = 0.0;
		}
		sum += tMin;
	}
	return sum;
}
void test() {
	
	double  l;// The length of the road
	
	int n,		//���վ�ĸ��� 
		c,		//��������ʻ�ľ��� 
		t,		//���ķ�ʱ��
		vr,		//�����ܲ����ٶ�
		vt1,	//�ڹ꿪�綯�� 
		vt2; 	//�ڹ�ŵ� 
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
		
		// ������ӻ���ʱ����ڵ����ڹ껨��ʱ�䣬���ڹ�Ӯ 
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