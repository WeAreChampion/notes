#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N, M;
	while(cin >> N >> M){
		int a[1010];
		for(int i = 0; i < N; i++) { 
			a[i] = i + 1;
		} 
		while(--M){
			next_permutation(a, a + N);
		}
		for(int i = 0; i < N; i++){
			if(i != 0) { 
				cout << " ";
			} 
			cout << a[i];
		}
		cout << endl;	
	}
	return 0;
}
/*
6 4
11 8
*/