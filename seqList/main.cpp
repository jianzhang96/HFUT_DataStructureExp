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
#include<iostream>
#include<algorithm>
using namespace std;
void ListMerge(SeqList A,SeqList B,SeqList * pC);
void insert(SeqList*,Type x);
void seperate(SeqList& a,SeqList& b,SeqList& c);
void common(SeqList& a,SeqList& b,SeqList& c);
int removeDuplicateEle(SeqList& a);
bool subset(SeqList *A,SeqList *B);
void mergeList(SeqList &a, SeqList& b);
void mergeSets(SeqList& a,SeqList& b,SeqList& );

int M_Search(int A[], int B[], int n);

int main()
{


    int a[]={1,2,3,4,5,6,7,8,9,10,33,2,5,90};
    SeqList c(a,14);
    //<1>求顺序表中第i个元素（函数），若不存在，报错。
    //第一组数据：顺序表长度n≥10，i分别为5，n，0，n+1，n+2
    //第二组数据：顺序表长度n=0，i分别为0，2
    cout<<"<1>求顺序表中第i个元素（函数），若不存在，报错。"<<endl;
    c.showSeqList();
    int e[]={5,14,0,15,16};
    int x;
    for(int i=0;i<5;i++)
    {
        if(c.getElement(e[i],x)) cout<<e[i]<<"对应的元素为："<<x<<endl;
        else cout<<e[i]<<"索引的元素不存在"<<endl;
    }

    cout<<endl;
    c.clearSeqList();
    c.showSeqList();
    if(c.getElement(0,x)) cout<<0<<"对应的元素为："<<x<<endl;
    else cout<<0<<"索引的元素不存在"<<endl;

    if(c.getElement(2,x)) cout<<2<<"对应的元素为："<<x<<endl;
    else cout<<2<<"索引的元素不存在"<<endl;


//    <2>在第i个结点前插入值为x的结点。
//    实验测试数据基本要求：
//    第一组数据：顺序表长度n≥10，x=100,  i分别为5,n,n+1,0,1,n+2
//    第二组数据：顺序表长度n=0，x=100，i=5
    cout<<endl<<"<2>在第i个结点前插入值为x的结点。"<<endl;
    SeqList s(a,14);
    s.showSeqList();
    x=100;
    for(int i=0;i<5;i++)
    {
        if(s.listInsert(e[i],x)){
            cout<<"在索引"<<e[i]<<"处成功插入"<<x<<endl;
            s.showSeqList();
        }
        else cout<<"在"<<e[i]<<"插入失败"<<endl;
    }

//    <3>删除顺序表中第i个元素结点。
//    实验测试数据基本要求：
//    第一组数据：顺序表长度n≥10，i分别为5,n,1,n+1,0
//    第二组数据：顺序表长度n=0， i=5
    cout<<endl<<"<3>删除顺序表中第i个元素结点。"<<endl;
    s.showSeqList();
    for(int i=0;i<5;i++)
    {
        if(s.listDelete(e[i])) {
            cout<<"在索引"<<e[i]<<"删除成功"<<endl;
            s.showSeqList();
        }
        else cout<<"在索引"<<e[i]<<"删除失败"<<endl;
    }


//    <4>在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性。
//    实验测试数据基本要求：
//    顺序表元素为 （10,20,30,40,50,60,70,80,90,100）,
//    x分别为25，85，110和8
    cout<<endl<<"<4>在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性"<<endl;
    int b[]={10,20,30,40,50,60,70,80,90,100};
    s.reCtor(b,10);
    s.showSeqList();
    int t[]={25,85,110,8};
    for(int i=0;i<4;i++)
    {
        insert(&s,t[i]);
        cout<<"插入"<<t[i]<<":"<<endl;
        s.showSeqList();
    }

//    <5>将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，
//    然后原表和新表元素同时输出到屏幕上，以便对照求解结果。
//    实验测试数据基本要求：
//    第一组数据：顺序表元素为 （1,2,3,4,5,6,7,8,9,10,20,30,40,50,60）
//    第二组数据：顺序表元素为 （10,20,30,40,50,60,70,80,90,100）
    cout<<endl<<"<5>将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中"<<endl;
    int m1[]={1,2,3,4,5,6,7,8,9,10,20,30,40,50,60};
    int m2[]={10,20,30,40,50,60,70,80,90,100};
    SeqList n;
    for(int i=0;i<2;i++)
    {
        cout<<"第"<<i+1<<"组数据："<<endl;
        if(i==0){
            s.reCtor(m1,sizeof(m1)/sizeof(m1[0]));
        }
        else  s.reCtor(m2,sizeof(m2)/sizeof(m2[0]));

        s.showSeqList();
        c.clearSeqList();
        n.clearSeqList();
        seperate(s,c,n);
        c.showSeqList();
        n.showSeqList();
        cout<<endl;
    }


//    <6>求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。
//    实验测试数据基本要求：
//    第一组
//    第一个顺序表元素为 （1，3，6，10，15，16，17，18，19，20）
//    第二个顺序表元素为 （1，2，3，4，5，6，7，8，9，10，18，20，30）
//    第二组
//    第一个顺序表元素为 （1，3，6，10，15，16，17，18，19，20）
//    第二个顺序表元素为 （2，4，5，7，8，9，12，22）
//    第三组
//    第一个顺序表元素为 （）
//    第二个顺序表元素为 （1，2，3，4，5，6，7，8，9，10）

    cout<<endl<<"<6>求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中"<<endl;
    int p1[]={1,3,6,10,15,16,17,18,19,20};
    int p2[]={1,2,3,4,5,6,7,8,9,10,18,20,};
    int p3[]={2,4,5,7,8,9,12,22};
    int p4[]={1,2,3,4,5,6,7,8,9,10};

    for(int i=0;i<3;i++)
    {
        cout<<"第"<<i+1<<"组元素："<<endl;
        if(i==0) {
            s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
            c.reCtor(p2,sizeof(p2)/sizeof(p2[0]));
        }
        else if(i==1){
            s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
            c.reCtor(p3,sizeof(p3)/sizeof(p3[0]));
        }
        else{
            s.clearSeqList();
            c.reCtor(p4,sizeof(p4)/sizeof(p4[0]));
        }
        s.showSeqList();
        c.showSeqList();
        n.clearSeqList();
        common(s,c,n);
        cout<<"公共元素为："<<endl;
        n.showSeqList();
        cout<<endl;

    }

//    <7>删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好。
//    实验测试数据基本要求：
//    第一组数据：顺序表元素为 （1,2,3,4,5,6,7,8,9）
//    第二组数据：顺序表元素为 （1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9）
//    第三组数据：顺序表元素为 （1,2,3,4,5,5,6,7,8,8,9,9,9,9,9）

    cout<<endl
        <<"<7>删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好。"<<endl;
    int p5[]={1,2,3,4,5,6,7,8,9};
    int p6[]={1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9};
    int p7[]={1,2,3,4,5,5,6,7,8,8,9,9,9,9,9};
    for(int i=0;i<3;i++) {
        cout<<"第"<<i+1<<"组数据："<<endl;
        if(i==0)s.reCtor(p5,sizeof(p5)/sizeof(p5[0]));
        else if(i==1) s.reCtor(p6,sizeof(p6)/sizeof(p6[0]));
        else s.reCtor(p7,sizeof(p7)/sizeof(p7[0]));

        s.showSeqList();
        cout<<"移动次数："<<removeDuplicateEle(s)<<endl;
        s.showSeqList();
    }


//    1.4* 顺序表扩展实验
//    非必做内容，有兴趣的同学选做，
//    <1> 递增有序顺序表L1、L2，对2表进行合并，并使得合并后成为一个集合，集合的元素放回L1表中保存，要求时间性能最好。
//    <2>（递增有序）顺序表表示集合A、B，实现：
//    C=A?B，C=A?B，C=A-B
//    A=A?B，A=A?B，A=A-B
//    <3>（递增有序）顺序表表示集合A、B，判定A是否B的子集。

    cout<<endl;
    cout<<"1.4* 顺序表扩展实验"<<endl;
    cout<<"<1> 递增有序顺序表L1、L2，对2表进行合并，并使得合并后成为一个集合，"<<endl
        <<"集合的元素放回L1表中保存，要求时间性能最好。"<<endl;
    s.reCtor(p6,sizeof(p6)/sizeof(p6[0]));
    s.showSeqList();
    c.showSeqList();
    mergeList(s,c);
    s.showSeqList();

//    <2>（递增有序）顺序表表示集合A、B，实现：
//    C=AUB，C=AUB，C=A-B
//    A=AUB，A=AUB，A=A-B
    cout<<endl;
    cout<<" <2>（递增有序）顺序表表示集合A、B，实现：C=AUB"<<endl;
    s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
    c.reCtor(p2,sizeof(p2)/sizeof(p2[0]));
    s.showSeqList();
    c.showSeqList();
    mergeSets(s,c,n);
    n.showSeqList();
    cout<<"<2>（递增有序）顺序表表示集合A、B，实现：C=AnB"<<endl;
    s.showSeqList();
    c.showSeqList();
    n.clearSeqList();
    common(s,c,n);
    n.showSeqList();
    cout<<endl;
    //<3>（递增有序）顺序表表示集合A、B，判定A是否B的子集
    cout<<"<3>（递增有序）顺序表表示集合A、B，判定A是否B的子集"<<endl;
    cout<<"第一组数据："<<endl;
    s.showSeqList();
    c.showSeqList();
    if(subset(&s,&c)) cout<<"第一个集合是第二个的子集"<<endl;
    else cout<<"第一个集合不是第二个的子集"<<endl;
    cout<<"第二组数据："<<endl;
    s.reCtor(p5,sizeof(p5)/sizeof(p5[0]));
    s.showSeqList();
    c.showSeqList();
    n.clearSeqList();
    if(subset(&s,&c)) cout<<"第一个集合是第二个的子集"<<endl;
    else cout<<"第一个集合不是第二个的子集"<<endl;


//    <4>(2011)（15 分）一个长度为L（L≥1）的升序序列S，处在第L/2（向上取整）个位置的数称为S 的中位数。
//    例如，若序列S1=(11, 13, 15, 17, 19)，则S1 的中位数是15。两个序列的中位数是含它们所有元素的升序序列的中位数。
//    例如，若S2=(2, 4, 6, 8, 20)，则S1 和S2 的中位数是11。
//    现有两个等长升序序列A 和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A 和B 的中位数。要求：
//    （1）给出算法的基本设计思想。
//    （2）根据设计思想，采用C 或C++语言描述算法，关键之处给出注释。
//    （3）说明你所设计算法的时间复杂度和空间复杂度。
    cout<<endl;
    cout<<"附加题<4>:求两个等长上升序列的中位数"<<endl;
    s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
    c.reCtor(p2,sizeof(p2)/sizeof(p2[0]));
    s.showSeqList();
    c.showSeqList();

    x=M_Search(s.data, c.data, sizeof(p1)/sizeof(p1[0]));
    cout<<"中位数为："<<x<<endl;

    cout<<"done!"<<endl;
    return 0;
}

