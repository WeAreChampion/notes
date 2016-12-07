#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dictree {
	struct dictree *child[26];
	int n;
};
struct dictree *root;
/*
	�����ֵ���
*/
void insert(char *source)
{
	int i,j;
	int len;
	struct dictree *current, *newnode;

	len = strlen(source);
	current = root;

	for(i = 0; i < len; i++) {
		if(current->child[source[i] - 'a'] != 0) {//����ֵ��Ϊ0

			//�����Ϊ������ʽ
			current = current->child[source[i] - 'a'];

			//����+1
			current->n++;
		} else {//Ϊ0�������µĽڵ㣬����ʼ���������ӽڵ�
			newnode = (struct dictree *) malloc(sizeof(struct dictree));
			//��ʼ���ӽڵ�Ϊ0
			for(j = 0; j < 26; j++)
				newnode->child[j] = 0;

			//��������ָ���½ڵ�
			current->child[source[i] - 'a'] = newnode;

			//�ı䵱ǰָ��ָ�������ڵ�
			current = newnode;
			current->n = 1;
		}
	}
}
int find(char *source)
{
	int i;
	int len;
	struct dictree *current;
	len = strlen(source);

	//�մ�
	if(len == 0)
		return 0;

	current = root;
	for(i = 0; i < len; i++) {

		//δ�ߵ�ĩβ�����з�֧������
		if(current->child[source[i] - 'a'] != 0) {
			current = current->child[source[i] - 'a'];
		} else//û����Ӧ��ǰ׺
			return 0;
	}
	return current->n;
}
int main()
{
	char temp[11];
	int i;

	root=(struct dictree *) malloc(sizeof(struct dictree));
	for(i = 0; i < 26; i++)
		root->child[i] = 0;
	root->n = 0;

	//���뵥�ʱ������ֵ���
	while(gets(temp), strcmp(temp,"") != 0)
		insert(temp);

	//�ֵ�������
	while(gets(temp) != 0)
		printf("%d\n", find(temp));
	return 0;

}
/*
Sample Input
banana
band
bee
absolute
acm

ba
b
band
abc


Sample Output
2
3
1
0
*/