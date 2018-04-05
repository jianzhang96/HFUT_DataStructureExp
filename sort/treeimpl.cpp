#include "tree.h"

/*构建叶子节点*/
BinaryTreeNode* buildList (const std::vector<int>& L)
{
    BinaryTreeNode* btnList = new BinaryTreeNode[L.size()];

    for (std::size_t i=0; i<L.size(); ++i)
    {
        btnList[i].from = true;
        btnList[i].m_nValue = L[i];
        btnList[i].m_pLeft = NULL;
        btnList[i].m_pRight = NULL;
    }

    return btnList;
}

/*不足偶数时, 需补充节点*/
BinaryTreeNode* addMaxNode (BinaryTreeNode* list, int n)
{
    /*最大节点*/
    BinaryTreeNode* maxNode = new BinaryTreeNode(); //最大节点, 用于填充
    maxNode->from = true;
    maxNode->m_nValue = INT_MAX;
    maxNode->m_pLeft = NULL;
    maxNode->m_pRight = NULL;

    /*复制数组*/
    BinaryTreeNode* childNodes = new BinaryTreeNode[n+1]; //增加一个节点
    for (int i=0; i<n; ++i) {
        childNodes[i].from = list[i].from;
        childNodes[i].m_nValue = list[i].m_nValue;
        childNodes[i].m_pLeft = list[i].m_pLeft;
        childNodes[i].m_pRight = list[i].m_pRight;
    }
    childNodes[n] = *maxNode;
    delete[] list;
    list = NULL;

    return childNodes;
}

/*根据左右子树大小, 创建树*/
BinaryTreeNode* buildTree (BinaryTreeNode* childNodes, int n)
{
    if (n == 1) {
        return childNodes;
    }

    if (n%2 == 1) {
        childNodes = addMaxNode(childNodes, n);
    }


    int num = n/2 + n%2;
    BinaryTreeNode* btnList = new BinaryTreeNode[num];
    for (int i=0; i<num; ++i) {
        btnList[i].m_pLeft = &childNodes[2*i];
        btnList[i].m_pRight = &childNodes[2*i+1];
        bool less = btnList[i].m_pLeft->m_nValue <= btnList[i].m_pRight->m_nValue;
        btnList[i].from = less;
        btnList[i].m_nValue = less ?
                btnList[i].m_pLeft->m_nValue : btnList[i].m_pRight->m_nValue;
    }

    buildTree(btnList, num);

}

/*返回树根, 重新计算数*/
int rebuildTree (BinaryTreeNode* tree)
{
    int result = tree[0].m_nValue;

    std::stack<BinaryTreeNode*> nodes;
    BinaryTreeNode* node = &tree[0];
    nodes.push(node);

    while (node->m_pLeft != NULL) {
        node = node->from ? node->m_pLeft : node->m_pRight;
        nodes.push(node);
    }

    node->m_nValue = INT_MAX;
    nodes.pop();

    while (!nodes.empty())
    {
        node = nodes.top();
        nodes.pop();
        bool less = node->m_pLeft->m_nValue <= node->m_pRight->m_nValue;
        node->from = less;
        node->m_nValue = less ?
                node->m_pLeft->m_nValue : node->m_pRight->m_nValue;
    }

    return result;
}

/*从上到下打印树*/
void printTree (BinaryTreeNode* tree) {

    BinaryTreeNode* node = &tree[0];
    std::queue<BinaryTreeNode*> temp1;
    std::queue<BinaryTreeNode*> temp2;

    temp1.push(node);

    while (!temp1.empty())
    {
        node = temp1.front();
        if (node->m_pLeft != NULL && node->m_pRight != NULL) {
            temp2.push(node->m_pLeft);
            temp2.push(node->m_pRight);
        }

        temp1.pop();

        if (node->m_nValue == INT_MAX) {
            std::cout << "MAX"  << " ";
        } else {
            std::cout << node->m_nValue  << " ";
        }

        if (temp1.empty())
        {
            std::cout << std::endl;
            temp1 = temp2;
            std::queue<BinaryTreeNode*> empty;
            std::swap(temp2, empty);
        }
    }
}
