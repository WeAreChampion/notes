#include<iostream> 
#include<cmath> 
using namespace std;  
int count;  
void isprime(int n) 
{ 
    int i; 
	if(n % 2 == 0 && n != 2) { 
		return ;
	} 
    for(i = 3;i <= (int)sqrt(double(n));i = i+2) { 
        if(n % i==0) { 
            return ; 
        } 
    } 
    count++; 
    return ; 
} 
int main() 
{ 
    int n,i,num; 
    while(scanf("%d", &n) != EOF) { 
        count = 0; 
        for(i = 0; i < n; i++) { 
            scanf("%d", &num); 
            isprime(num); 
        } 
        cout<<count<<endl; 
    } 
    return 0; 
} 
