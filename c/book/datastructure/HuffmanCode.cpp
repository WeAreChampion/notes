#include<iostream>
using namespace std;
#define N 50
#define M 2*N-1
typedef struct {
	char data[5];//节点值
	int weight;//权值
	int parent;//双亲节点
	int lchild;//左节点
	int rchild;//右节点
} HTNode;
typedef struct {
	char cd[N];//存huffman编码
	int start;//存储编码的位置
} HCode;
//创建huffman树
void CreatHT(HTNode ht[], int n)
{
	int i, k, lnode, rnode;
	int min1, min2;
	for(i = 0; i < 2 * n; i++) { //init
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for(i = n; i < 2 * n - 1; i++) { //构造huffman树，构造n-1个节点
		min1 = min2 = 32767;	//init
		lnode = rnode = -1;	//lnode和rnode为最小权重的两个节点位置
		for(k = 0; k <= i - 1; k++) { //在未构造二叉树的节点中查找
			if(ht[k].parent == -1) {
				if(ht[k].weight < min1) {
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;//记录左节点值
				} else if(ht[k].weight < min2) {
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}
		ht[lnode].parent = i;//存储双亲节点的节点值
		ht[rnode].parent = i;
		ht[i].weight = ht[lnode].weight+ht[rnode].weight;//生成新节点
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;//分别指向孩子节点
	}
}
//构造code
void CreateCode(HTNode ht[], HCode hcd[], int n)
{
	int i, f, c;
	HCode hc;
	for(i = 0; i < n; i++) {
		hc.start = n;//从后往前依次存储
		c = i;
		f = ht[i].parent;
		while(f != -1) {
			if(ht[f].lchild == c) { //处理左孩子节点
				hc.cd[hc.start--] = '0';
			} else { //处理右孩子节点
				hc.cd[hc.start--] = '1';
			}
			c = f;//以新的父亲节点作为新节点
			f = ht[f].parent;//保持父亲其父亲节点
		}
		hc.start++;//huffmanCode最开始字符
		hcd[i] = hc;
	}
}
void DispHCode(HTNode ht[], HCode hcd[], int n)
{
	int i,k;
	int sum = 0, m = 0, j;
	cout << "The Huffmancode is:" << endl;
	for(i = 0; i < n; i++) {
		j = 0;
		cout << ht[i].data << "\t";
		for(k = hcd[i].start; k <= n; k++) {
			cout << hcd[i].cd[k];//output Code
			j++;
		}
		m += ht[i].weight;
		sum += ht[i].weight * j;//求平均长度
		cout << endl;
	}
	cout << "The average is =" << 1.0 * sum / m << endl;
}
int main()
{
	int n = 15, i;
	char *str[] = {"The", "of", "a", "to", "and", "in", "that", "he", "is", "at", "on", "for", "His", "are", "be"
	             };
	int fnum[] = {
		1192, 677, 541, 518, 462, 450, 242, 195, 190, 181,174, 157, 138, 124, 123
	};
	HTNode ht[M];
	HCode hcd[N];
	for(i = 0; i < n; i++) {
		strcpy(ht[i].data, str[i]);
		ht[i].weight = fnum[i];
	}
	cout << endl;
	CreatHT(ht, n);
	CreateCode(ht, hcd, n);
	DispHCode(ht, hcd, n);
	cout << endl;
	return 0;
}