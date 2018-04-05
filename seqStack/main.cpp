#include<iostream>
#include "Stack.h"
#include<stack>
#include <string>
#include<fstream>
#include<sstream>
#include <cmath>
#include <cstring>
#include<vector>


using namespace std;

void dec2hex(int x);
bool is_match(string s);
double evaluate();
vector<string> split(string str,string pattern);
bool is_legal_output(int n,vector<int> a);
void all_legal_output(int i,int n,string s,stack<int> st);

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

    string s;
    #ifdef IA
        cout<<"请输入一个数学表达式：";
        cin>>s;
    #else
        s="[(1+2)*(3+4)]/2";
        cout<<"数学表达式为："<<s<<endl;
    #endif // IA

    cout<<"是否匹配：";
    cout<<boolalpha<<is_match(s)<<endl;

    cout<<endl<<"栈的扩展实验："<<endl;
//    <1>假设栈的输入序列为1、2、3、...、n，设计算法实现对给定的一个序列，判定其是否是此栈合法的输出序列。
//    <2>假设栈的输入序列为1、2、3、...、n，设计算法求出所有可能的出栈序列。
//    <3>利用栈求解算术表达式的值。

    cout<<"<1>假设栈的输入序列为1、2、3、...、n，设计算法实现对给定的一个序列，判定其是否是此栈合法的输出序列。"<<endl;
    #ifdef IA
        vector<int> e2;
        e2.push_back(0);//函数从n=1开始运算
        cout<<"输入一个序列（输入-1结束输入）："<<endl;
        int x;
        cin>>x;
        while(x!=-1)
        {
            e2.push_back(x);
            cin>>x;
        }

    #else
        vector<int> e2={0,1,3,4,5,2};
    #endif // IA

    cout<<"序列";
    for(int x : e2) if(x!=0) cout<<x<<' ';
    cout<<"是否1~"<<e2.size()-1<<"的合法输入序列："<<endl;
    cout<<boolalpha<<is_legal_output(e2.size()-1,e2)<<endl<<endl;

    cout<<"<2>假设栈的输入序列为1、2、3、...、n，设计算法求出所有可能的出栈序列。"<<endl;
    stack<int> st;
    int n;
    #ifdef IA
     cout<<"输入n的大小：";
     cin>>n;
    #else
        n=5;
    #endif // IA
    all_legal_output(1,n,"",st);
    cout<<endl;

    cout<<"<3>利用栈求解算术表达式的值。"<<endl;
//    cout<<"输入一个算术表达式（只可以用小括号）："<<endl;
//    cin>>s;

    cout<<"运算结果为："<<evaluate()<<endl;

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
//判断表达式是否合法
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
//双栈求表达式
double evaluate()
{//两个栈，一个保存读取式子的符号，遇到“（”不读，遇到“）”进行操作，其他符号保存。
    //另一个栈保存每次读到的数字。

    ifstream fin("H:/codes/console/seqList/exp.txt");
    if(!fin.is_open()){
        cout<<"open file failed"<<endl;
        exit(1);
    }
    stack<double> a;
    stack<string> b;
    string str;
    str="( 1 + ( ( 2 + 3 ) * ( sqrt ( 4 ) * 5 ) ) )";
    cout<<str<<endl;
    vector<string> exp=split(str," ");
    for(auto p=exp.begin();p!=exp.end();p++)
    {

        //cout<<str;
//        b.push(str);
        if(*p=="(") continue;
        else if(*p=="+") b.push(*p);
        else if(*p=="-") b.push(*p);
        else if(*p=="*") b.push(*p);
        else if(*p=="sqrt") b.push(*p);
        else if(*p==")")
        {
            string op=b.top();
            b.pop();// c++每次出栈不取出栈顶元素，所以每次要用top取完后在pop删除栈顶元素
            double v=a.top();
            a.pop();
            if(op=="+")
            {
                v=a.top()+v;
                a.pop();
            }
            else if(op=="-")
            {
                v=a.top()-v;
                a.pop();
            }
            else if(op=="*")
            {
                v=a.top()*v;
                a.pop();
            }
            else if(op=="sqrt")
            {
                v=sqrt(v);
            }
            a.push(v);
        }
        else
        {
            char c[20];
            strcpy(c,(*p).c_str());
            a.push(atof(c));//将string转换为double的函数atof只接受char*类型，所以上一步将string转换为char*
        }
    }
    return a.top();
}
//分割字符串函数
vector<string> split(string str,string pattern)
{
  string::size_type pos;
  vector<string> result;
  str+=pattern;//扩展字符串以方便操作
  int size=str.size();

  for(int i=0; i<size; i++)
  {
    pos=str.find(pattern,i);
    if(pos<size)
    {
      string s=str.substr(i,pos-i);
      result.push_back(s);
      i=pos+pattern.size()-1;
    }
  }
  return result;
}

bool is_legal_output(int n,vector<int> a)
{
    stack<int> s;
    int min=1,x;
    bool res=true;
    for(int i=1;i<=n;i++)
    {//遍历输出序列的每一个元素
        x=a[i];
        if(x>=min)
        {
            for(int j=min;j<=x;j++)//把min~x这几个元素入栈
                s.push(j);
            s.pop();//将X出栈
            min=x+1;//此时还没有入栈的是X+1~N这些数
        }
        else
        {
            if(s.top()!=x){
                res=false;
                break;
            }else
                s.pop();
        }
    }
    return res;
}
void all_legal_output(int i,int n,string s,stack<int> st)
{
    if(i>n) {//递归出口
        if(st.empty()) cout<<s<<endl;
        else{
            while(!st.empty())
            {
                stringstream sou;
                int t=st.top();
                st.pop();
                string ts;
                sou<<t;sou>>ts;
                 s+=ts;
            }
            cout<<s<<endl;//打印结果
        }
    }
    else{//直接压入栈的情况
        stack<int> st1(st);
        st1.push(i);
        all_legal_output(i+1,n,s,st1);
        //弹出0～st.size()可能的数情况
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            stack<int> st2(st);
             st2.push(i);
            string ts;
            stringstream sou;
            sou<<t;
            sou>>ts;
            s+=ts;
            all_legal_output(i+1,n,s,st2);
        }
    }
}
