#include <iostream>


using namespace std;
void merge(int a[],int b[],int l,int m,int r )
{
    int i=l;
    int j=m+1;
    int k=1;
    while((i<=m)&&(j<=r))
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>m)
    {
        for(int q=j;q<=r;q++)
        {
            b[k]=a[q];
            k++;
        }
    }
    else if(j>r)
    {
        for(int q=r;q<=m;q++)
        {
            b[k]=a[q];
            k++;
        }
    }

}
void mergepass(int a[],int b[],int s,int n)
{
    int i=0;
    while (i<=n-2*s)
    {
        merge(a,b,i,i+s-1,i+2*s-1)
        i=i+2*s;
    }
    if(i+s<n)
    {
        merge(a,b,i,i+s-1,n-1);
    }
    else
    {
        for(int j=i;j<n;j++)
        {
            b[j]=a[j];
        }
    }
}
void mergesort(int a[],int n)
{
    int *b= new int [n];
    int s=1;
    while(s<n)
    {
        mergepass(a,b,s,n);
        s=s+s;
        mergepass(b,a,s,n);
        s=s+s;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
