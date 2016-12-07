#include<iostream>
using namespace std;
class Knap {
	friend int Knapsack(int p[], int w[], int c, int n );
public:
	void print() {
		for(int m = 1; m <= n; m++) {	
			cout<<bestx[m]<<" ";
		}
		cout<<endl;
	}

private:
	int Bound(int i);
	void Backtrack(int i);
	int c;//背包容量
	int n; //物品数
	int *w;//物品重量数组
	int *p;//物品价值数组
	int cw;//当前重量
	int cp;//当前价值
	int bestp;//当前最优值
	int *bestx;//当前最优解
	int *x;//当前解
};
//找边界，用于剪枝 
int Knap::Bound(int i) {
	//计算上界
	int cleft = c - cw;//剩余容量
	int b = cp;
	//以物品单位重量价值递减序装入物品
	while(i <= n && w[i] <= cleft) {
		cleft -= w[i];
		b += p[i];
		i++;
	}
	//装满背包
	if(i <= n) { 
		b += p[i] / w[i] * cleft;
	} 
	return b;
}
/*
	回溯 
*/ 
void Knap::Backtrack(int i) {
	/*
		若完成搜索，即递归深度i > 物品数n 
	*/
	if(i > n) {
		/*
			若当前的价值大于前面的最优值，则保存当前最优解
			和最优值作为新的最优解和最优值。 
		*/
		if(bestp < cp) {
			for(int j = 1; j <= n; j++)
			bestx[j] = x[j];
			bestp = cp;
		}
		/*
			完成搜索 
		*/
		return ;
	}
	//搜索左子树，意味着当前节点加入背包，并修改相应的值 
	if(cw + w[i] <= c) {
		//加入背包 
		x[i] = 1;
		//当前重量增加 
		cw += w[i];
		//当前价值增加 
		cp += p[i];
		//进行递归搜索 
		Backtrack(i + 1);
		//回溯，相应的值回到开始水平 
		cw -= w[i];
		cp -= p[i];
	}
	//搜索右子树，利用边界剪枝 
	if(Bound(i + 1) > bestp) {
		x[i] = 0;
		Backtrack(i + 1);
	}
}
class Object {
	friend int Knapsack(int p[], int w[], int c, int n);
public:
	int operator <= (Object a) const {
		return (d >= a.d);
	}
	private:
	int ID;
	float d;
};
int Knapsack(int p[], int w[], int c, int n) {
	//为Knap::Backtrack初始化
	int W = 0;
	int P = 0;
	int i = 1;
	Object *Q = new Object[n];
	for(i = 1; i <= n; i++) {
		Q[i - 1].ID = i;
		
		//计算单位重量的价值量 
		Q[i - 1].d = 1.0 * p[i] / w[i];
		
		//累计价值 
		P += p[i];
		
		//累计重量 
		W += w[i];
	}
	if(W <= c) { 
		return P;//装入所有物品
	} 
	//依物品单位重量排序
	float f;
	for(i = 0; i < n; i++) { 
		for(int j = i + 1; j < n; j++) {
			if(Q[i].d < Q[j].d) {
				//交换相应的值 
			 	f = Q[i].d;
				Q[i].d = Q[j].d;
				Q[j].d = f;
			}
		}
	} 
	Knap K;
	K.p = new int[n + 1];
	K.w = new int[n + 1];
	K.x = new int[n + 1];
	K.bestx = new int[n + 1];
	K.x[0] = 0;
	K.bestx[0] = 0;
	for(i = 1; i <= n; i++) {
		K.p[i] = p[Q[i - 1].ID];
		K.w[i] = w[Q[i - 1].ID];
	}
	K.cp = 0;
	K.cw = 0;
	K.c = c;
	K.n = n;
	K.bestp = 0;
	
	//回溯搜索
	K.Backtrack(1);
	//打印最优解 
	K.print();
	delete [] Q;
	delete [] K.w;
	delete [] K.p;
	delete [] K.x;
	delete [] K.bestx;
	
	//返回最优值 
	return K.bestp;
}
int main()
{
	int *p;
	int *w;
	int c = 0;
	int n = 0;
	int i = 0;
	cout<<"请输入背包个数："<<endl;
	cin>>n;
	p = new int[n + 1];
	w = new int[n + 1];
	p[0] = 0;
	w[0] = 0;
	cout<<"请输入个背包的价值："<<endl;
	for(i = 1; i <= n; i++)
	cin>>p[i];
	
	cout<<"请输入个背包的重量："<<endl;
	for(i = 1; i <= n; i++)
	cin>>w[i];
	
	cout<<"请输入背包容量："<<endl;
	cin>>c;
	cout<<Knapsack(p,w,c,n)<<endl;
	
	delete p;
	delete w;
}
/*
Input:
5
9 20 1 6 7
6 1 8 9 2 
20
Output:
1 1 0 1 1
42
*/