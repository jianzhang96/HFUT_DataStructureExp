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
#include "linkedList.h"
using namespace std;


void commonElement(const linkedList<int>& a,
   const linkedList<int>& b,linkedList<int>& c);
int main()
{

//    <1>尾插法创建单链表，打印创建结果。
//    <2>头插法创建单链表，打印创建结果。
//    <3>销毁单链表。
//    <4>求链表长度。

    int a[]={3,5,8,9,1,10,22,2,4,55,7,0};
    int n=sizeof(a)/sizeof(a[0]);

    linkedList<int> v(a,n);
    cout<<"<1>尾插法创建单链表："<<endl;
    v.show();
    cout<<endl;
    v.reCtor(a,n,false);
    cout<<"<2>头插法创建单链表："<<endl;
    v.show();
    cout<<endl;
    v.clearList();
    cout<<"<3>销毁单链表："<<endl;
    v.show();cout<<endl;
    cout<<"<4>求链表长度："<<v.length()<<endl;
    cout<<endl;

//    <5>求单链表中第i个元素（函数），若不存在，报错。
//    实验测试数据基本要求：
//    第一组数据：单链表长度n≥10，i分别为5，n，0，n+1，n+2
//    第二组数据：单链表长度n=0，i分别为0，2

    v.reCtor(a,n);
    int e1[]={5,n,0,n+1,n+2};
    int e2[]={0,2};
    cout<<"<5>求单链表中第i个元素（函数），若不存在，报错。"<<endl;
    for(int i=0;i<2;i++)
    {
        cout<<"第"<<i+1<<"组数据："<<endl;
        int x;
        int n;
        if(i==0) n= sizeof(e1)/sizeof(e1[0]);
        else{
            n=sizeof(e2)/sizeof(e2[0]);
            v.clearList();
        }
        v.show();
        for(int j=0;j<n;j++)
        {
            int m;
            if(i==0) m=e1[j];
            else m=e2[j];
            if(v.getElement(m,x))
                cout<<"链表中第"<<m<<"个元素为："<<x<<endl;
            else
                cout<<"链表中第"<<m<<"个元素不存在"<<endl;
        }
    }
    cout<<endl;

//    <6>在第i个结点前插入值为x的结点。
//    实验测试数据基本要求：
//    第一组数据：单链表长度n≥10，x=100,  i分别为5,n,n+1,0,1,n+2
//    第二组数据：单链表长度n=0，x=100，i=5

    v.reCtor(a,n);
    int e3[]={5,n,n+1,0,1,n+2};
    cout<<"<6>在第i个结点前插入值为x的结点。"<<endl;
    cout<<"第一组数据："<<endl;
    v.show();
    for(int i=0;i<sizeof(e3)/sizeof(e3[0]);i++)
    {
        if(v.listInsert(e3[i],100)){
            cout<<"在第"<<e3[i]<<"个节点前插入值为100的节点成功"<<endl;
            v.show();
        }
        else
            cout<<"在第"<<e3[i]<<"个节点前插入值为100的节点失败"<<endl;
    }


    cout<<endl<<"第二组数据："<<endl;
    v.clearList();
    v.show();
    if(v.listInsert(5,100)){
        cout<<"在第5个节点前插入值为100的节点成功"<<endl;
        v.show();
    }
    else
        cout<<"在第5个节点前插入值为100的节点失败"<<endl;

//    <7>链表中查找元素值为x的结点，成功返回结点指针，失败报错。
//    实验测试数据基本要求：
//    单链表元素为 （1，3，6，10，15，16，17，18，19，20）
//    x=1，17，20，88

    cout<<endl;
    cout<<"<7>链表中查找元素值为x的结点，成功返回结点指针，失败报错。"<<endl;
    int a2[]={1,3,6,10,15,16,17,18,19,20};
    v.reCtor(a2,sizeof(a2)/sizeof(a2[0]));
    int e4[]={1,17,20,88};
    v.show();
    for(int i=0;i<sizeof(e4)/sizeof(e4[0]);i++)
    {
        int t;
        if(v.locate(e4[i],t))
            cout<<"在链表中查找元素值为"<<e4[i]<<"的结点成功,其在链表的位置为"<<t<<endl;
        else
            cout<<"链表中不存在值为"<<e4[i]<<"的元素"<<endl;
    }

//    <8>删除单链表中第i个元素结点。
//    实验测试数据基本要求：
//    第一组数据：单链表长度n≥10，i分别为5,n,1,n+1,0
//    第二组数据：单链表长度n=0， i=5
    cout<<endl<<"<8>删除单链表中第i个元素结点。"<<endl;
     cout<<"第一组数据；"<<endl;
     v.reCtor(a2,sizeof(a2)/sizeof(a2[0]));
     v.show();
     n=sizeof(a2)/sizeof(a2[0]);
     int e5[]={5,n,1,n+1,0};
     for(int i=0;i<sizeof(e5)/sizeof(e5[0]);i++)
     {
         if(v.listDelete(e5[i])) {
            cout<<"删除单链表中第"<<e5[i]<<"个元素结点成功"<<endl;
            v.show();
         }
         else
            cout<<"删除单链表中第"<<e5[i]<<"个元素结点失败"<<endl;
     }
    cout<<endl<<"第二组数据："<<endl;
    v.clearList();
    v.show();
    if(v.listDelete(5)) {
         cout<<"删除单链表中第"<<5<<"个元素结点成功"<<endl;
         v.show();
    }
    else
         cout<<"删除单链表中第"<<5<<"个元素结点失败"<<endl;

//    <9>在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。
//    实验测试数据基本要求：
//    单链表元素为 （10,20,30,40,50,60,70,80,90,100）,
//    x分别为25，85，110和8

    cout<<endl<<"<9>在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。"
        <<endl;
    int a3[]={10,20,30,40,50,60,70,80,90,100};
    int e6[]={25,85,110,8};
    v.reCtor(a3,sizeof(a3)/sizeof(a3[0]));
    v.show();
    for(int i=0;i<sizeof(e6)/sizeof(e6[0]);i++)
    {
        cout<<"在递增链表中插入值为"<<e6[i]<<"的元素"<<endl;
        v.incrementalInsert(e6[i]);
        v.show();
    }


//    <10>将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的单链表中，
//    然后原表和新表元素同时输出到屏幕上，以便对照求解结果。
//    实验测试数据基本要求：
//    第一组数据：单链表元素为 （1,2,3,4,5,6,7,8,9,10,20,30,40,50,60）
//    第二组数据：单链表元素为 （10,20,30,40,50,60,70,80,90,100）
    cout<<endl
        <<"<10>将单链表Ｌ中的奇数项和偶数项结点分解开，分别放入新的单链表中."<<endl;
    int a4[]={1,2,3,4,5,6,7,8,9,10,20,30,40,50,60};
    int a5[]={10,20,30,40,50,60,70,80,90,100};
    cout<<"第一组数据："<<endl;
    v.reCtor(a4,sizeof(a4)/sizeof(a4[0]));
    v.show();
    linkedList<int> v1,v2;
    v.seperateOddEven(v1,v2);
    v1.show();
    v2.show();
    cout<<"第二组数据："<<endl;
    v.reCtor(a5,sizeof(a5)/sizeof(a5[0]));
    v.show();
    v1.clearList();v2.clearList();
    v.seperateOddEven(v1,v2);
    v1.show();
    v2.show();

//    <11>求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。
//    实验测试数据基本要求：
//    第一组
//    第一个单链表元素为 （1，3，6，10，15，16，17，18，19，20）
//    第二个单链表元素为 （1，2，3，4，5，6，7，8，9，10，18，20，30）
//    第二组
//    第一个单链表元素为 （1，3，6，10，15，16，17，18，19，20）
//    第二个单链表元素为 （2，4，5，7，8，9，12，22）
//    第三组
//    第一个单链表元素为 （）
//    第二个单链表元素为 （1，2，3，4，5，6，7，8，9，10）

    cout<<endl;
    cout<<"<11>求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。"<<endl;
    int a6[]={1,3,6,10,15,16,17,18,19,20};
    int a7[]={1,2,3,4,5,6,7,8,9,10,18,20,30};
    int a8[]={2,4,5,7,8,9,12,22};
    int a9[]={1,2,3,4,5,6,7,8,9,10};

    for(int i=1;i<=3;i++)
    {
        cout<<"第"<<i<<"组数据："<<endl;
        if(i==1){
            v1.reCtor(a6,sizeof(a6)/sizeof(a6[0]));
            v2.reCtor(a7,sizeof(a7)/sizeof(a7[0]));
        }
        else if(i==2)
        {
             v2.reCtor(a8,sizeof(a8)/sizeof(a8[0]));
        }
        else {
            v1.clearList();
            v2.reCtor(a9,sizeof(a9)/sizeof(a9[0]));
        }
        v.clearList();
        v1.show();
        v2.show();
        commonElement(v1,v2,v);
        v.show();
        cout<<endl;
    }
//    <12>删除递增有序单链表中的重复元素，要求时间性能最好。
//    实验测试数据基本要求：
//    第一组数据：单链表元素为 （1,2,3,4,5,6,7,8,9）
//    第二组数据：单链表元素为 （1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9）
//    第三组数据：单链表元素为 （1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9）
    cout<<endl
        <<"<12>删除递增有序单链表中的重复元素，要求时间性能最好。"<<endl;
    int a12[]={1,2,3,4,5,6,7,8,9};
    int a10[]={1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9};
    int a11[]={1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9};
    for(int i=1;i<=3;i++)
    {
        cout<<"第"<<i<<"组数据："<<endl;
        if(i==1) v.reCtor(a12,sizeof(a12)/sizeof(a12[0]));
        else if(i==2) v.reCtor(a10,sizeof(a10)/sizeof(a10[0]));
        else v.reCtor(a11,sizeof(a11)/sizeof(a11[0]));
        v.show();
        v.removeDupEle();
        v.show();
    }


//    <13>递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并，
//    并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除L2的头结点，
//    要求时间性能最好。
//    实验测试数据基本要求：
//    第一组
//    第一个单链表元素为 （1，3，6，10，15，16，17，18，19，20）
//    第二个单链表元素为 （1，2，3，4，5，6，7，8，9，10，18，20，30）
//    第二组
//    第一个单链表元素为 （1，3，6，10，15，16，17，18，19，20）
//    第二个单链表元素为 （2，4，5，7，8，9，12，22）
//    第三组
//    第一个单链表元素为 （）
//    第二个单链表元素为 （1，2，3，4，5，6，7，8，9，10）
    int a13[]={1,3,6,10,15,16,17,18,19,20};
    int a14[]={1,2,3,4,5,6,7,8,9,10,18,20,30};
    int a15[]={2,4,5,7,8,9,12,22};
    cout<<endl;
    cout<<"<13>递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并，"<<endl
        <<"并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除L2的头结点，"<<endl
        <<"要求时间性能最好。"<<endl;

    for(int i=1;i<3;i++)
    {
        cout<<"第"<<i<<"组数据："<<endl;
        if(i==1){
            v.reCtor(a13,sizeof(a13)/sizeof(a13[0]));
            v1.reCtor(a14,sizeof(a14)/sizeof(a14[0]));
        }
        else if(i==2) {
            v.reCtor(a13,sizeof(a13)/sizeof(a13[0]));
            v1.reCtor(a15,sizeof(a15)/sizeof(a15[0]));
        }
        else{
            v.clearList();
            v1.reCtor(a9,sizeof(a9)/sizeof(a9[0]));
        }
        v.show();
        v1.show();
        v.mergelist(v1);
        v.show();
        cout<<endl;
    }


//    <3>(2009)（15分）已知一个带有表头结点的单链表，结点结构如下图。
//    假设该链表只给出了头指针list。在不改变链表的前提下，请设计一个尽可能高效的算法，
//    查找链表中倒数第k个位置上的结点（k为正整数）。若查找成功，算法输出该结点的data值，并返回1；
//    否则，只返回0。要求：
//    （1）描述算法的基本设计思想
//    （2）描述算法的详细实现步骤
//    （3）根据设计思想和实现步骤，采用程序设计语言描述算法（使用C 或C++语言实现），关键之处请给出简要注释。
    cout<<"查找链表中倒数第k个位置上的结点（k为正整数）"<<endl;
    v.reCtor(a13,sizeof(a13)/sizeof(a13[0]));
    v.show();
    cout<<"k的位置："<<6<<endl;
    v.findK(6);

    return 0;
}

void commonElement(const linkedList<int>& a,
const linkedList<int>& b,linkedList<int>& c)
{
    int ia=1,ib=1;
    int ta,tb;
    while(ia<=a.length()&&ib<=b.length())
    {
        a.getElement(ia,ta);
        b.getElement(ib,tb);
        if(ta==tb) {
            c.listInsert(c.length()+1,ta);
            ia++;ib++;
        }
        else if(ta>tb) ib++;
        else ia++;
    }
}
