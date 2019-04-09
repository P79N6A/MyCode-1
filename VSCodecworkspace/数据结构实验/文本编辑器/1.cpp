#include<iostream>
#include<fstream>
using namespace std;
struct node
{
    node *right;
    node *left;
    string str;
    node()
    {
        right=NULL;
        left=NULL;
    }
};
void read()
{
    string input;
    cout << "请输入操作文件名"<<endl;
    cin >> input;
    
}
void write(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        
    }
}
int main()
{
    node *head=new node;
    
    return 0;
}