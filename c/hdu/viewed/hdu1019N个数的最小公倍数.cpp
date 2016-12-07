/*
int gcd(int m, int n)
{
    return n ? gcd(n, m % n) : m;
}
int main()
{
    int num1, num2;
    puts("请输入两个数");
    scanf("%d %d", &num1, &num2);
    int g = gcd(num1, num2);
    printf("两个数的最大公约数是%d,\n最小公倍数是%d\n", g, num1 * num2 / g);
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
			//不能是a[0]*a[i]/g,因为a[0]*a[i]其可能出界
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
