#include <iostream>
using namespace std;
int main()
{
	int z, y, n, c;
	
	// 测试数据数量
	cin >> z;
	while (z--) {
		cin >> y >> n;
		c = 0;
		--y;
		while (c < n) {
			++y;
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
				++c;
		}
		cout << y << endl;
	}

	return 0;
}
