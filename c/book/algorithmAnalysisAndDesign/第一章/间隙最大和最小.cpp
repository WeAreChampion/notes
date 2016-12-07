#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
/**
	初始化区间
	count[i] = 0; //区间是否有数据存入
	low[i] = max; //将区间的左端赋值最大值
	high[i] = min; //将区间的右端赋值最小值
*/
void initial(int n, int count[], float low[], float high[], float min, float max)
{
	int i;
	for(i = 0; i < n; i++) {
		count[i] = 0; //区间是否有数据存入
		low[i] = max; //将区间的左端赋值最大值
		high[i] = min; //将区间的右端赋值最小值
	}
}
/**
	1.将数据序列依次放入对应区间
	2.区间的求法
		判断数据进入哪个区间:按照等分区间，数据与最小值的差与
	区间大小的比值+1就是区间编号
*/
void dataIn(float m, int count[], float low[], float high[], int n, float data[], float min)
{
	int i, location;
	for(i = 0; i < n; i++) {
		/*
			判断数据进入哪个区间:按照等分区间，数据与最小值的差与
			区间大小的比值+1就是区间编号
		*/
		location = int((data[i] - min) / m) + 1;

		//第n个区间，实际上只有n-1个区间
		if(location == n)
			location--;

		//区间有数据存入，计数值加1
		count[location]++;

		/**
			初始时左端是最大值，右端最小值；根据数据修改左端与右端值
		*/
		//如果数据比左端值小，则作为左端值
		if(data[i] < low[location])
			low[location] = data[i];

		//如果数据比右端值大，则作为右端值
		if(data[i] > high[location])
			high[location] = data[i];
	}
}
/**
	1.找出最大间隙，整个问题的核心
	2.上面已经把对应数据放入相应的区间，在之前可以知道，总共有n-1个区间
	，相应的只有n-2个值，那么就一定有一个区间不会有数据
	3.因为最大值与最小值已经分别被设为最小区间的左端值和最大区间的右端
	值，所以中间的n-1区间只有n-2个值
	4.那么可以想象，最大间隙肯定不会是在一个区间中，而一定是在空区间的
	两端，最大间隙为空区间右边相邻区间的左端值-空区间左边相邻区间的右端
	值；有可能有多个这种情况，找出最大就行了
*/
float findMaxGap(int n,float low[],float high[],int count[])
{
	int i;
	float maxgap, dhigh, temp;

	// 初始化为high[1]
	dhigh = high[1];
	for(i = 2; i < n; i++) {
		// 有数据
		if(count[i]) {
			temp = low[i] - dhigh;
			//保存最大间隙
			if(maxgap < temp)
				maxgap = temp;
			dhigh = high[i];
		}
	}
	return maxgap;
}
int main()
{
	float data[MAX];
	int n, i = 0;
	float min = 99999.0L, max = -99999.0L;
	float m, maxgap;
	float low[MAX], high[MAX];
	int count[MAX];
	while(cin >> n) {
		for(i = 0; i < n; i++) {
			cin >> data[i];

			// To get the max
			if(data[i] >= max) {
				max = data[i];
			}

			// To get the min
			if(data[i] <= min) {
				min = data[i];
			}
		}

		// 计算平均间隙
		m = (max - min) / (n - 1);

		// 初始化区间
		initial(n, count, low, high, min, max);

		// 数据写入与区间写入
		dataIn(m, count, low, high, n, data, min);

		// 计算最大间隙
		maxgap = findMaxGap(n, low, high, count);
		printf("%.1f", maxgap);
	}
	return 0;
}
/**
Input:
5
2.3 3.1 7.5 1.6 6.3


Output:
3.2
*/