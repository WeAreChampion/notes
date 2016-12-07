/**
	大数阶乘，使用W位进制，即冯10000进1
	获得N!，返回大数十进制下的位数
	To display the N! value and return the value's counts of bit in 10
*/
int factorial(int n)
{
	//存储数组
	long a[10000];
	int i, j, l, c, m = 0, w;
	//初始化为1，阶乘从1开始
	a[0] = 1;
	
	// To multiply n times
	for(i = 1; i<= n; i++) {
		//进位标志
		c = 0;
		
		//遍历数组的长度
		for(j = 0; j <= m; j++) {
			//计算方法为当前数与数组中的每一位相乘并加上进位c
			a[j] = a[j] * i + c;
			//算进位与进位后的余数
			c = a[j] / 10000;
			a[j] = a[j] % 10000;
		}
		//进位标志大于0，即有进位
		if(c > 0) {
			//数组的长度+1
			m++;
			//对应的值存储进位
			a[m] = c;
		}
	}
	//保存所有的位数即大数阶乘以十进制的方式应该有多少位
	w = m * 4 + log10(a[m]) + 1;
	//输出最高位
	printf("\n%ld", a[m]);
	//输出低位，按每4位输出
	for(i = m - 1; i >= 0; i--)
		printf("%4.4ld",a[i]);
	return w;
}