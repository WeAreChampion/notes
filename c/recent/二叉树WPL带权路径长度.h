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

/**
	To get the Tree's WPL
*/
int getWPL(BTree *root) {
	return WPL(root, 0);
}

/**
	To calculate the WPL
*/
int WPL(BTree *root, int depth) {
	
	// is leaf node
	if(root->left == NULL && root->right == NULL) {
		return root->weight * depth;
	}
	/*
		递归访问左子树，右子树;深度加1
	*/
	return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
}