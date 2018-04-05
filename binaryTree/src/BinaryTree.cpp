#include "BinaryTree.h"
#include <sstream>

BinaryTree::BinaryTree()
{
    //ctor
    root=nullptr;
}

BinaryTree::BinaryTree(string filepath)
{

    ifstream fin(filepath);
    if(fin.fail()){
        cout<<"打开文件失败！"<<endl;
        root=nullptr;
    }
    else{
        vector<nodeinfo> vt;
        nodeinfo temp;
        while(!fin.eof())
        {
            fin>>temp.dat>>temp.lef>>temp.rig;
            vt.push_back(temp);
        }
        fin.close();
        int t=0;
        creat_node(root,vt,t);
    }
}
void BinaryTree::creat_node(node *& pt,vector<nodeinfo> vt,int& i)
{
    pt=new node;
    pt->data=vt.at(i).dat;
    pt->left=pt->right=nullptr;
    nodeinfo tmp=vt.at(i);
    if(tmp.lef) creat_node(pt->left,vt,++i);
    if(tmp.rig) creat_node(pt->right,vt,++i);

}

BinaryTree::BinaryTree(const BinaryTree& tc)
{
    creat_node(root,tc.root);
}
void BinaryTree::creat_node(node*& pt,node * pc)
{
    pt=new node;
    pt->data=pc->data;
    pt->left=pt->right=nullptr;
    if(pc->left) creat_node(pt->left,pc->left);
    if(pc->right) creat_node(pt->right,pc->right);
}
//输出遍历
void BinaryTree::preorder_show(node * t)
{
    cout<<t->data<<' ';
    if(t->left) preorder_show(t->left);
    if(t->right) preorder_show(t->right);
}

void BinaryTree::inorder_show(node *t)
{
    if(t->left) inorder_show(t->left);
    cout<<t->data<<' ';
    if(t->right) inorder_show(t->right);

}

void BinaryTree::postorder_show(node * t)
{
    if(t->left) postorder_show(t->left);
    if(t->right) postorder_show(t->right);
    cout<<t->data<<' ';
}

void BinaryTree::print(int flag)
{
    if(flag==1) {
        preorder_show(root);cout<<endl;
    }
    else if(flag==2) {
        inorder_show(root);
        cout<<endl;
    }
    else {
        postorder_show(root);
        cout<<endl;
    }
}
void BinaryTree::inorder_and_level(node * pt,int level)
{
    if(level==1) pt=root;
    if(pt)
    {
        inorder_and_level(pt->left,level+1);
        cout<<"data: "<<pt->data<<", level: "<<level<<endl;
        inorder_and_level(pt->right,level+1);
    }
}
int BinaryTree::cal_height(node * pt)
{
    if(pt==nullptr) return 0;
    else
        return 1+max(cal_height(pt->left),cal_height(pt->right));
}
int BinaryTree::height()
{
    return cal_height(root);
}

int BinaryTree::cal_nodes(node* pt)
{
    if(pt==nullptr) return 0;
    else
        return 1+cal_nodes(pt->left)+cal_nodes(pt->right);
}
int BinaryTree::count()
{
    return cal_nodes(root);
}
int BinaryTree::cal_leaves(node * pt)
{
    if(pt->left==nullptr&&pt->right==nullptr) return 1;
    else if(pt->left&&pt->right)
        return cal_leaves(pt->left)+cal_leaves(pt->right);
    else if(pt->left)
        return cal_leaves(pt->left);
    else if(pt->right) return cal_leaves(pt->right);
}

int BinaryTree::leaves()
{
    return cal_leaves(root);
}
int BinaryTree::cal_two_degree(node * pt)
{
    if(pt->left && pt->right)
        return 1+cal_two_degree(pt->left)+cal_two_degree(pt->right);
    else if(pt->left)
        return cal_two_degree(pt->left);
    else if(pt->right)
        return cal_two_degree(pt->right);
    else return 0;
}

int BinaryTree::two_degree_nodes()
{
    return cal_two_degree(root);
}

