#include<iostream>
using namespace std;
void SelectSort(int a[], int n)
{
	cout<<"选择法排序是：\n";
	int i, j, k;
	for(int i = 0; i < n - 1; i++) {
		k = i;
		for(j = i + 1; j < n; j++) {
			if(a[j] < a[k]) {
				k = j;
			}
		}
		if(k != i) {
			int temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
		cout << "第i=" << i << "次排序：\t";
		for(int m = 0; m < n; m++) {
			cout << a[m] << " ";
		}
		cout << endl;
	}
}
void BubbleSort(int a[], int n)
{
	cout << "冒泡法排序是：\n";
	int i, j, k;
	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		cout << "第i=" << i << "次排序：\t";
		for(int m = 0; m < n; m++) {
			cout << a[m] << " ";
		}
		cout << endl;
	}
}
void QuickSort(int a[],int s,int t,int n)//对a[s]和a[t]间的元素排序
{
	int i=s,j=t,k;
	if(s<t) {
		int temp=a[s];
		while(i!=j) {
			while(j>i&&a[j]>temp) {
				j--;
			}
			if(i<j) {
				a[i]=a[j];
				i++;
			}
			while(i<j&&a[i]<temp) {
				i++;
			}
			if(i<j) {
				a[j]=a[i];
				j--;
			}
		}
		a[i]=temp;
		cout<<"\t";
		for(k=0; k<n; k++) {
			if(k==i) {
				cout<<"["<<a[k]<<"]";
			} else {
				cout<<"  "<<a[k];
			}
		}
		cout<<endl;
		QuickSort(a,s,i-1,n);
		QuickSort(a,i+1,t,n);
	}
}
int main()
{
	int n=10;
	int a[]= {9,2,3,4,6,8,7,0,1,5};
	cout<<"========================"<<endl;
	SelectSort(a,n);
	int b[]= {9,2,3,4,6,8,7,0,1,5};
	BubbleSort(b,n);
	int c[]= {6,8,7,9,0,1,3,2,4,5};
	cout<<"快速排序是：\n";
	QuickSort(c,0,n-1,n);
	return 0;
}