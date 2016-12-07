#include<iostream>
using namespace std;
/*
有一堆个数为 n 的石子，游戏双方轮流取石子，满足：
1. 先手不能在第一次把所有的石子取完；
2. 之后每次可以取的石子数介于1到对手刚取的石子数的2倍之间（包含1和对手刚
取的石子数的2倍）。
约定取走最后一个石子的人为赢家，求必败态。
 n = 2时输出second；     
 n = 3时也是输出second； 
 n = 4时，第一个人想获胜就必须先拿1个，这时剩余的石子数为3，此时无论第二个人
 如何取，第一个人都能赢，输出first； 
 n = 5时，first不可能获胜，因为他取2时，second直接取掉剩下的3个就会获胜，
 当他取1时，这样就变成了n为4的情形，所以输出的是second；   
 n =6时，first只要去掉1个，就可以让局势变成n为5的情形，所以输出的是first；
 n = 7时，first取掉2个，局势变成n为5的情形，故first赢，所以输出的是first；   
 n = 8时，当first取1的时候，局势变为7的情形，第二个人可赢，first取2的时候，
 局势变成n为6得到情形，也是第二个人赢，取3的时候，second直接取掉剩下的5个，
 所以n = 8时，输出的是second.
借助“Zeckendorf定理”（齐肯多夫定理）：任何正整数可以表示为若干个不连续的Fibonacci数之和。
n=12时，只要谁能使石子剩下8且此次取子没超过3就能获胜。因此可以把12看成8+4，把8看成一个站，
等价与对4进行"气喘操作"。又如13，13=8+5，5本来就是必败态，得出13也是必败态。也就是说，只
要是斐波那契数，都是必败点。
所以我们可以利用斐波那契数的公式：fib[i] = fib[i-1] + fib[i-2]，只要n是斐波那契数就输出
second。
*/
int main()
{   
    int n, fib[45]; 
    int i, flag = 0;
    fib[0] = 2;
    fib[1] = 3;
    for(i = 2; i < 45; i++)  
        fib[i] = fib[i - 1] + fib[i - 2];  
    while(cin >> n && n) {           
        flag = 0;
        for(i = 0; i < 45; i++)   
            if(fib[i] == n) {           
                cout << "Second win\n";
                flag = 1;
                break;
            }  
		if(flag == 0) {
			cout << "First win\n";
		}
    }   
    return 0;
}
/*
Sample Input
2
13
10000
0
 

Sample Output
Second win
Second win
First win
*/