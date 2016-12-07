#include<iostream.h>
#include<stdio.h>
#include<math.h>
#define M 20
/**
	x, y : 点的x,y坐标
	id : 点在数组中的标号
*/
struct point {
	float x, y;
	int id;
};

/**
	a,b两点间的距离
*/
struct pair {
	point a, b;
	float dist;
};

/**
	若xx为真时，对point型数组x[n]按元素的x坐标排序；否则按其y坐标排序
*/
void sort(point x[], int n, bool xx)
{
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(xx == true) {
				// 按元素的x坐标排序
				if(x[i].x > x[j].x) {
					// x[i]、x[j]互换
					point t = x[j];
					x[j] = x[i];
					x[i] = t;

					// 修改x[i]、x[j]的id值
					x[i].id = i;
					x[j].id = j;
				}
			} else {
				// 按元素的y坐标排序
				if(x[i].y > x[j].y) {
					// x[i]、x[j]互换
					point t = x[j];
					x[j] = x[i];
					x[i] = t;

					// 修改x[i]、x[j]的id值
					x[i].id = i;
					x[j].id = j;
				}
			}
		}
	}
}

/**
	输入二维点集中的各点，记录于数组x[]中
*/
void input(point x[], int n)
{
	cout << "Please input point :\n";
	for(int i = 0; i < n; i++) {
		cout << "The " <<i + 1 << "'st point:";
		cin >> x[i].x >> x[i].y;
		x[i].id = i;
	}
}

/**
	To get the distance
*/
float dis(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
/**

*/
pair closestpair(point x[], point y[], point z[], int l, int r)
{
	pair t;
	if(r == l) { //1点的情形
		t.dist = 1000;
		return t;
	}
	if(r - l == 1) { //2点的情形
		t.a = x[l];
		t.b = x[r];
		t.dist = dis(x[l], x[r]);
		return t;
	}
	if(r - l == 2) { //3点的情形
		float d1 = dis(x[l], x[l + 1]),d2 = dis(x[l + 1], x[r]), d3 = dis(x[l], x[r]);
		if(d1 <= d2 && d1 <= d3) {
			t.a = x[l];
			t.b = x[l+1];
			t.dist = d1;
			return t;
		}
		if(d2 <= d3) {
			t.a = x[l + 1];
			t.b = x[r];
			t.dist = d2;
			return t;
		} else {
			t.a = x[l];
			t.b = x[r];
			t.dist = d3;
			return t;
		}
	}
	// 多于3点的情形，用分治法
	int m = (l + r) / 2;
	int f = l, g = m + 1;
	for(int i = l; i <= r; i++) {
		if(y[i].id > m) {
			z[g++] = y[i];
		} else {
			z[f++] = y[i];
		}
	}
	//递归求解
	pair best = closestpair(x, z, y, l, m);
	pair right = closestpair(x, z, y, m + 1, r);

	if(right.dist < best.dist) {
		best = right;
	}
	// 将距中位线l=m的距离小于dist且宽度为2*dist的点置于z[]中
	int k = l;
	for(i = l; i <= r; i++) {
		if(abs(x[m].x - y[i].x) < best.dist) {
			z[k++] = y[i];
		}
	}
	//搜索z[l:k-1]
	for(i = l; i < k; i++) {
		for(int j = i + 1; j < k && z[j].y - z[i].y < best.dist; j++) {
			float dp = dis(z[i],z[j]);
			if(dp < best.dist) {
				t.a = z[i];
				t.b = z[j];
				t.dist = dp;
				return t;
			}
		}
	}
	return best;
}

//寻找最近点对
pair cpair2(point x[], int n)
{
	int i;
	pair t;
	if(n < 2) {
		t.dist = 1000;        //当元素个数不足2时,返回具有较大dist值的t
		return t;
	}
	sort(x, n, true);//依x坐标排序
	point y[M];
	for(i = 0; i < n; i++) //将数组x[]中的点复制到数组y[]中
		y[i] = x[i];
	sort(y, n, false);//依y坐标排序
	point z[M];
	return closestpair(x, y , z, 0, n - 1);//计算最近点对
}

void main()
{
	int n;
	point x[M];
	pair t;
	cout << "Point counts : ";
	cin >> n;
	while(n < 2) {
		cout << "Not not exist point counts \n";
		cout << "Point counts : ";
		cin >> n;
	}
	cout << endl;
	input(x, n);
	t = cpair2(x, n);
	cout << "Point (" << t.a.x << "," << t.a.y << ") and ("
		<< t.b.x << "," << t.b.y << "), Distance : " << t.dist << endl;
}
