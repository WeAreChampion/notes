#include<iostream>
#include<cmath>
using namespace std;
/*
首先还是i从2开始到sqrt(n)的每一个i由n试除 ,如果i能整除n，那么不用判断i，
i必为n的质因子，将n=n/i  ，因为n可能有多个相同的质因子，为了避免遗漏，
只需将i-- ，当跳到下一步循环的时候与i++抵消，i的值不变，由于由2~i的每
一个数都已经判断过是否能整除n，所以不必要再将i回退到2，只需另i在跳到
下步循环的时候值不变即可，最后n也会被约成质数，也是一个质因子，所以
写成程序就是开头的代码，至于效率吗 我认为还是比较高的。。
*/
void display(int n) {
	for(i = 2; i <= (int)sqrt((double)n); i++) {
		if(n % i == 0 && (n /= i)) {
			printf("%d ", i--);
		}
	}
	printf("%d\n", n);
}

/*
质因数分解 
Prime[]：素数表，至少需要达到sqrt(n)
pn：素数表的元素个数
N：待分解的数
Rest：分解结果，按照升序排列
返回值：分解因子个数
*/
int reduce(int prime[], int pn, int n, int rest[])
{
	int i, k = 0;
	for(i = 0; i < pn; i++) {
		if(n == 1) {
			break;
		} 
		if(prime[i] * prime[i] > n) {
			rest[k++] = n;
			break;
		}
		while(n % prime[i] == 0) {
			n /= prime[i];
			rest[k++] = prime[i];
		}
	}
	return k;
}
int isPrime(int n)
{
	if(n < 2) { 
		return 0;
	}
	int length = (int)(sqrt(double(n)));
	for(int i = 2; i <= length; i++) {
		if(n % i == 0) { 
			return 0;
		} 
	}
	return 1;
}
int main()
{
	int i, prime[100], Max = 100, n, rest[20], count=0;
	for(i = 2; count < Max; i++) {
		if(isPrime(i)) {
			prime[count] = i;
			count++;
		}
	}
	while(cin >> n) {
		int k = reduce(prime, Max, n, rest);
		for(i = 0; i < k; i++) {
			cout << rest[i] << " ";
		}
		cout<<endl;
	}
	return 0;
}