#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
/**
	First Come First Service way.
	To get the average find way time
*/
double FCFS(int a[], int length, int start)
{
	int sum = 0;
	for(int i = 0; i < length; i++) {
		int count = abs(start - a[i]);
		cout << "Visited " << a[i] << " Move " << count << " distances" << endl;
		sum += count;
		start = a[i];
	}
	return sum * 1.0 / length;
}
/**
	To test FCFS
*/
void TestFCFS()
{
	int a[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
	int length = 9;
	int start = 100;
	cout << "平均寻道时间：" << FCFS(a, length, start) << endl;
}
/**
	最短寻道时间优先，要求访问的磁道与当前磁头所在磁道距离最近	
*/
double SSTF(vector<int> v, int start)
{
	int sum = 0;
	int length = v.size();
	while(v.size() != 0) {
		int min = 9999;
		vector<int>::iterator pos;
		for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			int count = abs(start - *it);
			if(min >= count) {
				min = count;
				pos = it;
			}
		}
		sum += min;
		cout << "Visited " << *pos << " Move " << min << " distances" <<endl;
		start = *pos;
		v.erase(pos);
	}
	return sum * 1.0 / length;
}
void TestSSTF()//is right
{
	int a[] = {55,58,39,18,90,160,150,38,184};
	int length = 9;
	vector<int> v;
	v.clear();
	for(int i = 0; i < length; i++) {
		v.push_back(a[i]);
	}
	int start = 100;
	cout << "平均寻道时间：" << SSTF(v, start)<<endl;
}
bool Comp1(int a,int b)//from small to big
{
	return a<b;
}
bool Comp2(int a,int b)//from big to small
{
	return a>b;
}
double SCAN(vector<int> vsmall,vector<int> vbig,int start,bool flag)
{
	int sum=0;
	if(flag) { //is start from small to big
		for(int i=0; i<vbig.size(); i++) {
			int count=abs(start-vbig[i]);
			sum+=count;
			cout<<"Visited "<<vbig[i]<<" Move "<<count<<" distances"<<endl;
			start=vbig[i];
		}
		for(int i=0; i<vsmall.size(); i++) {
			int count=abs(start-vsmall[i]);
			sum+=count;
			cout<<"Visited "<<vsmall[i]<<" Move "<<count<<" distances"<<endl;
			start=vsmall[i];
		}
	} else { //is start from big to small
		for(int i=0; i<vsmall.size(); i++) {
			int count=abs(start-vsmall[i]);
			sum+=count;
			cout<<"Visited "<<vsmall[i]<<" Move "<<count<<" distances"<<endl;
			start=vsmall[i];
		}
		for(int i=0; i<vbig.size(); i++) {
			int count=abs(start-vbig[i]);
			sum+=count;
			cout<<"Visited "<<vbig[i]<<" Move "<<count<<" distances"<<endl;
			start=vbig[i];
		}
	}
	return sum*1.0/(vsmall.size()+vbig.size());
}
void TestSCAN()//is right
{
	int a[]= {55,58,39,18,90,160,150,38,184};
	int length=9;
	vector<int> vsmall,vbig;
	vsmall.clear();
	vbig.clear();
	int start=100;
	for(int i=0; i<length; i++) {
		if(a[i]>=start) {
			vbig.push_back(a[i]);
		} else {
			vsmall.push_back(a[i]);
		}
	}
	//Quick Sort
	sort(vsmall.begin(),vsmall.end(),Comp2);
	sort(vbig.begin(),vbig.end(),Comp1);
	//cout<<"平均寻道时间："<<SCAN(vsmall,vbig,start,true)<<endl;//checked
	cout<<"平均寻道时间："<<SCAN(vsmall,vbig,start,false)<<endl;
}
//循环扫描算法
double CSCAN(vector<int> vsmall,vector<int> vbig,int start)
{
	int sum=0;
	for(int i=0; i<vbig.size(); i++) {
		int count=abs(start-vbig[i]);
		sum+=count;
		cout<<"Visited "<<vbig[i]<<" Move "<<count<<" distances"<<endl;
		start=vbig[i];
	}
	for(int i=0; i<vsmall.size(); i++) {
		int count=abs(start-vsmall[i]);
		sum+=count;
		cout<<"Visited "<<vsmall[i]<<" Move "<<count<<" distances"<<endl;
		start=vsmall[i];
	}
	return sum*1.0/(vsmall.size()+vbig.size());
}
void TestCSCAN()//is right
{
	int a[]= {55,58,39,18,90,160,150,38,184};
	int length=9;
	vector<int> vsmall,vbig;
	vsmall.clear();
	vbig.clear();
	int start=100;
	for(int i=0; i<length; i++) {
		if(a[i]>=start) {
			vbig.push_back(a[i]);
		} else {
			vsmall.push_back(a[i]);
		}
	}
	//Quick Sort
	sort(vsmall.begin(),vsmall.end(),Comp1);//small to big
	sort(vbig.begin(),vbig.end(),Comp1);//small to big
	//cout<<"平均寻道时间："<<SCAN(vsmall,vbig,start,true)<<endl;//checked
	cout<<"平均寻道时间："<<CSCAN(vsmall,vbig,start)<<endl;
}
int main()
{
	TestCSCAN();
	return 0;
}