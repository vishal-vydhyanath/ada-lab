#include<bits/stdc++.h>
using namespace std;
int tile=1;
int board[20][20];
void chessboard(int trow, int tcol, int drow, int dcol,int size)
{
    if(size==1)
        return;
    int qsize=size/2;
    int tileToUse=tile++;
    if(drow<=trow+qsize-1 && dcol<=tcol+qsize-1)
    {
        chessboard(trow,tcol,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize-1][tcol+qsize-1]=tileToUse;
        chessboard(trow,tcol,trow+qsize-1,tcol+qsize-1,qsize);
    }
    if(drow<=trow+qsize-1 && dcol>=tcol+qsize)
    {
        chessboard(trow,tcol+qsize,drow,dcol,qsize);
    }
     else
    {
        board[trow+qsize-1][tcol+qsize]=tileToUse;
        chessboard(trow,tcol+qsize,trow+qsize-1,tcol+qsize,qsize);
    }
    if(drow>=trow+qsize && dcol<=tcol+qsize-1)
    {
        chessboard(trow+qsize,tcol,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize][tcol+qsize-1]=tileToUse;
        chessboard(trow+qsize,tcol,trow+qsize,tcol+qsize-1,qsize);
    }
    if(drow>=trow+qsize && dcol>=tcol+qsize)
    {
        chessboard(trow+qsize,tcol+qsize,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize][tcol+qsize]=tileToUse;
        chessboard(trow+qsize,tcol+qsize,trow+qsize,tcol+qsize,qsize);
    }
}

int main()
{
    int n,drow,dcol,i,j;
    cout<<"Enter the size\n";
    cin>>n;
    cout<<"Enter the defective row and coloumn\n";
    chessboard(0,0,drow,dcol,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}