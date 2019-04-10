#include <iostream>
#include <cstdio>
#include <cmath>
#include<cstring>
using namespace std;
struct element
{
    int zhishu;//??
    int xishu;//??
    element *next;
    element(int zhisuh=0,int xishu=0)
    {
        zhishu = zhishu;
        xishu = xishu;
        next = NULL;
    }
};
struct polylist
{
   element *head;
   element *ele;
   element *tail;
   polylist()
   {
       head = new element; 
       head->xishu = 0;
       head->zhishu = 0;
       tail = head;
   }
   void append(element *ele)
   {
       tail->next = ele;
       tail = ele;
   }
   int length()
   {
       int count =0;
       element *ele = head->next;
       while(ele!=tail)
       {
           count++;
           ele=ele->next;
       }
       count++;
       return count;
   }
    polylist operator + ( polylist &p) 
    {
        polylist lc;
        element *apos=this->head->next,*bpos=p.head->next;
        int len = min(this->length(),p.length());
        while(1)
        { 
            element *temp=new element;
            if(apos->zhishu==bpos->zhishu)
            {
                temp->xishu = apos->xishu + bpos->xishu;
				temp->zhishu= apos->zhishu;
                lc.tail->next = temp;
                lc.tail = temp;
                bpos = bpos->next;
                apos = apos->next;
            }
            else if(apos->zhishu>bpos->zhishu) 
            {
                temp = bpos;
                lc.tail->next = temp;
                lc.tail = temp;
                bpos = bpos->next;
            }
            else 
            { 
                temp = apos;
                lc.tail->next = temp;
                lc.tail = temp;
                apos = apos->next;
            }
            if(apos ==NULL&&bpos ==NULL)
            {
                break;
            } 
           
        }
        return lc;
    }
    polylist operator = (const polylist &p)
    {
        head->next= p.head->next ;
    }
};

int main()
{ 
	string char1; 
	int num[100];
    cout <<"(�밴�ա�a��b���ĸ�ʽ���룬aΪ���ϵ����bΪ���ָ�����Կո���Ϊ�ֽ�)"<<endl;
    cout << "�������һ������ʽ"<<endl;
    int zhishu,xishu;
    int i,n,j=0;
    char c;
    polylist la,lb,lc;
	getline(cin,char1);
	n = char1.length();
	//��������ַ���ת����int 
    for(i=0;i<n;i++)
    {
    	if(char1[i]>='0'&&char1[i]<='9')
		{
			num[j]=char1[i]-'0';
			j++;
		}	
    }
    for(i=0;i<j;i+=2)
    {
    	element *temp = new element;
        temp->zhishu = num[i+1];
        temp->xishu = num[i];
        la.tail->next = temp;
        la.tail = temp;
	}
    cout << "������ڶ�������ʽ";//<<endl;
    //getchar();
    getline(cin,char1);
	n = char1.length();
    j=0;
    for(i=0;i<n;i++)
    {
    	if(char1[i]>='0'&&char1[i]<='9')
		{
			num[j]=char1[i]-'0';
			j++;
		}	
    }
    for(i=0;i<j;i+=2)
    {
    	element *temp = new element;
        temp->zhishu = num[i+1];
        temp->xishu = num[i];
        lb.tail->next = temp;
        lb.tail = temp;
	}
    cout<<"��������ʽ��ӵĽ��Ϊ";//<<endl;
    lc = (la + lb);
    element *pos=lc.head->next;
    while(pos!=NULL)
    {
        printf("%dX%d",pos->xishu,pos->zhishu);
        printf(" ");
        pos=pos->next;
    }
    return 0;
}
