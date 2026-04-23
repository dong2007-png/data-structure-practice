#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 10000;

class Bitree
{
    private:
    char data[MAX_SIZE];
    int length;
    public:
    Bitree(string s);
    void preorder(int i);
};

Bitree::Bitree(string s)
{
    for (int i=0;i<MAX_SIZE;i++)
    {
        data[i]=0;
    }
    length=s.length();
    for (int i=0;i<length;i++)
    {
        if (s[i]=='^')
        {
            data[i+1]=0;
        }else
        {
            data[i+1]=s[i];
        }
    }
}


void Bitree::preorder(int i)
{
    if (i>=MAX_SIZE||data[i]==0)
    {
        return;
    }
    cout<<data[i];
    preorder(i*2);
    preorder(i*2+1);

}
int main()
{
    string a;
    cin>>a;
    Bitree b(a);
    b.preorder(1);
    cout<<endl;
    return 0;

}