//类外方法



//等长上升子序列的中位数
int M_Search(int A[], int B[], int n)
{
	int start1 = 0, end1 = n - 1, m1, start2 = 0, end2 = n - 1, m2;
	//分别表示序列A和B的首位数、末位数和中位数
	while (start1 != end1 || start2 != end2)
	{
		m1 = (start1 + end1) / 2;
		m2 = (start2 + end2) / 2;
		if (A[m1] == B[m2])
			return A[m1];   //满足条件 1)
		if (A[m1]<B[m2]) // 满足条件 2)
		{
			if ((start1 + end1) % 2 == 0)  //若元素个数为奇数
			{
				start1 = m1;  //舍弃A中间点以前的部分且保留中间点
				end2 = m2;  //舍弃B中间点以后的部分且保留中间点
			}
			else				//元素个数为偶数
			{
				start1 = m1 + 1;  //舍弃A中间点及中间点以前部分
				end2 = m2;  //舍弃B中间点以后部分且保留中间点
			}
		}
		else
		{  //满足条件3)
			if ((start2 + end2) % 2 == 0)   //若元素个数为奇数
			{
				end1 = m1;    //舍弃A中间点以后的部分且保留中间点
				start2 = m2;    //舍弃B中间点以前的部分且保留中间点
			}
			else     //元素个数为偶数
			{
				end1 = m1;    //舍弃A中间点以后部分且保留中间点
				start2 = m2 + 1;    //舍弃B中间点及中间点以前部分
			}
		}
	}
	return  A[start1]<B[start2] ? A[start1] : B[start2];
}



