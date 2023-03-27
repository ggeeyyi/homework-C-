#include<iostream>
#include<cstring>
#include<algorithm>
#include<tchar.h>
using namespace std;
class Strings
{
    public:
        Strings(char *s);
        void Print();
        void Set(char *s);
        friend bool operator==(Strings &str1,Strings &str2);
        friend bool operator>(Strings &str1,Strings &str2);
        friend bool operator<(Strings &str1,Strings &str2);
        friend Strings operator+(Strings &str1,Strings &str2);
        friend Strings operator-(Strings &str1,Strings &str2);
        Strings operator=(Strings &str1);
    private:
        int length;
        char *str;
};

Strings::Strings(char *s)
{
    length=strlen(s);
    str=new char[length+1];
    strcpy(str,s);
}
void Strings::Set(char *s)
{
    length=strlen(s);
    delete []str;
    str=new char[length+1];
    strcpy(str,s);
}
void Strings::Print()
{
    cout<<str<<endl;
    cout<<length<<endl;
}
bool operator==(Strings &str1,Strings &str2)
{
    if(str1.length!=str2.length)
        return false;
    else
    {
        for(int i=0;i<str1.length;i++)
        {
            if(str1.str[i]!=str2.str[i])
            {
                return false;
            }
        }
        return true;
    }
}
bool operator>(Strings &str1,Strings &str2)
{
    int maxlength;
    if(str1.length>str2.length)
        maxlength=str1.length;
    else
        maxlength=str2.length;
    for(int i=0;i<maxlength;i++)
    {
        if(str1.str[i]>str2.str[i])
        {
            return true;
        }
    }
    return false;
}
bool operator<(Strings &str1,Strings &str2)
{
    int maxlength;
    if(str1.length>str2.length)
        maxlength=str1.length;
    else
        maxlength=str2.length;
    for(int i=0;i<maxlength;i++)
    {
        if(str1.str[i]<str2.str[i])
        {
            return true;
        }
    }
    return false;
}
Strings operator+(Strings &str1,Strings &str2)
{
    Strings S(" ");
    strcat(str1.str,str2.str);
    S.str=str1.str;
    S.length=str1.length+str2.length;
    return S;
}
Strings operator-(Strings &str1,Strings &str2)
{
    char temp1[20],temp2[20],temp3[20];
    int l1=str1.length;
    int l2=str2.length;
    int flag=0;
    strcpy(temp1,str1.str);
    strcpy(temp2,str2.str);
    for(int i=0;i<l2;i++)
    {
        flag=0;
        for(int j=0;j<l1;j++)
        {
            if(temp1[j]==temp2[i])
            {
                for(int k=j;k<l1-1;k++)
                {
                    temp1[k]=temp1[k+1];
                }
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return NULL;
        }
    }
    for(int i=0;i<(l1-l2);i++)
    {
        temp3[i]=temp1[i];
    }
    strcpy(str1.str,temp3);
    str1.length=str1.length-str2.length;
    return str1;
}
Strings Strings::operator=(Strings &str1)
{
    Strings S("");
    S.str=str1.str;
    S.length=str1.length;
    return S;
}

int main()
{
    Strings s1("Hell"),s2("Hello");
    (s1-s2).Print();
    return 0;
}

