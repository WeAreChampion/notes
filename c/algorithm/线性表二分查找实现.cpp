#include<iostream>
using namespace std;
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct {
	KeyType key;
	InfoType data;
} NodeType;
typedef NodeType SeqList[MAXL];
void Create(SeqList R,int a[],int n)
{
	for(int i=1; i<=n; i++)
		R[i].key=a[i];
	R[0].key=n;
}
void Disp(SeqList R)
{
	for(int i=1; i<=R[0].key; i++)
		cout<<R[i].key<<"  ";
	cout<<endl;
	cout<<"线性表长度(R[0].key)是："<<R[0].key<<endl;
}
int BinSearch(SeqList R,KeyType key)//二分查找，对已有顺序查找
{
	int mid,low=1,high=R[0].key;
	int count=0;					//计算关键字比较次数
	while(low<=high) {
		mid=(low+high)/2;
		cout<<"第"<<count+1<<"次查找的关键字是：\t"<<R[mid].key<<endl;
		if(R[mid].key ==key) {
			count++;
			cout<<"关键字比较的次数是：\t"<<count<<endl;
			return mid;
		}
		if(R[mid].key >key)
			high=mid-1;
		else
			low=mid+1;
		count++;
	}
	return -1;
}
int main()
{
	SeqList R;
	int n=10,i;
	KeyType key;
	int a[]= {0,1,2,3,4,5,6,7,8,9,10};
	Create(R,a,n);
	cout<<"要查找的顺序表是："<<endl;
	Disp(R);
	cout<<"请输入要查找的关键字：";
	cin>>key;
	if((i=BinSearch(R,key))!=-1)
		cout<<key<<"在线性表中的位置下标是:"<<i<<endl;
	else
		cout<<"not find it"<<endl;
	return 0;
}