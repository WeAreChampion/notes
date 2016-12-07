#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n, i, j, k;
	bool t[1010];//mark stack is in or out
	char a[1010], b[1010];
	while(cin>>n>>a>>b)
	{
		stack<char>train;
		i = j = k = 0;
		//j -> array a[] 
		//i -> array b[]
		//k -> array t[] value is 1 means in, 0 means out
		while(i < n) {	
			//train not empty or train.top()!=b[i] and j<n then push a[j++] into stack 	
			if(train.empty() || train.top() != b[i] && j < n) { 
				train.push(a[j++]);
				//mark is in
				t[k++] = 1;
			} else if(train.top() == b[i]) {
				//pop
				train.pop();
				//mark is out
				t[k++] = 0;
				i++;//i get the next means counts++
			}
			else { 
				break;//If j == n
			} 
		}	
		//train is empty that means can solve
		if(train.empty()) {
			cout<<"Yes."<<endl;
			for(i=0; i < k; i++){				
				if(t[i]) { 
					cout<<"in"<<endl;
				} 
				else { 
					cout<<"out"<<endl;
				} 
		}
		else { 
			cout<<"No."<<endl;
		} 
		cout<<"FINISH"<<endl;
	}
	return 0;
}
/*
In:
3 123 321
3 123 312
output:
Yes.
in
in
in
out
out
out
FINISH
No.
FINISH

*/