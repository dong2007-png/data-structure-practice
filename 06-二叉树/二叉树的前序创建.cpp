// 【问题描述】使用前序字符串构建一个二叉树，为了检查树建立得是否正确，需要采用前序序遍历这棵树。字符串使用“#”表示孩子为空的情况。
// 【输入形式】
// ab##cd##e##
// 【输出形式】
// abcde
// 【用例说明】
// 上述输入能构建下图的二叉树。
//    a
//   /  \
//  b     c
//       /  \
//      d   e
/**字符串建树 并实现遍历(待填充代码）*/


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
        //release(root);
    }
    BiNode * getRoot(){return root;}
    BiNode *creat(BiNode *bt); //构造函数调用
    void release(BiNode *bt);  //析构函数调用，释放树的存储空间
    void preOrder(BiNode *bt); //前序遍历函数调用
    void inOrder(BiNode *bt);  //中序遍历函数调用
    void postOrder(BiNode *bt);//后序遍历函数调用
    void leverOrder();//后序遍历函数调用
};

/**前序构建二叉树*/
BiNode *BiTree::creat(BiNode *bt)
{
    char ch;
    cin>>ch;
    if (ch=='#')
    {
        return NULL;
    }else
    {
        bt=new BiNode();
        bt->data=ch;
        bt->lchild=creat(bt->lchild);
        bt->rchild=creat(bt->rchild);
    }
    return bt;

}
/**前序遍历*/
void BiTree::preOrder(BiNode * bt)
{
    if (bt!=NULL)
    {
        cout<<bt->data<<" ";
        preOrder(bt->lchild);
        preOrder(bt->rchild);
    }

}

int main()
{
    //cout<<"输入前序字符串:";
    BiTree tree;
    //cout << "前序遍历二叉树"<<endl;
    tree.preOrder(tree.getRoot());
    return 0;
}













