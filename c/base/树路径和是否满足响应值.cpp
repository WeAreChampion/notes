#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};
int count = 0;

void findPath(BinaryTreeNode *pTreeNode,
        int expectedSum,
        vector<int> &path,
        int &currentSum) {
    if(!pTreeNode)
		return;
	//节点入栈，当前和累加 
    currentSum += pTreeNode->m_nValue;
    path.push_back(pTreeNode->m_nValue);
    //是否为叶子节点 
    bool isLeaf = !(pTreeNode->m_pLeft) && !(pTreeNode->m_pRight);
    //如果为叶子节点且和为exceptedSum 
    if(currentSum == expectedSum && isLeaf) {   
        vector<int>::iterator iter;
        //输出路径
        for(iter = path.begin(); iter != path.end(); iter++) {   
            cout << *iter << "\t";
        }   
        cout << endl;
    }
    //递归遍历左子树 
    if(pTreeNode->m_pLeft)
        findPath(pTreeNode->m_pLeft, expectedSum, path, currentSum);
    //递归遍历右子树 
	if(pTreeNode->m_pRight)
        findPath(pTreeNode->m_pRight, expectedSum, path, currentSum);
	//即到达叶子节点时，回溯，节点出栈 
    currentSum -= pTreeNode->m_nValue;
    path.pop_back();
}
//创建树 
void addTree(BinaryTreeNode **T, int num) {
    if(*T == NULL) {   
		*T = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
		(*T)->m_nValue = num;
        (*T)->m_pLeft = NULL;
        (*T)->m_pRight = NULL;
    }   
    else if((*T)->m_nValue > num)
         addTree(&((*T)->m_pLeft), num);
    else if((*T)->m_nValue < num)
        addTree(&((*T)->m_pRight), num);
    else
        cout << "重复加入同一结点" << endl;
}
int main()
{
    BinaryTreeNode *T = NULL;
    addTree(&T, 10);
    addTree(&T, 12);
    addTree(&T, 5);
    addTree(&T, 7);
    addTree(&T, 4);

    vector<int> path;
    int sum = 0;
    findPath(T, 22, path, sum);
    return 0;
}