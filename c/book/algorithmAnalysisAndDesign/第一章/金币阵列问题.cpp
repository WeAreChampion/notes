#include<iostream>
using namespace std;
/**
	��Ϸ����
	1. ÿ�ν���һ�н�ҷ�����(0->1;1->0)
	2. ÿ����ѡ���У�����
	��ӳ�ʼ״̬�任��Ŀ��״̬��Ҫ�����ٱ任����
*/

// �任�������ֵ
const int inf = 99999;
const int N = 101;
/**
	a save the start array
	b save the aim array
	temp save the current array
*/
int a[N][N], b[N][N], temp[N][N];

int n, m;
/**
	�任����
*/
int need;

/**
	����a��b
*/
int swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

/**
	��������temp array����
*/
void swapColumn(int x, int y) {
	if(x == y) {
		return;
	}
	
	// 
	for(int i = 1; i <= n; i++) {
		swap(temp[i][x], temp[i][y]);
	}
	
	// �任����+1
	need++;
}
/**
	��תtempĳһ�У�0->1;1->0����ȡ���
*/
void changeRow(int x) {
	for(int i = 1; i <= m; i++) {
		temp[x][i] ^= 1;//��1ȡ���
	}
}
/**
	�ж�Ŀ������b�ĵ�x������ʱ����temp�ĵ�y���Ƿ���ͬ
	��ͬ����true�����򷵻�false
*/
bool Same(int x, int y) {
	for(int i = 1; i <= n; i++) {
		if(b[i][x] != temp[i][y]) {
			return false;
		}
	}
	return true;
}
int main() {
	int tests;
	cin >> tests;
	while(tests--) {
		cin >> n >> m;
		int i, j;
		
		// �����ʼ�任����
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		
		// ����Ŀ��任����
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				cin >> b[i][j];//input the aim array
			}
		}
		
		// ��ʼ�任���󣬲���任����
		int k;
		
		// ��ǰ�任��������ֵ
		int ans = inf;
		
		// ö��m�б任
		for(k = 1; k <= m; k++) {
			
			// ��¼��ǰ��ʼֵ
			for(i = 1; i <= n; i++) {
				for(j = 1; j <= m; j++)
					temp[i][j] = a[i][j];
			}
			
			// ��ʼ�任����
			need = 0;
			
			// ����temp�ĵ�һ�����k�У�k from 1 to m
			swapColumn(1, k);
			
			// �Ƚϵ�һ�У�����ȣ������б任
			for(i = 1; i <= n; i++) {
				if(temp[i][1] != b[i][1]) {
					changeRow(i);
					need++;
				}
			}
			
			// ���m���Ƿ���ͬ
			bool find;
			
			// ���μ��m���Ƿ���Ŀ������b��ͬ
			for(i = 1; i <= m; i++) {
				find = false;
				
				//��Ŀ����������ж�
				if(Same(i, i)) { 
					find = true;
					continue;
				}
				
				// Ѱ��temp����b��ͬ����
				for(j = 1; j <= m; j++) {
					
					// Ŀ������ĵ�i������ʱ����ĵ�j���Ƿ���ͬ
					if(Same(i, j)) {
						// ����Ŀ������ĵ�j������ʱ����ĵ�j���Ѿ���ͬ�ˣ��򲻱任
						if(Same(j, j))
							continue;
						
						// ���б任������ҵ�����Ӧ����
						swapColumn(i, j);//������
						find = true;
						break;
					}
				}
				
				if(find == false) { //�Ҳ������ж�Ӧ����
					break;
				}
			}
			
			// �����ҵ���Ӧ�ı任��
			if(find && need < ans) {
				// ���ĵ�ǰ����ֵ
				ans = need;
			}
		}
		
		// �ܷ�任�ɹ�
		if(ans < inf) {
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
/*
Input:
2
4 3
1 0 1
0 0 0
1 1 0
1 0 1
1 0 1
1 1 1
0 1 1
1 0 1
4 3
1 0 1
0 0 0
1 0 0
1 1 1
1 1 0
1 1 1
0 1 1
1 0 1

Output:
2
-1
*/