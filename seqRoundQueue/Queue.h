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
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAXLEN=100;
template<typename Type>
class Queue
{
    private:
        Type data[MAXLEN];
        int front;
        int rear;

    public:
        Queue() { rear=0;front=0;srand(time(0)); }
        Queue(int *a,int n);
        void randomCtor(int n);
        virtual ~Queue() {}
        void clear();
        bool isEmpty();
        void getFront(Type &x);
        void dequeue();
        void enqueue(Type x);
        bool isFull();
        void print();
        int count();
};

template<typename Type>
Queue<Type>::Queue(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        if(!isFull()){
            rear=(rear+1)%MAXLEN;
            data[rear]=a[i];
        }

    }
}

template<typename Type>
void Queue<Type>::randomCtor(int n)
{
    for(int i=0;i<n;i++)
    if(!isFull())
    {
        rear=(rear+1)%MAXLEN;
        data[rear]=rand()%500;
    }
}
template<typename Type>
void Queue<Type>::clear()
{
    front=rear;
}

template<typename Type>
bool Queue<Type>::isEmpty()
{
    return front==rear;
}

template<typename Type>
bool Queue<Type>::isFull()
{
    return (rear+1)%MAXLEN==front;
}

template<typename Type>
void Queue<Type>::getFront(Type& x)
{
    if(isEmpty()) cout<<"error";
    else
        x=data[(front+1)%MAXLEN];
}

template<typename Type>
void Queue<Type>::dequeue()
{
    if(isEmpty()) cout<<"error";
    else front=(front+1)%MAXLEN;

}

template<typename Type>
void Queue<Type>::enqueue(Type x)
{
    if(isFull()) cout<<"isFull";
    else{
        rear=(rear+1)%MAXLEN;
        data[rear]=x;
    }
}
template<typename Type>
int Queue<Type>::count()
{
    return (rear-front+MAXLEN)%MAXLEN;
}

template<typename Type>
void Queue<Type>::print()
{
    cout<<count()<<":(";
    for(int i=front+1;i<=rear;i++)
    {
        cout<<data[i]<<' ';
    }
    cout<<")"<<endl;
}
#endif // QUEUE_H
