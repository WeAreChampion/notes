#include<iostream>
#include<cmath>
using namespace std;
int s[7];
void inttoseries(int i, int n)
{
	int k, j;
	for(k = 0, j = i; k < n-1; k++) {
		s[k] = j % n;
		j = j / n;
	}
}
int maxColumn(int n, int array[100][100])
{
	int i, max, temp, j;
	for(max = array[0][0], i = 1; i < n; i++) {
		max += array[i][s[i - 1]];
	}
	for(i=1; i<n; i++) {
		for(j=1,temp=array[0][i]; j<n; j++) {
			temp+=array[j][(s[j-1]+i)%n];
		}
		if(temp>max) {
			max=temp;
		}
	}
	return max;
}
int main()
{
	int n,array[100][100],i,j,max,temp;
	while(cin>>n&&n+1) {
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				cin>>array[i][j];
			}
		}
		int k=(int)pow((float)n,(float)n);
		cout<<"k="<<k<<endl;
		inttoseries(0,n);
		max=maxColumn(n,array);
		for(i=1; i<k; i++) {
			inttoseries(i,n);
			temp=maxColumn(n,array);
			if(temp<max) {
				max=temp;
			}
		}
		cout<<"the min is:"<<max<<endl;
	}
	return 0;
}
/*
2
4 6
3 7
3
1 2 3
4 5 6
7 8 9
-1
*/