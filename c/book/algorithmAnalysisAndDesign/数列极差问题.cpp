#include<iostream>
using namespace std;
#include<set>
/**
	ÿ��ȡ������С����a, b��������a + b + 1����ӵ������У����õ�һ�����ֵ
*/
int getMax(multiset<int> v)
{
	int flag = 1;
	int a = 0, b = 0;
	while(v.size() > 1) {
		multiset<int>::iterator it1 = v.begin(), it2 = v.begin();
		it2++;
		if(flag) {
			flag = 0;
			a = *it1;
		} else {
			flag = 1;
			b = *it2;
		}
		if(a != 0 && b != 0) {
			int c = a * b + 1;
			it2++;
			v.erase(it1, it2);
			v.insert(c);
			a = b = 0;
		}
	}
	return *(v.begin());
}
/*
	ÿ��ȡ����������a, b��������a + b + 1����ӵ������У����õ�һ����Сֵ
*/
int getMin(multiset<int> v)
{
	int flag = 1;
	int a = 0, b = 0;
	while(v.size() > 1) {
		multiset<int>::iterator it1 = v.end(), it2;
		it1--;//the last
		it2 = it1;
		it2--;//the last second
		if(flag) {
			flag = 0;
			a = *it1;
		} else {
			flag = 1;
			b = *it2;
		}
		if(a != 0 && b != 0) {
			int c = a * b + 1;
			v.erase(it2, v.end());//clear[it2,v.end())
			v.insert(c);
			a = b = 0;
		}
	}
	return *(v.begin());
}
/**
	To display the multiset<int> v's all elements
*/
void Disp(multiset<int> v)
{
	for(multiset<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	int n, i, k;
	multiset<int> v;
	while(cin >> n) {
		v.clear();
		for(i = 0; i < n; i++) {
			cin >> k;
			v.insert(k);
		}
		Disp(v);
		cout << "Max=" << getMax(v) << "\nMin=" << getMin(v) << endl;
	}
	return 0;
}
/*
3
1 2 3
*/