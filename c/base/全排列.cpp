#include<iostream>
using namespace std;
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
/**
	To get all perm from k to m
	产生全排列
*/
void Perm(int list[], int k, int m)
{
	int i; 
	if(k == m) {
		for(i = 0; i <= m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<endl;
	} else {
		for(i = k; i <= m; i++) {
			Swap(list[k], list[i]);
			Perm(list, k + 1, m);
			Swap(list[k], list[i]);	
		}
	}
}
int main()
{
	int n;
	int list[100];
	while(cin >> n) {
		cout << "请输入全排列的数字:";
		for(int i = 0; i < n; i++) {
			cin >> list[i];
		}
		Perm(list, 0, n - 1);
	}
	return 0;
}