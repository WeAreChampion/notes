#include<iostream>
#include<string>
using namespace std;
int main()
{
	int ca,k=1;
	cin>>ca;
	while(ca--)
	{
		int n;
		string s="";
		cin>>n>>s;
	//	cout<<n<<" "<<s<<endl;
		s.erase(n-1,1);
		cout<<k<<" "<<s<<endl;
		k++;
	}
	return 0;
} 