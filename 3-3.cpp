#include <iostream>
using namespace std;
class salesman
{
private:
    /* data */
public:
    int ID;
    int number;
    double price;
    static double total;
    static double average;
    static void sum(salesman a[],int n);
    void init(int id,int num,double pri);
};

double salesman::total=0;
double salesman::average=0;
void salesman::init(int id,int num,double pri)
{
    ID=id;
    number=num;
    price=pri;
}

void sum(salesman a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].number<=10)
            salesman::total+=a[i].price*a[i].number;
        if (a[i].number>10)
        {
            salesman::total+=a[i].price*0.98*a[i].number;
        }
        count+=a[i].number;
    }
    salesman::average=salesman::total/count;
}

int main()
{
    salesman staff[3];
    staff[0].init(101,5,23.5);
    staff[1].init(102,12,24.5);
    staff[2].init(103,100,21.5);
    sum(staff,3);
    cout<<"sum="<<salesman::total<<" average="<<salesman::average<<endl;
    return 0;
}
