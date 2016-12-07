#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
int sequence[1010];
int main()
{
	setbuf(stdout, NULL);
	int i, j, k;
	while(scanf("%d %d", &n, &m)!=EOF) {
		sequence[0] = 0;

		//init the array's value
		for(i = 1; i <= n; i++) {
			sequence[i] = i;
		}

		
		//swap m times
		for(i = 2; i <= m; i++) {
			
			//init n
			j = n;
			
			//find the index where sequence[j] >= sequence[j - 1]
			while(sequence[j] < sequence[j - 1]) {
				j--;
			}
			if(j == 1) {
				//go the origin
				for(k = 1; k <= n; k++) {
					sequence[k] = k;
				}
			} else {
				
				//For k from n to j, swap from array[j] to array[n]
				for(k = n; k >= j; k--) {
					
					//元素后移
					if(sequence[k] > sequence[j - 1]) {
						int temp = sequence[j - 1];
						sequence[j - 1] = sequence[k];
						sequence[k] = temp;
						break;
					}
				}
				
				//sort from sequence + j and sequence + n + 1
				sort(sequence + j, sequence + n + 1);
			}
		}
		
		//output
		for(i = 1; i < n; i++) {
			printf("%d ",sequence[i]);
		}
		printf("%d\n",sequence[n]);
	}
	return 0;
}
/*
Sample Input
//n m
6 4
11 8
 

Sample Output
1 2 3 5 6 4
1 2 3 4 5 6 7 9 8 11 10
*/