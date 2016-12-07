#include<iostream>
#include<cmath>
using namespace std;
double operation(double a, double b, char op)
{
	switch(op) {
		case '+' :
			return a + b;
			break;
		case '-' :
			return a - b;
			break;
		case '*' :
			return a * b;
			break;
		case '/' :
			return a / b;
			break;
	}
}
int main()
{
	int n;
	cin>>n;
	getchar();
	char op;
	double a, b;
	for(int i = 0; i < n; i++) {
		cin>>op>>a>>b;
		cout<<op<<" "<<a<<" "<<b<<endl;
		getchar();
		double result = operation(a, b, op);
		int value = (int)result;
		if(fabs(result - value) < 1E-8) { 
			cout<<result<<endl;
		}  else { 
			printf("%.2lf\n", operation(a, b, op));
		} 
	}
	return 0;
}
/*
4
+ 1 2
- 1 2
* 1 2
/ 1 2 
SampleOutput
3
-1
2
0.50
*/