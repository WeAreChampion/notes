#include<iostream>
using namespace std;
int main()
{
    int a[123][123] = {0}, i, j, number;
    while(cin >> number) {
        for(i = 1; i < 121; i++) {
			a[1][i] = a[i][1] = 1;
            for(j = 2; j <= 121; j++) {
                if(i > j) { 
					a[i][j] = a[i - j][j] + a[i][j - 1];
				} 
                if(i == j) { 
					a[i][j] = 1 + a[i][j - 1];
				} 
                if(i < j) { 
					a[i][j] = a[i][i];
				} 
            }
        }
        cout << a[number][number] << endl;
    }
}
//for(i=1;i<=121;i++)            
/*
  4 = 4;
  4 = 3 + 1;
  4 = 2 + 2;
  4 = 2 + 1 + 1;
  4 = 1 + 1 + 1 + 1;
*/