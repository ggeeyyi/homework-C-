#include <iostream>
using namespace std;
class CPU
   {
    private:
        enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};
        CPU_Rank rank;
        int frequency;
        float voltage;
    public:
        void enter();
        void display();
   };
    void CPU::enter()
    {
        getchar();
        char a;
        a=getchar();
        switch (a-48)
        {
        case 1:
            rank=P1;
            break;
        case 2:
            rank=P2;
            break;
        case 3:
            rank=P3;
            break;
        case 4:
            rank=P4;
            break;
        case 5:
            rank=P5;
            break;
        case 6:
            rank=P6;
            break;
        case 7:
            rank=P7;
            break;
        default:
            break;
        }
        cin>>frequency>>voltage;
    }
    void CPU::display()
    {
        cout<<"rank:"<<rank<<" frequency:"<<frequency<<" voltage:"<<voltage<<endl;
    }
int main()
{
    CPU cpu;
    cpu.enter();
    cpu.display();
}