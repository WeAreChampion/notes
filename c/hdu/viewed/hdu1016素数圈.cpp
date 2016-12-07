#include <iostream>
#include <cstring>
#include <cmath>
int hash[30]; //标记是否使用 
int arr[100]; //存储相应的数字 
int n;
/*
	To judge the int number is prime.
	If is a prime then return 1, else return 0.
*/
int isPrime(int x)
{
	if(x == 2) {
		return 1;
	}
	if(x < 2 || x % 2 == 0) {
		return 0;
	}
	int length = (int) (sqrt(double (x))); 
	for(int i = 2; i <= length; i++) {
		if(x % i == 0) { 
			return 0;
		}
	} 
	return 1;
}
//index --> 表示值
//order -->表示递归深度，即搜索到几个n 
void DFS(int order, int index)
{
	int i;
	//存储相应的值 
	arr[order] = index;
	//标记该值已使用 
	hash[index] = 1;
	 //递归出口 
	if(order == n) {
		//若最后的一个数和1的和为质数，则表示是一组解 
     	if(isPrime(arr[order] + arr[1])) {
     		
     		//输出解 
	    	printf("1");
       		for(i = 2; i<= n; i++)
      			printf(" %d", arr[i]);
       		printf("\n");
     	}
     	//递归结束 
     	return ;
   	}
   	//对1-n个数依次进行选择 
   	for(i = 1; i <= n; i++) {
   		//如果没有使用 且 与当前的的数字相加为质数 
		if(!hash[i] && isPrime(arr[order] + i)) {
			//进行下一步搜索 
	   		DFS(order + 1, i);
	   		//回溯，因为可能存在多组解，需要求出所有解 
		   	hash[i] = 0;//注意回溯
	   	}
   	}
	return ;
}
int main()
{
	int flag = 1;
	while(scanf("%d", &n) != EOF) {
      	printf("Case %d:\n", flag++);
      	memset(hash, 0, sizeof(hash));
      	//第一个数字为1，即从1开始 
	  	DFS(1, 1);
	  	printf("\n");
	}
	return 0;
}
/*
Sample Input
6
8
Sample Output
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/ 