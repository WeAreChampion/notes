#include<iostream>
using namespace std;
int data[105][105];    
//������������� 
int max(int x,int y)
{     
	return x>y?x:y;
}
int main()
{//     freopen("input.txt","r",stdin);     
	int t;        //t�β���     
	int n;        //�����ĸ߶�     
	int i,j;    //for()     
	cin>>t;     
	while(t--) 
	{         
		memset(data,0,sizeof(data));//quick set the array      
		cin>>n;         
		for(i=1;i<=n;i++)
		{            
			for(j=1;j<=i;j++)
	  		{             
		   		cin>>data[i][j];                   
		   		data[i][j]+=max(data[i-1][j-1],data[i-1][j]); //�ؼ���            
		   	}         
	  	}         
	  	int res=0;         
	  	for(i=1;i<=n;++i)
	  	{            
	  		res=max(res,data[n][i]);         
	  	}         
	  	cout<<res<<endl;    
  	}     
	return 0;
}
/*
In:
1 
5 
7 
3 8 
8 1 0 
2 7 4 4 
4 5 2 6 5
Out:
30
*/ 