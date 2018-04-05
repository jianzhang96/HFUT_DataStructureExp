#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

/*树的结构*/
struct BinaryTreeNode{
    bool from; //判断来源, 左true, 右false
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

/*构建叶子节点*/
BinaryTreeNode* buildList (const std::vector<int>& L);
/*不足偶数时, 需补充节点*/
BinaryTreeNode* addMaxNode (BinaryTreeNode* list, int n);
/*根据左右子树大小, 创建树*/
BinaryTreeNode* buildTree (BinaryTreeNode* childNodes, int n);
/*返回树根, 重新计算数*/
int rebuildTree (BinaryTreeNode* tree);
/*从上到下打印树*/
void printTree (BinaryTreeNode* tree);
