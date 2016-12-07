#include <iostream>
#include <string>
 
using namespace std;
 
int hash[36] = {'0','1','2','3','4','5',
                 '6','7','8','9','a','b',
                 'c','d','e','f','g','h',
                 'i','j','k','l','m','n',
                 'o','p','q','r','s','t',
                 'u','v','w','x','y','z'};
 
 
string subset(string s,unsigned int size)
{
    unsigned int i;
    unsigned int j;
    unsigned int k = 0;
    unsigned int max;
    unsigned int num[128] = {0};
    string st = s;
    for(i = 0; i < size; i++)
    {
        num[int(s[i])]++;
    }
    max = num[hash[0]];
    for(i = 1; i < 36; i++)
    {
        if(num[hash[i]]>max)
        {
            max = num[hash[i]];
        }
    }
    for(j = 0; j < max; j++)
    {
        for(i = 0; i < 36; i++)
        {
            if(num[hash[i]]>0)
            {
                st[k++] = hash[i];
                num[hash[i]]--;
            }
        }
    }
    return st;
}
 
int main()
{
    string str;
    string result;
    unsigned int i;
    unsigned int f = 1;
    while(getline(cin,str))
    {
        for(i=0; i<str.length(); i++)
        {
            if((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='z'))
                continue;
            else
            {
                cout<<"<invalid input string>"<<endl;
                f = 0;
                break;
            }
        }
        if(f)
        {
            result = subset(str,str.length());
            cout<<result<<endl;
        }
    }
    return 0;
}
/*
Sample In£º 
aabbccdd
007799aabbccddeeff113355zz
1234.89898
abcdefabcdefabcdefaaaaaaaaaaaaaabbbbbbbddddddee


Sample Out£º 
abcdabcd
013579abcdefz013579abcdefz
<invalid input string>
abcdefabcdefabcdefabdeabdeabdabdabdabdabaaaaaaa
*/ 