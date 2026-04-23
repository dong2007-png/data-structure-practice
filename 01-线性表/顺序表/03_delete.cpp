#include<iostream>
#include<string>
using namespace std;

class Seqlist
{
private:
    int data[100];
    int length;

public:
    Seqlist();
    ~Seqlist();
    void append(int value);
    void print();
    bool insert(int pos,int value);
    bool remove(int pos);
    int  size();


};

void Seqlist::append(int value)
{
    if (length>=100)
    {
        cout<<"表已满"<<endl;

    }else
    {
        data[length++] = value;
    }

}
int  Seqlist::size()
{
    return length;
}

Seqlist::Seqlist()
{
    length=0;

}

Seqlist::~Seqlist()
{

}


void Seqlist::print()
{
    cout<<"[";
    for (int i=0;i<length;i++)
    {
        cout<<data[i];
        if (i!=length-1)
        {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;

}
bool Seqlist::insert(int pos,int value)
{
    if (length>=100)
    {
        cout<<"表已满"<<endl;
        return false;
    }

    if (pos>length||pos<0)
    {
        cout<<"位置非法"<<endl;
        return false;
    }else{
        for (int i=length;i>pos;i--)
        {
            data[i]=data[i-1];
        }
        data[pos]=value;
        length++;

    }


    return true;
}

bool Seqlist::remove(int pos)
{
    if (length==0)
    {
        return false;
    }

    if (pos<0||pos>=length)
    {
        return false;
    }
     for (int i=pos;i<length-1;i++)
     {
         data[i]=data[i+1];
     }
     length--;
     return true;

}


int main()
{
    Seqlist list;
    for (int i = 10; i <= 50; i += 10) list.append(i); // 10,20,30,40,50
    cout << "Initial: ";
    list.print();

    list.remove(2); // 删除30（位置2）
    cout << "After remove at pos 2: ";
    list.print();

    list.remove(0); // 删除头部
    cout << "After remove at pos 0: ";
    list.print();

    list.remove(list.size() - 1); // 删除尾部
    cout << "After remove at tail: ";
    list.print();

    // 非法测试
    list.remove(-1);
    list.remove(list.size()); // 比如 size=2，删除 pos=2 非法
    return 0;




}