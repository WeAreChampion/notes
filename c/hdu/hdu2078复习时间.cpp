#include<iostream>
using namespace std;
/**
	为了能过个好年，xhd开始复习了，于是每天晚上背着书往教室跑。
	xhd复习有个习惯，在复习完一门课后，他总是挑一门更简单的课
	进行复习，而他复习这门课的效率为两门课的难度差的平方,而复
	习第一门课的效率为100和这门课的难度差的平方。xhd这学期选
	了n门课，但是一晚上他最多只能复习m门课，请问他一晚上复习
	的最高效率值是多少？

	Input
	输入数据的第一行是一个数据T，表示有T组数据。
	每组数据的第一行是两个整数n(1 <= n <= 40)，m(1 <= m <= n)。
	接着有n行，每行有一个正整数a(1 <= a <= 100)，表示这门课的难度值。
	
	解决办法：
	选一门复杂度最少的课，就是效率最高的。
*/
int main()
{
	int T, i, m, n, min;
	int ans;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		
		cin >> min;
		
		for(i = 1; i < n; i++) {
			cin >> m;
			// To find the min
			if(m < min) {
				min = m;
			}
		}
		ans = 100 - min;
		cout << ans * ans << endl;
	}
	return 0;
}
/**
Sample Input
2
2 2
52
25
12 5
89
64
6
43
56
72
92
23
20
22
37
31
 
Sample Output
5625
8836

*/