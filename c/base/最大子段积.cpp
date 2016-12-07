#include<iostream>
using namespace std;
/*
	1.给一个浮点数序列，取最大乘积子序列的值，
例如 -2.5，4，0，3，0.5，8，-1，则取出的最
大乘积子序列为3，0.5，8。
	2.需要用两个变量保存包括当前位置序列的最
大乘积和最小乘积.
	3.然后还需要比较两次，一次是最大乘积和最
小乘积是否需要互换，还有一次是不是只选当前
位置就是最好的.
*/
/*
	分析：假设数组为a[]，直接利用动归来求解，考虑
到可能存在负数的情况，我们用Max[i]来表示以a[i]结尾
的最大连续子序列的乘积值，用Min[i]表示以a[i]结尾的
最小的连续子序列的乘积值，那么状态转移方程为：
   	Max[i] = max{a[i], Max[i - 1] * a[i], Min[i - 1] * a[i]};
   	Min[i] = min{a[i], Max[i - 1] * a[i], Min[i - 1] * a[i]};
初始状态为Max[1] = Min[1] = a[1]。代码如下：

	给定一个整数数组，有正有负数，0，正数组成,数组下标从1算起
求最大连续子序列乘积，并输出这个序列，如果最大子序列乘积为
负数，那么就输出-1
	用Max[i]表示以a[i]结尾乘积最大的连续子序列
	用Min[i]表示以a[i]结尾乘积最小的连续子序列，因为有负数，所以
保存这个是必须的
*/

int startPos;
int endPos;
double maxMulti(double v[], int n) {
	double maxt = 1;
    double mint = 1;
    //save the multiply's max value
    double maxv = v[0];
    //for each the array
    for(int i = 0; i < n; ++i) {
  		//v[i] is 0 then reset the value
        if(v[i] == 0) {
            maxt = 1;
            mint = 1;
            if (v[i] > maxv) { 
                maxv = 0;
                startPos = i;
            } 
        } else{
			double oriMint = mint;
            double oriMaxt = maxt;
            //To calculate v[i] * mint
            double minrst = mint * v[i];
            //To calculate v[i] * maxt
            double maxrst = maxt * v[i];
            //To get the max
            maxt = maxrst > minrst ? maxrst : minrst;
            //To get the min
            mint = maxrst > minrst ? minrst : maxrst;
            //If the maxt < v[i] then save the max value v[i] into maxt
            if (maxt < v[i]) { 
                maxt = v[i];
                endPos = i;
            }
            //If the mint > v[i] then save the min value v[i] into mint
            if (mint > v[i]) { 
                mint = v[i];
                startPos = i - 1;
            }
            //If the maxt > maxv then save into maxv
            if (maxv < maxt) { 
                maxv = maxt;
                endPos = i;
            } 
        }
    }
    //return the max multiple value
	return maxv;
}
int main()
{
	int length, i, j, m, n;
	double array[100]; 
	while(cin >> length) {
		for(i = 0; i < length; i++) {
			cin >> array[i];
		}
		cout << maxMulti(array, length) << endl;
		cout << "startPos = " << startPos << endl;
		cout << "endPos = " << endPos << endl;
	}
}
/*
7
-2.5 4 0 -3 -0.5 8 -1
7
-2.5 4 0 -3 -0.5 -8 -1
4
-1 1000 -0.1 15
3
12 0.1 15
5
-1 -2 0 1 2
*/