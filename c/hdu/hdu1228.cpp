///*
#include <stdio.h>   
#include <math.h>   
int main()   
{   
	int s, a, i, j;   
    char line[1024];   
    char num[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};   
    while (gets(line))   
    {   
        s = j = 0;   
        a = 0;   
        while (line[j] != '=')   
        {   
			for (i = 0; i < 10; i++)   
			{   
				if (line[j] == num[i][0] && line[j+1] == num[i][1])   
				{   
					a += i;   
                    while(line[j] != ' ')   
						j++;   
                    break;   
                }   
            }   
			j++;   
			if (line[j] == '+')   
			{   
				s += a;   
				a = 0;   
				j += 2;   
			}   
            else if (line[j] != '=')   
            {   
                a *= 10;    
			}   
        }   
        if (s != 0 || a != 0)   
            printf("%d\n", s + a);
		else
			break;
    }   
    return 0;   
}
//*/
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,str[10];
	int a[10],b[10];
	int i=0;
	while(cin>>s)
	{	
		int point;//remeber the "+" position
		if(s == "=")
		{
			i=0;
			cout<<point<<endl;
			//cout<<a+b<<endl;
			continue;
		}
		else
		{
			if(s!="+")
			{
				if(s=="zero")
					a[i]=0;
				else if(s=="one")
					a[i]=1;
				else if(s=="two")
					a[i]=2;
				else if(s=="three")
					a[i]=3;
				else if(s=="four")
					a[i]=4;
				else if(s=="five")
					a[i]=5;
				else if(s=="six")
					a[i]=6;
				else if(s=="seven")
					a[i]=7;
				else if(s=="eight")
					a[i]=8;
				else if(s=="nigh")
					a[i]=9;
				i++;
			}
			else
			{
				if(s=="zero")
					a[i]=0;
				else if(s=="one")
					a[i]=1;
				else if(s=="two")
					a[i]=2;
				else if(s=="three")
					a[i]=3;
				else if(s=="four")
					a[i]=4;
				else if(s=="five")
					a[i]=5;
				else if(s=="six")
					a[i]=6;
				else if(s=="seven")
					a[i]=7;
				else if(s=="eight")
					a[i]=8;
				else if(s=="nigh")
					a[i]=9;
				i++;
			}
			str[i]=s;
			if(s=="+")
				point=i;
			cout<<str[i]<<" "<<i<<endl;
			i++;
		}
	}
	return 0;
}
*/