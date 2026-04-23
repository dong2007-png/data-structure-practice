/**字符串建树 并实现遍历(待填充代码）*/
#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_SIZE 100


struct BiNode
{
    char data;
    BiNode  *lchild, *rchild;
};

class queue {
private:
    int front, rear;
    int size;
    BiNode** data;
public:
    queue() {
        size = MAX_SIZE;
        front = rear = 0;
        data = new BiNode*[size];
    }
    ~queue() {
        delete[] data;
    }
    bool isempty() {
        return front == rear;
    }
    bool isfull() {
        return (rear + 1) % size == front;
    }
    void enqueue(BiNode* bt) {
        if (isfull()) {
            return;
        }
        else {
            data[rear] = bt;
            rear = (rear + 1) % size;
        }
    }
    BiNode* dequeue() {
        if (isempty()) {
            return NULL;
        }
        BiNode* c = data[front];
        front = (front + 1) % size;
        return c;
    }
};

class BiTree {
private:
    BiNode *root;
public:
    BiTree()
    {
        root = creat(root);
    }
    ~BiTree(){
    	release(root);
    }
    BiNode * getRoot(){return root;}
    BiNode *creat(BiNode *bt);
    void release(BiNode *bt);
    void preOrder(BiNode *bt);
    void inOrder(BiNode *bt);
    void postOrder(BiNode *bt);
    void leverOrder();
};

// 前序建树
BiNode* BiTree::creat(BiNode *bt){
    char ch = getchar();
    if(ch == '#'){
        bt = NULL;
    }else{
        bt = new BiNode;
        bt->data = ch;
        bt->lchild = creat(bt->lchild);
        bt->rchild = creat(bt->rchild);
    }
    return bt;
}

void BiTree::release(BiNode *bt){
    if(bt!=NULL){
        release(bt->lchild);
        release(bt->rchild);
        // cout<<"delete "<<bt->data<<endl;
        delete bt;
    }
}

void BiTree::leverOrder()
{

    if(root == NULL) return;
    queue queue;
    queue.enqueue(root);

    while(!queue.isempty()){
        BiNode* q = queue.dequeue();
        cout << q->data;

        if(q->lchild != NULL){
            queue.enqueue(q->lchild);
        }

        if(q->rchild != NULL){
            queue.enqueue(q->rchild);
        }
    }
}


int main()
{
    BiTree tree;
    tree.leverOrder();
    return 0;
}
