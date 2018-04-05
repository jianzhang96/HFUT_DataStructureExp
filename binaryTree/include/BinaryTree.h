#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef int Type;

struct nodeinfo
{
    char dat;
    int lef,rig;
};

class BinaryTree
{
private:
    struct node
    {
        Type data;
        struct node * left,*right;
        int height;//节点的高度,用于计算父节点的平衡因子
    };

    node * root;

    void preorder_show(node * t);
    void inorder_show(node *t);
    void postorder_show(node *t);
    int cal_height(node * pt);
    int cal_nodes(node* pt);
    int cal_leaves(node * pt);
    int cal_two_degree(node * pt);
    void find_father(node *& res,Type child,node* pt=nullptr);
    node* search_sort(node*pt,Type x,bool prt=true);
    Type maximum();
    Type minimum();


public:
    BinaryTree();
    BinaryTree(string filepath);

    void creat_node(node *& pt, vector<nodeinfo> vt,int &i);
    void creat_node(node *&pt,node *pc);
    BinaryTree(const BinaryTree& tc);

    void print(int flag);
    void inorder_and_level(node * pt=nullptr,int level=1);
    int height();
    int count();
    int leaves();
    int two_degree_nodes();
    void about_x(Type x);
    int find_level(Type x,int lev=1,node* pt=nullptr);
    void change_right_left(node* t=nullptr);
    void clear(node* t);
    void leaves2root(bool longest=false,node* pt=nullptr,string path="");
    void print_by_level();
    Type near_common_ancestor(Type a,Type b);
    //二叉排序树的方法
    BinaryTree(Type a[],int n,bool avl=false);
    void insert(node*& pt,Type x);
    void search(Type x);
    void remove(Type x);
    //平衡查找树的方法
    int height_avl(node* pnode);
    node* leftRotation(node* proot);
    node* rightRotation(node* proot);
    node* rightLeftRotation(node* proot);
    node* leftRightRotation(node* proot);
    node* insert_avl(node*&pnode,Type key);
    node* remove_avl(node*&pnode,Type key);
    node* maximum(node* pnode);
    node* minimum(node* pnode);

    virtual ~BinaryTree();
};

#endif // BINARYTREE_H
