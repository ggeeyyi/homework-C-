#include <iostream>
using namespace std;
#include "employee.h"

int main()
{
    employee emp1,emp2,emp3,emp4;
    emp1.setdata();
    emp2.setdata();
    emp3.setdata();
    emp4.setdata();
    cout<<"setdatacompleted"<<endl;
    emp1.printdata();
    emp2.printdata();
    emp3.printdata();
    emp4.printdata();
    return 0;
}