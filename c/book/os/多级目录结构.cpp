#include<iostream>
using namespace std;
typedef struct File
{
	string file_name;	//the file's name
	int file_size;		//the file's size
	int file_count; 	//the file contain child_file amount
	int file_type;		//0 is read only;1 is write only;2 is read and write;
	string file_pos;	//the file's position
	string file_remark;	//the file's remark
	string file_create_time;//the file's create time
	string file_change_time;//the file's change time
	string file_visit_time;//the file's visit time
}File; 
typedef File NodeData;
typedef struct TreeNode
{
	NodeData data;
	struct TreeNode *front;
	struct TreeNode *rear;
}Tree;
void InitTree(Tree *&tree)
{
	tree=new Tree();
	tree->front=NULL;
	tree->rear=NULL;
}
void DestroyTree(Tree *&tree)
{
	
}
bool IsEmpty(Tree *tree)
{
	tree->front==NULL;
}
bool AddNodes(Tree *&tree,NodeData data)
{
	
}
int getFileCount(Tree *tree)
{
	
}
int getFileSize(Tree *tree)
{
	
}
void Test()
{
	Tree *tree;
	InitTree(tree);
	DestroyTree(tree); 
}
int main()
{
	return 0;
}