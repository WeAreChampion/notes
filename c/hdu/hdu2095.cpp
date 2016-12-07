/*
5
1 2 1 2 3
3 
1 2 1
0
*/
/*
整数的异或是先把他们化成二进制，再按位异或，比如3^5,
3=011,5=101,两数按位抑或后为110，即6。几个数异或满足
交换律。2^3^2=2^2^3=0^3=3.两个相同的数异或为0，普通数
都出现了偶数次，所以他们异或后都是0，而0与那个特别的
数异或后还是那个特殊的数。
*/
#include<iostream>
using namespace std;
int main()
{
    int n, x, y;
    while(scanf("%d", &n) != EOF, n) {
         scanf("%d", &x);       
         while(--n) {
             scanf("%d", &y); 
             x = x^y;
         }
         cout << x << endl;
    }
    return 0;
}
