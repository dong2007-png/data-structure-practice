#include<iostream>
using namespace std;
const int QueueSize = 100;

struct BiNode{
    char data;
    BiNode *lchild, *rchild;
};

class BiTree {
private:
    BiNode *root;
public:
    BiTree()
    {
        root=creat(root);
    };
    ~BiTree()
    {
        release(root);
    }
    void release(BiNode* bt);
    BiNode *creat(BiNode *bt);
    void preorder(BiNode*bt);
    void inorder(BiNode*bt);
    BiNode* deleteroot(char ch, BiNode* bt);
    BiNode *getroot();
};

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

void BiTree::release(BiNode* bt)
{
    if(bt)
    {
        release(bt->lchild);
        release(bt->rchild);
        delete bt;
    }
}

BiNode *BiTree::getroot()
{
    return root;
}

void BiTree::preorder(BiNode* bt)
{
    if (bt==NULL) return;
    cout<<bt->data;
    preorder(bt->lchild);
    preorder(bt->rchild);
}

void BiTree::inorder(BiNode* bt)
{
    if (bt==NULL) return;
    inorder(bt->lchild);
    cout<<bt->data;
    inorder(bt->rchild);
}

BiNode* BiTree::deleteroot(char ch, BiNode* bt)
{
    if (bt == NULL) return NULL;

    if (ch == bt->data)
    {
        release(bt);
        return NULL;
    }


    bt->lchild = deleteroot(ch, bt->lchild);
    bt->rchild = deleteroot(ch, bt->rchild);

    return bt;
}

int main(){
    BiTree tree;
    char ch;
    cin >> ch;

    cout <<"删除后........."<<endl;

    BiNode* newroot = tree.deleteroot(ch, tree.getroot());

    cout<<"前序遍历：";
    tree.preorder(newroot);
    cout<<endl;

    cout<<"中序遍历：";
    tree.inorder(newroot);
    cout<<endl;

    return 0;
}