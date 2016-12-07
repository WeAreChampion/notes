#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct
{
	int data[MaxSize];
	int length;
}List;
//get A U B 
void MergeList(List la, List lb, List &lc)
{
	int ia = 0, ib = 0, i = 0;
	while(ia < la.length && ib < lb.length) {
		if(la.data[ia] < lb.data[ib]) {
			lc.data[i++] = la.data[ia++];
		} else if(la.data[ia] == lb.data[ib]) {
			lc.data[i++] = lb.data[ib++];
			ia++;
		} else {
			lc.data[i++] = lb.data[ib++];
		}
	}
	while(ib < lb.length) {
		lc.data[i++] = lb.data[ib++];
	}
	while(ia < la.length) {
		lc.data[i++] = la.data[ia++];
	}
	lc.length = i;
}
//get A ¡ÉB
void getIntersection(List la, List lb, List &lc) 
{
	int ia = 0, ib = 0, i = 0;
	while(ia < la.length && ib < lb.length) {
		if(la.data[ia] < lb.data[ib]) {
			ia++;
		} else if(la.data[ia] == lb.data[ib]) {
			lc.data[i++] = lb.data[ib++];
			ia++;
		} else {
			ib++;
		}
	}
	lc.length = i;
}
int Partition(List &l, int low, int high)
{
	l.data[l.length] = l.data[low];
	int pivotkey = l.data[low];//save the fist key
	while(low < high) {
		while(low < high && l.data[high] >= pivotkey) {
			--high;
		}
		l.data[low] = l.data[high];
		while(low < high && l.data[low] <= pivotkey) {
			++low;
		}
		l.data[high] = l.data[low];
	}
	l.data[low] = l.data[l.length];
	return low;
}
void Qsort(List &l, int low, int high)//quick sort
{
	int pivotloc;
	if(low < high) {
		pivotloc = Partition(l, low, high);
		Qsort(l, low, pivotloc - 1);
		Qsort(l, pivotloc + 1, high);
	}
}
int main()
{
	List la,lb,lc;
	int na,nb,i;
	int ca;
	cin>>ca;//case number
	while(ca--) {
		cin>>na;
		la.length = na;
		for(i = 0; i < na; i++) {
			cin>>la.data[i];
		}
		Qsort(la, 0, na - 1);
		cin>>nb;
		lb.length = nb;
		for(i = 0;i < nb; i++) {
			cin>>lb.data[i];
		}
		Qsort(lb, 0, nb - 1);
		cout<<"la is:\n";
		for(i = 0; i < la.length; i++) {
			cout<<la.data[i]<<" ";
		}
		cout<<endl;
		cout<<"lb is:\n";
		for(i = 0; i < lb.length; i++) {
			cout<<lb.data[i]<<" ";
		}
		cout<<endl;
		MergeList(la, lb, lc);
		cout<<"lc's length is: "<<lc.length<<endl;
		for(i = 0; i < lc.length; i++) {
			cout<<lc.data[i]<<" ";
		}
		cout<<endl;
		List ld;
		getIntersection(la, lb, ld);
		cout<<"ld's length is: "<<ld.length<<endl;
		for(i = 0;i < ld.length; i++) {
			cout<<ld.data[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/*
2 
3
3 1 2
3
4 3 1
*/