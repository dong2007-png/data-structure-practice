#include <iostream>
#include <algorithm>
using namespace std;
struct Binode
{
    char data;
    Binode *lchild;
    Binode *rchild;

};


class Btree
{
private:
    Binode *root;
public:
    Btree()
    {
        root = creat(root);
    }
    ~Btree()
    {
        release(root);
    }
    void release(Binode *bt);
    Binode* creat(Binode *bt);
    int treelength(Binode *bt);
    Binode* getroot();
    int numbernode(Binode *bt);
};
Binode* Btree::getroot()
{
    return root;
}

void Btree::release(Binode *bt)
{
    if (bt != NULL)
    {
        release(bt->lchild);
        release(bt->rchild);
        delete bt;
    }
}


Binode* Btree::creat(Binode *bt)
{
    char ch;
    cin>>ch;
    if (ch=='#')
    {
        return NULL;
    }else
    {
        bt=new Binode;
        bt->data=ch;
        bt->lchild=creat(bt->lchild);
        bt->rchild=creat(bt->rchild);

    }
    return bt;
}



int Btree::treelength(Binode *bt)
{
    if (bt == NULL) return 0;


    if (!bt->lchild&&!bt->rchild)
    {
        return 1;
    }

    if (!bt->lchild&&bt->rchild)
    {
        return treelength(bt->rchild)+1;
    }

    if (bt->lchild&&!bt->rchild)
    {
        return treelength(bt->lchild)+1;
    }

    if (bt->rchild&&bt->lchild)
    {
        return max(treelength(bt->rchild),treelength(bt->lchild))+1;
    }


}
int Btree::numbernode(Binode *bt)
{
    if (bt == NULL) return 0;
    return numbernode(bt->lchild)+numbernode(bt->rchild)+1;
}



int main()
{
    Btree tree;
    cout<<tree.numbernode(tree.getroot())<<endl;
    return 0;



}