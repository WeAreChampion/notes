#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<vector>
#include<IOMANIP>
struct student
{
	string s;//name
	double d;//���� 
};
bool Comp(const student s1, const student s2)
{
	if(s1.d != s2.d) {
		return s1.d > s2.d;//����Ӵ�С���� 
	}
	if(s1.s != s2.s) {
		return s1.s < s2.s;//���ִ�С��������
	} 
}
int main()
{
	int n;
	int c;
	double xf;
	vector<double> vxf;
	int p;
	string name;
	double score;
	student xs;
	vector<student> vxs;
	cin>>n;
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		cin>>c;
		for(j = 0; j < c; j++) {
			cin>>xf;
			vxf.push_back(xf);
		}
		cin>>p;
		for(j = 0; j < p; j++) {
			cin>>name;
			xs.s = name;
			xf = 0.0;
			for(k = 0; k < c; k++) {
				cin>>score;
				if(score < 0) {
					continue;
				}
				//�ɼ��������60���м���
				if(score >= 60){ 
					xf = xf + (score - 50) / 10 * vxf[k];//������㹫ʽ
				} 
			}
			xs.d = xf / 10;
			vxs.push_back(xs);
		}
		cout<<(i ? "\n" : "");
		cout<<"Class "<<i + 1<<":"<<endl;
		sort(vxs.begin(), vxs.end(), Comp);//���� 
		for(vector<student>::iterator it = vxs.begin(); it < vxs.end(); it++)
		{
			cout<<fixed<<setprecision(2);//���������λ��Ч���� 
			cout<<left<<setw(11);//������10�ַ�������룬�ٿ�һ����г����� 
			cout<<(*it).s<<(*it).d<<endl;
		}
		vxf.clear();//������� 
		vxs.clear();
	}
	return 0; 
}
/*
1
3 3 4 3
3
���� 89 62 71
Smith 98 50 80
���� 67 88 91 
*/