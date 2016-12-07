#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
/*
	�ظ�Ԫ���������⣬�����۽�����Ԫ���Ƿ�����ǰ���ֹ�
	����˵���Ѿ��Ź��������ǣ����������.
*/
/**
	����������ϵ�����
*/
long long ans;
/**
	�ж��ַ�����ǰ��Ľ����ַ��Ƿ���֣� ���������д����ظ���
	�������в��ظ������ж�[a-(b - 1)]֮����ַ������Ƿ���ֹ�
	��ͬ���ַ���
	char str[]  : ��Ҫ�������е��ַ�����
	int a  		: ���еĳ�ʼλ��
	int b  		: ���еĽ���λ��

	���ַ���0�����������Ѿ�����������Ҫ���²�����ͬ�����У����򷵻�1.
*/
int ok(char str[], int a, int b )
{
	// �������
	if(b > a) {

		// �ж��ַ��Ƿ����a~b-1��
		for(int i = a; i < b; i++) {
			if(str[i] == str[b]) {
				return 0;
			}
		}
	}
	return 1;
}
/**
	�������з��ظ�Ԫ�ص�����
	char str[]  : ��Ҫ�������е��ַ�����
	int k  		: �������еĳ�ʼλ��
	int m  		: �������еĽ���λ��
*/
void perm(char str[], int k, int m)
{
	int i;

	// �ݹ����
	if(k == m) {

		// �ۼ�
		ans++;

		// ������
		for(i = 0; i <= m; i++)
			printf("%c", str[i]);
		printf("\n");
		return ;
	} else {
		
		// ����k~m֮�����������
		for(i = k; i <= m; i++)
			// Ҫ������Ԫ����ǰ��δʹ��
			if(ok(str, k, i)) {
				
				// ����
				swap(str[k], str[i]);
				
				// �ݹ����k+1~m֮�����������
				perm(str, k + 1, m);
				
				// ����
				swap(str[k], str[i]);
			}
	}
}
int main()
{
	char str[505];
	int n, i;
	scanf("%d", &n);
	getchar();
	ans = 0;
	for(i = 0; i < n; i++)
		scanf("%c", &str[i]);
	
	// ����0 ~ n-1֮������з��ظ�Ԫ�ص�����
	perm(str, 0, n - 1) ;
	printf("%lld\n", ans);
	return 0;
}
/*
Input:
4
aacc

Output:
aacc
acac
acca
caac
caca
ccaa
6
*/