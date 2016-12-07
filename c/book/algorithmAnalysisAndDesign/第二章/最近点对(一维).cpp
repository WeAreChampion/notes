#include<iostream>
using namespace std;
#define M 20

/**
	1. 给定平面上n个点，找其中的一对点，使得在n个点组成的所有点对中，
	该点对间的距离最小。
	
	2. 假设用x轴上某个点m将S划分为2个集合S1和S2，使得S1={x∈S|x<=m}；S2={x∈S|x>m}。因此，
	对于所有p∈S1和q∈S2有p<q。递归的在S1和S2上找出其最接近点对{p1，p2}和{q1，q2}，并设d=
	min{|p1-p2|,|q1-q2|}。由此易知，S中的最接近点对或者是{p1，p2}，或者是{q1，q2}，或者是
	某个{p3，q3}，其中p3∈S1且q3∈S2。
	
*/
/**
	表示具有最近距离的点对(d1,d2)的距离dist
*/
struct cpair {
	float dist;
	float d1, d2;
};

/**
	s[]为一维点集，n为s[]中的元素个数
*/
int input(float s[], int n)
{
	cout << "Please input data end with -1 : \n";
	n = 0;
	cin >> s[n];
	while(s[n] != -1) {
		n++;
		cin >> s[n];
	}
	return n;
}

/**
	返回s[b]到s[e]中的最大值
	To get the max distance from s[] where index between b and e
*/
float max(float s[], int b, int e)
{
	float m1 = s[b];
	for(int i = b + 1; i <= e; i++) {
		if(m1 < s[i]) {
			m1 = s[i];
		}
	}
	return m1;
}
/**
	返回s[b]到s[e]中的最小值
	To get the min distance from s[] where index between b and e
*/
float min(float s[], int b, int e)
{
	float m1 = s[b];
	for(int i = b + 1; i <= e; i++) {
		if(m1 > s[i]) {
			m1 = s[i];
		}
	}
	return m1;
}
/**
	返回s[]中的具有最近距离的点对及其距离
*/
cpair cpair1(float s[], int n)
{
	cpair temp = {
		1000, 0, 0
	};
	/*
		当点集中元素的个数不足2时,返回具有无穷大的dist值(此处设为1000)的temp
	*/
	if(n < 2) {
		return temp;
	}
	
	// m1 save the max and m2 save the min
	float m1 = max(s, 0, n - 1), m2 = min(s, 0, n - 1);
	
	// 找出点集中的中位数
	float m = (m1 + m2) / 2;
	int j = 0, k = 0;
	
	/*
		将点集中的各元素按与m的大小关系分组
	*/
	float s1[M], s2[M];
	for(int i = 0; i < n; i++) {
		
		// 小于等于m的在s1[]中，j保存数组长度
		if(s[i] <= m) {
			s1[j] = s[i];
			j++;
		} else {// 大于m的在s2[]中，k保存数组长度
			s2[k] = s[i];
			k++;
		}
	}
	
	// 递归求s1中的最近点对，s2中的最近点对，
	cpair d1 = cpair1(s1, j), d2 = cpair1(s2, k);
	
	// 求s1中的最大最小点
	float p = max(s1, 0, j - 1), q = max(s2, 0, k - 1);
	
	// 返回s[]中的具有最近距离的点对及其距离
	if(d1.dist < d2.dist) {
		if((q - p) < d1.dist) {
			temp.dist = (q - p);
			temp.d1 = q;
			temp.d2 = p;
			return temp;
		} else {
			return d1;
		}
	} else {
		if((q - p) < d2.dist) {
			temp.dist = (q - p);
			temp.d1 = q;
			temp.d2 = p;
			return temp;
		} else {
			return d2;
		}
	}
}
int main()
{
	int n, m;
	float s[M];
	cpair dist;
	m = input(s, n);
	dist = cpair1(s, m);
	cout << "Point (" << dist.d1 
		<< ", " << dist.d2 << "), Distance : " << dist.dist << endl;
	
	return 0;
}
/**
Input:
5 3 9 6 8 15 26 -1

Output:
该一维点集中最近点对为(9,8),其距离为1

*/