void BinaryTree::find_father(node*& res,Type c,node* pt)
{
    if(root->data==c) res=nullptr;
    else{
         if(pt==nullptr) pt=root;
    if((pt->left&&pt->left->data==c) || (pt->right&&pt->right->data==c))
        res=pt;
    else{
        if(pt->left) find_father(res,c,pt->left);
        if(pt->right) find_father(res,c,pt->right);
    }
    }

}

void BinaryTree::about_x(Type x)
{
    //父节点
    node *fat;
    find_father(fat,x);
    if(fat==nullptr) {
        cout<<"该节点是根节点;";
        fat=root;
    }
    else cout<<"该节点的父节点的值为："<<fat->data<<";";

    //兄弟节点
    if(fat&&fat->left&&fat->left->data==x){
        if(fat->right) cout<<"该节点的右兄弟的值为："<<fat->right->data<<";";
        else cout<<"该节点没有右兄弟;";


        //孩子节点
        if(fat->left->left) cout<<"左孩子的值为："<<fat->left->left->data<<";";
        else cout<<"没有左孩子;";

        if(fat->left->right) cout<<"右孩子的值为："<<fat->left->right->data<<";";
        else cout<<"没有右孩子;";

    }
    else{
        if(fat->left) cout<<"该节点的左兄弟的值为："<<fat->left->data<<";";
        else cout<<"该节点没有左兄弟;";

          //孩子节点
        if(fat->right->left) cout<<"左孩子的值为："<<fat->right->left->data<<";";
        else cout<<"没有左孩子;";

        if(fat->right->right) cout<<"右孩子的值为："<<fat->right->right->data<<";";
        else cout<<"没有右孩子;";
    }

}
int BinaryTree::find_level(Type x,int lev,node* pt)
{
    if(pt==nullptr) pt=root;
    if(pt->data==x) { return lev; }
    else{
        int t1=0,t2=0;
        if(pt->left) t1=find_level(x,lev+1,pt->left);
        if(pt->right) t2=find_level(x,lev+1,pt->right);
        return t1==0?t2:t1;
    }
}
void BinaryTree::change_right_left(node* t)
{
    if(t==nullptr) t=root;
    node *tmp=t->left;
    t->left=t->right;
    t->right=tmp;
    if(t->left) change_right_left(t->left);
    if(t->right) change_right_left(t->right);
}

void BinaryTree::clear(node*t)
{
    if(t)
    {
        clear(t->left);
        clear(t->right);
        delete t;
    }
}

void BinaryTree::leaves2root(bool longest,node* pt,string path)
{
    if(pt==nullptr) pt=root;
    if(!pt->left&&!pt->right) {
        if(longest){
            if(find_level(pt->data)==height())
                cout<<pt->data<<"；"<<path<<endl;
        }
        else
            cout<<pt->data<<"；"<<path<<endl;
    }
    else{
        stringstream sinout;
        sinout<<pt->data;
        string tmp;sinout>>tmp;
        path=tmp+path;
        if(pt->left) leaves2root(longest,pt->left,path);
        if(pt->right) leaves2root(longest,pt->right,path);
    }
}
void BinaryTree::print_by_level()
{
    queue<node*> Q;
    Q.push(root);
    Q.push(0);
    do {
        node* node = Q.front();
        Q.pop();
        if (node) {
            cout << node->data << " ";
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
        }
        else if (!Q.empty()) {
            Q.push(0);
            cout << endl;
        }
    } while(!Q.empty());
}

