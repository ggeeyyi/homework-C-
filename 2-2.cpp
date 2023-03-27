#include <iostream>
#include <string.h>
using namespace std;
struct Chess   //��¼��������Ľṹ��
{
    int chessLocationX;
    int chessLocationY;
};
class Chessboard
{
    public:
        void show();  //��ӡ��������
        Chess chess[100];  //�����������ӵ�����
        void init(int inputLength,int inputWidth);
        int Width;
        int Length;
        int nowchessboard[100][100];
    //private:
};
class player
{
    public:
        char name[20];
        int chesstype;
        void setchess();
        Chess chesslocation[100];  //��¼�������ӵ�����
        void init(char inputName[]);
    public:
        static int count;
};

int player::count=0;

void Chessboard::show()
{
    cout<<"chessLocationX:"<<chess->chessLocationX<<" "<<"chessLocationY:"<<chess->chessLocationY<<endl;  //��ӡ
}
void Chessboard::init(int inputLength,int inputWidth)
{
    Width=inputWidth;
    Length=inputLength;
}
void player::setchess()
{
    int setlocationX;
    int setlocationY;
    cout<<"setlocationX:";
    cin>>setlocationX;
    cout<<"setlocationY:";
    cin>>setlocationY;
    chesslocation->chessLocationX=setlocationX;
    chesslocation->chessLocationY=setlocationY;

}
void player::init(char *inputName)
{
    strcpy(name,inputName);
}
int flag;

int main()
{
    Chessboard myChessboard;
    player player1,player2;
    int tempWidth,tempLength;
    void judge(int p[][100],int l,int w);
    void print(int p[][100],int l,int w);
    char tempName[20];

    cout<<"������̵ĳ��Ϳ���г�ʼ��"<<endl;
    cout<<"����";
    cin>>tempLength;
    cout<<"��";
    cin>>tempWidth;
    myChessboard.init(tempLength,tempWidth);
    cout<<"�������������г�ʼ��: "<<"���1:"<<endl;
    cin>>tempName;
    player1.init(tempName);
    cout<<"�������������г�ʼ��: "<<"���2:"<<endl;
    cin>>tempName;
    player2.init(tempName);
    while(true)
    {
    flag=0;
    cout<<"������"<<player1.name<<"����"<<endl;
    player1.setchess();
    while(player1.chesslocation->chessLocationX>=myChessboard.Width||player1.chesslocation->chessLocationY>=myChessboard.Length||myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]!=0)
    {
        if (player1.chesslocation->chessLocationX>=myChessboard.Width||player1.chesslocation->chessLocationY>=myChessboard.Length)
        {
            cout<<"������������Ѿ����������̱߽磡"<<endl;
        }
        if(myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]!=0)
        {
            cout<<"���������Ѿ����ӵ�λ�÷������ӣ�"<<endl;
        }
        player1.setchess();
    }
    myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]--;
    myChessboard.show();
    judge(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    print(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    player::count++;
    if(flag==1)
    {
        cout<<player1.name<<"ʤ��"<<endl;
        break;
    }
    

    cout<<"������"<<player2.name<<"����"<<endl;
    player2.setchess();
    while(player2.chesslocation->chessLocationX>=myChessboard.Width||player2.chesslocation->chessLocationY>=myChessboard.Length||myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]!=0)
    {
        if (player2.chesslocation->chessLocationX>=myChessboard.Width||player2.chesslocation->chessLocationY>=myChessboard.Length)
        {
            cout<<"������������Ѿ����������̱߽磡"<<endl;
        }
        if(myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]!=0)
        {
            cout<<"���������Ѿ����ӵ�λ�÷������ӣ�"<<endl;
        }
        player2.setchess();
    } 
    myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]++;
    myChessboard.show();
    judge(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    print(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    player::count++;
    if(flag==1)
        {
            cout<<player2.name<<"ʤ����"<<endl;
            break;
        }
    }
    cout<<"��Ϸ����,һ������"<<player::count<<"����"<<endl;
    return 0;
}
void judge(int p[][100],int l,int w)
{
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(p[i][j]==1&&p[i][j]==p[i+1][j]&&p[i][j]==p[i+2][j]&&p[i][j]==p[i+3][j]&&p[i][j]==p[i+4][j]) flag=1; 
            if(p[i][j]==-1&&p[i][j]==p[i+1][j]&&p[i][j]==p[i+2][j]&&p[i][j]==p[i+3][j]&&p[i][j]==p[i+4][j]) flag=1; 
            if(p[i][j]==1&&p[i][j]==p[i][j+1]&&p[i][j]==p[i][j+2]&&p[i][j]==p[i][j+3]&&p[i][j]==p[i][j+4]) flag=1; 
            if(p[i][j]==-1&&p[i][j]==p[i][j+1]&&p[i][j]==p[i][j+2]&&p[i][j]==p[i][j+3]&&p[i][j]==p[i][j+4]) flag=1;
            if(p[i][j]==1&&p[i][j]==p[i+1][j+1]&&p[i][j]==p[i+2][j+2]&&p[i][j]==p[i+3][j+3]&&p[i][j]==p[i+4][j+4]) flag=1;
            if(p[i][j]==-1&&p[i][j]==p[i+1][j+1]&&p[i][j]==p[i+2][j+2]&&p[i][j]==p[i+3][j+3]&&p[i][j]==p[i+4][j+4]) flag=1;
            if(p[i][j]==1&&p[i][j]==p[i-1][j+1]&&p[i][j]==p[i-2][j+2]&&p[i][j]==p[i-3][j+3]&&p[i][j]==p[i-4][j+4]) flag=1;
            if(p[i][j]==-1&&p[i][j]==p[i-1][j+1]&&p[i][j]==p[i-2][j+2]&&p[i][j]==p[i-3][j+3]&&p[i][j]==p[i-4][j+4]) flag=1;
        }
    }
}
void print(int p[][100],int l,int w)
{
    cout<<"  ";
    for(int i=0;i<l;i++)
    {
        if(i<=10)
            cout<<" "<<i;
        else
            cout<<i;
    }
    cout<<endl;
    for(int i=1;i<=2*l+1;i++)
    {
        if(i%2==1)
            {
                cout<<"  ";
                for(int j=0;j<2*w;j++)
                {
                    cout<<"-";
                }
            }
        if(i%2==0)
        {
            if(i/2-1<=9)
                cout<<" "<<i/2-1;  
            else
                cout<<i/2-1;  
        for(int j=0;j<=2*w+1;j++)
        {
            if(j%2==1)
            {
                cout<<"|";
            }
            if(j%2==0&&j>=2)
            {
                if(p[i/2-1][j/2-1]==0)
                    cout<<" ";
                if(p[i/2-1][j/2-1]==1)
                    cout<<"��";
                if(p[i/2-1][j/2-1]==-1)
                    cout<<"��";
            }
        }
        }
        cout<<" "<<endl;
    }
}