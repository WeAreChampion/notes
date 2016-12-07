/*
A 和 B求最大公约数
假设A是比较大的数字，先看B能否 整除A，如果能，直接输出B
如果不能，让A等于原来的B，新B等于原来的A模上原来的B，此
时再看B是否能整除A，并重复上面步骤。 
*/
int gcd(int a, int b)
{
	if(a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if(b == 0) {
		return a;	
	} else {
		return gcd(b, a % b)
	}
}