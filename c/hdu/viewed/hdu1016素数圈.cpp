#include <iostream>
#include <cstring>
#include <cmath>
int hash[30]; //����Ƿ�ʹ�� 
int arr[100]; //�洢��Ӧ������ 
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
//index --> ��ʾֵ
//order -->��ʾ�ݹ���ȣ�������������n 
void DFS(int order, int index)
{
	int i;
	//�洢��Ӧ��ֵ 
	arr[order] = index;
	//��Ǹ�ֵ��ʹ�� 
	hash[index] = 1;
	 //�ݹ���� 
	if(order == n) {
		//������һ������1�ĺ�Ϊ���������ʾ��һ��� 
     	if(isPrime(arr[order] + arr[1])) {
     		
     		//����� 
	    	printf("1");
       		for(i = 2; i<= n; i++)
      			printf(" %d", arr[i]);
       		printf("\n");
     	}
     	//�ݹ���� 
     	return ;
   	}
   	//��1-n�������ν���ѡ�� 
   	for(i = 1; i <= n; i++) {
   		//���û��ʹ�� �� �뵱ǰ�ĵ��������Ϊ���� 
		if(!hash[i] && isPrime(arr[order] + i)) {
			//������һ������ 
	   		DFS(order + 1, i);
	   		//���ݣ���Ϊ���ܴ��ڶ���⣬��Ҫ������н� 
		   	hash[i] = 0;//ע�����
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
      	//��һ������Ϊ1������1��ʼ 
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