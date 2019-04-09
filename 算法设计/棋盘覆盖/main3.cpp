#include <iostream>

using namespace std;
 static int title =1;
static int Board[8][8]={0};
void chessboard(int tr,int tc,int dr,int dc,int size)
{
    if(size==1)
    {
       return ;
    }
   int t= title++;
   int  s = size/2;
    //×óÉÏ½ÇÆåÅÌ
    if(tr+s>dr&&tc+s>dc)
    {

         chessboard(tr,tc,dr,dc,s);
    }
    else
    {
       Board[tr+s-1][tc+s-1]=t;
        chessboard(tr,tc,tr+s-1,tc+s-1,s);
    }
    //ÓÒÉÏ½ÇÆåÅÌ
    if(tr+s>dr&&tc+s<=dc)
    {
        chessboard(tr,tc+s,dr,dc,s);
    }
    else
    {
        Board[tr+s-1][tc+s]=t;
        chessboard(tr,tc+s,tr+s-1,tc+s,s);
    }
    //×óÏÂ½ÇÆåÅÌ
    if(tr+s<=dr&&tc+s>dc)
    {
        chessboard(tr+s,tc,dr,dc,s);
    }
    else
    {
        Board[tr+s][tc+s-1]=t;
        chessboard(tr+s,tc,tr+s,tc+s-1,s);
    }
    //ÓÒÏÂ½ÇÆåÅÌ
    if(tr+s<=dr&&tc+s<=dc)
    {
        chessboard(tr+s,tc+s,dr,dc,s);
    }
    else
    {
        Board[tr+s][tc+s]=t;
        chessboard(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main()
{
    Board[3][4]=-1;
    chessboard(0,0,3,4,8);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout.width(3);
            cout << Board[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}
