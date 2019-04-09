#include<iostream>
#include<stack>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;

int calculate(int a,int b,char c)
{
    int out=0;
    if(c=='^')
    {
        out=1;
        for(int i=1;i<=b;i++)
        {
            out=out*a;
        }
        return out;
    }
    if(c=='+')
    {
        return a+b;
    }
    if(c=='-')
    {
        return a-b;
    }
    if(c=='%')
    {
        return a-(a/b)*b;
    }
    if(c=='*')
    {
        return a*b;
    }
}


int main()
{
    stack<char> stachar;
    stack<int>  staint;
    string input;
    string output;
    map<char,int>inside,outside;
    inside['=']=0;outside['=']=0;
    inside['(']=1;outside['(']=8;
    inside['^']=7;outside['^']=6;
    inside['*']=5;outside['*']=4;
    inside['/']=5;outside['/']=4;
    inside['%']=5;outside['%']=5;
    inside['+']=3;outside['+']=2;
    inside['-']=3;outside['-']=2;
    inside[')']=8;outside[')']=1;
    while(1)
    {
        //stachar.clear()
        //清空栈
        while(stachar.size())
        {
        	stachar.pop();
		}
        stachar.push('=');
        int j=0;
        getline(cin,input);
        //输入0结束
        if(input[0]=='0')
        {
            break;
        } 
        int n=input.length();
        //检查输入是否合法
        bool first=false;//检查括号
        bool end=false;
       for(int i=0;i<n;i++)
       {
           bool first=false;
           bool end=false;
           if(map.count(input[i])==0)
           {
               cout<<"运算符输入不合法！"endl;
               continue;
           }
           if(!(map.count(input[i])==0&&input[i]>='0'&&input<='9'))
           {
               cout<<"输入不合法！"endl;
               continue;
           }
           if(input[i]=='/'&&input[i+1]=='0')
           {
               cout << "除数不能为零！"<<endl;
               continue;
           }
           if(input[i]=='(')
           {
               first=true;
           }
           if(input[i]==')')
           {
               end=true;
           }
       }
       if(first!=end)
       {
           cout<<"括号不匹配！"<<endl;
           continue;
       }
        input[n]='=';
        int i=0;
        //for(int i=0;i<n+1;i++)
        while(1)
        {
            if(stachar.size()==0||staint.size()==0)
            {
                	break;
			}
        	//cout << input[i];
            while(!map.count(input[i]))
            {
                int a =0;
                a=a*10+input[i]-'0';
                i++;
                //cout << output[j];
            }
            staint.push(a);
            while(1)
            {
                if(stachar.size()==0||staint.size()==0)
                {
                	break;
				}
                if(inside[stachar.top()]<outside[input[i]])
                {
                    stachar.push(input[i]);
                    break;
                }
                else if(inside[stachar.top()]>outside[input[i]])
                {
                    int a,b;
                    char c;
                    b=staint.pop();
                    a=staint.pop();
                    staint.push(calculate(a,b,c));
                }        
                else 
                {
                    stachar.pop();
                    break;
				}
            }
        }
        int output=staint.pop();
        cout <<output<<endl;
        //不能直接输出string，转换为char*
        //printf("%s\n",output.c_str());
    }
}
