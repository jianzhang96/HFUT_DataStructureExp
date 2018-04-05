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

#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

template<typename Type>
class Stack
{
    private:
        struct sNode
        {
            Type data;
            struct sNode *next;
        };
        sNode *top;
        int count;
    public:
        Stack() { srand(time(0));top=NULL;count=0; }
        void randomCtor(int n);
        bool isEmpty();
        bool getTop(Type& x);
        int size();
        void push(const Type& x );
        bool pop(Type& x);
        void print();

        virtual ~Stack();
};


template<typename Type>
void Stack<Type>::randomCtor(int n)
{
    top=NULL;
    for(int i=0;i<n;i++){
        push(rand()%200);
    }
    count=n;
}

template<typename Type>
bool Stack<Type>::isEmpty()
{
    return top==NULL;
}

template<typename Type>
bool Stack<Type>::getTop(Type &x)
{
    if(isEmpty()) return false;
    else {
        x=top->data;
        return true;
    }
}

template<typename Type>
int Stack<Type>::size()
{
    return count;
}

template<typename Type>
void Stack<Type>::push(const Type& x)
{
    sNode * s=new sNode;
    s->data=x;
    s->next=top;
    top=s;
    count++;
}

template<typename Type>
bool Stack<Type>::pop(Type& x)
{
    if(isEmpty()) return false;
    else{
        sNode *u=top;
        x=top->data;
        top=top->next;
        delete u;
        count--;
        return true;
    }
}

template<typename Type>
void Stack<Type>::print()
{

    for(int k=1;top;top=top->next,k++)
    {
        cout<<top->data<<' ';
        if(k%10==0) cout<<endl;
    }

}
template<typename Type>
Stack<Type>::~Stack()
{

    while(top)
    {
        sNode* u=top;
        top=top->next;
        delete u;
    }
}

#endif // STACK_H
