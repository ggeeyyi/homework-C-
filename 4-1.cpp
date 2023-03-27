#include <iostream>
#include <iomanip>
using namespace std;
class Date
{
    int d,m,y;
public:
    Date(int dd,int mm,int yy):d(dd),m(mm),y(yy){};
    void addDay();
    friend Date operator ++(Date &D);
    friend Date operator ++(Date &D,int);
    void Print()
    {
        cout<<d<<","<<m<<","<<y<<endl;
    }
};

Date operator ++(Date &D)
{
    Date tmp(1000,1,1);
    D.addDay();
    tmp.d=D.d;
    tmp.y=D.y;
    tmp.m=D.m;
    return tmp;
}
Date operator ++(Date &D,int)
{
    Date tmp(1000,1,1);
    tmp.d=D.d;
    tmp.y=D.y;
    tmp.m=D.m;
    D.addDay();
    return tmp;
}

void Date::addDay()
{
    d++;
    if(y%4!=0)
    {
    switch (m)
    {
    case 1:
        if(d>31)
        {
            d=1;
            m=2;
        }
        break;
    case 2:
        if(d>28)
        {
            d=1;
            m=3;
        }
        break;
   case 3:
        if(d>31)
        {
            d=1;
            m=4;
        }
        break;
    case 4:
        if(d>30)
        {
            d=1;
            m=5;
        }
        break;
    case 5:
        if(d>31)
        {
            d=1;
            m=6;
        }
        break;
    case 6:
        if(d>30)
        {
            d=1;
            m=7;
        }
        break;
    case 7:
        if(d>31)
        {
            d=1;
            m=8;
        }
        break;
    case 8:
        if(d>31)
        {
            d=1;
            m=9;
        }
        break;
    case 9:
        if(d>30)
        {
            d=1;
            m=10;
        }
        break;
    case 10:
        if(d>31)
        {
            d=1;
            m=11;
        }
        break;
    case 11:
        if(d>30)
        {
            d=1;
            m=12;
        }
        break;
    case 12:
        if(d>31)
        {
            d=1;
            m=1;
            y++;
        }
        break;
    }
    }
    if(y%4==0)
    {
    switch (m)
    {
    case 1:
        if(d>31)
        {
            d=1;
            m=2;
        }
        break;
    case 2:
        if(d>29)
        {
            d=1;
            m=3;
        }
        break;
   case 3:
        if(d>31)
        {
            d=1;
            m=4;
        }
        break;
    case 4:
        if(d>30)
        {
            d=1;
            m=5;
        }
        break;
    case 5:
        if(d>31)
        {
            d=1;
            m=6;
        }
        break;
    case 6:
        if(d>30)
        {
            d=1;
            m=7;
        }
        break;
    case 7:
        if(d>31)
        {
            d=1;
            m=8;
        }
        break;
    case 8:
        if(d>31)
        {
            d=1;
            m=9;
        }
        break;
    case 9:
        if(d>30)
        {
            d=1;
            m=10;
        }
        break;
    case 10:
        if(d>31)
        {
            d=1;
            m=11;
        }
        break;
    case 11:
        if(d>30)
        {
            d=1;
            m=12;
        }
        break;
    case 12:
        if(d>31)
        {
            d=1;
            m=1;
            y++;
        }
        break;
        }
    }
}
int main()
{
    Date D1(9,10,2012),D2(28,2,2023);
    (D1++).Print();
    (++D2).Print();
    return 0;
}