/*
1. 题目：输入一个已经按升序排序过的数组和一个数字，
在数组中查找两个数，使得它们的和正好是输入的那
个数字。
2. 要求时间复杂度是 O(n)。如果有多对数字的和等于输
入的数字，输出任意一对即可。
3. 例如输入数组 1 、 2、 4、 7、 11 、 15 和数字15。
由于 4+11=15，因此输出 4 和 11 。
*/
#include<iostream>
using namespace std;
/*
	双向搜索，若数组中两个元素和为sum，则返回true；并
	保存两个元素值；否则返回false。 
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