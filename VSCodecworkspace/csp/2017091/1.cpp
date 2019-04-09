#include<iostream>
using namespace std;
int num(int b)
{
    int c;
    if(b<3)
    {
        return b;
    }
    else if(b>=3&&b<5)
    {
        return (b+1);
    }
    else
    {
        c=b/5*2+b-b%5;//ÔùËÍµÄ½´ÓÍÊıÄ¿
        b=b%5;
        return (c+num(b));
    }
}
int main ()
{
    int a;
    cin >> a ;
    int b=a/10;
    cout <<num(b);
    return 0;
}
