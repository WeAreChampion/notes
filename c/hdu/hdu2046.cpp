//��n������2*nʱ�����ɵ�n-1������ֱ�����ټ�һ����n-2��
//�к�������������f(n) = f(n-1) + f(n-2)
#include<iostream>
using namespace std;
int main()
{
	__int64 f1,f2,f3;
	int n,i;
	while(cin>>n)
	{
		f1=0;f2=1;
		for(i=1;i<=n;i++)
		{
			f3=f1+f2;
			f1=f2;
			f2=f3;
		}
		printf("%I64d\n",f2);
	}
	return 0;
}
