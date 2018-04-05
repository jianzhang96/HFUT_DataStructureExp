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
using namespace std;

//不带头结点的泛型链表
template<typename Type>
class linkedList
{
private:
    struct Node
    {
        Type data;
        struct Node *next;
    };
    Node *root; //根
    int size;  //记录链表大小
public:
    linkedList();
    linkedList(Type*,int n,bool rear=true);
    virtual ~linkedList();

    void clearList();//清空链表
    void reCtor(Type* a,int n,bool rear=true);//重构
    int length() const;
    bool getElement(int i,/*Node* &*/Type& t) const;
    bool locate(Type x,/*Node*&*/int& t);
    bool listInsert(int i,Type x);
    bool listDelete(int i);
    void show() const;

    //递增有序插入一个元素保持递增有序
    void incrementalInsert(const Type& x);
    //数值为奇数和偶数的值分别放到两个链表中
    void seperateOddEven(linkedList<Type>& a,linkedList<Type>& b) const;
    //删除递增有序但链表中重复元素
    void removeDupEle();
    //递增有序合并成一个集合，不申请新节点
    void mergelist(linkedList<Type>& b);
    int findK(int k);


};


//倒数位置k的值
template<typename Type>
int linkedList<Type>::findK(int k)
{
    Node *p=root,*q=root;//p、q指向链表的第一个结点,p为工作指针
    int num = 0;
    while(p && num < k) {
        p = p -> next;
        num ++;
    }//遍历链表，找第k个位置结点
    if(p == NULL ) {
        if(num != k) {//p到尾且链表元素个数小于k
            return 0;
        }else {//p到尾且第k个结点恰好为尾结点
            cout<<q -> data;
        }
    }else {//找到第k个结点，p、q向后移动，p到链尾，q指的就是第k个位置的结点
        while(p) {
            p = p -> next;
            q = q -> next;
        }
        cout<<q -> data;
        return 1;
    }
}


//类方法实现
template<typename Type>
linkedList<Type>::linkedList()
{
    root=nullptr;
    size=0;
}

template<typename Type>
linkedList<Type>::linkedList(Type *a,int n,bool rear)
{
    //尾插法建立链表，数据来自数组
    if(rear){
        Node *R,*u;
        R=root;
        for(int i=0;i<n;i++)
        {
            u=new Node;
            u->data=a[i];
            if(i==0) root=u;
            else R->next=u;
            R=u;

        }
        R->next=nullptr;
        size=n;
    }//头插法
    else{
        Node* u;
        for(int i=0;i<n;i++){
            u=new Node;
            u->data=a[i];
            u->next=root;
            root=u;
        }
        size=n;
    }
}

template<typename Type>
int linkedList<Type>::length() const
{
    return size;
}

template<typename Type>
bool linkedList<Type>::getElement(int i,/*Node *&*/Type& t) const
{
    Node *p=root;
    //找到对应位置的节点
    for(int j=1;p&&j!=i;j++,p=p->next)
        continue;
    //空表，超出范围
    if(!p) return false;
    else {
        t=p->data;
        return true;
    }
}

template<typename Type>
bool linkedList<Type>::locate(Type x,/*Node *&*/int& t)
{
    Node *p=root;
    int ct=1;
    while(p&&p->data!=x)
    {
        p=p->next;ct++;
    }

    if(p==nullptr) return false;
    else {
        //t=p;
        t=ct;
        return true;
    }
}

//增删元素，不含头结点
template<typename Type>
bool linkedList<Type>::listInsert(int i,Type x)
{
    if(i<1||i>size+1) return false;
    Node *p=new Node;
    p->next=root;
    //搜索前驱节点
    for(int j=0;p&&j!=i-1;j++,p=p->next)
        continue;
    Node *u=new Node;
    u->data=x;
    u->next=p->next;
    if(size==0||p->next==root) root=u;//根节点的更新
    p->next=u;

    size++;
}

template<typename Type>
bool linkedList<Type>::listDelete(int i)
{
    if(i<1||i>size) return false;
    Node *p=new Node;
    p->next=root;
    for(int k=0;p&&k!=i-1;k++,p=p->next)
        continue;
    if(p->next==root)
        root=root->next;
    else {
        Node *u=p->next;
        p->next=u->next;
        delete u;
    }

    size--;
    if(size==0) root=nullptr;
    return true;

}

