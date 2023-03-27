class employee
{
private:
    int individualEmpNo;
    int grade;
    int accumPay;
public:
    void setdata();
    void printdata();
    employee();
    employee(int i,int g,int a):individualEmpNo(i),grade(g),accumPay(a){};
    static int currentEmpNo;
};
int employee::currentEmpNo=10004;
employee::employee()
{
    individualEmpNo=10001;
    grade=1;
    accumPay=500;
}
inline void employee::setdata()
{
    employee::currentEmpNo++;
    cout<<"grade:";
    cin>>grade;
    cout<<"accumPay:";
    cin>>accumPay;
    individualEmpNo=currentEmpNo;
}
inline void employee::printdata()
{
    cout<<"individualEmpNo:"<<individualEmpNo<<endl;
    cout<<"grade:"<<grade<<endl; 
    cout<<"accumPay:"<<accumPay<<endl;
}
