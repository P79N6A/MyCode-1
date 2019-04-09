#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int maxcol = 60;
int maxn = 100 + 5;
string files[105];

 void printt (string &str,int len,char extra)
 {
    cout << str;
    for(int i=0;i<len-(int)str.length();i++)
    {
        cout <<extra;
    }
 }
int main()
{
    int n;
    int M=0;
    cin >> n;
    while( cin >>n)
    {

        for(int i=0;i<n;i++)
        {

            cin >>files[i];
            M = max(M,(int)files[i].length());
        }
    }
    sort(files,files+n);
    int cols = (maxcol-M)/(M+2)+1;
    int rows = (n-1)/cols+1;
    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int idx = j * rows + i;
            if(idx<n)
            {
                printt(files[idx],j==cols-1?M:M+2,' ');
            }
            cout <<"\n";
        }
    }
    ///cout << "Hello world!" << endl;
    return 0;
}
