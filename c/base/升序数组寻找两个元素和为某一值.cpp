/*
1. ��Ŀ������һ���Ѿ�������������������һ�����֣�
�������в�����������ʹ�����ǵĺ��������������
�����֡�
2. Ҫ��ʱ�临�Ӷ��� O(n)������ж�����ֵĺ͵�����
������֣��������һ�Լ��ɡ�
3. ������������ 1 �� 2�� 4�� 7�� 11 �� 15 ������15��
���� 4+11=15�������� 4 �� 11 ��
*/
#include<iostream>
using namespace std;
/*
	˫��������������������Ԫ�غ�Ϊsum���򷵻�true����
	��������Ԫ��ֵ�����򷵻�false�� 
*/ 
bool getSum(int array[], int length, int &value1, int &value2, int sum)
{
	int i = 0;
	int j = length - 1;
	while(i <= j) {
		if(array[i] + array[j] == sum) {
			value1 = array[i];
			value2 = array[j];
			return true;
		} else if(array[i] + array[j] > sum){
			j--;
		} else {
			i++;
		}
 	}
 	return false;
}
void test()
{
	int array[] = {
		1, 2, 4, 7, 11, 15
	};
	int length = 6;
	int value1, value2;
	int sum = 15;
	getSum(array, length, value1, value2, sum);
	cout << value1 << " + " << value2 << "= " << sum << endl;
}
int main()
{
	test();
	return 0;
}