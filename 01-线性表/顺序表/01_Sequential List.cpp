#include <iostream>
using namespace std;



class Seqlist
{
    private:
    int data[100];
    int length;
public:
    Seqlist();
    ~Seqlist();
    void append(int data);
    void print();

};

Seqlist::Seqlist()
{
    length=0;
}

Seqlist::~Seqlist()
{

}

void Seqlist::append(int value)
{
    if (length>=100)
    {
        cout<<"表已满，无法插入"<<endl;
    }else
    {
        data[length]=value;
        length++;
    }
    return ;

}
void Seqlist::print()
{
    cout<<"[";
    for (int i=0;i<length;i++)
    {
        cout<<data[i];
        if (i!=length-1) cout<<",";
    }
    cout<<"]"<<endl;
    return ;
}



int main()
{
    Seqlist list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.print();


}
