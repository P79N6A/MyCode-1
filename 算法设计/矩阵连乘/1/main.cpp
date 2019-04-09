#include <iostream>

using namespace std;
void  matrixchain(int**m,int **s,int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        m[i][i]=0;
    }
    for(int r=2;r<n;r++)
    {
        for(int i=0;i<n-r+1;i++)
        {
            int j= i+r-1;
            m[i][j] = m[i+1][j] + p[i][i+1][j+1];
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int t = m[i][k] + m[k+1][j] +p[i]*p[k+1]*p[j+1];
                if(t<m[i][j])
                {
                    m[i][j] = t;
                }
            }
        }
    }
}
int main()
{
   int p[]={30,35,15,5,10,20,25};
   int m[6][6];
   int s[6][6];
   matrixchain(m,s,p,7);
   cout <<m[0][5];
   // cout << "Hello world!" << endl;
    return 0;
}
