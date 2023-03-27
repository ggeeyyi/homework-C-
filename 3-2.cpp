#include<iostream>
#include<string.h>
using namespace std;
class student
{    
public:
    void init(string nam,int id,int grad);
    string name;
    int ID;
    int grade;
    void print(void);
    student(student &stud);
    student(void);
};

student::student(student &stud)
{
    ID=stud.ID;
    grade=stud.grade;
    name=stud.name;
}
student::student(void)
{
}
void student::print(void)
{
    cout<<"name:"<<name<<" ID:"<<ID<<" grade:"<<grade<<endl;
}
void student::init(string nam,int id,int grad)
{
    ID=id;
    grade=grad;
    name=nam;
}
int main()
{
    student stu[10],stumax;
    int id,grad,maxid,maxi;
        string nam;
    for(int i=0;i<10;i++)
    {
        cin>>nam>>id>>grad;
        stu[i].init(nam,id,grad);
    }
    int max(student stu[]);
    maxid=max(stu);   
    cout<<maxid<<endl;      
    for(int i=0;i<10;i++)
    {
        if(stu[i].ID==maxid)
        {
            maxi=i;
        }
    }
    student studmax(stu[maxi]);
    studmax.print();
}
int max(student *stu)
{
    int max=0,maxid;
    for(int i=0;i<10;i++)
    {
        if(stu[i].grade>max)
        {
            max=stu[i].grade;
            maxid=stu[i].ID;
        }
    }
    return maxid;
}
