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
#include "Forest.h"
using namespace std;

int main()
{
    Forest fo1("./data/tree11.txt");
    Forest fo2("./data/F20.txt");

    //(1)按先序、后序、层次遍历森林。
    cout<<"(1)按先序、后序、层次遍历森林。"<<endl;
    cout<<"第一组数据tree11："<<endl;
    fo1.print(1);fo1.print(2);fo1.print(3);
    cout<<"第二组数据f20: "<<endl;
    fo2.print(1);fo2.print(2);fo2.print(3);
    //(2)求森林的高度。
    cout<<"(2)求森林的高度。"<<endl;
    cout<<"第一组数据tree11："<<endl;
    cout<<fo1.height()<<endl;
    cout<<"第二组数据f20: "<<endl;
    cout<<fo2.height()<<endl;
    //(3)求森林结点总数。
    cout<<"(3)求森林结点总数。"<<endl;
    cout<<"第一组数据tree11："<<endl;
    cout<<fo1.node_count()<<endl;
    cout<<"第二组数据f20: "<<endl;
    cout<<fo2.node_count()<<endl;
    //(4)求森林叶子结点数。
    cout<<"(4)求森林叶子结点数。"<<endl;
    cout<<"第一组数据tree11："<<endl;
    cout<<fo1.leaves()<<endl;
    cout<<"第二组数据f20: "<<endl;
    cout<<fo2.leaves()<<endl;
    //(5)求森林的度。
    cout<<"(5)求森林的度。"<<endl;
    cout<<"第一组数据tree11："<<endl;
    cout<<fo1.degrees()<<endl;
    cout<<"第二组数据f20: "<<endl;
    cout<<fo2.degrees()<<endl;
    //(6)先序输出结点值及其层次号。
    cout<<"(6)先序输出结点值及其层次号。"<<endl;
    cout<<"第一组数据tree11："<<endl;
    fo1.print(4);
    cout<<"第二组数据f20: "<<endl;
    fo2.print(4);
    //(7)输出广义表表示的树。
    cout<<"(7)输出广义表表示的树。"<<endl;
    cout<<"第一组数据tree11："<<endl;
    fo1.print(6);
    cout<<"第二组数据f20: "<<endl;
    fo2.print(6);
    cout<<endl;
    cout<<"完成"<<endl;
    return 0;
}
