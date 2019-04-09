#include<iostream>
using namespace std;
int main()
{
    int n,m;
    int i,j;
    int input[n][m];
    int output[m][n];
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> input[i][j];
        }
    }
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            output[m-j-1][i]=input[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout << output[i][j];
        }
    }
return 0;
}