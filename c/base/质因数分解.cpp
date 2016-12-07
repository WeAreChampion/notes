#include<iostream>
#include<cmath>
using namespace std;
/*
���Ȼ���i��2��ʼ��sqrt(n)��ÿһ��i��n�Գ� ,���i������n����ô�����ж�i��
i��Ϊn�������ӣ���n=n/i  ����Ϊn�����ж����ͬ�������ӣ�Ϊ�˱�����©��
ֻ�轫i-- ����������һ��ѭ����ʱ����i++������i��ֵ���䣬������2~i��ÿ
һ�������Ѿ��жϹ��Ƿ�������n�����Բ���Ҫ�ٽ�i���˵�2��ֻ����i������
�²�ѭ����ʱ��ֵ���伴�ɣ����nҲ�ᱻԼ��������Ҳ��һ�������ӣ�����
д�ɳ�����ǿ�ͷ�Ĵ��룬����Ч���� ����Ϊ���ǱȽϸߵġ���
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
�������ֽ� 
Prime[]��������������Ҫ�ﵽsqrt(n)
pn���������Ԫ�ظ���
N�����ֽ����
Rest���ֽ�����������������
����ֵ���ֽ����Ӹ���
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