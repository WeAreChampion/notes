#include<iostream>
using namespace std;
/**
	产生所有排列
*/

/**
	To swap the vlaue
*/
template<class Type>
void Swap(Type &a, Type &b) {
	Type temp = a;
	a = b;
	b = temp;
}

/**
	1.构造递归调用
		1) n = 1时，唯一元素，递归结束
		2) n > 1时，所有排列是由(r1)Perm(R1), (r2)Perm(R2)...(rn)Perm(Rn)构成
			其中Ri = R - {ri}
	
	2. 在数组list[]中产生从k到m的所有排列
	
	3. 参数说明
		list[] : 需要产生排列的数组
		k : 产生排列的第一个元素的位置
		m : 产生排列的最后一个元素位置
	
	4. 递归出口
		当k=m时，此时只有一个元素，递归产生排列结束，输出解
	
*/
template<class Type>
void getPerm(Type list[], int k, int m) {
	int i;
	
	/*
		递归出口：只有一个元素
	*/
	if(k == m - 1) {
		// 输出相应的排列
		for(i = 0; i < m; i++) {
			cout << list[i];
		}
		cout << endl;
	} else {// 有多个元素
		
		// 通过递归依次产生[k, m - 1]间所有排列
		for(i = k; i < m; i++) {
			
			// 交换
			Swap(list[k], list[i]);
			
			// 递归产生k+1 - m 间的所有排列
			getPerm(list, k + 1, m);
			
			// 交换
			Swap(list[k], list[i]);
		}
	}
}
int main()
{
	int list[10];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> list[i];
	}
	getPerm(list, 0, n);
	return 0;
}
/*
Input:
3
1 2 3

*/