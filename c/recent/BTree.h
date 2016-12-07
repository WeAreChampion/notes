#include<iostream>
using namespace std;
/**
	The Tree Node
*/
typedef struct TreeNode {
	int weight;
	struct TreeNode *left;
	struct TreeNode *right;
}BTree;