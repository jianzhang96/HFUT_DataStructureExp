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

#include"Queue.h"
#include<iostream>

using namespace std;
void interact();

int main()
{
//    编写算法实现下列问题的求解。
//    <1>初始化一个队列。
//    <2>判断是否队空。
//    <3>判断是否队满。
//    设队列最大长度：MaxLen=100
//    第一组数据：入队n个元素，判断队满
//    第二组数据：用循环方式将1到99，99个元素入队，判队满

    cout<<" <1>初始化一个队列。"<<endl;
    Queue<int> q;
    q.print();

    cout<<"<2>判断是否队空。"<<endl;
    cout<<"队列是否为空："<<boolalpha<<q.isEmpty()<<endl;
    cout<<"<3>判断是否队满。"<<endl;
    cout<<"第一组数据：入队n个元素，判断队满"<<endl;
    q.randomCtor(30);
    cout<<"队列是否为满："<<q.isEmpty()<<endl;
    cout<<"第二组数据：用循环方式将1到99，99个元素入队，判队满"<<endl;
    q.clear();
    for(int i=1;i<=99;i++)
        q.enqueue(i);
    cout<<"队列是否为满："<<q.isFull()<<endl;

//    <4>入队
//    第一组数据：4，7，8，12，20，50
//    第二组数据：a,b,c,d,f,g
//    <5>出队
//    <6>取队头元素
//    <7>求当前队列中元素个数

    cout<<endl<<"<4>入队"<<endl;
    int e1[]={4,7,8,12,20,50};
    char e2[]={'a','b','c','d','f','g'};
    for(int i=1;i<=2;i++){

        if(i==1) {
            cout<<"第一组数据：4，7，8，12，20，50"<<endl;
            q.clear();
            for(int i=0;i<6;i++)
                q.enqueue(e1[i]);

            q.print();
            cout<<"<5>出队"<<endl;
            q.dequeue();
            q.print();
            cout<<"<6>取队头元素:";
            int x;
            q.getFront(x);
            cout<<x<<endl;
            cout<<"<7>求当前队列中元素个数:"<<q.count()<<endl;

        }
        else {
            Queue<char> q;
            cout<<"第二组数据：a,b,c,d,f,g"<<endl;

            for(int i=0;i<sizeof(e2)/sizeof(e2[0]);i++)
                q.enqueue(e2[i]);
            q.print();
            cout<<"<5>出队"<<endl;
            q.dequeue();
            q.print();
            cout<<"<6>取队头元素:";
            char x;
            q.getFront(x);
            cout<<x<<endl;
            cout<<"<7>求当前队列中元素个数:"<<q.count()<<endl;

        }

    }
//
//    <8>编写算法实现
//    ①初始化空循环队列；
//    ②当键盘输入奇数时，此奇数入队；
//    ③当键盘输入偶数时，队头出队；
//    ④当键盘输入0时，算法退出；
//    ⑤每当键盘输入后，输出当前队列中的所有元素。
    cout<<endl<<"<8>编写算法实现,①②..."<<endl;
    interact();

    return 0;
}
void interact()
{
    Queue<int> q;
    int num;
    cin>>num;
    while(num)
    {
        if(num%2==1)
            q.enqueue(num);
        else q.dequeue();
        q.print();
        cin>>num;
    }
}
