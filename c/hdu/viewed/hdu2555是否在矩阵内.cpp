#include <iostream>
#include <algorithm>
using namespace std;
//sort from small to big
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, i, j, m, k, temp = 0, sum;
	int a[20000][2], b[100][2], b1[100][2], c[20000];
	cin >>m >>n;
	//save the counts-m people position 
	for(i = 0; i < m; i++) { 
		cin >>a[i][0] >>a[i][1];
	} 
	for(j = 0; j < n; j++) {
		//the left-down pos 
		cin >>b[j][0] >>b[j][1];
		//the right-up pos 
		cin >>b1[j][0] >>b1[j][1];
	}
	k = 0;
	for(i = 0; i < m; i++) {
		temp = 0;
		for(j = 0; j < n; j++) { 
			//To judge whether the pos is in the Rectangle
			if(a[i][0] >= b[j][0] && a[i][0] <= b1[j][0]) {
				if(a[i][1] >= b[j][1] && a[i][1] <= b1[j][1]) {
					//calculte the arc's length
					sum = 2 * (b1[j][0] - b[j][0]) + 2 * (b1[j][1] - b[j][1]);
					//mark the pso is in the Rectangle
					temp = 1;
					break;
				}
			}
		} 
		if(temp == 1) { 
			c[i] = sum;
		} else { 
			c[i]=0;
		} 
	}
	//sort
 	sort(c, c + m, cmp);
	for(i = 0; i < m; i++) { 
		cout<<c[i]<<endl;
	}
}
/*
Sample Input
5 3
15 27
32 93
22 3
98 4
65 23
22 65 100 76
2 5 7 9
54 6 94 24

Sample Output
116
0
0
0
0

*/