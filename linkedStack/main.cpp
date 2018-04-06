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
#include "Stack.h"
#include <string>
using namespace std;

void dec2hex(int x);
bool is_match(string s);

int main()
{
//    <1>利用顺序栈实现将10进制数转换为16进制数。
//    第一组数据：4
//    第二组数据：11
//    第三组数据：254
//    第四组数据：1357
    cout<<" <1>利用顺序栈实现将10进制数转换为16进制数。"<<endl;
    int e1[]={4,11,254,1357};
    for(int i=0;i<sizeof(e1)/sizeof(e1[0]);i++)
    {
        cout<<"第"<<i+1<<"组数据："<<e1[i]<<endl;
        cout<<"转换为16进制数的结果为：";
        dec2hex(e1[i]);
    }
//    <2>对一个合法的数学表达式来说，其中的各大小括号“{”，“}”，“[”，“]”，“(”和“)”应是相互匹配的。
//    设计算法对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的。
    cout<<endl<<"<2>对一个合法的数学表达式来说，其中的各大小括号“{”，“}”，“[”，“]”，"<<endl
        <<    "“(”和“)”应是相互匹配的。设计算法对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的。"
        <<endl;
    cout<<"请输入一个数学表达式：";
    string s;
    cin>>s;
    cout<<boolalpha<<is_match(s)<<endl;



    return 0;

}

void dec2hex(int x)
{
    Stack<char> s;
    char m[]={'0','1','2','3','4','5','6','7','8','9','A','B',
                'C','D','E','F'};
    while(x)
    {
        s.push(m[x%16]);
        x/=16;
    }
    char temp;
    while(!s.isEmpty())
    {
        s.pop(temp);
        cout<<temp;
    }
    cout<<endl;
}

bool is_match(string s)
{//遇到左括号压入栈，遇到右括号与栈顶元素匹配，其他字符跳过
    Stack<char> st;
    for(char c : s)
    {
        char t;
        st.getTop(t);
        if(c=='[' || c=='{' || c=='(')
            st.push(c);
        else if(c==']'||c=='}'||c==')')
        {
            if((c==']'&&t=='[')||(c=='}'&&t=='{')||(c==')'&&t=='('))
               st.pop(t);//弹栈
            else return false;
        }
        else continue;
    }
    return true;

}

