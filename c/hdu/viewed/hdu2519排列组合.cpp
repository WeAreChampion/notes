#include<iostream>
using namespace std;
/*
	n(n-1)...(n-m)/m! = 
	n / m * (n - 1) / (m - 1)...(n - m) /1
*/
double home(__int64 n, __int64 m)//返回类型必须是浮点型，不然会造成误差
{
    __int64 i , j;
    double sum = 1.0;
    j = m;
    while(j--) {
        sum = sum * n / m; //约分
        n--;
        m--;
    }
    return sum;
}
int main()
{
    __int64 n, m, t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        if(m > n) {
           cout << 0 << endl;
           continue;
        }
       printf("%.0lf\n", home(n, m));
	}
    return 0;
}

/*
Sample Input
5
3 2
5 3
4 4
3 6
8 0


Sample Output
3
10
1
0
1

*/