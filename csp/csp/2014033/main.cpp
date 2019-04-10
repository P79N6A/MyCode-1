#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;


vector<string> vec;
map<char,string> ma;
char output[256];


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
int find_out_put ()
{
    int j=0;
    int i;
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
    for(i=1;i<n;i++)//µÚÒ»¸ö×Ö·û´®ÊÇls
    {
        if(vec[i][0]=='-'&&(ma.count((char)vec[i][1])))
        {
            output[j]=vec[i][1];
            //cout << vec[i][1]<<" ";
            j++;
            if(ma[vec[i][1]]!="")
            {
                ma[vec[i][1]] = vec[i+1] ;
                i=i+1;
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
    return j;
}

int main ()
{
    string str1;
    int N,i;
    int count =1;
    getline(cin,str1);
    cin >> N;
    char s[N][256];


    //map的初始化，方便快速查找
    for(i=0;i<(int)str1.length();i++)
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

    //单行读取
    for(int i=0;i<N;i++)
    {
    	cin.getline(s[i],256,'\n');
    	//scanf("%s",&s[i]);
	}

	//逐行处理
    for(int j=0;j<N;j++)
    {
        int n;
        split(s[j]);
        n=find_out_put();
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
        char out='N';//避免重复输出
        //cout <<n;
        for(int i=0;i<n;i++)
        {
            if(output[i]!=out)
            {
                out = output[i];
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

        }
        vec.clear();
        printf("\n");
    }
}
