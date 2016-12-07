#include<iostream>
using namespace std;
int main()
{
	int matrix[100][100];
	int sl[100], sc[100];//每行之和与每列之和 
	int i, j, pl, pc, countL, countC;
	int n;
	while(cin >> n && n) {
		pl = pc = countL = countC = 0;//init
		for(i = 0; i < n; i++) {//init the sum of row and column
			sl[i] = 0;
			sc[i] = 0;
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				cin >> matrix[i][j];
				sl[i]+=matrix[i][j];//计算每行之和 
				sc[j] += matrix[i][j];//计算每列之和 
			}
		}
		for(i = 0; i < n; i++) {
			if(sl[i] % 2 != 0) {//每行和为奇数 
				pl = i;//记下行数 
				countL++;//记下为奇数的次数 
			}
			if(sc[i] % 2 != 0) {//每列和为奇数
				pc = i;//记下列数 
				countC++;//记下为奇数的次数 
			}
		}
		if(countL == 0 && countC == 0) {//行列和都为偶数 
			cout << "OK\n";
		} else if(countL == 1 && countC == 1) {
			//每行每列仅有一行为奇数
			//cout<<"pl="<<pl+1<<endl;
			pl = pl + 1;
			//可以交换的位置 << pl + 1 
			cout << "Change bit(" << pl << "," << pc + 1 << ")" << endl;
		} else {//否则输出不行
			cout << "Corrupt\n";
		}
	}
	return 0;
}
/*
4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 0 1 0
1 1 1 1
0 1 0 1
0
*/ 