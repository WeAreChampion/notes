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
	cout<<"���Ա���(R[0].key)�ǣ�"<<R[0].key<<endl;
}
int BinSearch(SeqList R,KeyType key)//���ֲ��ң�������˳�����
{
	int mid,low=1,high=R[0].key;
	int count=0;					//����ؼ��ֱȽϴ���
	while(low<=high) {
		mid=(low+high)/2;
		cout<<"��"<<count+1<<"�β��ҵĹؼ����ǣ�\t"<<R[mid].key<<endl;
		if(R[mid].key ==key) {
			count++;
			cout<<"�ؼ��ֱȽϵĴ����ǣ�\t"<<count<<endl;
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
	cout<<"Ҫ���ҵ�˳����ǣ�"<<endl;
	Disp(R);
	cout<<"������Ҫ���ҵĹؼ��֣�";
	cin>>key;
	if((i=BinSearch(R,key))!=-1)
		cout<<key<<"�����Ա��е�λ���±���:"<<i<<endl;
	else
		cout<<"not find it"<<endl;
	return 0;
}