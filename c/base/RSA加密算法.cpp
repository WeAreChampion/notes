/*
RSA�㷨��C����ʵ��
1.��Կ�Ĳ���
(1)ѡ������ȫ�Ĵ�����p��q��
(2)����n=p��q����(n)=(p-1)(q-1)�����Ц�(n)��n��ŷ������ֵ��
(3)ѡһ����e������1<e<��(n)����gcd(��(n),e)=1��
(4)����d������de��1 mod��(n)����d��e��ģ��(n)�µĳ˷���Ԫ��
��e���(n)���أ���ģ�����֪�����ĳ˷���Ԫһ�����ڡ�
(5)��{e,n}Ϊ����Կ��{d,n}Ϊ����Կ��
2.����
����ʱ���Ƚ�����M���ش����飬ʹ��ÿ�������Ӧ��ʮ������С
��n��������ĳ���С��log(2)n��Ȼ���ÿ�����ķ��飬������
���㣺C=M^e(mod n)
3.����
�����ķ���Ľ�������Ϊ��M=C^d(mod n)
*/
#include<stdio.h>
#include<stdlib.h>
int is_prime(int);//�����ж�
int Euclid(int, int);//������Լ����֤����
int exEuclid(int, int);//��չEuclid����
int mod_ex_quick(int, int, int);//�����㷨�ӽ���

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
		if(c == '#') break;//�˳�
		else if(c == 'E')//����
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
		else if(c == 'D')//����
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

int Euclid(int a, int b)//������Լ����֤����
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
int exEuclid(int a, int b)//��չEuclid����
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
int mod_ex_quick(int a, int b, int mod)//�����㷨�ӽ���
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
int is_prime(int p)//�����ж�
{
	int a = 1, gcd;
	while(a <= 1)//����2��(p-1)�������a
		a = rand() % p;
	gcd = Euclid(p, a);
	if(gcd > 1) return 0;
	if(mod_ex_quick(a, p-1, p) == 1) return 1;
	return 0;
}