//合并顺序表
void ListMerge(SeqList A,SeqList B,SeqList * pC)
{
    int i;
    Type x;
    for(i=0;i<A.length();i++) {
        A.getElement(i+1,x);
        pC->listInsert(pC->length()+1,x);
    }
    for(i=0;i<B.length();i++) {
        B.getElement(i+1,x);
        if(!A.locate(x))
            pC->listInsert(pC->length(),x);
    }
}
//递增有序表插入一个元素
void insert(SeqList *L,Type x)
{
    int i=L->listLen-1;
    if(i>=MAXLEN-1) return;
    else {
        while(i>=0 && L->data[i]>x)
        {
            L->data[i+1]=L->data[i];
            i--;
        }
        L->data[i+1]=x;
        L->listLen++;
    }
}

//奇偶项分开
void seperate(SeqList& a,SeqList& b,SeqList& c)
{
    for(int i=1;i<=a.length();i++)
    {
        int s;
        a.getElement(i,s);
        if(s%2==0) b.listInsert(b.length()+1,s);
        else c.listInsert(c.length()+1,s);
    }
}

//求两个递增有序的顺序表的公共元素
void common(SeqList& a,SeqList& b,SeqList& c)
{
    int ia=0,ib=0,ic=0;
    while(ia<a.length()&&ib<b.length())
    {
        if(a.data[ia]==b.data[ib]){
            //c.listInsert(c.length(),a.data[ia]);
            c.data[ic++]=a.data[ia];c.listLen++;
            ia++;ib++;
        }
        else if(a.data[ia]>b.data[ib]) ib++;
        else ia++;
    }
}

