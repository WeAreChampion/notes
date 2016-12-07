#include<iostream>
using namespace std;
#include<vector>
int main()
{
	vector<int> v, v1(4);
	int a, i;
	for(i = 1; i <= 4; i++) {
		v.push_back(i);//尾部追加元素
	}
	for(i = 0; i < 4; i++) { //以数组形式遍历
		cout << v[i] << " ";
	}
	cout << endl;

	v.insert(v.begin(), 9);
	v.insert(v.begin() + 2, 10);
	v.insert(v.end(), 11);
	for(i = 0; i < 4; i++) { //以数组形式遍历
		cout << v[i] << " ";
	}
	cout << endl;
	//=================================
	//=================================
	v1[0] = 2;
	v1[1] = 3;
	v1[2] = 7;
	vector<int> ::iterator it;
	for(it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	v1.insert(v1.begin(), 9);//在位置上插入
	v1.insert(v1.begin() + 2, 10);
	v1.insert(v1.end(), 11);
	for(it = v1.begin(); it != v1.end(); it++)
		//for(it=v.begin();it<v.end();it++)//迭代器遍历
	{
		cout << *it << " ";
	}
	cout << endl;
	v1.erase(v1.begin() + 1);
	cout << "删除第2个元素后是:";
	for(it = v1.begin(); it != v1.end(); it++)
		//for(it=v.begin();it<v.end();it++)//迭代器遍历
	{
		cout << *it << " ";
	}
	cout << endl;
	v1.erase(v1.begin() + 2, v1.begin () + 4);//删除第2到第4区间所有元素,不包括第5个，即下标是4
	cout<<"删除第2到第4区间的元素后是:";
	for(it = v1.begin(); it != v1.end(); it++)
		//for(it=v.begin();it<v.end();it++)//迭代器遍历
	{
		cout << *it << " ";
	}
	cout << endl;
	//=================================
	return 0;
}
// 5