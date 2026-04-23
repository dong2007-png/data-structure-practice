#include<iostream>
#include<cmath>
using namespace std;

typedef struct
{
    int x;
    int y;
    int item;
}zuobiao;

class sanyuanshuzu
{
private:
    int hang;
    int lie;
    int num;
    zuobiao data[100];
public:
    sanyuanshuzu();
    ~sanyuanshuzu();
    sanyuanshuzu(int hang, int lie);
    void findmax(zuobiao &a);
    void remove(zuobiao &a);
    void add(int x,int y,int item);
};




sanyuanshuzu::sanyuanshuzu()
{
    hang=0;
    lie=0;
    num=0;
}

sanyuanshuzu::~sanyuanshuzu(){}

sanyuanshuzu::sanyuanshuzu(int hang,int lie)
{
    this->hang=hang;
    this->lie=lie;
    num=0;
}

void sanyuanshuzu::add(int x,int y,int item){
    data[num].x=x;
    data[num].y=y;
    data[num].item=item;
    num++;
}

void sanyuanshuzu::findmax(zuobiao &a)
{
    a.item=0;
    for(int i=0;i<num;i++)
    {
        if (data[i].item>a.item)
        {
            a=data[i];
        }
    }
}

void sanyuanshuzu::remove(zuobiao &a)
{
    for (int i = 0;i <num;i++) {
        if (data[i].x==a.x && data[i].y == a.y) {
            for (int j = i; j < num - 1; j++)
                data[j] = data[j + 1];
            num--;
            break;
        }
    }
}

int main()
{
    int M,N,K,time=0,res=0;
    cin>>M>>N>>K;
    sanyuanshuzu t(M,N);
    zuobiao max1;

    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            int v;
            cin>>v;
            if(v>0)
            {
                t.add(i,j,v);
            }

        }
    }

    int x=0,y=0;
    while(1){
        t.findmax(max1);
        if(max1.item==0) break;

        int cost;
        if(x==0)
        {
            cost=max1.x+1+max1.x;
        }else{
            cost=abs(max1.x-x)+abs(max1.y-y)+1+max1.x;
        }
        if(time+cost>K) break;

        res+=max1.item;
        time+=cost-max1.x;
        x=max1.x;
        y=max1.y;
        t.remove(max1);
    }
    cout<<res;
    return 0;
}