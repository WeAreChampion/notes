/*
RSA算法的C语言实现
1.密钥的产生
(1)选两个安全的大素数p和q。
(2)计算n=p×q，φ(n)=(p-1)(q-1)，其中φ(n)是n的欧拉函数值。
(3)选一整数e，满足1<e<φ(n)，且gcd(φ(n),e)=1。
(4)计算d，满足de≡1 modφ(n)，即d是e在模φ(n)下的乘法逆元，
因e与φ(n)互素，由模运算可知，它的乘法逆元一定存在。
(5)以{e,n}为公开钥，{d,n}为秘密钥。
2.加密
加密时首先将明文M比特串分组，使得每个分组对应的十进制数小
于n，即分组的长度小于log(2)n。然后对每组明文分组，作加密
运算：C=M^e(mod n)
3.解密
对密文分组的解密运算为：M=C^d(mod n)
*/
#include<stdio.h>
#include<stdlib.h>
int is_prime(int);//素性判定
int Euclid(int, int);//求解最大公约数验证互素
int exEuclid(int, int);//扩展Euclid求逆
int mod_ex_quick(int, int, int);//快幂算法加解密

int main()
{
	int p, q;
	int n, fin;
	int e, d;
	int express, cipher;
	char c;
	printf("Please type in two primes p and q:\n");
	scanf("%d%d", &p, &q);
	while(!is_prime(p))
	{
		printf("p must be a prime, please type in again:");
		scanf("%d", &p);
	}
	while(!is_prime(q))
	{
		printf("q must be a prime, please type in again:");
		scanf("%d", &q);
	}
	getchar();
	n = p * q;
	fin = (p - 1) * (q - 1);
	do{
		e = rand() % fin;
	}while(Euclid(e, fin) != 1);
	d = (exEuclid(e, fin) + fin) % fin;
	while(1)
	{
		printf("Please type in 'E' to encript or 'D' to decript or '#' to exit:");
		c = getchar();
		getchar();
		if(c == '#') break;//退出
		else if(c == 'E')//加密
		{
			printf("Please type in the express:");
			while(1)
			{
				scanf("%d", &express);
				getchar();
				if(express >= n)
					printf("The express must less than n, please try again:");
				else
					break;
			}			
			printf("The cipher is: %d\n", mod_ex_quick(express, e, n));
		}
		else if(c == 'D')//解密
		{
			printf("Please type in the cipher:");
			while(1)
			{
				scanf("%d", &cipher);
				getchar();
				if(cipher >= n)
					printf("The cipher must less than n, please try again:");
				else
					break;
			}			
			printf("The express is: %d\n", mod_ex_quick(cipher, d, n));
		}
		else
			printf("Type in error!\n");
	}
	return 0;
}

int Euclid(int a, int b)//求解最大公约数验证互素
{
	int tmp;
	if(a == 0 && b == 0) return -1;
	if(a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if(a < 0) a = -a;
	if(b < 0) b = -b;
	while(b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
int exEuclid(int a, int b)//扩展Euclid求逆
{
	int m = 1, n;
	int tmp, i, k = 0, flag = 1;
	int num[100][4];
	if(a < b)
	{
		flag = 0;
		tmp = a;
		a = b;
		b = tmp;
	}
	while(a % b)
	{
		num[k][0] = a;
		num[k][1] = b;
		num[k][2] = a / b;
		num[k][3] = a % b;
		k++;
		tmp = a;
		a = b;
		b = tmp % b;
	}
	n = -num[k-1][2];
	for(i = k - 2; i >= 0; i--)
	{
		tmp = m;
		m = n;
		n = tmp - n * num[i][2];
	}
	return flag ? m : n;
}
int mod_ex_quick(int a, int b, int mod)//快幂算法加解密
{
	int result = 1;
	while(b > 0)
	{
		if(b % 2)
			result = a * result % mod;
		a = (a % mod) * (a % mod) % mod;
		b /= 2;
	}
	return result;
}
int is_prime(int p)//素性判定
{
	int a = 1, gcd;
	while(a <= 1)//产生2到(p-1)的随机数a
		a = rand() % p;
	gcd = Euclid(p, a);
	if(gcd > 1) return 0;
	if(mod_ex_quick(a, p-1, p) == 1) return 1;
	return 0;
}