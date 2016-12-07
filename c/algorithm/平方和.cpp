#include<iostream>
using namespace std;
int main()
{
	__int64 n;
	while(scanf("%I64d",&n)!=EOF)
	{
		__int64 sum;
		sum=(2n+1)*(n+1)*n/6;
		printf("%I64d\n",sum);
	}
	return 0;
}