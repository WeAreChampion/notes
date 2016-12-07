#include<iostream>  
using namespace std;
/*
	��Ŀ������������A��B,A=(a1,a2,...,ak),B=(b1,b2,...,bk),
A��B�����������У�����1<=i,j<=k����k����С�ģ�ai+bj����Ҫ��
�㷨������Ч .

	�ⷨ���趨�����±�i��j�ֱ�ָ��A, B��β��������ǰ��i-1��* j>=k
��(j-1)*i>=k˵����ʣ�µ��������С��i*j�����ҿ��Ը���A[i]��
B[j]����Ԫ�صĴ�С�ֱ��ƶ���Ӧ���±ֱ꣬����i-1��*j<k��
(j-1)*i<k����ʱʣ�µ������Ϊi*j�������������ǰk����С�ͣ�
���ظ��û���

	ʱ�临�Ӷ�Ϊmin{O(min(len1,len2))��O(k)}���ռ临�Ӷ�Ϊ
O(k)����ֻ����Ҫ�����С��k���ͣ�����Ҫ��O(k)�Ŀռ��k��
��С�ʹ洢����������ʱ�临�Ӷ�ΪO(1).
*/ 
int *min_k(int *A, int *B, int len1, int len2, int k);  
int main()  
{  
	int len1, len2, k; 
    cin >> len1 >> len2 >> k;//������������ĳ���len1,len2�Լ���С�ĺ͵���Ŀ  
    int *A = new int[len1];
    int *B = new int[len2];
    int i;
    //input the array A
    for(i = 0; i < len1; i++) {
        cin >> A[i];
    }
    //input the array B
    for(i = 0; i < len2; i++) { 
        cin>>B[i];
    } 
    //To get the result
    int *result = min_k(A, B, len1, len2, k);  
    for(i = 0; i < k; i++) { 
        cout<<result[i]<<" ";
	}  
    cout << endl;
    //delete the room
    delete []A;  
    delete []B;  
    delete []result;  
    return 0;  
}  
int *min_k(int *A, int *B, int len1, int len2, int k)  
{  
	if(A == NULL || B == NULL || k <= 0) { 
        return NULL;
 	} 
    int i, j;
    int *tmp = new int[k];
    i = len1;
    j = len2;
    //i -> array A
    //j -> array B
    //To get the i and j pos
    while(i > 0 && j > 0) {
    	//The array A's value is larger then array B's value 
        if(A[i - 1] > B[j - 1]) {
        	//ǰ����͵���������ڵ���k 
            if((i - 1) * j >= k) {
            	//iָ������ 
                i--;
            } else { 
                break;
			} 
        } else {
            if((j - 1) * i >= k) {
            	//jָ������ 
                j--;
            } else { 
                break;
			}  
        }  
    }  
    int count = 0;  
    if(A[i - 1] > B[j - 1]) {  
        int p, q;
        //p -> array A
        //q -> array B 
        for(p = 0; p < i; p++) {  
            for(q = 0; q < j; q++) {
            	//count���м��� 
                if(count < k) { 
                    tmp[count++] = A[p] + B[q];
                } 
                else { 
                    break;
                } 
            }  
        }  
    } else {  
        int p, q; 
        //p -> array B
        //q -> array A 
        for(p = 0; p < j; p++) {  
            for(q = 0; q < i; q++) {  
                if(count < k) { 
                    tmp[count++] = B[p] + A[q];
                } else { 
                    break;
				} 
            }  
        }  
    }  
    return tmp;  
}
/*
3 3 5
1 2 3
4 5 16
*/ 