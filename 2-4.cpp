#include <iostream>
using namespace std;
#include "employee.h"

int main()
{
    employee emp1;
    employee emp2(10002,2,1000),emp3(10003,3,1200),emp4(10004,4,2000);
    cout<<"setdatacompleted"<<endl;
    emp1.printdata();
    emp2.printdata();
    emp3.printdata();
    emp4.printdata();
    return 0;
}