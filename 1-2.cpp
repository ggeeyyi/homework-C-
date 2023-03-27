#include <iostream>
using namespace std;
struct Chess   //记录落子坐标的结构体
{
    int chessLocationX;
    int chessLocationY;
};
class ChessBoard
{
    public:
        void show();  //打印棋子坐标
        Chess chess[100];  //棋盘已有棋子的坐标
};
class player
{
    private:
        char name;
        int chesstype;
    public:
        void setchess();
        Chess chesslocation[100];  //记录所有落子的坐标
};
void ChessBoard::show()
{
    cout<<"chessLocationX:"<<chess->chessLocationX<<" "<<"chessLocationY:"<<chess->chessLocationY<<endl;  //打印
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
int main()
{
    ChessBoard mychessBoard;
    player player1;
    player1.setchess();
    mychessBoard.chess->chessLocationX=player1.chesslocation->chessLocationX;
    mychessBoard.chess->chessLocationY=player1.chesslocation->chessLocationY;
    mychessBoard.show();
    return 0;
}