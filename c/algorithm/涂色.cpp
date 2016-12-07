#include<iostream>
#include<string>
using namespace std;
void getMin(string s,int it,int &min)
{
	int i,count=0;
	for(i=0;i<it;i++)
	{
		if(s[i] != 'R')
			count++;
		if(count > min)
			return ;
	}
	for(i=it+1;i<s.length ();i++)
	{
		if(s[i] != 'G')
		{
			count++;
		}
		if(count > min)
			return ;
	}
	min=count;
	return ;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int min1=32678,min=32678,countG=0;
		int t=s.length ();
		for(int i=0 ; i<t ; i++)
		{
			getMin(s,i,min);
			if(s[i]=='G')
				countG++;
		}
		min1=countG<(t-countG)?countG:(t-countG);
		cout<<(min1<min?min1:min)<<endl;
	}
	return 0;
}