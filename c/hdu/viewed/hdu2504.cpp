#include <iostream>
using namespace std;
/*
	�����Լ�� 
*/
int gcd(int a, int b)
{
    while(a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}
int main()
{
    int n, a, b, c, i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        c = 2 * b;
        /*
        	c ��b�ı�����ÿ���ۼ�һ��b 
        */
        while(gcd(a, c) != b) {
            c += b;
        }
        cout<<c<<endl;
    }
    return 0;
}
/*
Sample Input
2
6 2
12 4


Sample Output
4
8

*/ 