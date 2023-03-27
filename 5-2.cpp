#include <iostream>
#include <assert.h>
using namespace std;
class Matrix
{
    double *data;
    int row;
    int col;
    public:
        Matrix();
        Matrix(double *pData,int r,int c);
        ~Matrix();
        double & operator()(int r,int c);
};
Matrix::Matrix()
{
    data=NULL;
    row =0;
    col =0;
}
Matrix::Matrix(double *pData,int r,int c)
{
    data=pData;
    row=r;
    col=c;
}
Matrix::~Matrix()
{
    delete []data;
}
double & Matrix::operator()(int r,int c)
{
    assert(r>=0&&r<row&&c>=0&&c<col);
    return data[col*r+c];
}
int main()
{
    double *pData=new double[9];
    int row=2;
    int col=2;
    Matrix m(pData,row,col);
    int cnt=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            m(i,j)=cnt++;
            cout<<m(i,j)<<' ';
        }
        cout<<endl;
    }
    return 0;
}