Type BinaryTree::near_common_ancestor(Type a,Type b)
{
    node* fat1,*fat2;
    find_father(fat1,a);
    find_father(fat2,b);
    while(fat1!=fat2)
    {
        if(fat1==nullptr || fat2==nullptr) {
            fat1=root;
            break;
        }
        find_father(fat1,fat1->data);
        find_father(fat2,fat2->data);
    }
    return fat1->data;
}
//下面是排序树算法的实现
BinaryTree::BinaryTree(Type a[],int n,bool avl)
{
    root=nullptr;
    for(int i=0;i<n;i++)
        if(avl) insert_avl(root,a[i]);
        else    insert(root,a[i]);
}
void BinaryTree::insert(node*&pt,Type x)
{
    if(pt==nullptr) {
        pt=new node;
        pt->data=x;
        pt->left=pt->right=nullptr;
    }
    else if(pt->data>x) insert(pt->left,x);
    else insert(pt->right,x);
}
BinaryTree::node* BinaryTree::search_sort(node*pt,Type x,bool prt)
{
    if(pt==nullptr) {
        if(prt) cout<<": 查找失败"<<x<<endl;
        return nullptr;
    }
    if(pt->data==x) {
        if(prt) cout<<": 查找成功"<<x<<endl;
        return pt;
    }
    else{
        if(prt) cout<<pt->data<<' ';
        if(x>pt->data) search_sort(pt->right,x,prt);
        else search_sort(pt->left,x,prt);
    }
}

void BinaryTree::remove(Type x)
{
    node *sf,*s;
    node* p=search_sort(root,x,false);
    find_father(sf,x);
    if(p->left==nullptr&&p->right==nullptr)
    {   delete p;
        if(sf->left==p) sf->left==nullptr;
        else sf->right==nullptr;
    }
    else if(p->left==nullptr&&p->right)
    {
        if(sf->left==p) sf->left=p->right;
        else sf->right=p->right;
        delete p;
    }
    else if(p->left&&p->right==nullptr)
    {
        if(sf->left==p) sf->left=p->left;
        else sf->right=p->left;
        delete p;
    }
    else
    {
        sf=p;s=p->left;
        while(s->right)
        {
            sf=s;
            s=s->right;
        }
        p->data=s->data;
        if(sf==p) sf->left=s->left;
        else sf->right=s->left;
        delete s;
    }
}
void BinaryTree::search(Type x)
{
    search_sort(root,x);
}

//AVL树的方法
int BinaryTree::height_avl(node * pnode)
{
    if (pnode != nullptr)
    {
        return pnode->height;
    }
    return 0;
}
BinaryTree::node* BinaryTree::leftRotation(node* proot)
{
    node* prchild = proot->right;
    proot->right = prchild->left;
    prchild->left = proot;

    proot->height = max(height_avl(proot->left),height_avl(proot->right))+1;     //更新节点的高度值
    prchild->height = max(height_avl(prchild->left), height_avl(prchild->right)) + 1; //更新节点的高度值
    return prchild;
}
BinaryTree::node* BinaryTree::rightRotation(node* proot)
{
    node* plchild = proot->left;
    proot->left = plchild->right;
    plchild->right = proot;

    proot->height = max(height_avl(proot->left),height_avl(proot->right))+1;     //更新节点的高度值
    plchild->height = max(height_avl(plchild->left), height_avl(plchild->right)) + 1; //更新节点的高度值

    return plchild;
}
BinaryTree::node* BinaryTree::rightLeftRotation(node* proot)
{
    proot->right=rightRotation(proot->right);
    return leftRotation(proot);
}
BinaryTree::node* BinaryTree::leftRightRotation(node* proot)
{
    proot->left=leftRotation(proot->left);
    return rightRotation(proot);
}
BinaryTree::node* BinaryTree::insert_avl(node*&pnode,Type key)
{
    if (pnode == nullptr)    //寻找到插入的位置
    {
        pnode = new node;
        pnode->data=key;
        pnode->left=pnode->right=nullptr;
    }
    else if (key > pnode->data)    //插入值比当前结点值大，插入到当前结点的右子树上
    {
        pnode->right = insert_avl(pnode->right, key);
        if (height_avl(pnode->right) - height_avl(pnode->left) == 2) //插入后出现失衡
        {
            if (key > pnode->right->data) //情况一：插入右子树的右节点，进行左旋
                pnode=leftRotation(pnode);
            else if (key < pnode->right->data)  //情况三：插入右子树的左节点,进行先右再左旋转
                pnode=rightLeftRotation(pnode);
        }
    }
    else if (key < pnode->data) //插入值比当前节点值小，插入到当前结点的左子树上
    {
        pnode->left = insert_avl(pnode->left, key);
        if (height_avl(pnode->left) - height_avl(pnode->right) == 2) //如果插入导致失衡
        {
            if (key < pnode->left->data)        //情况二：插入到左子树的左孩子节点上，进行右旋
                pnode = rightRotation(pnode);
            else if (key>pnode->left->data)
                pnode = leftRightRotation(pnode);//情况四：插入到左子树的右孩子节点上，进行先左后右旋转
        }
    }
    pnode->height= max(height_avl(pnode->left), height_avl(pnode->right)) + 1;
    return pnode;
}

