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

#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
#define MAXLEN 100
#define DA
using namespace std;
typedef  int  Type;
class SeqList
{
private:
public:
    #ifdef DA   //实现一个动态数组的版本
    Type *data;
    int size; //记录动态数组当前长度
    #else
    Type data[MAXLEN];
    #endif // DA
    int listLen;

    SeqList();
    SeqList(int *,int n);
    virtual ~SeqList();

    void reCtor(int *,int n);
    int length();
    bool getElement(int i,Type & x);
    int locate(const Type & x);
    bool listInsert(int i,const Type & x);
    bool insertRear(const Type& x);
    bool listDelete(int i);
    void clearSeqList();
    void showSeqList();
};




#endif // SEQLIST_H
