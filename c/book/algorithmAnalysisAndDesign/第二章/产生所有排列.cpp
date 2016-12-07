#include<iostream>
using namespace std;
/**
	������������
*/

/**
	To swap the vlaue
*/
template<class Type>
void Swap(Type &a, Type &b) {
	Type temp = a;
	a = b;
	b = temp;
}

/**
	1.����ݹ����
		1) n = 1ʱ��ΨһԪ�أ��ݹ����
		2) n > 1ʱ��������������(r1)Perm(R1), (r2)Perm(R2)...(rn)Perm(Rn)����
			����Ri = R - {ri}
	
	2. ������list[]�в�����k��m����������
	
	3. ����˵��
		list[] : ��Ҫ�������е�����
		k : �������еĵ�һ��Ԫ�ص�λ��
		m : �������е����һ��Ԫ��λ��
	
	4. �ݹ����
		��k=mʱ����ʱֻ��һ��Ԫ�أ��ݹ�������н����������
	
*/
template<class Type>
void getPerm(Type list[], int k, int m) {
	int i;
	
	/*
		�ݹ���ڣ�ֻ��һ��Ԫ��
	*/
	if(k == m - 1) {
		// �����Ӧ������
		for(i = 0; i < m; i++) {
			cout << list[i];
		}
		cout << endl;
	} else {// �ж��Ԫ��
		
		// ͨ���ݹ����β���[k, m - 1]����������
		for(i = k; i < m; i++) {
			
			// ����
			Swap(list[k], list[i]);
			
			// �ݹ����k+1 - m �����������
			getPerm(list, k + 1, m);
			
			// ����
			Swap(list[k], list[i]);
		}
	}
}
int main()
{
	int list[10];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> list[i];
	}
	getPerm(list, 0, n);
	return 0;
}
/*
Input:
3
1 2 3

*/