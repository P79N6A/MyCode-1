#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;


vector<string> vec;
map<char,string> ma;
char *output;


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
/*   getnum(string s)
{
    int n = s.length();
    int out=0;
    for(int i=0;i<n;i++)
    {
        out = out *10 + s[i]-'0';
    }
    return out;
}*/
void find_out_put ()
{
    int j=0;
    int n =vec.size();
    output[0]='N';
   /* for(vector<string>::iterator it=vec.begin();it!=vec.end();it++)
	{
		cout << *it<<" ";
	}
	for(map<char,string>::iterator it=ma.begin();it!=ma.end();it++)
	{
		cout << it->first<<" "<<it->second.c_str()<<" ";
	}*/
    for(int i=1;i<n;i++)//第一个字符串是ls
    {
        if(vec[i][0]=='-'&&(vec[i][1]>='a')&&(vec[i][1]<='z'))
        {
            if(ma.count((char)vec[i][1]))
            {
                if(ma[vec[i][1]]!="")
                {
                    ma[vec[i][1]] = vec[i+1] ;
                    i=i+1;
                }
                output[j]=vec[i][1];
                j++;
            }
        }
        else if((vec[i][0]>='0')&&(vec[i][0]<='9'))
		{
			i++;
		} 
        else 
		{
			break;
		} 
    }
}

int main ()
{ 
    string str1;
    int N,i;
    int count =1;
    getline(cin,str1);
    cin >> N;
    char s[N][256];
    //将可选选项存储起来
    for(i=0;i<str1.length();i++)
    {
        if(str1[i+1]==':')
        {
            ma[str1[i]]="havenum";
            i=i+1;
        }
        else 
        {
            ma[str1[i]]="";
        }
    }
    getchar();
    for(int i=0;i<N;i++)
    {
    	cin.getline(s[i],256,'\n');
    	//scanf("%s",&s[i]);
	} 
    for(int j=0;j<N;j++)
    {
        int n;
        n=strlen(s[j]);
        split(s[j]);
        if(output[0]=='N')
        {
        	vec.clear();
         	cout << "Case "<<count<<':'<<' ';
        	count++;
        	printf("\n");
        	continue;
		}
        sort(output,output+strlen(output));
        cout << "Case "<<count<<':'<<' ';
        count++;
        int m = strlen(output);
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
        vec.clear();
        printf("\n");
    } 
}
