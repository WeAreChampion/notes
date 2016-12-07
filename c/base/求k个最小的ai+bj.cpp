#include<iostream>  
using namespace std;
/*
	题目：有两个序列A和B,A=(a1,a2,...,ak),B=(b1,b2,...,bk),
A和B都按升序排列，对于1<=i,j<=k，求k个最小的（ai+bj），要求
算法尽量高效 .

	解法：设定两个下标i，j分别指向A, B的尾部，若当前（i-1）* j>=k
或(j-1)*i>=k说明，剩下的组合是最小的i*j，而且可以根据A[i]，
B[j]两个元素的大小分别移动相应的下标，直到（i-1）*j<k或
(j-1)*i<k，此时剩下的组合数为i*j，遍历数组求得前k个最小和，
返回给用户。

	时间复杂度为min{O(min(len1,len2))，O(k)}，空间复杂度为
O(k)，若只是需要输出最小的k个和，则不需要用O(k)的空间把k个
最小和存储起来，这样时间复杂度为O(1).
*/ 
int *min_k(int *A, int *B, int len1, int len2, int k);  
int main()  
{  
	int len1, len2, k; 
    cin >> len1 >> len2 >> k;//输入两个数组的长度len1,len2以及最小的和的数目  
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
        	//前面求和的组合数大于等于k 
            if((i - 1) * j >= k) {
            	//i指针左移 
                i--;
            } else { 
                break;
			} 
        } else {
            if((j - 1) * i >= k) {
            	//j指针左移 
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
            	//count进行计数 
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