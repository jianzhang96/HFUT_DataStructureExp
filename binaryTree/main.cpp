/**
 *Copyright:
 *This code is free software; you can redistribute it and/or modify
 *it under the terms of the GPL-3.0
 *
 * @author zhangjian
 * @date 2017.11
 *
 */

///////////////////////////////////////////////////////////////////////

#include<iostream>
#include "./include/BinaryTree.h"

//#define BIN_EXP

using namespace std;
void binary_exp();
void bin_sort_exp();
int bin_search(int a[],int n,int x);

int main()
{
    #ifdef BIN_EXP
    binary_exp();
    #else
    bin_sort_exp();
    #endif // BIN_EXP
    return 0;
}

int bin_search(int a[],int n,int key)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(key<a[mid]) hi=mid-1;
        else if(key>a[mid]) lo=mid+1;
        else return mid;
    }
    return -1;
}
void bin_sort_exp()
{
    //(1) 对下列数据表，分别采用二分查找算法实现查找，
    //给出查找过程依次所比较的元素（的下标），并以二分查找的判定树来解释。
    int a1[]={1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,100};
    int a2[]={2,3,5,7,8,10,12,15,18,20,22,25,30,35,40,45,50,55,60,80,100};
    int e1[]={2,8,20,30,50,5,15,33,110 };
    int e2[]={22,8,80,3,100,1,13,120};
    cout<<"(1)二分查找"<<endl;
    cout<<"第一组数据:";
    for(int i=0;i<sizeof(a1)/sizeof(a1[0]);i++) cout<<a1[i]<<' ';
    cout<<endl;
    for(int i=0;i<sizeof(e1)/sizeof(e1[0]);i++)
    {
        cout<<e1[i]<<": "<<bin_search(a1,sizeof(a1)/sizeof(a1[0]),e1[i])<<endl;
    }
    cout<<endl;
    cout<<"第二组数据:";
    for(int i=0;i<sizeof(a2)/sizeof(a2[0]);i++) cout<<a2[i]<<' ';
    cout<<endl;
    for(int i=0;i<sizeof(e2)/sizeof(e2[0]);i++)
    {
        cout<<e2[i]<<": "<<bin_search(a2,sizeof(a2)/sizeof(a2[0]),e2[i])<<endl;
    }
    cout<<endl;
    //下面的实验和二叉排序树有关，所以在类中实现
    //(2) 设计出在二叉排序树中插入结点的算法，在此基础上实现构建二叉排序树的算法。
    cout<<"(2) 设计出在二叉排序树中插入结点的算法，在此基础上实现构建二叉排序树的算法。"<<endl;
    int a3[]={100,150,120,50,70,60,80,170,180,160,110,30,40,35,175};
    int a4[]={100,70,60,80,150,120,50,160,30,40,170,180,175,35};
    BinaryTree st1(a3,sizeof(a3)/sizeof(a3[0]));
    BinaryTree st2(a4,sizeof(a4)/sizeof(a4[0]));
    cout<<"第一组数据："<<endl;
    st1.print(2);
    cout<<"第二组数据："<<endl;
    st2.print(2);
    cout<<endl;
    //(3) 设计算法在二叉排序树中查找指定值的结点。
    cout<<"(3) 设计算法在二叉排序树中查找指定值的结点。"<<endl;
    int e3[]={150,70,160,190,10,55,175 };
    for(int i=0;i<sizeof(e3)/sizeof(e3[0]);i++)
        st1.search(e3[i]);
    cout<<endl;
    //(4) 设计算法在二叉排序树中删除特定值的结点。
    cout<<"(4) 设计算法在二叉排序树中删除特定值的结点."<<endl;
    cout<<"删除前：";st1.print(2);
    cout<<"删除30：";st1.remove(30); st1.print(2);
    cout<<"删除150：";st1.remove(150); st1.print(2);
    cout<<"删除100: ";st1.remove(100); st1.print(2);
    cout<<endl;
    //(5) 已知整型数组A[1..26]递增有序，设计算法以构造一棵平衡的二叉排序树来存放该数组中的所有元素。
    cout<<"(5) 已知整型数组A[1..26]递增有序，设计算法以构造一棵平衡的二叉排序树来存放该数组中的所有元素。"<<endl;
    int a5[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    int a6[]={1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,277,302,328};
    BinaryTree avl_st1(a5,sizeof(a5)/sizeof(a5[0]),true);
    BinaryTree avl_st2(a6,sizeof(a6)/sizeof(a6[0]),true);
    cout<<"第一组数据："<<endl;
    avl_st1.print_by_level();
    cout<<endl;
    cout<<"第二组数据："<<endl;
    avl_st2.print_by_level();
    cout<<endl<<endl;
    //

    cout<<"完成"<<endl;

}
void binary_exp()
{
    BinaryTree tree1("./btr151.txt");
    BinaryTree tree2("./btr21.txt");
//    <1>打印出二叉树的三种遍历序。
//    实验测试数据基本要求：
//    第一组数据： bt151.btr
//    第二组数据： bt21.btr
    cout<<"<1>打印出二叉树的三种遍历序。"<<endl;
    for(int i=1;i<=2;i++)
    {
        cout<<"第"<<i<<"组数据："<<endl;
        cout<<"先序，中序，后序遍历输出"<<endl;
        if(i==1){
            tree1.print(1);
            tree1.print(2);
            tree1.print(3);
        }
        else{
            tree2.print(1);
            tree2.print(2);
            tree2.print(3);
        }
    }
//    <2>设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数。
    cout<<endl;
    cout<<"<2>设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数。"<<endl;
    cout<<"第一组数据bt151.btr："<<endl;
    tree1.inorder_and_level();
    cout<<"第二组数据bt21.btr："<<endl;
    tree2.inorder_and_level();
    cout<<endl;
//    <3>求二叉树的高度。
//	实验测试数据基本要求：
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr
    cout<<"<3>求二叉树的高度。"<<endl;
    BinaryTree tree3("./btr261.txt");
    cout<<"第一组数据： bt261.btr"<<endl;
    cout<<tree3.height()<<endl;
    cout<<"第二组数据： bt21.btr"<<endl;
    cout<<tree2.height()<<endl;

    cout<<endl;
//    <4>求二叉树的结点数。
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr
    cout<<"<4>求二叉树的结点数。"<<endl;
    cout<<"第一组数据： bt261.btr: "<<tree3.count()<<endl;
    cout<<"第二组数据： bt21.btr: "<<tree2.count()<<endl;

    cout<<endl;
//    <5>求二叉树的叶子结点数。
//	实验测试数据基本要求：
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr
    cout<<"<5>求二叉树的叶子结点数。"<<endl;
    cout<<"第一组数据：bt261.btr: "<<tree3.leaves()<<endl;
    cout<<"第二组数据：bt21.btr: "<<tree2.leaves()<<endl;
    cout<<endl;

//    <6>求二叉树的度为2的结点数。
//	实验测试数据基本要求：
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr

    cout<<"<6>求二叉树的度为2的结点数。"<<endl;
    cout<<"第一组数据： bt261.btr: "<<tree3.two_degree_nodes()<<endl;
    cout<<"第二组数据： bt21.btr: "<<tree2.two_degree_nodes()<<endl;
    cout<<endl;

//    <7>键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，不存在时给出相应提示信息。
//    对兄弟结点和孩子结点，存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子。
//	实验测试数据基本要求：
//    第一组数据： bt31.btr
//    第二组数据： bt21.btr

    BinaryTree tree4("./btr31.txt");
    cout<<"<7>键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，不存在时给出相应提示信息。"<<endl;
    cout<<"第一组数据： bt31.btr:"<<endl;
    cout<<"输入一个树中的字符：";
    char t;cin>>t;
    tree4.about_x(t);
    cout<<endl<<endl;
    cout<<"第二组数据： bt21.btr"<<endl;
    cout<<"输入一个字符：";cin>>t;
    tree2.about_x(t);
    cout<<endl<<endl;

//    <8>键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。
//	实验测试数据基本要求：
//    第一组数据： bt26.btr
//    第二组数据： bt21.btr
    BinaryTree tree5("./btr26.txt");
    cout<<"<8>键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。"<<endl;
    cout<<"第一组数据："<<endl;
    cout<<"输入一个元素：";cin>>t;
    cout<<"层数为："<<tree5.find_level(t)<<endl;
    cout<<"第二组数据："<<endl;
    cout<<"输入一个元素：";cin>>t;
    cout<<"层数为:"<<tree2.find_level(t)<<endl;
    cout<<endl;

//    <9>将按顺序方式存储在数组中的二叉树转换为二叉链表形式。（数组中要扩展为完全二叉树）。
//	实验测试数据基本要求：
//    第一组数据： bt8.btr
//    第二组数据： bt14.btr



//<10>交换二叉树中每个结点的左右孩子指针的值。（即：左子树变为右子树，右子树变为左子树）。
//	实验测试数据基本要求：
//    第一组数据： bt151.btr
//    第二组数据： bt21.btr
    cout<<"<10>交换二叉树中每个结点的左右孩子指针的值。"<<endl;
    cout<<"第一组数据： bt151.btr:"<<endl;
    BinaryTree tree6("./btr151.txt");
    tree6.print(2);
    tree6.change_right_left();
    tree6.print(2);
    cout<<"第二组数据： bt21.btr: "<<endl;
    tree2.print(2);
    tree2.change_right_left();
    tree2.print(2);
    cout<<endl;


    cout<<"选做实验"<<endl;
//    <11>复制一棵二叉树T到T1。
//	实验测试数据基本要求：
//    第一组数据： bt151.btr
//    第二组数据： bt21.btr
    cout<<"<11>复制一棵二叉树T到T1。"<<endl;
    cout<<"第一组数据： bt151.btr"<<endl;
    BinaryTree tree62(tree6);
    tree62.print(1);
    cout<<"第二组数据：bt21.btr"<<endl;
    BinaryTree tree22(tree2);
    tree22.print(1);
    cout<<endl;
//    <12>输出二叉树从每个叶子结点到根结点的路径（经历的结点）。
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr
    cout<<"<12>输出二叉树从每个叶子结点到根结点的路径（经历的结点）。"<<endl;
    cout<<"第一组数据： bt261.btr"<<endl;
    tree3.leaves2root();
    cout<<"第二组数据： bt21.btr"<<endl;
    tree2.change_right_left();
    tree2.leaves2root();
    cout<<endl;

//    <13>对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，
//    即按层次打印。（提示：需要使用队列）
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr

    cout<<"<13>对二叉链表表示的二叉树,按层次打印节点"<<endl;
    cout<<"第一组数据： bt261.btr"<<endl;
    tree3.print_by_level();
    cout<<"第二组数据： bt21.btr"<<endl;
    tree2.print_by_level();
    cout<<endl;

//    <14>对二叉链表表示的二叉树，求2个结点最近的共同祖先。
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr
    cout<<"<14>对二叉链表表示的二叉树，求2个结点最近的共同祖先。"<<endl;
    cout<<"第一组数据： bt261.btr"<<endl;
    cout<<tree3.near_common_ancestor('l','e')<<endl;
    cout<<"第二组数据： bt21.btr"<<endl;
    cout<<tree2.near_common_ancestor('u','m')<<endl;
    cout<<endl;

//    <15>求二叉树中一条最长的路径长度（边数），并输出路径上的个结点值。
//    第一组数据： bt261.btr
//    第二组数据： bt21.btr
    cout<<"<15>求二叉树中一条最长的路径长度（边数），并输出路径上的个结点值。"<<endl;
    cout<<"第一组数据： bt261.btr"<<endl;
    tree3.leaves2root(true);
    cout<<"第二组数据： bt21.btr"<<endl;
    tree2.leaves2root(true);
    cout<<endl;


}
