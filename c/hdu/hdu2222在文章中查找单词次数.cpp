#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
/*
	给你很多个单词，然后给你一篇文章，问给出的单词在文章中出现的次数。
	解题思路：AC自动机入门题。需要注意的就是可能有重复单词
	Trie(字典树) + KMP(模式匹配算法)
*/
#define N 500010
char str[1000010], keyword[51];//模式串和输入的单词
int head, tail;//队列的头和尾

struct node
{
	//失败指针，The fail point
	node *fail;
	
	// To save all words(a,b...z), counts are 26
	//每个节点的所有子节点最多是26个(a-z)
	node *next[26];
	
	// To save the count of same words
	//是否为单词的最后一个节点
	int count;
	
	// 构造方法，初始化
	node() //init
	{
		fail = NULL;
		count = 0;
		
		//
		for(int i = 0; i < 26; ++i)
			next[i] = NULL;
	}
}*q[N];//队列，方便用于bfs构造失败指针
node *root;
/*
	建立Trie树(字典树)
*/
void insert(char *str) //建立Trie
{
	int temp, len;
	
	// p -> root
	node *p = root;
	
	// To save the str length
	len = strlen(str);
	
	// for each the str
	for(int i = 0; i < len; ++i) {
		
		// To save the convert int value
		temp = str[i] - 'a';
		
		// if don't have the node then new node and insert behind node p
		if(p->next[temp] == NULL)
			p->next[temp] = new node();
		
		//p -> the last node 
		p = p->next[temp];
	}
	//在单词的最后一个节点count+1,代表一个单词
	p->count++;
}
/*
	构造失败指针
	设这个节点上的字母为C，沿着他父亲的失败指针走，直到走到一个节点，
	他的儿子中也有字母为C的节点。然后把当前节点的失败指针指向那个字母也为C的儿子。
	如果一直走到了root都没找到，那就把失败指针指向root。具体操作起来只需要：先把root
	加入队列(root的失败指针指向自己或者NULL)，这以后我们每处理一个点，就把它的所有儿
	子加入队列，队列为空。
*/
void build_ac() //初始化fail指针，BFS
{
	q[tail++] = root;
	while(head != tail)
	{
		node *p = q[head++]; //弹出队头
		node *temp = NULL;
		
		// 26个字母(26 words like (a,b...z))
		for(int i = 0; i < 26; ++i)
		{
			if(p->next[i] != NULL)
			{
				if(p == root) //第一个元素fail必指向根
					p->next[i]->fail = root;
				else
				{
					temp = p->fail; //失败指针
					while(temp != NULL) //2种情况结束：匹配为空or找到匹配
					{
						if(temp->next[i] != NULL) //找到匹配
						{
							p->next[i]->fail = temp->next[i];
							break;
						}
						temp = temp->fail;
					}
					if(temp == NULL) //为空则从头匹配
						p->next[i]->fail = root;
				}
				q[tail++] = p->next[i]; //入队
			}
		}
	}
}

int query() //扫描
{
	int index, len, result;
	node *p = root; //Tire入口
	result = 0;
	len = strlen(str);
	for(int i = 0; i < len; ++i)
	{
		index = str[i] - 'a';
		while(p->next[index] == NULL && p != root) //跳转失败指针
			p = p->fail;
		p = p->next[index];
		if(p == NULL)
			p = root;
		node *temp = p; //p不动，temp计算后缀串
		while(temp != root && temp->count != -1)
		{
			result += temp->count;
			temp->count = -1;
			temp = temp->fail;
		}
	}
	return result;
}

int main()
{
	int ncase, num;
	scanf("%d", &ncase);
	while(ncase--)
	{
		head= tail = 0;
		
		// new node for root 
		root = new node();
		scanf("%d", &num);
		getchar();
		for(int i = 0; i < num; ++i)
		{
			//input the keyword
			gets(keyword);
			
			// To insert the keyword into root
			insert(keyword);
		}
		build_ac();
		scanf("%s", str);
		printf("%d\n", query());
	}
	return 0;
}
/*
Sample Input
1
5
she
he
say
shr
her
yasherhs
 

Sample Output
3
*/