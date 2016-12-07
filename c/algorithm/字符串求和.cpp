//统计[a,b]区间的1的出现的次数，0<a,b<10^8
//应该是先计算0~a之间的1的个数而后减去0~b-1之间的个数就是
//a~b之间的1出现的次数，其关键在于求0~a之间1出现的次数
/*0~197可以知道，
1。首先可以求出190~197出现的次数，而后对于0~189.190~197
中1在个位上出现了1次
2。个位考虑完后，直接考虑197/10-1，同时数字减小了，权值
会变为原来的10倍，例现在的1是原来10~19之间所有的1.*/
#include<iostream>
using namespace std;
const int N=11;
int d[N];//定义全局数组,分别存储0~9出现的次数
int value;//记录权值变化
void deal(int n)//统计1的个数
{
	if(n <= 0) {
		return;
	}
	int one, ten;
	one = n % 10;//个位
	n = n / 10;
	ten = n;//十位
	for(int i = 0; i <= one; i++) {
		d[i] += value;//将个位出现的次数统计下来
	}
	while(ten) {
		d[ten % 10] += (one + 1) * value;
		ten /= 10;
	}
	for(i = 0; i < 10; i++) {
		d[i] += value * n;
	}
	d[0] -= value;//排除第一位是0的情况
	value *= 10;//权值变为原来的10倍
	deal(n - 1);
}
int main()
{
	int a,b,i;
	while(cin>>a>>b) {
		if(a == 0 && b == 0) {
			break;
		}
		for(i = 0; i < 10; i++) {
			d[i] = 0;
		}
		if(a < b) {
			int tem = a;
			a = b;
			b = tem;
		}
		value = 1;
		deal(a);
		value = -1;//保证自己会在原来的基础上作差
		deal(b - 1);
		cout<<d[1]<<endl;
	}
	return 0;
}
/*Input:
1 10
44 497
346 542
1199 1748
1496 1403
0 0
Output:
2
185
40
666
113
*/