/*
A �� B�����Լ��
����A�ǱȽϴ�����֣��ȿ�B�ܷ� ����A������ܣ�ֱ�����B
������ܣ���A����ԭ����B����B����ԭ����Aģ��ԭ����B����
ʱ�ٿ�B�Ƿ�������A�����ظ����沽�衣 
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