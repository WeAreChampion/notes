#include<iostream>
using namespace std;
int getCounts(int n)
{
	int counts = 0;
	while(n){
		if(n % 2 == 0) {
			n = n / 2;
		} else {
			n--;
			counts++;
		}
	}
	return counts;
}
void test()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			int a;
			cin>>a;
			cout<<getCounts(a)<<endl;
		}
	}
}
int main()
{
	test();
	return 0;
} 
/*
Sample Input
2
1
5 

Sample Output
1
2

*/
