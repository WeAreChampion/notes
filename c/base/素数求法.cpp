/*
求素数的算法：
1.先从2开始找，然后删去这一范围中所有能被2整除的数。
2.找到下一个没有被删除的数字n。
3.删去这一范围中所有能整除n的数
4.如果n*n>范围最大值，就跳出，否则跳到第2步
*/
int prime[500000];
void choseprime(int n)
{
　　prime[1] = prime[0] = 1;
　　for(int i = 2; i <= (int)sqrt((double)n); i++) {
		if(prime[i] == 0) {//找到了没有被删除的数字i
	　　	for(int j = 2 * i; j <= n; j += i) { 
	　　		prime[j] = 1;	//prime数组里面值为0的是素数
			} 
	　　}
	} 
}