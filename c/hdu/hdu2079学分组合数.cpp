#include <iostream>
using namespace std; 
int credit[10];  
int Count[10];  
int c1[50], c2[50];  
/*
���������ѧ�ֺ�ΪN�����----ĸ����
T----�������ݶ�����
N----��ѧ����
K----ѧ������ 
credit[i]----ѧ��
Count[i]----ѧ��Ϊcredit[i]����
*/ 
int main() {  
    int T;
    cin >> T;
    while (T--) {
        int i, j, k;
        int n, K;
        cin >> n >> K;
        for (i = 1; i <= K; i++) {
            cin >> credit[i] >> Count[i];
        }
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        c1[0] = 1;
        for (i = 1; i <= K; i++) {
            for (j = 0; j <= n; j++) {
            	//���ܳ���������ѧ���������ܴ���n 
                for (k = 0; k <= Count[i] && credit[i] * k + j <= n; k++) {
                    c2[credit[i] * k + j] += c1[j];
                }
            }
            //���鸴�� c2->c1
            memcpy(c1, c2, sizeof(c1));
            //���鸳ֵ0->c2 
            memset(c2, 0, sizeof(c2));
        }
        cout << c1[n] << endl;
    }
    return 0;
}
/*
Sample Input
2
2 2
1 2
2 1
40 8
1 1
2 2
3 2
4 2
5 8
6 9
7
8 8

 

Sample Output

2
445
*/