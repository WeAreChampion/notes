#include<iostream>
using namespace std;
/*
	To get max Sum.
*/
//To save the current start pos and end pos
int bStart;
int bEnd;
//To save the start pos and end pos
int start;
int end;
int maxsum(int a[], int n)//һά����Ӵ��� 
{
	int sum = -10000000, b = 0;
	int i;
	for(i = 0; i < n; i++) {
		//����ǰֵ����0�����ۼ� 
		if(b > 0) {
			b += a[i];
			//������Ӧ�����λ��i 
			bEnd = i;
		} else {
			//����ǰֵС�ڵ���0���򽫵�ǰֵa[i]���浽��ǰ����ֵ��. 
			b = a[i];
			bStart = i;
			bEnd = i;
		}
		if(b > sum) {//����ǰ����ֵ���ڱ��������ֵ���򱣴浱ǰֵΪ����ֵ 
			sum = b;
			//To save the start pos and end pos
			start = bStart;
			end = bEnd;
		}
	}
	return sum;
}
void test() {
	int array[] = {
		-1, 2, -1, 6, 8, -7, 8, -2
	};
	cout << maxsum(array, 8) << endl;
	cout << "start = " << start <<" , end = " << end << endl;
}
int main()
{
	test();
	return 0;
}