//删除递增有序顺序表中的重复元素
int removeDuplicateEle(SeqList& a)
{
    int k=0;
    for(int i=1;i<a.length();i++){
        if(a.data[i]!=a.data[i-1]){
            a.data[++k]=a.data[i];
        }
    }

    return a.listLen=++k;
}

//递增有序合并成一个集合A=AUB
void mergeList(SeqList& a,SeqList& b)
{
    removeDuplicateEle(a);
    removeDuplicateEle(b);
    int* c=new int[max(a.length(),b.length())];
    int t1=0,t2=0,k=0;
    while(t1<a.length()&&t2<b.length())
    {
        if(a.data[t1]==b.data[t2]){
            c[k++]=a.data[t1];
            t1++;t2++;
        }
        else if(a.data[t1]>b.data[t2]){
            c[k++]=b.data[t2];
            t2++;
        }
        else {
            c[k++]=a.data[t1];
            t1++;
        }
    }
    while(t2<b.length())
        c[k++]=b.data[t2++];

    while(t1<a.length())
        c[k++]=a.data[t1++];
    delete [] a.data;
    a.data=c;
    a.listLen=k;

}
//C=AUB
void mergeSets(SeqList& a,SeqList& b,SeqList& c1)
{

    int c[max(a.length(),b.length())];
//    c.clearSeqList();
//    c.data=new int[max(a.length(),b.length())];
    int t1=0,t2=0,k=0;
    while(t1<a.length()&&t2<b.length())
    {
        if(a.data[t1]==b.data[t2]){
            c[k++]=a.data[t1];
            t1++;t2++;
        }
        else if(a.data[t1]>b.data[t2]){
            c[k++]=b.data[t2];
            t2++;
        }
        else {
            c[k++]=a.data[t1];
            t1++;
        }
    }
    while(t2<b.length())
        c[k++]=b.data[t2++];

    while(t1<a.length())
        c[k++]=a.data[t1++];
    c1.reCtor(c,k);
}

//判断A是不是B的子集，都是有序的集合
bool subset(SeqList *A,SeqList *B)
{
    int ia=0,ib=0;
    while(ia<A->length()&&ib<B->length())
    {
        if(A->data[ia]==B->data[ib]) {ia++;ib++;}
        else if(A->data[ia]>B->data[ib]) ib++;
        else return false;
    }
    if(ia>=A->length()) return true;
    else return false;

}
