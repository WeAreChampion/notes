#include<iostream>
using namespace std; 
int main()
{
	int *p, i, *A;
	A = new int[10];
	p = A; //point p->A
	for(i = 0; i < 10; i++) {
		*p = i;
		p++;
	}
	p = A;//point p->A
	for(i = 0;i < 10; i++)
	{
		cout<<*p<<" "; 
		p++;
	}
	cout<<endl;
	return 0;
}