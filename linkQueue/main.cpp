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
//    ±àÐ´Ëã·¨ÊµÏÖÏÂÁÐÎÊÌâµÄÇó½â¡£
//    <1>³õÊ¼»¯Ò»¸ö¶ÓÁÐ¡£
//    <2>ÅÐ¶ÏÊÇ·ñ¶Ó¿Õ¡£
//    <3>ÅÐ¶ÏÊÇ·ñ¶ÓÂú¡£
//    Éè¶ÓÁÐ×î´ó³¤¶È£ºMaxLen=100
//    µÚÒ»×éÊý¾Ý£ºÈë¶Ón¸öÔªËØ£¬ÅÐ¶Ï¶ÓÂú
//    µÚ¶þ×éÊý¾Ý£ºÓÃÑ­»··½Ê½½«1µ½99£¬99¸öÔªËØÈë¶Ó£¬ÅÐ¶ÓÂú

    cout<<" <1>³õÊ¼»¯Ò»¸ö¶ÓÁÐ¡£"<<endl;
    Queue<int> q;
    q.print();

    cout<<"<2>ÅÐ¶ÏÊÇ·ñ¶Ó¿Õ¡£"<<endl;
    cout<<"¶ÓÁÐÊÇ·ñÎª¿Õ£º"<<boolalpha<<q.isEmpty()<<endl;
    //cout<<"<3>ÅÐ¶ÏÊÇ·ñ¶ÓÂú¡£"<<endl;
    //cout<<"µÚÒ»×éÊý¾Ý£ºÈë¶Ón¸öÔªËØ£¬ÅÐ¶Ï¶ÓÂú"<<endl;
    //q.randomCtor(30);
    //cout<<"¶ÓÁÐÊÇ·ñÎªÂú£º"<<q.isEmpty()<<endl;
    cout<<"µÚ¶þ×éÊý¾Ý£ºÓÃÑ­»··½Ê½½«1µ½99£¬99¸öÔªËØÈë¶Ó"<<endl;
    q.clear();
    for(int i=1;i<=99;i++)
        q.enqueue(i);
    q.print();
    //cout<<"¶ÓÁÐÊÇ·ñÎªÂú£º"<<q.isFull()<<endl;

//    <4>Èë¶Ó
//    µÚÒ»×éÊý¾Ý£º4£¬7£¬8£¬12£¬20£¬50
//    µÚ¶þ×éÊý¾Ý£ºa,b,c,d,f,g
//    <5>³ö¶Ó
//    <6>È¡¶ÓÍ·ÔªËØ
//    <7>Çóµ±Ç°¶ÓÁÐÖÐÔªËØ¸öÊý

    cout<<endl<<"<4>Èë¶Ó"<<endl;
    int e1[]={4,7,8,12,20,50};
    char e2[]={'a','b','c','d','f','g'};
    for(int i=1;i<=2;i++){

        if(i==1) {
            cout<<"µÚÒ»×éÊý¾Ý£º4£¬7£¬8£¬12£¬20£¬50"<<endl;
            q.clear();
            for(int i=0;i<6;i++)
                q.enqueue(e1[i]);

            q.print();
            cout<<"<5>³ö¶Ó"<<endl;
            q.dequeue();
            q.print();
            cout<<"<6>È¡¶ÓÍ·ÔªËØ:";
            int x;
            q.getFront(x);
            cout<<x<<endl;
            cout<<"<7>Çóµ±Ç°¶ÓÁÐÖÐÔªËØ¸öÊý:"<<q.count()<<endl;

        }
        else {
            Queue<char> q;
            cout<<"µÚ¶þ×éÊý¾Ý£ºa,b,c,d,f,g"<<endl;

            for(int i=0;i<sizeof(e2)/sizeof(e2[0]);i++)
                q.enqueue(e2[i]);
            q.print();
            cout<<"<5>³ö¶Ó"<<endl;
            q.dequeue();
            q.print();
            cout<<"<6>È¡¶ÓÍ·ÔªËØ:";
            char x;
            q.getFront(x);
            cout<<x<<endl;
            cout<<"<7>Çóµ±Ç°¶ÓÁÐÖÐÔªËØ¸öÊý:"<<q.count()<<endl;

        }

    }
//
//    <8>±àÐ´Ëã·¨ÊµÏÖ
//    ¢Ù³õÊ¼»¯¿ÕÑ­»·¶ÓÁÐ£»
//    ¢Úµ±¼üÅÌÊäÈëÆæÊýÊ±£¬´ËÆæÊýÈë¶Ó£»
//    ¢Ûµ±¼üÅÌÊäÈëÅ¼ÊýÊ±£¬¶ÓÍ·³ö¶Ó£»
//    ¢Üµ±¼üÅÌÊäÈë0Ê±£¬Ëã·¨ÍË³ö£»
//    ¢ÝÃ¿µ±¼üÅÌÊäÈëºó£¬Êä³öµ±Ç°¶ÓÁÐÖÐµÄËùÓÐÔªËØ¡£
    cout<<endl<<"<8>±àÐ´Ëã·¨ÊµÏÖ,¢Ù¢Ú..."<<endl;
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

