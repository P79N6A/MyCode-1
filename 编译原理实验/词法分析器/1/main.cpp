#include <iostream>
#include <cstring>
#include <fstream>
#define key_length 20 //关键字数组的长度
using namespace std;
string prog,token_key_word;
string token_varible;
string token;
string token_num;
string key_word[key_length]={"if","while","else","void","int","double","main","define","include","float","iostream","cin","cout" ,"string","return"};

void outtofile(string &prog,string &token)
{
    ofstream outfile("output.txt");
    for(int i =0;i<(int)prog.length();i++)
    {
        outfile << prog[i];
    }
    outfile << "\n";
    for(int i=0;i<(int)token.length();i++)
    {
        outfile << token[i];
    }
    outfile << "\n";
    outfile.close();
}
//寻找关键字
int is_found(string &s)
{
    for(int i=0;i<key_length;i++)
    {
        if(s==key_word[i])
        {
            return i;
        }
    }
    return -1;
}
//添加注释到token
void scan_zhushi(string &prog,int n)
{
    string output;
    int j=0;
    for(int i=n;i<(int)prog.length();i++)
    {
        if(prog[i++]=='*'||prog[i++]=='/')
        {
            continue;
        }
        output[j++] = prog[i++];
    }
    token = token + output;
    token = token + "\0";
}

void scaner()
{
    ifstream infile("input.txt");
    int i=1;
    char ch = prog[0];
    string temp="";
    token="";
    while(i<=(int)prog.length())
    {
        if(ch == ' '||ch=='\t')
        {
            ch = prog[i++];
        }
        if((ch >='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            while((ch>='0'&&ch<='9')||(ch >='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
            {
                temp = temp + ch;
                ch = prog[i++];
            }
            if(is_found(temp)!=-1)
            {
                token_key_word = token_key_word + temp +'\0';
                temp = "";
            }
            else
            {
                token_varible =token_varible + temp +'\0';
                temp = "";
            }

        }
        else if((ch>='0'&&ch<='9'))
        {
            while((ch>='0'&&ch<='9'))
            {
                token_num = token_num + ch;
                ch =prog[i++];
            }
            token_num = token_num + '\0';
        }
        else
        {
            switch(ch)
            {
                case '<':
                    token = token + ch;
                    ch = prog[i++];
                    if(ch =='=')
                    {
                        token = token +ch;
                        ch = prog[i++];
                    }
                    else if(ch =='>')
                    {
                        token = token + ch;
                        ch = prog[i++];
                    }
                    else if(ch =='<')
                    {
                        token = token + ch;
                        ch = prog[i++];
                    }
                    token = token + '\0';
                    break;
                case '>' :
                    token = token + ch;
                    ch = prog[i++];
                    if(ch =='=')
                    {
                        token = token +ch;
                        ch = prog[i++];
                    }
                    else if(ch =='<')
                    {
                        token = token + ch;
                        ch = prog[i++];
                    }
                    else if(ch=='>')
                    {
                        token = token + ch;
                        ch = prog[i++];
                    }
                    token = token + '\0';
                    break;
                case '|':
                    token = token + ch;
                    ch = prog[i++];
                    if(ch == '|')
                    {
                        token = token + ch;
                        ch = prog[i++];
                    }
                    token = token +'\0';
                    break;
                case '&':
                    token = token + ch;
                    ch = prog[i++];
                    if(ch == '&')
                    {
                        token = token + ch;
                        ch = prog[i++];
                    }
                    token = token +'\0';
                    break;
                case '=':
                    token = token + ch;
                    ch = prog[i++];
                    if(ch == '=')
                    {
                        token = token + ch;
                        ch = prog[i++];
                    }
                    token = token +'\0';
                    break;
                case '+':token = token +ch;
                        ch =prog[i++];
                        if(ch =='+')
                        {
                            token = token + ch;
                            ch = prog[i++];
                        }
                        token = token + '\0';
                        break;
                case '-':token = token +ch;
                        ch =prog[i++];
                        if(ch =='-')
                        {
                            token = token + ch;
                            ch = prog[i++];
                        }
                        token = token + '\0';
                        break;
                case '(':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case ')':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case ';':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case '#':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case '[':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case ']':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                 case '"':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case '\\':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case '/': token = token + ch;
                            ch = prog[i++];
                            if(ch == '*')
                            {
                                token = token + ch;
                                scan_zhushi(prog,i);
                                ch = prog[i++];
                            }
                            break;
                case '\n':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case '}':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
                case '{':token =token + ch;
                            ch = prog[i++];
                            token =token + '\0';
                            break;
            }
        }
    }
}

int main()
{
    ifstream infile("input.txt");
    token = "";
    int i=1;
    while(getline(infile,prog))
    {
        token ="";
        token_key_word = "";
        token_num = "";
        token_varible = "";
        scaner();
        cout << "第 "<<i<<" 行"<<": ";
        i++;
        cout <<prog<<endl;
        cout << "符号 : ";
        cout <<token;
        cout <<"          ";
        cout << "立即数 ："<< token_num;
        cout << endl;
        cout <<"变量 ：" << token_varible;
        cout <<"          ";
        cout <<"关键字 ："<< token_key_word;
        cout <<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
