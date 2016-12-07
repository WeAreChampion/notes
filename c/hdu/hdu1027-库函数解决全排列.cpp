#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int N, M;
int sequence[1010];
int main() {
	setbuf(stdout, NULL);
	while(scanf("%d %d", &N, &M) != EOF) {
		int i;
		
		//init array by value index + 1
		for(i = 0; i < N; i++) {
			sequence[i] = i + 1;
		}
		
		//执行M-1次，产生下一个全排列
		for(i = 2;i <= M; i++) {
			//调用STL库函数next_permutation(startAddress, endAddress)
			next_permutation(sequence, sequence + N);
		}
		
		//print the sequence
		for(i = 0; i < N - 1; i++) {
			printf("%d ", sequence[i]);
		}
		printf("%d\n",sequence[N - 1]);
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