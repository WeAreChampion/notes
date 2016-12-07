#include<iostream>
using namespace std;
int arrange[1005];
/*
	求1-N中全排列情况下的第m个子序列
*/
/*
	To init the array[i] with value i.
*/
void init(int n) {
    for(int i = 1; i <= n; ++i) {
        arrange[i] = i;      
    }     
}
/*
	在全排列中查找
*/
void find(int n, int m)
{
	int i, p, j, k, c, c2, temp, q;
    
	//find the m-th counts
    for(p = 0; p < m; ++p) {
		for(j = n - 1; j >= 1; j--) {
			if(arrange[j] < arrange[j + 1]) {
				c = j;
                break;
			}      
		}   

		for(k = c + 1; k <= n; ++k) {
			if(arrange[k] > arrange[c]) {
				c2 = k;
			}
			else {
				break;
			}			   
		}  

		temp = arrange[c2];
		arrange[c2] = arrange[c];
		arrange[c] = temp;

		for(j = c + 1; j <= (c + 1 + n) / 2; ++j) {
			temp = arrange[j];
			q = n - (j - c - 1);
			arrange[j] = arrange[q];
			arrange[q] = temp;      
		}     
	}
}
int main()
{
    int n, m, i, t;
    
    while(cin >> n >> m) {
        init(n);
        find(n, m - 1);   
        for(i = 1; i <n; ++i) {
			cout<<arrange[i] << " ";
        }
		cout<<arrange[i] << endl;		
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