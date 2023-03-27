#include <iostream>
using namespace std;
class Student
{
    private:
        int ID;
        int Grade;
    public:
        void Input();
        void Output();
};
void Student::Input()
{
    cout<<"ID:";
    cin>>ID;
    cout<<"Grade:";
    cin>>Grade;
}
void Student::Output()
{
    cout<<"ID:"<<ID<<" Grade:"<<Grade<<endl;
}
int main()
{
    Student student[5],p;
    for(int i=0;i<5;i++)
    {
        p.Input();
        student[i]=p;
    }
    for(int i=0;i<5;i+=2)
    {
        student[i].Output();
    }
    return 0;
}