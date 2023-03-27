#include <iostream>
#include <string.h>
using namespace std;
class Strings
{
    public:
        Strings(char *s);
        ~Strings();
        void Print();
        void Set(char *s);
    private:
        int length;
        char *str;
};
Strings::Strings(char *s)
{
    str=s;
    Strings::length=0;
}
Strings::~Strings()
{
    cout<<"Destructor called"<<endl;
}
void Strings::Set(char *s)
{
    str=s;
    length=strlen(str);
}
void Strings::Print()
{
    cout<<"Length:"<<length<<"  string:"<<str<<endl;
}
int main()
{
    char s[10]="Default";
    char temp[100];
    cin>>temp;
    Strings string1(s);
    string1.Set(temp);
    string1.Print();
    return 0;
}