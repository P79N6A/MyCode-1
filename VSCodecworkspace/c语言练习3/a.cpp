#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    int a[6]={100,50,10,5,2,1};
    int b[N];
    int count;
    while(1)
    {
        count=0;
        cin >> N;
        if(N==0)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            cin >> b[i];
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(b[i]<=0)
                {
                    break;
                }
                if(b[i]/a[j]>0)
                {
                    b[i]=b[i]%a[j];
                    count+=b[i]/a[j];
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
