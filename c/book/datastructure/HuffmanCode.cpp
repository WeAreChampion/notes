#include<iostream>
using namespace std;
#define N 50
#define M 2*N-1
typedef struct {
	char data[5];//�ڵ�ֵ
	int weight;//Ȩֵ
	int parent;//˫�׽ڵ�
	int lchild;//��ڵ�
	int rchild;//�ҽڵ�
} HTNode;
typedef struct {
	char cd[N];//��huffman����
	int start;//�洢�����λ��
} HCode;
//����huffman��
void CreatHT(HTNode ht[], int n)
{
	int i, k, lnode, rnode;
	int min1, min2;
	for(i = 0; i < 2 * n; i++) { //init
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for(i = n; i < 2 * n - 1; i++) { //����huffman��������n-1���ڵ�
		min1 = min2 = 32767;	//init
		lnode = rnode = -1;	//lnode��rnodeΪ��СȨ�ص������ڵ�λ��
		for(k = 0; k <= i - 1; k++) { //��δ����������Ľڵ��в���
			if(ht[k].parent == -1) {
				if(ht[k].weight < min1) {
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;//��¼��ڵ�ֵ
				} else if(ht[k].weight < min2) {
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}
		ht[lnode].parent = i;//�洢˫�׽ڵ�Ľڵ�ֵ
		ht[rnode].parent = i;
		ht[i].weight = ht[lnode].weight+ht[rnode].weight;//�����½ڵ�
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;//�ֱ�ָ���ӽڵ�
	}
}
//����code
void CreateCode(HTNode ht[], HCode hcd[], int n)
{
	int i, f, c;
	HCode hc;
	for(i = 0; i < n; i++) {
		hc.start = n;//�Ӻ���ǰ���δ洢
		c = i;
		f = ht[i].parent;
		while(f != -1) {
			if(ht[f].lchild == c) { //�������ӽڵ�
				hc.cd[hc.start--] = '0';
			} else { //�����Һ��ӽڵ�
				hc.cd[hc.start--] = '1';
			}
			c = f;//���µĸ��׽ڵ���Ϊ�½ڵ�
			f = ht[f].parent;//���ָ����丸�׽ڵ�
		}
		hc.start++;//huffmanCode�ʼ�ַ�
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
		sum += ht[i].weight * j;//��ƽ������
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