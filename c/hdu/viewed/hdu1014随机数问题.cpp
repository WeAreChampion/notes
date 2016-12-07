#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	int s,m;
	while(cin>>s>>m)
	{
		int a, b, i;
		set<int> v;
		v.insert(0);
		a = 0;
		for(i = 0; ; i++) {
			b = (a + s) % m;
			if(b == 0) { 
				break;
			} 
			v.insert(b);
			a = b;
		}
		if(v.size() != m) {
			printf("%10d%10d    Bad Choice\n\n", s, m);
		} else {
			printf("%10d%10d    Good Choice\n\n",s,m);
		}
	}
	return 0;
}
/*
Input:
3 5
15 20
63923 99999
Output:
         3         5    Good Choice

        15        20    Bad Choice

     63923     99999    Good Choice
*/