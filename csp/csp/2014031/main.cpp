#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N=500;
int num[N];
int main()
{
    int n,i;
    cin >> n;
    int x,counted=0;
    memset(num,0,sizeof(num));
    for(i=0;i<n;i++)
    {
        cin >> x;
        if(x>=0)
        {
            num[x]++;
        }
        else
        {
            num[-x]++;
        }
        if(num[abs(x)]>1)
        {
            counted++;
        }
    }
    cout <<counted;
    return 0;
}
