#include<iostream>
using namespace std;
#define MAX_SIZE 1001
#include<stack>
/**
	火车调度的出栈序列
*/
void test() {
	int n, target[MAX_SIZE];
	
	while(cin >> n) {
		// 初始化栈s
		stack<int> s;
		
		int A = 1, B =1;
		
		// To get the out array；出栈序列
		for(int i = 1; i <= n; i++) {
			cin >> target[i];
		}
		// 标记是否能为出栈序列
		bool ok = true;
		
		// A->当前的序号，从1开始
		// B->出栈序列target
		while(B <= n) {
			// 若相等，A == target[B]；则B->下指
			
			// 即不用入栈，直接可判断可行
			if(A == target[B]) {
				A++;
				B++;
			} else if(!s.empty() && s.top() == target[B]){// 栈非空且栈顶与target[B]相等
				// 出栈
				s.pop();
				
				// B自增
				B++;
			} else if(A <= n){// 若当前的序号比n小；入栈且自增
				s.push(A++);
			} else { // 不满足条件，跳出循环
				ok = false;
				break;
			}
		}
		
		if(ok) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
int main() {
	test();
	return 0;
}
/**
Input:
5
1 2 3 4 5

5
5 4 1 2 3

6
6 5 4 3 2 1

Output:
Yes
No
Yes
*/