#include<iostream>
using namespace std;
#include<fstream>
int main()
{
	int a[1000];
	int n,i,j,t;
	while(cin>>n)
	{
		ofstream outfile("f2.dat",ios::out);
		if(!outfile)
		{
			cerr<<"ERROR!"<<endl;
			exit(1);
		}
		outfile<<n<<endl;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(j=0;j<n;j++)
			for(i=0;i<n-j-1;i++)
				if(a[i]>a[i+1])
				{
					t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
				}
		for(i=0;i<n-1;i++)
		{
			cout<<a[i]<<" ";
			outfile<<a[i]<<" ";
		}
		cout<<a[i]<<endl;
		outfile<<a[i]<<endl;
		outfile.close();
	}
	return 0;
}