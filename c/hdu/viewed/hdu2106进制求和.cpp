#include<iostream>
#include<cmath>
using namespace std;
int sum;
int convert(int n, int m)//convert to (10)
{
	int sum = 0,k = 0, a;
	while(n != 0) {
		a = n % 10;
		sum += a * pow(m, k);
		k++;
		n = n / 10;
	}
	return sum;
}
int main()
{
	int n,i;
	//char a[100];
	int aa, bb;
	while(cin>>n) {
		sum=0;
		for(i=0;i<n;i++) {
			//cin>>a[i];
			scanf("%d(%d)", &aa, &bb);
			sum += convert(aa, bb);
		}
		cout << sum << endl;
	}
	return 0;
}