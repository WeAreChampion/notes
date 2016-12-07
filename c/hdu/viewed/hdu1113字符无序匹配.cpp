#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<string, string> node;
int main()
{
	string s;
	/*
		input the dictionary
		If the s is "XXXXXX", that means the dictionary is ending.
	*/
    while(cin >> s && s != "XXXXXX") {
		string t = s;
		//sort s from small to big
        sort(s.begin(), s.end());
        //insert s into map
		node.insert(pair<string, string>(t, s));
	}
	while(cin >> s) {
		//input 
  		if(s == "XXXXXX") {
		  	break;
	  	} 
  		int flag = 1;
  		map<string, string>::iterator it;
  		//sort the input string s from small to big
    	sort(s.begin(), s.end());
    	for(it = node.begin(); it != node.end(); it++) {
    		//if is equal, then output the string in the map
     		if(it->second == s) {
      			flag = 0;
	  			cout << it->first << endl;
			}
		}
    	if(flag) {
			cout<<"NOT A VALID WORD"<<endl;
		} 
    	cout<<"******"<<endl;
 	}
 	return 0;
}
