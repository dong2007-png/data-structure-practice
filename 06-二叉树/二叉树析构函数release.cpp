/**字符串建树 并实现遍历(待填充代码）*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct BiNode
{
    char data;//数据域
    BiNode  *lchild, *rchild;//左右儿子指针
};

class BiTree {
private:
    BiNode *root;              //指向根结点的头指针

public:
    BiTree()
    {
        root = creat(root);//调函数构建二叉树
    }
    ~BiTree(){
        release(root);
    }
    BiNode * getRoot(){return root;}
    BiNode *creat(BiNode *bt); //构造函数调用
    void release(BiNode *bt);  //析构函数调用，释放树的存储空间
    void preOrder(BiNode *bt); //前序遍历函数调用
    void inOrder(BiNode *bt);  //中序遍历函数调用
    void postOrder(BiNode *bt);//后序遍历函数调用
    void leverOrder();//后序遍历函数调用
};

BiNode* BiTree::creat(BiNode *bt){
    char ch;
    cin>>ch;
    if(ch=='#'){
        bt=NULL;
    }else{
        bt=new BiNode;
        bt->data=ch;
        bt->lchild=creat(bt->lchild);
        bt->rchild=creat(bt->rchild);
    }
    return bt;
}
void BiTree::release(BiNode *bt){
    if(bt!=NULL){
        release(bt->lchild);
        release(bt->rchild);
        cout<<"delete "<<bt->data<<endl;
        delete bt;
    }
}
int main()
{
    //cout<<"输入前序字符串:";
    BiTree tree;

    return 0;
}

