#include<iostream>
using namespace std;
int main()
{
	int matrix[100][100];
	int sl[100], sc[100];//ÿ��֮����ÿ��֮�� 
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
				sl[i]+=matrix[i][j];//����ÿ��֮�� 
				sc[j] += matrix[i][j];//����ÿ��֮�� 
			}
		}
		for(i = 0; i < n; i++) {
			if(sl[i] % 2 != 0) {//ÿ�к�Ϊ���� 
				pl = i;//�������� 
				countL++;//����Ϊ�����Ĵ��� 
			}
			if(sc[i] % 2 != 0) {//ÿ�к�Ϊ����
				pc = i;//�������� 
				countC++;//����Ϊ�����Ĵ��� 
			}
		}
		if(countL == 0 && countC == 0) {//���кͶ�Ϊż�� 
			cout << "OK\n";
		} else if(countL == 1 && countC == 1) {
			//ÿ��ÿ�н���һ��Ϊ����
			//cout<<"pl="<<pl+1<<endl;
			pl = pl + 1;
			//���Խ�����λ�� << pl + 1 
			cout << "Change bit(" << pl << "," << pc + 1 << ")" << endl;
		} else {//�����������
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