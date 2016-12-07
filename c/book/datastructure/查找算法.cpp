#include<iostream>
using namespace std;
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{
	KeyType key;
	InfoType data;
}NodeType;
typedef NodeType SeqList[MAXL];
int SeqSearch(SeqList R, int n, KeyType key)//顺序查找
{
	int i = 0;
	for(i = 0; i < n && R[i].key != key; i++);
	if(i >= n) {
		return -1;
	}
	return i;
}
//二分查找，对已有顺序查找
int BinSearch(SeqList R,int n,KeyType key)
{
	int mid,low = 0,high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;
		if(R[mid].key == key) {
			return mid;
		}
		if(R[mid].key > key) {
			high = mid-1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}
//分治法（二分法）
void Search_Max_Min(SeqList R, int start, int end, int &max, int &min)
{
	int mid, lmax, lmin, rmax, rmin;
	if(start==end)
	{
		max= R[start].key;
		min= R[start].key;
	}
	else if(end==start+1)
	{
		if(R[start].key>R[end].key)
		{
			max=R[start].key;
			min=R[end].key;
		}
		else
		{
			max=R[end].key;
			min=R[start].key;
		}
	}
	else
	{	mid=(start+end)/2;
		Search_Max_Min(R,start,mid,lmax,lmin);//
		Search_Max_Min(R,mid+1,end,rmax,rmin);//
		if(lmax>rmax)
			max=lmax;
		else
			max=rmax;
		if(lmin>rmin)
			min=rmin;
		else
			min=lmin;
	}
}
int main()
{
	SeqList R;
	int n=10,i;
	KeyType key=6;
	int max,min;
	int a[]={3,6,2,10,1,8,5,7,4,9},b[]={1,2,3,4,5,6,7,8,9,10};
	for(i=0;i<n;i++)
	{
		R[i].key =a[i];
		cout<<R[i].key<<" ";
	}
	cout<<endl;
	if((i=SeqSearch(R,n,key))!=-1)
	{
		cout<<key<<"在数组中的位置是："<<i<<endl;
	}
	else
	{
		cout<<"not find it"<<endl;
	}
	Search_Max_Min(R,0,n-1,max,min);
	cout<<"max = "<<max<<"\tmin = "<<min<<endl;
//有序的二分法查找
	for(i=0;i<n;i++)
	{
		R[i].key =b[i];
		cout<<R[i].key<<" ";
	}
	cout<<endl;
	if((i=BinSearch(R,n,key))!=-1)
	{
		cout<<key<<"在数组中的位置是："<<i<<endl;
	}
	else
	{
		cout<<"not find it"<<endl;
	}
	Search_Max_Min(R,0,n-1,max,min);
	cout<<"max = "<<max<<"\tmin = "<<min<<endl;
	return 0;
}
/*
#include <time.h>   
#include <iostream>   
#include <iomanip>     
const int NUM = 40;   
void InitArray(int *arr, int num);  
void Find(int *arr, int begin, int end, int *max, int *min)  
{  
    if (end-begin <= 1)  //一直到分解为最小子结构时才走这里   
    {  
        if (arr[begin] > arr[end])  
        {  
            *max = arr[begin]>*max ? arr[begin] : *max;  
            *min = arr[end]<*min ? arr[end] : *min;  
        }  
        else  
        {  
            *max = arr[end]>*max ? arr[end] : *max;  
            *min = arr[begin]<*min ? arr[begin] : *min;  
        }  
        return;  
    }  
    else  
    {  
        int i = begin + (end-begin)/2;  
        Find(arr, begin, i, max, min);  
        Find(arr, i+1, end, max, min);  
    }  
}  
int main()  
{  
    int arr[NUM];  
    InitArray(arr, NUM);  
    int max = 0;  
    int min = 0;  
    Find(arr, 0, NUM-1, &max, &min);  
    std::cout << "max = " << max << ", min = " << min << std::endl;  
    return 0;  
}  
  
void InitArray(int *arr, int num)  
{  
    for (int i=0; i<num; ++i)  
    *(arr+i) = i;  
    srand( time(NULL));  
    int s, r;  
    for (int j=0; j<num; ++j)  
    {  
        r = rand() % num;  
        s = arr[r];  
        arr[r] = arr[num-1-r];  
        arr[num-1-r] = s;  
    }  
  
    for (int k=0; k<num; ++k)  
    {  
        std::cout << std::setw(2) << *(arr+k) << ' ';  
        if (!((k+1)%10))  
            std::cout << std::endl;  
    }  
}
*/