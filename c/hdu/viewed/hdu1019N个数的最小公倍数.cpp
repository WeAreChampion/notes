/*
int gcd(int m, int n)
{
    return n ? gcd(n, m % n) : m;
}
int main()
{
    int num1, num2;
    puts("������������");
    scanf("%d %d", &num1, &num2);
    int g = gcd(num1, num2);
    printf("�����������Լ����%d,\n��С��������%d\n", g, num1 * num2 / g);
    system("PAUSE");
}
*/
/*
int f(int n, int m)
{
	for(int i = (m > n ? m : n); ; i++) { 
		if(i % n == 0 && i % m == 0) {
			return i;
		} 
	} 
}
*/
#include<iostream>
using namespace std;
int gcd(int m, int n)
{
    return n ? gcd(n, m % n) : m;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, i, a[10000], g;
		scanf("%d%d", &n, &a[0]);
		for(i = 1; i < n; i++) {
			scanf("%d", &a[i]);
			g = gcd(a[0], a[i]);
			a[0] = a[0] / g * a[i];
			//������a[0]*a[i]/g,��Ϊa[0]*a[i]����ܳ���
		}
		cout<<a[0]<<endl;
	}
	return 0;
}
/*
Sample Input
2
3 5 7 15
6 4 10296 936 1287 792 1

Sample Output
105
10296

*/
