#include<iostream>
using namespace std;
double getValue(int a,char op,int b)
{
	double sum;
	switch(op) {
		case '+' :
			sum = a + b;
			break;
		case '-' :
			sum = a - b;
			break;
		case '*' :
			sum = a * b;
			break;
		case '/' :
			sum = a * 1.0 / b;
			break;
	}
	return sum;
}
int convert(char a[])
{
	int i, k = 1;
	int sum = 0;
	for(i = strlen(a) - 1; i >= 0; i--) {
		sum += (a[i] - '0') * k;
		k = k * 10;
	}
	return sum;
}
int main()
{
	int ca;
	cin>>ca;
	while(ca--)
	{
		char a[10], b[1000], c[1000];
		scanf("%s%s%s", &a, &b, &c);
		//cout<<a<<" "<<b<<" "<<c<<endl;
		int value_a = convert(b), value_b = convert(c);
		//cout<<"zalue_a="<<value_a<<" value_b="<<value_b<<endl;
		if((value_a % value_b == 0 && a[0] == '/') 
			|| a[0] == '+' || a[0] == '-' || a[0] == '*') {
			cout<<getValue(value_a, a[0], value_b)<<endl;
		}
		else { 
			printf("%.2f\n", getValue(value_a, a[0], value_b));
		} 
	}
	return 0;
}