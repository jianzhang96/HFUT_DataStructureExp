#ifndef FOREST_H
#define FOREST_H

#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

class Forest
{
    private:
        //双亲表示法数据结构
        struct pnode
        {
            char data;
            int parent;
        };
        //孩子兄弟链表表示法节点
        struct csNode
        {
            char data;
            struct csNode *firstChild, *nextSibling;
        };

        vector<pnode> ptree;
        csNode *root;

        void create(csNode*& T,int v);
        int firstChild(int t);
        int next(int t);
        void pre_order(csNode * pt);
        void post_order(csNode * pt);
        void level_print();
        void pre_order_level(csNode* pt,int level);
        void gen_print(csNode *pt);

    public:
        Forest();
        Forest(string path);
        virtual ~Forest();
        void print(int fg=5);
        int height();
        int node_count();
        int leaves();
        int degrees();
};

#endif // FOREST_H
