/*
���ٳ˷�
1.��kд��2������s��s[1]Ϊ�����λ��
2.����֮ǰi-1������ĵ���ΪAns����
��s[i]λ�ϵ�����Ϊ1����ô���ڵĴ�
������Ans*A^(2^i)�� A^(2^(i-1))��
��һ�����ظ�������ġ� 
*/
int QKpower(int a,int k)
{
	int ans=1,tmep=a;
	while(k)
	{
		if(k%2)
			ans=ans*temp;
		temp=temp*temp;//���������һ����������� A^(2^(i-1))
		k/=2;
	}
	return ans;
}