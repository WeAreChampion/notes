/*
快速乘方
1.将k写成2进制数s，s[1]为其最低位。
2.假设之前i-1求出来的得数为Ans，如
果s[i]位上的数字为1，那么现在的答
案都是Ans*A^(2^i)而 A^(2^(i-1))在
上一步是呢个算出来的。 
*/
int QKpower(int a,int k)
{
	int ans=1,tmep=a;
	while(k)
	{
		if(k%2)
			ans=ans*temp;
		temp=temp*temp;//这个就是上一步计算出来的 A^(2^(i-1))
		k/=2;
	}
	return ans;
}