#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define maxn 500

double x[maxn];
double y[maxn];

int input()
{
    ifstream infile("input.txt");
    if(!infile)
    {
        cout << "data can not be opened"<<endl;
        return -1;
    }
    string linex;
    string liney;
    int j=0;
    int i;
	string x0;
	int p=0;
    getline(infile,linex);
    for(i=0;i<linex.length();i++)
    {  
        if(linex[i]!=',')
        {
            x0[p]=linex[i];
            p++;
        }
        else 
        {
            x[j]=atof(x0.c_str());
            j++;
            p=0;
        }
    }
    j=0;
    getline(infile,liney);
    for(i=0;i<liney.length();i++)
    {  
        if(liney[i]!=',')
        {
            x0[p]=liney[i];
            p++;
        }
        else 
        {
            y[j]=atof(x0.c_str());
            j++;
            p=0;
        }
    }
    infile.close();
    return j;
}


int main()
{
    double w1;
    double w0;
    long long a=0;
    long long b=0;
    double averx=0;
    double avery=0;
    int n=input();
    for(int i=0;i<n;i++)
    {
        a+=x[i]*y[i];
        b+=x[i]*x[i];
        averx+=x[i]/n;
        avery+=y[i]/n;
    }
    w1=(a-n*averx*avery)/(b-n*averx*averx);
    w0=avery-w1*averx;
    cout << w1<<endl<<w0;
    return 0;
}
