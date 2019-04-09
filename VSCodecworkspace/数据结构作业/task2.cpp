#include<iostream>
#include<stack>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    stack<char> stachar;
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
        input[n]='=';
        for(int i=0;i<n+1;i++)
        {
        	//cout << input[i];
            if(input[i]>='0'&&input[i]<='9')
            {
                output[j]=input[i];
                //cout << output[j];
                j++;
            }
            else 
            {
                while(1)
                {
                	if(stachar.size()==0)
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
                        output[j]=stachar.top();
                        //cout << output[j];
                        j++;
                        stachar.pop();
                    }
                    else 
                    {
                    	stachar.pop();
                    	break;
					}
                }
                
            }
        }
        //不能直接输出string，转换为char*
        printf("%s\n",output.c_str());
    }
}


//中缀表达式求值
while(1)
        {
            if(stachar.size()==0||staint.size()==0)
            {
                	break;
			}
        	//cout << input[i];
			int a =0;
            while(!inside.count(input[i]))
            {
                
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
                    b=staint.top();
                    staint.pop();
                    a=staint.top();
                    staint.pop();
                    staint.push(calculate(a,b,c));
                }        
                else 
                {
                    stachar.pop();
                    break;
				}
            }
        }
        int outputint=staint.top();
        cout <<outputint<<endl;
    }