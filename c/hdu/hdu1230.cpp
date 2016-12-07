#include<iostream> 
#include<cmath> 
#include<vector> 
using namespace std;  
int prime[30];  
int isprime(int n) 
{ 
    int i; 
	if(n%2==0&&n!=2)
		return 0;
    for(i=3;i<=(int)sqrt(double(n));i=i+2) 
        if(n%i==0) 
            return 0;
    return 1; 
}
int main() 
{
	int k=0,i;
	char a[100],b[100];
	for(i=2;i<100;i++)
		if(isprime(i))
		{
			prime[k++]=i;//save primes
		}
	while(scanf("%s%s",a,b)!=EOF)
	{
		//cout<<a<<" "<<b<<endl;
		vector<int> va,vb;
		int i,k=0,kk=0,array[100];
		va.clear ();
		vb.clear ();
		for(i=0;i<strlen(a)-1;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				array[kk]=a[i]-'0';
				kk++;
			}
			else if(a[i]==',')
			{
				for(int ii=0;ii<kk;ii++)
					k=k+array[ii]*pow(10,kk-1-ii);
				va.push_back (k);
				k=kk=0;
			}
		}
		va.push_back (a[i]-'0');	
		kk=k=0;
		for(i=0;i<strlen(b)-1;i++)
		{
			if(b[i]>='0'&&b[i]<='9')
			{
				array[kk]=b[i]-'0';
				kk++;
			}
			else if(b[i]==',')
			{
				for(int ii=0;ii<kk;ii++)
					k=k+array[ii]*pow(10,kk-1-ii);
				vb.push_back (k);
				k=kk=0;
			}
		}
		vb.push_back (b[i]-'0');
		/*
		cout<<va.size ()<<endl;
		for(i=0;i<va.size ();i++)
			cout<<va[i]<<" ";
		cout<<endl;
		cout<<vb.size ()<<endl;
		for(i=0;i<vb.size ();i++)
			cout<<vb[i]<<" ";
		cout<<endl;
		*/
		if((va[0]==0&&va.size ()==1)||(vb[0]==0&&vb.size()==1))
			break;
		int la=va.size (),lb=vb.size (),i1,i2,aa,bb,flag=0,c[100];
		for(i1=la-1,i2=lb-1,i=0; ;i++,i1--,i2--)
		{
			if(i1<0 && i2<0)
				break;
			if(i1>=0&&i2>=0)
				{
					aa=va[i1];
					bb=vb[i2];
				}
			else if(i1<0 && i2>=0)
			{
				aa=0;
				bb=vb[i2];
			}
			else if(i2<0 && i1>=0)
			{
				aa=va[i1];
				bb=0;
			}
			c[i]=flag+aa+bb;
			if(c[i]>=prime[i])
			{
				flag=1;
				c[i]=c[i]%prime[i];
			}
			else 
				flag=0;
		}
		if(flag)
		{
			c[i]=1;
			for( k=i;k>=0;k--)
			{
				if(k!=0)
					cout<<c[k]<<",";
				else
					cout<<c[k]<<endl;
			}
		}
		else
		{
			for( k=i-1;k>=0;k--)
			{
				if(k!=0)
					cout<<c[k]<<",";
				else
					cout<<c[k]<<endl;
			}
		}
	}
    return 0; 
} 