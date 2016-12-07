#include<iostream>
using namespace std;
#include<queue>
/**
	当至少还剩两张牌执行以下操作：
		把第一张牌扔掉，然后把新的第一张放到整叠牌的最后。
	输出扔掉的牌顺序。
*/
void test()
{
	queue<int> q;
	int n;
	while(cin >> n) {
		
		// To init the queue
		for(int i = 1; i <= n; i++) {
			q.push(i);
		}
		
		while(!q.empty()) {
			// To print the front info
			cout << q.front() << " ";
			
			// out queue
			q.pop();
			
			// push the front into queue's rear
			q.push(q.front());
			
			// out queue
			q.pop();
		}
		
		cout << endl;
	}
}
int main()
{
	test();
	return 0;
}
/**
Input:
7

Output:
1 3 5 7 4 2 6

*/