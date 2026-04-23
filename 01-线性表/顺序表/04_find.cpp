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
    int find(int value);
    bool set(int pos, int value);
    void reverse();


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

int Seqlist::find(int value)
{
    if (length==0)
    {
        return -1;
    }
    for (int i=0;i<length;i++)
    {
        if (data[i]==value)
        {
            return i;
        }
    }
    return -1;
}
bool Seqlist::set(int pos,int value)
{
    if (length==0)
    {
        return false;
    }
    if (pos<0||pos>=length)
    {
        return false;
    }
    data[pos]=value;
    return true;
}

void Seqlist::reverse()
{
    int temp;
    for (int i=0;i<length/2;i++)
    {
        temp=data[i];
        data[i]=data[length-1-i];
        data[length-1-i]=temp;
    }
}


int main()
{
    Seqlist list;
    list.append(2);
    list.append(30);
    list.append(40);
    list.set(0,-1);
    list.print();
    list.reverse();
    list.print();




}