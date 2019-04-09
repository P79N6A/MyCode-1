#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
vector<string> vec;
map<char,string> ma;
void split(char s[])
{
    char *sp;
    char char1[1];
    char1[0]=' ';
    sp = strtok(s,char1);
    while(sp)
    {
        vec.push_back(sp);
        sp = strtok(NULL,char1);
    }
}
   getnum(string s)
{
    int n = s.length();
    int out=0;
    for(int i=0;i<n;i++)
    {
        out = out *10 + s[i]-'0';
    }
    return out;
}
 char *find_out_put ()
{
    char *s;
    int j=0;
    int n =vec.size();
    for(int i=1;i<n;i++)//µÚÒ»¸ö×Ö·û´®ÊÇls
    {
        if(vec[i][0]=='-'&&(vec[i][1]>='a')&&(vec[i][1]<='z'))
        {
            if(ma.count(vec[i][1]))
            {
                if(ma[vec[i][1]]!="")
                {
                    ma[vec[i][1]] = vec[i+1] ;
                    i=i+1;
                }
                s[j]=vec[i][2];
                j++;
            }
        }
    }
    return s;
}

int main ()
{ 
    string str1;
    string str2;
    int N;
    getline(cin,str1);
    cin >> N;
    char s[N][256];
    //½«¿ÉÑ¡Ñ¡Ïî´æ´¢ÆðÀ´
    for(int i=0;i<str1.length();i++)
    {
        if(str1[i+1]==':')
        {
            ma[str1[i]]=':';
            i=i+1;
        }
        else 
        {
            ma[str1[i]]="";
        }
    }
    for(int i=0;i<N;i++)
    {
        int n;
        int count =1;
        cout << "Case "<<count<<':'<<' ';
        scanf("%s",&s[i]);
        n=strlen(s[i]);
        split(s[i]);
        char *output = find_out_put();
        sort(output,output+strlen(output));
        for(int i=0;i<strlen(output);i++)
        {
            if(ma[output[i]]!="")
            {
                cout << '-'<<output[i]<<' ';
                cout << ma[output[i]]<<' ';
            }
            else 
            {
                cout << '-'<<output[i]<<' ';
            }
        }
        cout <<endl;
        
    } 
}