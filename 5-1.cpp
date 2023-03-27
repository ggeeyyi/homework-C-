#include <iostream>
using namespace std;
class Date
{
    public:
    int day;
    int month;
    int year;
    friend istream & operator>>(istream & input,Date &p);
    friend ostream & operator<<(istream & output,Date &p);
};
class People
{
    private:
        char name[11];
        char number[7];
        char sex[3];
        char id[16];
        Date birthday;
    public:
        friend istream & operator >>(istream & input,People &p);
        friend ostream & operator <<(ostream &output,People &p);
};
istream & operator>>(istream & input,Date &p)
{
    cout<<"please input year:";
    input>>p.year;
    cout<<"please input month:";
    input>>p.month;
    cout<<"please input day:";
    input>>p.day;
    return input;
}
ostream & operator<<(ostream & output,Date &p)
{
    output<<p.year<<"-"<<p.month<<"-"<<p.day<<endl;
    return output;
}
istream & operator>>(istream & input,People &p)
{
    cout<<"please input name:";
    input>>p.name;
    cout<<"please input number:";
    input>>p.number;
    cout<<"please input sex:";
    input>>p.sex;
    cout<<"please input id:";
    input>>p.id;
    cout<<"please input birthday:"<<endl;
    input>>p.birthday;
    return input;
} 
ostream & operator <<(ostream &output,People &p)
{
    output<<"name:"<<p.name<<" number:"<<p.number<<" sex:"<<p.sex<<" id:"<<p.id<<" birthday"<<p.birthday<<endl;
    return output;
}

int main()
{
    People p;
    cin>>p;
    cout<<p<<endl;
    return 0;
}