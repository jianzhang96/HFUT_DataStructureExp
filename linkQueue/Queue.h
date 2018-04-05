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

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

//不带头结点的的链队列
template<typename Type>
class Queue
{
    private:
        struct node
        {
            Type data;
            node *next;
        };
        node *front;
        node *rear;
    public:
        Queue();
        void randomCtor(int n);
        virtual ~Queue();
        void clear();
        bool isEmpty();
        void getFront(Type &x);
        void dequeue();
        void enqueue(Type x);
        void print();
        int count();

};

template<typename Type>
Queue<Type>::Queue()
{
    front=nullptr;
    rear=nullptr;
}

template<typename Type>
void Queue<Type>::randomCtor(int n)
{
    for(int i=0;i<n;i++)
    {
        enqueue(i%15);
    }
}
template<typename Type>
bool Queue<Type>::isEmpty()
{
    return front==rear;
}

template<typename Type>
void Queue<Type>::enqueue(Type x)
{
    node * p=new node;
    p->data=x;
    p->next=nullptr;
    if(rear) rear->next=p;
    rear=p;
    if(front==nullptr) front=p;
}
template<typename Type>
void Queue<Type>::dequeue()
{
    if(isEmpty()) cout<<"error"<<endl;
    else{
        node* p=front;
        front=front->next;
        delete p;
        if(front==nullptr)
            rear=nullptr;
    }
}

template<typename Type>
void Queue<Type>::getFront(Type & x)
{
    if(isEmpty()) cout<<"error"<<endl;
    x=front->data;
}
template<typename Type>
void Queue<Type>::clear()
{
    while(!isEmpty())
        dequeue();
}

template<typename Type>
int Queue<Type>::count()
{
    node * p=front;
    int ct=0;
    while(p!=rear)
    {
        ct++;
        p=p->next;
    }
    return ct+1;
}
template<typename Type>
void Queue<Type>::print()
{
    cout<<"( ";
    node * p=front;
    int count=1;
    while(p)
    {
        cout<<p->data<<"->";
        if(count%10==0) cout<<endl;
        p=p->next;
        count++;
    }
    cout<<")"<<endl;
}

template<typename Type>
Queue<Type>::~Queue()
{
    clear();
}
#endif // QUEUE_H
