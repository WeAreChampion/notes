#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n) {
		int i, j;
		for(i = 0; i < 2 * n + 1; i++) {
			if(i == 0 || i == 2 * n) {
				for(j = 0; j < 2 * n + 1; j++) {
					cout << "*";
				}
				if(j == 2 * n + 1)
					cout << endl;
			} else {
				for(j = 0; j < 2 * n + 1; j++) {
					if(j + i == 2 * n) {
						cout << "*" << endl;
						break;
					} else {
						cout << " ";
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}