BinaryTree::node* BinaryTree::remove_avl(node*&pnode,Type key)
{
    if (pnode != nullptr)
    {
        if (key == pnode->data)            //找到删除的节点
        {
            //因AVL也是二叉排序树，删除节点要维护其二叉排序树的条件
            if (pnode->left != nullptr&&pnode->right != nullptr)        //若左右都不为空
            {
                // 左子树比右子树高,在左子树上选择节点进行替换
                if (height_avl(pnode->left) > height_avl(pnode->right))
                {
                    //使用左子树最大节点来代替被删节点，而删除该最大节点
                    node* ppre = maximum(pnode->left);        //左子树最大节点
                    pnode->data = ppre->data;                                //将最大节点的值覆盖当前结点
                    pnode->left = remove_avl(pnode->left, ppre->data);    //递归地删除最大节点
                }
                else  //在右子树上选择节点进行替换
                {
                    //使用最小节点来代替被删节点，而删除该最小节点
                    node* psuc = minimum(pnode->right);        //右子树的最小节点
                    pnode->data = psuc->data;                                //将最小节点值覆盖当前结点
                    pnode->right = remove_avl(pnode->right, psuc->data);    //递归地删除最小节点
                }

            }
            else
            {
                node* ptemp = pnode;
                if (pnode->left != nullptr)
                    pnode = pnode->left;
                else if (pnode->right != nullptr)
                    pnode = pnode->right;
                delete ptemp;
                return nullptr;
            }

        }
        else if (key > pnode->data)//要删除的节点比当前节点大，则在右子树进行删除
        {
            pnode->right =  remove_avl(pnode->right, key);
            //删除右子树节点导致不平衡:相当于情况二或情况四
            if (height_avl(pnode->left) - height_avl(pnode->right) == 2)
            {
                //相当于在左子树上插入右节点造成的失衡（情况四）
                if (height_avl(pnode->left->right)>height_avl(pnode->left->left))
                    pnode = leftRightRotation(pnode);
                else//相当于在左子树上插入左节点造成的失衡（情况二）
                    pnode = rightRotation(pnode);
            }
        }
        else if (key < pnode->data)//要删除的节点比当前节点小，则在左子树进行删除
        {
            pnode->left= remove_avl(pnode->left, key);
             //删除左子树节点导致不平衡：相当于情况三或情况一
            if (height_avl(pnode->right) - height_avl(pnode->left) == 2)
            {
                //相当于在右子树上插入左节点造成的失衡（情况三）
                if (height_avl(pnode->right->left)>height_avl(pnode->right->right))
                    pnode = rightLeftRotation(pnode);
                else//相当于在右子树上插入右节点造成的失衡（情况一）
                    pnode = leftRotation(pnode);
            }
        }
        return pnode;
    }
    return nullptr;
}
BinaryTree::node* BinaryTree::maximum(node* pnode)
{
    if (pnode != nullptr)
    {
        while (pnode->right!= nullptr)
            pnode = pnode->right;
        return pnode;
    }
    return nullptr;
}
Type BinaryTree::maximum()
{
    node* presult = maximum(root);
    if (presult != nullptr)
        return presult->data;
}
BinaryTree::node* BinaryTree::minimum(node* pnode)
{
    if (pnode != nullptr)
    {
        while (pnode->left!= nullptr)
            pnode = pnode->left;
        return pnode;
    }
    return nullptr;
}
Type BinaryTree::minimum()
{
    node* presult = minimum(root);
    if (presult != nullptr)
        return presult->data;
}
BinaryTree::~BinaryTree()
{
    //dtor
    clear(root);
}
