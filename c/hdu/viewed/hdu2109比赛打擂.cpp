#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//sort from small to big
bool Comp(const int a, const int b)
{
    return a < b;
}
int main()
{
    int n, i, sum1, sum2, a;
    while(cin >> n && n) {
        sum1 = 0, sum2 = 0;
        vector<int> v1, v2;
        for(i = 0; i < n; i++) {
            cin >> a;
            v1.push_back(a);
        }
        for(i = 0; i < n; i++) {
            cin >> a;
            v2.push_back(a);
        }
        //sort vector v1 and v2 from small to big
        sort(v1.begin(), v1.end(), Comp);
        sort(v2.begin(), v2.end(), Comp);
        //If the one value is bigger than other, then add 2 
        for(i = 0; i < n; i++) {
            if(v1[i] > v2[i]) { 
                sum1 += 2;
            } else if(v1[i] == v2[i]) {
                sum1++;
                sum2++;
            } else { 
                sum2 += 2;
            } 
        }
        cout << sum1 << " vs " << sum2 << endl;
    }
    return 0;
}
/*
Sample Input
3
5 2 6
1 3 4
0

Sample Output

6 vs 0
*/ 