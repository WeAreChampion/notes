#include<iostream>
#include<cstdio>
using namespace std;
/*
	1.To get the value that the amount is the largest, 
	and the amount must is bigger than the value of 
 	length / 2.
 	2.The Tn = O(n), Sn = O(1).
*/
int getManyValue(int array[], int length) {
	int count = 1;
	int manyValue = array[0];
	for(int i = 1; i < length; i++) {
		if(array[i] == manyValue) {
			count++;
		} else {
			if(count > 0) {
				count--;
			} else {
				manyValue = array[i];
				count = 1;
			}
		}
	}
	return manyValue;
}
int main() {  
	int ans, num, count, n;  
	while (scanf("%d", &n) != EOF) {
		count = 0;
		
		//The Tn = O(n), Sn = O(1).
		//scanf and counts
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ans);
			
			if (count == 0) {
				//save the number
				num = ans;
				
				//add and save the count
				count++;  
			}  
			else { 
				if (ans == num)// is equal then add one
					count++;
				else // else decrease one
					count--;
			}
		}  
		printf("%d\n", num);  
	}  
	return 0;     
}
/*
Sample Input
5
1 3 2 3 3
11
1 1 1 1 1 5 5 5 5 5 5
7
1 1 1 1 1 1 1


Sample Output
3
5
1

*/