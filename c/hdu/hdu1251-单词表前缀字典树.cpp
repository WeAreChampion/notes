#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dictree {
	struct dictree *child[26];
	int n;
};
struct dictree *root;
/*
	建立字典树
*/
void insert(char *source)
{
	int i,j;
	int len;
	struct dictree *current, *newnode;

	len = strlen(source);
	current = root;

	for(i = 0; i < len; i++) {
		if(current->child[source[i] - 'a'] != 0) {//索引值不为0

			//作差，改为索引方式
			current = current->child[source[i] - 'a'];

			//数量+1
			current->n++;
		} else {//为0，开辟新的节点，并初始化其所有子节点
			newnode = (struct dictree *) malloc(sizeof(struct dictree));
			//初始化子节点为0
			for(j = 0; j < 26; j++)
				newnode->child[j] = 0;

			//在其后添加指向新节点
			current->child[source[i] - 'a'] = newnode;

			//改变当前指针指向新增节点
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

	//空串
	if(len == 0)
		return 0;

	current = root;
	for(i = 0; i < len; i++) {

		//未走到末尾，还有分支可以走
		if(current->child[source[i] - 'a'] != 0) {
			current = current->child[source[i] - 'a'];
		} else//没有相应的前缀
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

	//输入单词表，建立字典树
	while(gets(temp), strcmp(temp,"") != 0)
		insert(temp);

	//字典树查找
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