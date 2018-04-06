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

#include "SeqList.h"
#define DA
SeqList::SeqList()
{
    listLen=0;
    #ifdef DA
    data =new Type[100];
    size=100;
    #endif // DA
}
SeqList::SeqList(int *a,int n)
{
    data=new Type[n+100];
    for(int i=0;i<n;i++)
        data[i]=a[i];
    listLen=n;
    size=n+100;
}

void SeqList::reCtor(int* a,int n)
{
    delete [] data;
    data=new Type[n+100];
    for(int i=0;i<n;i++) {
        data[i]=a[i];
    }
    listLen=n;
    size=n+100;

}

int SeqList::length()
{
    return listLen;
}
bool SeqList::getElement(int i,Type & x)
{
    if(i<1 || i>listLen) return false;
    else{
         x=data[i-1];
         return true;
    }

}

int SeqList::locate(const Type& x)
{
    for(int i=0;i<listLen;i++)
        if(data[i]==x) return i+1;
    return 0;
}

bool SeqList::listInsert(int i,const Type & x)
{
    #ifdef DA
    if(listLen==size*0.5)
    {
        Type* tempdata=new Type[2*size];
        for(int i=0;i<listLen;i++)
            tempdata[i]=data[i];
        delete [] data;
        data=tempdata;
        size*=2;
    }
    if(i<1 || i>listLen+1)
        return false;
    else {
        for(int j=listLen-1;j>=i-1;j--)
            data[j+1]=data[j];
        data[i-1]=x;
        listLen++;
        return true;
    }

    #else
    int j;
    if(listLen==MAXLEN) return 0;
    else if(i<1 || i>listLen+1)
        return false;
    else {
        for(j=listLen-1;j>=i-1;j--)
            data[j+1]=data[j];
        data[i-1]=x;
        listLen++;
    }
    return 2;
    #endif // DA

}

bool SeqList::listDelete(int i)
{
    #ifdef DA
    if(listLen==size*0.25)
    {
        Type *tempdata=new Type[int(0.5*size)];
        for(int i=0;i<listLen;i++)
            tempdata[i]=data[i];
        delete [] data;
        data=tempdata;
        size*=0.5;
    }
    #endif // DA
    int j;
    if(listLen<=0) return false; //
    else if(i<1 || i>listLen) //
        return false;
    else {
        for(j=i;j<listLen;j++)
            data[j-1]=data[j];
        listLen--;
        return true;
    }


}

void SeqList::showSeqList()
{
    cout<<listLen<<": ";
    cout<<'('<<' ';
    for(int k=0;k<listLen;k++){
         cout<<data[k]<<' ';
         if((k+1)%20==0) cout<<endl;
    }
    cout<<' '<<')';
    cout<<endl;
}

void SeqList::clearSeqList()
{
    delete [] data;
    data=new Type[100];
    listLen=0;
    size=100;
}
SeqList::~SeqList()
{
    delete [] data;
}
