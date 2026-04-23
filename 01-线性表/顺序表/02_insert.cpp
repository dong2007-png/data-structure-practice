#include<iostream>
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



int main()
{
    Seqlist list;
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "初始: ";
    list.print();

    list.insert(1, 99);
    cout << "在位置1插入99: ";
    list.print();

    list.insert(0, 5);
    cout << "在位置0插入5: ";
    list.print();

    // 尾部插入：需要知道当前长度，可以手动计算或增加 size() 函数
    // 建议在类中添加 int size() const { return length; }
    // 然后调用 list.insert(list.size(), 100);
    // 这里暂时用已知长度5（因为上面插入后表有5个元素）
    list.insert(5, 100);
    cout << "在尾部插入100: ";
    list.print();

    // 非法测试
    list.insert(-1, 999);
    list.insert(10, 999);

    return 0;





}