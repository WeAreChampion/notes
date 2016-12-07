#include<iostream>
#include<iomanip>
using namespace std;
double a[21];
int main()
{
    int m;
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    for(int i = 3; i <= 20; i++)
 		a[i] = (a[i - 1] + a[i - 2]) * (i - 1);
    int n;  
    cin >> m;
    while(m--) {
       cin >> n;
       double sum = 1;
       for(double j = 1; j <= n; j++)
        	sum *= j;
        double temp;
        temp = a[n] / sum;
        temp = temp * 100;
        cout << setiosflags(ios::fixed) << setprecision(2);
        cout << temp << "%" << endl; 
//        printf("%.2f",&temp);
	}
 	return 0;
} 