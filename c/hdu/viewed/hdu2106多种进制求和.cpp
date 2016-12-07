#include<iostream>
#include<cmath>
using namespace std;
int sum;
//convert n(m) to sum(10)
int convert(int n, int m)
{
    int sum = 0, k = 0, a;
    while(n != 0) {
        a = n % 10;
        sum += a * pow(m, k);
        k++;
        n = n / 10;
    }
    return sum;
}
int main()
{
    int n, i;
    int aa, bb;
    while(cin >> n) {
        sum = 0;
        for(i = 0; i < n; i++) {
            scanf("%d(%d)", &aa, &bb);
            //To get the sum
            sum += convert(aa, bb);
        }
        cout << sum << endl;
    }
    return 0;
}
/*
Sample Input
3
1(2)
2(3)
3(4)

4
11(10)
11(2)
11(3)
11(4)

Sample Output
6
23
*/