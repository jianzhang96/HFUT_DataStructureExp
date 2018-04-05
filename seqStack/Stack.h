#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<cstdlib>
#include<ctime>
const int MAXLEN=100;
template<typename Type>
class Stack
{
    public:
        Stack();
        Stack(Type *,int n);
        void randomCtor(int n);
        bool isEmpty();
        bool isFull();
        bool getTop(Type & x);
        bool push(const Type& x);
        bool pop(Type& x);
        void print();

        virtual ~Stack();

    private:
        Type data[MAXLEN];
        int top;
};

template<typename Type>
Stack<Type>::Stack()
{
    //ctor
    top=-1;
    std::srand(std::time(0));
}
//用数组构造
template<typename Type>
Stack<Type>::Stack(Type*s,int n)
{
    for(int i=0;i<n;i++)
        data[++top]=s[i];
}
template<typename Type>
void Stack<Type>::randomCtor(int n)
{
    for(int i=0;i<n;i++)
        data[++top]=std::rand()%500;
}
template<typename Type>
bool Stack<Type>::isEmpty()
{
    return top==-1;
}

template<typename Type>
bool Stack<Type>::isFull()
{
    return top==MAXLEN;
}
template<typename Type>
bool Stack<Type>::getTop(Type& x)
{
    if(isEmpty()) return false;
    else{
        x=data[top];
        return true;
    }
}

template<typename Type>
bool Stack<Type>::push(const Type& x)
{
    if(isFull()) return false;
    else{
        data[++top]=x;
        return true;
    }
}

template<typename Type>
bool Stack<Type>::pop(Type & x)
{
    if(isEmpty()) return false;
    else{
        x=data[top--];
        return true;
    }
}

template<typename Type>
void Stack<Type>::print()
{
    for(int i=0;i<=top;i++) {
        std::cout<<data[i]<<' ';
        if((i+1)%10==0)
            std::cout<<std::endl;
    }
}

template<typename Type>
Stack<Type>::~Stack()
{
    //dtor
}


#endif // STACK_H
