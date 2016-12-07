#include<iostream>
using namespace std;
long long a[22];
int main()
{
    int m;   
    a[0]=0;
    a[1]=0;
    a[2]=1;
    for(int i=3;i<=21;i++){
		a[i]=(a[i-1]+a[i-2])*(i-1);
    }   
    int n,d;  
    cin>>m;
    while(m--){
       cin>>n>>d;
       int n1=n;
       int d1=d;
       long long sum=1,sum1=1;
        for(int j=1;j<=d;j++)
        	sum*=j;
        while(d1>0)
		{
             sum1=sum1*n1;
             n1--;
             d1--;
  		}
    	sum=sum1/sum;
		sum=sum*a[d];
		cout<<sum<<endl;
      }
      return 0;
}   