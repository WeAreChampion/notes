#include<iostream>
#include<string>
using namespace std;
/**
	������X = {x1,x2...xm}��Y = {y1,y2...yn}�������������ΪZ = {z1,z2..zk}
		1. ��xm = yn����zk = xm = yn����Zk-1��Xm-1��Yn-1�������������
		2. ��xm != yn ��zk != xm����Z��Xm-1��Y�������������
		3. ��xm != yn ��zk != yn����Z��X��Yn-1�������������

	c[i][j] ��¼����Xi��Yj������������еĳ���
	Xi = {x1,x2...xi}
	Yj = {y1,y2...yj}
	
	��̬ת�Ʒ���:
	          0                               i = 0, j = 0
	c[i][j] = c[i - 1][j - 1] + 1             i, j > 0;xi = yj
	          max{c[i][j - 1], c[i - 1][j]}   i,j > 0,xi != yj
			  
	b[i][j]��¼c[i][j] ��ֵ������һ��������õ��ģ����ڹ��������������ʱҪ�õ�
	
	          1 ������ı�ע1�õ�
	b[i][j] = 2 ������ı�ע2�õ�
	          3 ������ı�ע3�õ�
	
	c[m][n] ����¼����Xm��Yn������������еĳ��ȣ���X��Y������������еĳ���
	X��Y������������еĳ��ȼ�¼��c[m][n]��
	
	
	m   : X���еĳ���
	n   : Y���еĳ���
	*x  : X����
	*y  : Y����
	**c : ��������
	**b : ��������
	Tn = O(m * n)
*/
void LCSLength(int m, int n, char *x, char *y, int c[10][10], int b[10][10])
{
	int i, j;
	// j = 0, c[i][j] = 0;
	for(i = 1; i <= m; i++) {
		c[i][0] = 0;
	}
	
	// i = 0, c[i][j] = 0
	for(i = 1; i <= n; i++) {
		c[0][i] = 0;
	}
	
	// ����������X��Y
	for(i = 1; i <= m; i++) {
		for(j = 1; j <= n; j++) {
			
			// ��һ�ַ���
			if(x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			} else if(c[i - 1][j] >= c[i][j - 1]) {// �ڶ��з���
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			} else {// �����з���
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
}
/**
	����b[i][j]����⣬��������������������
	b[i][j] = 1ʱ����ʾXi��Yj�����������������Xi-1��Yj-1���������������β������
xi���õ��������С�
	b[i][j] = 2ʱ����ʾXi��Yj���������������Xi-1��Yj���������������ͬ
xi���õ��������С�
	b[i][j] = 3ʱ����ʾXi��Yj���������������Xi��Yj-1���������������ͬ
xi���õ��������С�
	Tn = O(m + n)
*/
void LCS(int i, int j, char *x, int b[10][10])
{
	if(i == 0 || j == 0) {
		return ;
	}
	
	// Xi-1��Yj-1���������������β������xi���õ��������С�
	if(b[i][j] == 1) {
		LCS(i - 1, j - 1, x, b);
		cout << x[i];
	} else if(b[i][j] == 2) { // Xi-1��Yj���������������ͬ
		LCS(i - 1, j, x, b);
	} else { // Xi��Yj-1���������������ͬ
		LCS(i, j - 1, x, b);
	}
}
int main()
{
	string sa, sb;
	while(cin >> sa >> sb) {
		char x[10], y[10];
		int i, m, n;
		
		// ��ʼ��x����
		for(i = 0; i < sa.size(); i++) {
			x[i + 1] = sa[i];
		}
		
		// ��ʼ��y����
		for(i = 0; i < sb.size(); i++) {
			y[i + 1] = sb[i];
		}
		int c[10][10];
		int b[10][10];
		m = sa.size();
		n = sb.size();
		LCSLength(m, n, x, y, c, b);
		cout << "the length is: " << c[m][n] << endl;
		cout << "������������ǣ�" << endl;
		LCS(m, n, x, b);
		cout << endl;
	}
	return 0;
}
/*
Input:
ABCBDAB
BDCABA

Output:
4
BCAB
*/