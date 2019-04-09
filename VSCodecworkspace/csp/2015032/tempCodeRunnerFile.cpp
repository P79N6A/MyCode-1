#include<iostream>
#include<utility>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.second>b.second)
    {
        return true;
    }
    else if(a.second<b.second)
    {
        return false;
    }
    else if(a.second=b.second)
    {
        if(a.first>b.first)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
}
int main ()
{
    pair<int,int>a[1000];
    int b[1000];
    int n,m;
    cin >> n;
    int i,j=0;
    for(i=0;i<n;i++)
    {
        cin >>m;
        b[m]++;
    }
    for(i=0;i<n;i++)
    {
        if(b[i]!=0)
        {
            a[j].first=i;
            a[j].second=b[i];
        }
    }
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
    {
        cout << a[i].first<<" "<<a[i].second<<endl;
    }
    system("pasue");
    return 0;
}