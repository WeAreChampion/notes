/*
A number sequence is defined as follows:
f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
Given A, B, and n, you are to calculate the value of f(n).
�ҹ��ɣ����ظ����֣��������ڡ�
����û���Ż��Ļ�����ʱ���ڴ�ȵ��Ǳ��ⲻ�˵��ˡ�
�������Ȼ��һ���ҹ��ɵ���Ŀ��Ҳ���Ǹ�������
���Ǵ���ѭ���ڵġ�
���ڹ�ʽ f[n] = A * f[n-1] + B * f[n-2]; ����
ֻ��7 * 7 = 49 �ֿ��ܣ�Ϊʲô��ô˵����Ϊ����
f[n-1] ���� f[n-2] ��ȡֵֻ�� 0,1,2,3,4,5,6
��7������A��B���ǹ̶��ģ����Ծ�ֻ��49�ֿ���ֵ
�ˡ��ɸù�ϵʽ��֪ÿһ��ֻ��ǰ�������ϵ����
�Ե�������������ǰ����ֹ�ѭ���ڳ����ˣ�ע��ѭ
���ڲ���һ�����ǿ�ʼ�� 1��1 �� ����Ϊһ�����
������f[n]ֻ��49�п��ܵĴ𰸣�������������
������������ˣ���ô��Ҳ����50�������в���ѭ����
���ҵ�ѭ���ں󣬾Ϳ������ɽ���ˡ�
*/
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int rec[60];
int main()
{
	int a, b, n;
	rec[0] = rec[1] = rec[2] = 1;
	while(scanf( "%d %d %d", &a, &b, &n ), a | b | n) {
		int beg, end, flag = 0;
		for(int i = 3; i <= n && !flag; ++i) {
			//To calculate f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7
			rec[i] = ( a * rec[i - 1] + b * rec[i - 2] ) % 7;
			//��ǰѰ��ֵ���������ظ������
			for(int j = 2; j <= i - 1; ++j) {
				if(rec[i] == rec[j] && rec[i - 1] == rec[j - 1]) {
					beg = j, end = i;
					flag = 1;
					break;
				}
			}
		}
		//The circle is end - beg
		if(flag) {
			printf("%d\n", rec[beg + (n - end) % (end - beg)]);
		} else {
			printf("%d\n", rec[n]);
		}
	}
	return 0;
}
/*
Sample Input
1 1 3
1 2 10
0 0 0

Sample Output
2
5

*/