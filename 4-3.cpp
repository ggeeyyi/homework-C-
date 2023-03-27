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

struct Chess   //记录落子坐标的结构体
{
    int chessLocationX;
    int chessLocationY;
};
class Chessboard
{
    public:
        void show();  //打印棋子坐标
        Chess chess[100];  //棋盘已有棋子的坐标
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
        Chess chesslocation[100];  //记录所有落子的坐标
        void init(char inputName[]);
    public:
        static int count;
};

int player::count=0;

void Chessboard::show()
{
    cout<<"chessLocationX:"<<chess->chessLocationX<<" "<<"chessLocationY:"<<chess->chessLocationY<<endl;  //打印
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

    cout<<"请对棋盘的长和宽进行初始化"<<endl;
    cout<<"长：";
    cin>>tempLength;
    cout<<"宽：";
    cin>>tempWidth;
    myChessboard.init(tempLength,tempWidth);
    cout<<"请对玩家姓名进行初始化: "<<"玩家1:"<<endl;
    cin>>tempName;
    Strings player_1(tempName);
    player1.init(tempName);
    cout<<"请对玩家姓名进行初始化: "<<"玩家2:"<<endl;
    cin>>tempName;
    Strings player_2(tempName);
    player2.init(tempName);
    if(player_1>player_2)
    {
    while(true)
    {
    cout<<"本次棋局"<<player1.name<<"先手!"<<endl;
    flag=0;
    cout<<"现在是"<<player1.name<<"落子"<<endl;
    player1.setchess();
    while(player1.chesslocation->chessLocationX>=myChessboard.Width||player1.chesslocation->chessLocationY>=myChessboard.Length||myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]!=0)
    {
        if (player1.chesslocation->chessLocationX>=myChessboard.Width||player1.chesslocation->chessLocationY>=myChessboard.Length)
        {
            cout<<"您输入的坐标已经超过了棋盘边界！"<<endl;
        }
        if(myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]!=0)
        {
            cout<<"您不能在已经落子的位置放置棋子！"<<endl;
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
        cout<<player1.name<<"胜利"<<endl;
        break;
    }
    cout<<"现在是"<<player2.name<<"落子"<<endl;
    player2.setchess();
    while(player2.chesslocation->chessLocationX>=myChessboard.Width||player2.chesslocation->chessLocationY>=myChessboard.Length||myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]!=0)
    {
        if (player2.chesslocation->chessLocationX>=myChessboard.Width||player2.chesslocation->chessLocationY>=myChessboard.Length)
        {
            cout<<"您输入的坐标已经超过了棋盘边界！"<<endl;
        }
        if(myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]!=0)
        {
            cout<<"您不能在已经落子的位置放置棋子！"<<endl;
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
            cout<<player2.name<<"胜利！"<<endl;
            break;
        }
    }
    cout<<"游戏结束,一共下了"<<player::count<<"步！"<<endl;
    }

    else
    {
    while(true)
    {
    cout<<"本次棋局"<<player2.name<<"先手!"<<endl;
    flag=0;
    cout<<"现在是"<<player2.name<<"落子"<<endl;
    player2.setchess();
    while(player2.chesslocation->chessLocationX>=myChessboard.Width||player2.chesslocation->chessLocationY>=myChessboard.Length||myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]!=0)
    {
        if (player2.chesslocation->chessLocationX>=myChessboard.Width||player2.chesslocation->chessLocationY>=myChessboard.Length)
        {
            cout<<"您输入的坐标已经超过了棋盘边界！"<<endl;
        }
        if(myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]!=0)
        {
            cout<<"您不能在已经落子的位置放置棋子！"<<endl;
        }
        player2.setchess();
    }
    myChessboard.nowchessboard[player2.chesslocation->chessLocationX][player2.chesslocation->chessLocationY]--;
    myChessboard.show();
    judge(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    print(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    player::count++;
    if(flag==1)
    {
        cout<<player2.name<<"胜利"<<endl;
        break;
    }

    cout<<"现在是"<<player1.name<<"落子"<<endl;
    player1.setchess();
    while(player1.chesslocation->chessLocationX>=myChessboard.Width||player1.chesslocation->chessLocationY>=myChessboard.Length||myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]!=0)
    {
        if (player1.chesslocation->chessLocationX>=myChessboard.Width||player1.chesslocation->chessLocationY>=myChessboard.Length)
        {
            cout<<"您输入的坐标已经超过了棋盘边界！"<<endl;
        }
        if(myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]!=0)
        {
            cout<<"您不能在已经落子的位置放置棋子！"<<endl;
        }
        player1.setchess();
    } 
    myChessboard.nowchessboard[player1.chesslocation->chessLocationX][player1.chesslocation->chessLocationY]++;
    myChessboard.show();
    judge(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    print(myChessboard.nowchessboard,myChessboard.Length,myChessboard.Width);
    player::count++;
    if(flag==1)
        {
            cout<<player1.name<<"胜利！"<<endl;
            break;
        }
        cout<<"游戏结束,一共下了"<<player::count<<"步！"<<endl;
    }
    }
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
    for(int i=0;i<w;i++)
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
                    cout<<"●";
                if(p[i/2-1][j/2-1]==-1)
                    cout<<"○";
            }
        }
        }
        cout<<" "<<endl;
    }
}