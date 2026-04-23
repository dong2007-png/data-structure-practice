#include <iostream>
using namespace std;
struct Binode
{
    int data;
    Binode* lchild,*rchild;
};

class Bitree
{
    private:
    Binode* root;
public:
    Bitree()
    {
        root=creat(root);

    }
    ~Bitree()
    {
        release(root);
    }
    void preorder(Binode* bt);
    void inorder(Binode* bt);
    void postorder(Binode* bt);
    Binode* creat(Binode *bt);
    void release(Binode *bt);
    void levelOrder(Binode* bt);
};
Binode* Bitree::creat(Binode *bt)
{
    char ch;
    cin>>ch;
    if(ch=='#')
    {
        return NULL;
    }else
    {
        bt=new Binode;
        bt->data=ch;
        bt->lchild=creat(bt->lchild);
        bt->rchild=creat(bt->rchild);
    }
};
void Bitree::preorder(Binode* bt)
{
    if (bt!=NULL)
    {
        cout<<bt->data<<" ";
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}
void Bitree::inorder(Binode* bt)
{
    if (bt!=NULL)
    {
        inorder(bt->lchild);
        cout<<bt->data<<" ";
        inorder(bt->rchild);
    }
}
void Bitree::postorder(Binode* bt)
{
    if (bt!=NULL)
    {
        postorder(bt->lchild);
        postorder(bt->rchild);
        cout<<bt->data<<" ";
    }
}
void Bitree::release(Binode *bt)
{
    if (bt!=NULL)
    {
        release(bt->lchild);
        release(bt->rchild);
        delete bt;
    }
}
void levelOrder(Binode* bt)
{

}


int main()
{

}