template<typename Type>
void linkedList<Type>::clearList()
{
    Node* p=root,*u;
    while(p)
    {
        u=p->next;
        delete p;
        p=u;
    }
    root=nullptr;
    size=0;
}

template<typename Type>
void linkedList<Type>::reCtor(Type* a,int n,bool rear)
{
    this->clearList();
    //尾插法创建的是与数组同向
    if(rear){
        Node *r,*u;
        for(int i=0;i<n;i++,size++)
        {
            u=new Node;
            u->data=a[i];
            if(size==0) root=u;
            else r->next=u;
            r=u;
        }
        r->next=nullptr;//最后一个指针置为空
    }
    //头插法
    else {
        Node *u;
//        u->next=nullptr;
        for(int i=0;i<n;i++) {
            u=new Node;
            u->data=a[i];
            u->next=root;
            root=u;
        }
    }
    size=n;
}


template<typename Type>
void linkedList<Type>::show() const
{
    cout<<size<<":( ";
    Node *p=root;
    while(p)
    {
        cout<<p->data;
        if(p->next!=nullptr) cout<<" -> ";
        p=p->next;
    }
    cout<<" )"<<endl;
}
template<typename Type>
linkedList<Type>::~linkedList()
{
    Node* p=root;
    Node* t;
    while(p)
    {
        t=p->next;
        delete p;
        p=t;
    }
}


template<typename Type>
void linkedList<Type>::incrementalInsert(const Type& x)
{
    Node *p=root;
    Node *u=new Node;
    u->data=x;
    if(p->data>x)//插入为第一个元素
    {
        u->next=root;
        root=u;
        return;
    }

    while(p->next&&p->next->data<x)
        p=p->next;
    if(p->next==nullptr)//插入为最后一个元素
    {
        p->next=u;
        u->next=nullptr;
    }
    else{
        Node* t=p->next;
        p->next=u;
        u->next=t;
    }
    size++;
}

template<typename Type>
void linkedList<Type>::seperateOddEven(linkedList<Type>& a,
                            linkedList<Type>& b) const
{
    Node *p=root;
    while(p)
    {
        if((p->data)%2==0)
            a.listInsert(a.length()+1,p->data);
        else
            b.listInsert(b.length()+1,p->data);
        p=p->next;
    }
}

template<typename Type>
void linkedList<Type>::removeDupEle()
{
    //用两个指针，一个指向当前元素，一个在链表后查找
    //当值与当前元素不同是把值放到当前元素后面
    //不改变链表的连接
    Node *a=root;
    Node *b=a->next;
    int ct=1;
    while(b)
    {
        if(a->data!=b->data&&b!=a->next)
        {
            a->next->data=b->data;
            a=a->next;ct++;
            b=b->next;
        }
        else b=b->next;
    }
    size=ct;
    //a之后的节点全部释放
    Node* u=a->next,*t;
    a->next=nullptr;
    while(u){
        t=u->next;
        delete u;
        u=t;
    }
}

//改变链表节点的连接，扫描两表，相同元素跳过
template<typename Type>
void linkedList<Type>::mergelist(linkedList<Type>& b)
{
    Node *t1=this->root;
    Node *t2=b.root,*u,*t;
    //头结点问题

    if(this->root==nullptr){
        root=b.root;
        size=b.length();
        return;
    }

    if(t2->data<t1->data)
    {
        u=t2->next;
        t2->next=t1;
        root=t2;
        t2=u;

    }
    if(t1->data==t2->data) t2=t2->next;
    while(t2&&t1->next)
    {
        if(t1->next->data==t2->data) {t1=t1->next;t2=t2->next;}
        else if(t1->next->data<t2->data) t1=t1->next;
        else{
            u=t1->next;
            t=t2->next;
            t1->next=t2;
            t2->next=u;
            t2=t;
            t1=t1->next;
            size++;
        }
    }
    //b表后面的元素全面附加到表后面
    if(t2) t1->next=t2;
    while(t2)
    {
        size++;
        t2=t2->next;
    }

}
