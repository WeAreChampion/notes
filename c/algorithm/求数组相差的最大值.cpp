#include<iostream>
using namespace std;
int a[100000];
int main()
{
	int n, i, ca = 0, j;
	while(scanf("%d", &n) != EOF && n) {
		ca++;
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int max = -32676,aa;
		for(i = 0; i < n; i++) {
			for(j = i + 1; j < n; j++) {
				aa = a[i] - a[j];
				if(max < aa)
					max = aa;
			}
		}
		//cout<<"Case "<<ca<<": "<<max<<endl;
		printf("Case %d: %d\n", ca, max);
	}
	return 0;
}